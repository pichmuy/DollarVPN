#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "firstpage.h"
#include "connectpage.h"
#include <QFontDatabase>
#include <QFont>
#include <QTimer>
#include "openvpnmanager.h"
#include "osspecific.h"
#include "setting.h"
#include "wndmanager.h"
#include "authmanager.h"
#include "log.h"
#include "trayiconmanager.h"
#include "loading.h"
#include "notification.h"
#include "location.h"
#include <QDesktopWidget>
#include <QIcon>
#include <QDebug>
std::auto_ptr<MainWindow> MainWindow::mInstance;
MainWindow * MainWindow::instance()
{
    if (!mInstance.get())
        mInstance.reset(new MainWindow());
    return mInstance.get();
}
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    setWindowTitle(qApp->applicationName());
    QPixmap bkgnd(":/resources/img/background.png");
    bkgnd=bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    setFixedSize(this->size());

    QSettings settings("settings.ini",QSettings::IniFormat);
    if (settings.contains("pos")) {
        QDesktopWidget *desktop = QApplication::desktop();
        QPoint p = settings.value("pos").toPoint();
        if (desktop->availableGeometry().contains(p))
            WndManager::instance()->trans(p, this);
        else
            WndManager::instance()->trans(QPoint(100, 100), this);
    }
    loading=new QMovie(":/resources/img/loading.gif");
    ui->rememberMeButton->setChecked(settings.value("cb_Rememberme", true).toBool());

    if (ui->rememberMeButton->isChecked()) {
        if (settings.contains("eLogin"))
            ui->eLogin->setText(settings.value("eLogin", "").toString());
    }

    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/resources/img/fonts/open-sans.bold.ttf");
    int boldid = QFontDatabase::addApplicationFont(":/resources/img/fonts/open-sans.bold.ttf");
    QString boldfamily = QFontDatabase::applicationFontFamilies(boldid).at(0);
    QFont boldsans(boldfamily);
    boldsans.setPointSize(10);
    ui->signin->setFont(boldsans);
    fontDB.addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont sans(family);
    sans.setPointSize(10);
    ui->label_3->setFont(sans);
    ui->label_4->setFont(sans);
    ui->upgrade->setFont(sans);
    effect	= new QGraphicsDropShadowEffect();
    effect->setBlurRadius(20);
    effect->setColor(QColor(255,255,255,255));
    effect->setOffset(0);
    ui->eLogin->setGraphicsEffect(effect);
    QGraphicsDropShadowEffect *signEffect = new QGraphicsDropShadowEffect();
    signEffect->setBlurRadius(20);
    signEffect->setColor(QColor(248,205,59));
    signEffect->setOffset(0);
    ui->signin->setGraphicsEffect(signEffect);
    connect(loading,SIGNAL(frameChanged(int)),this,SLOT(setButtonIcon(int)));
    connect(loading,SIGNAL(finished()),loading,SLOT(start()));
    QTimer::singleShot(100, this, SLOT(Timer_Constructed()));
}

MainWindow::~MainWindow()
{
    if (this->isVisible())
        WndManager::instance()->HideThis(this);
    else
        WndManager::instance()->CloseAll();
    if (this->isVisible())
        WndManager::instance()->HideThis(this);
    WndManager::instance()->SavePos();
    TrayIconManager::cleanup();
    AuthManager::cleanup();
    OpenvpnManager::cleanup();
    OsSpecific::cleanup();
    Setting::cleanup();
    WndManager::Cleanup();
    Cleanup();
    delete ui;
}

void MainWindow::quitApplication()
{
// HACK: workaround: without any form visible program exits => force show() primary
//	if (WndManager::Instance()->ScrVisible() != NULL)
    int res = QDialog::Rejected;

        // already confirmed, so set res to accepted
        res = QDialog::Accepted;


    if (res == QDialog::Accepted) {
        mQuitConfirmed = true;
        WndManager::instance()->CloseAll();
        if (OpenvpnManager::exists())
            OpenvpnManager::instance()->stop();
        g_pTheApp->quit();
    }
}

void MainWindow::setButtonIcon(int frame)
{
    ui->signin->setIcon(QIcon(loading->currentPixmap()));

}

void MainWindow::closeEvent(QCloseEvent * event)
{
    event->ignore();
    quitApplication();
}

void MainWindow::on_signin_clicked()
{

        QString userid=ui->eLogin->text();
//        loading->start();
        if(userid=="")
        {
            loading->stop();
            ui->signin->setIcon(QIcon());
            popupNotification("Invalid Credentials\n\n","You have entered an invalid User-Id.\nPlease enter the correct details and try again.\nDon't forget that the User-Id is case sensitive.");
        }
        else{
            AuthManager::instance()->login(userid);
            enableButtons(false);
        }
}

void MainWindow::on_upgrade_clicked()
{

}

void MainWindow::Timer_Constructed()
{
    AuthManager::instance()->getOldIP();
    connect(AuthManager::instance(), SIGNAL(loginCompleted()),
            this, SLOT(loggedIn()));
    connect(AuthManager::instance(), SIGNAL(loginError(QString)),
            this, SLOT(loginError(QString)));
    connect(AuthManager::instance(),SIGNAL(logoutCompleted()),this,SLOT(logout()));

    if (Setting::instance()->autoconnect()) {
        log::logt("autoconnect set so logging in automatically");
        _ConnectAfterLogin = true;
        on_signin_clicked();
    }

    if (Setting::instance()->detectInsecureWifi()) {
        log::logt("autodetect insecure wifi is on, so starting wifi watcher");
        startWifiWatcher();
    }
}

void MainWindow::Cleanup()
{
    std::auto_ptr<MainWindow> d(mInstance.release());
}

void MainWindow::ToScr_Primary()
{
    WndManager::instance()->ToPrimary();
}


void MainWindow::enableButtons(bool enabled)
{
    ui->signin->setEnabled(enabled);
    ui->eLogin->setEnabled(enabled);
    ui->upgrade->setEnabled(enabled);
//    ui->ePsw->setEnabled(enabled);
}

void MainWindow::StatusConnecting()
{

    TrayIconManager::instance()->updateStateIcon(OpenvpnManager::ovsConnecting);
}

void MainWindow::StatusConnected()
{
    TrayIconManager::instance()->updateStateIcon(OpenvpnManager::ovsConnected);
}

void MainWindow::StatusDisconnected()
{
    TrayIconManager::instance()->updateStateIcon(OpenvpnManager::ovsDisconnected);
}


void MainWindow::startWifiWatcher()
{
    if (NULL == _timer_wifi.get()) {
        _wifi_processing = false;
        _timer_wifi.reset(new QTimer());
        connect(_timer_wifi.get(), SIGNAL(timeout()), this, SLOT(checkWifi()));
        _timer_wifi->start(5000);
    }
}

void MainWindow::stopWifiWatcher()
{
    if (NULL != _timer_wifi.get()) {
        QTimer * t = _timer_wifi.release();
        t->stop();
        t->deleteLater();
    }
}

void MainWindow::checkWifi()
{
    if (NULL != _timer_wifi.get() 		// if not terminating now
            && !_wifi_processing) {			// and not already in the body below
        _wifi_processing = true;
        log::logt("Checking wifi");
        bool stopped = false;
        if (!AuthManager::exists()) {
            log::logt("setting stopped because AuthManager doesn't exist");
            stopped = true;
        } else {
            if (!OpenvpnManager::exists()) {
                log::logt("setting stopped because OpenvpnManager doesn't exist");
                stopped = true;
            } else {
                if (OpenvpnManager::instance()->state() == OpenvpnManager::ovsDisconnected) {
                    log::logt("setting stopped because openvpnmanager is disconnected");
                    stopped = true;
                }
            }
        }

        if (stopped) {
            if (!AuthManager::instance()->loggedIn()) {
                if (Setting::instance()->autoconnect()) {	// log in only if checked Auto-connect when app starts
                    log::logt("Autoconnect is set, so logging in if hasInSecureWifi");
                    if (OsSpecific::instance()->hasInsecureWifi()) {
                        log::logt("Logging in because hasInsecureWifi");
                        _ConnectAfterLogin = true;
                        on_signin_clicked();
                    }
                }
            } else {
                log::logt("starting openvpn manager.....");
                if (OsSpecific::instance()->hasInsecureWifi())                 
                    OpenvpnManager::instance()->start();

            }
        }
        _wifi_processing = false;
    }
}

void MainWindow::detectInsecureWifiChanged()
{
    if (Setting::instance()->detectInsecureWifi())
        MainWindow::instance()->startWifiWatcher();
    else
        MainWindow::instance()->stopWifiWatcher();
}

void MainWindow::BlockOnDisconnect()
{

    bool doblock = false;
    if (Setting::instance()->blockOnDisconnect()) {
        if (AuthManager::exists()) {
            if (!AuthManager::instance()->loggedIn()) {
                doblock = true;
            } else {
                if (!OpenvpnManager::exists()) {
                    doblock = true;
                } else {
                    if (OpenvpnManager::instance()->state() == OpenvpnManager::ovsDisconnected)
                        doblock = true;
                    // otherwise unblocked and should be unblocked
                }
            }
        }
    }

    if (doblock) {
        OsSpecific::instance()->netDown();
    }
}

void MainWindow::saveCredentials()
{
    QSettings settings("settings.ini",QSettings::IniFormat);

    settings.setValue("eLogin", ui->eLogin->text());


}

void MainWindow::loggedIn()
{
    qDebug()<<"Logged In Called";
    log::logt("LoginWindow loggedIn called\n");
    if (ui->rememberMeButton->isChecked()){
            saveCredentials();
    }
    disconnect(AuthManager::instance(), SIGNAL(loginError(QString)),
            this, SLOT(loginError(QString)));
    Setting::instance()->currentserver = Setting::instance()->getlastServer();
    connect_page = new ConnectPage(ui->stackedWidget);
    ui->stackedWidget->addWidget(connect_page);
    port_page = new PortforPage(ui->stackedWidget);
    ui->stackedWidget->addWidget(port_page);
    connect(port_page,SIGNAL(errorMsg(QString)),this,SLOT(errorNotification(QString)));
    connect(connect_page,SIGNAL(move_Port()),this,SLOT(moveToPort()));
    ui->stackedWidget->setCurrentWidget(connect_page);
    enableButtons(true);
    loading->stop();
    ui->signin->setIcon(QIcon());

}

void MainWindow::loginError(QString message)
{
    enableButtons(true);
    loading->stop();
    ui->signin->setIcon(QIcon());
    log::logt("Login Error " + message);
    popupNotification("Subscription Expired\n\n","Oh looks like your subscription have ran out\nplease resubscribe to be able to continue using the software");
}

void MainWindow::on_rememberMeButton_clicked()
{
    QSettings settings("settings.ini",QSettings::IniFormat);
    settings.setValue("cb_Rememberme", ui->rememberMeButton->isChecked());
}

void MainWindow::logout()
{
    ui->stackedWidget->setCurrentIndex(0);
    QTimer::singleShot(100, this, SLOT(Timer_Constructed()));
}

void MainWindow::moveToPort()
{
    ui->stackedWidget->setCurrentWidget(port_page);
    port_page->refresh_widget();
    connect(port_page,SIGNAL(move_Conn()),this,SLOT(moveToConn()));
}

void MainWindow::moveToConn()
{
    ui->stackedWidget->setCurrentWidget(connect_page);
}

void MainWindow::popupNotification(QString title,QString msg)
{
    notification = new Notification(this);
    notification->setPopupText(title,msg);
    notification->show();
}

void MainWindow::errorNotification(QString msg)
{

    notification = new Notification(this);
    notification->errorMsg(msg);
    notification->show();
}
