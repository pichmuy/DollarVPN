#include "connectpage.h"
#include "ui_connectpage.h"




#include "settingpage.h"
#include "wndmanager.h"
#include "authmanager.h"
#include "mainwindow.h"
#include "openvpnmanager.h"
#include "setting.h"
#include "listwidgetthread.h"
#include "mainwindow.h"
#include <QFontDatabase>
#include <QScrollBar>
#include <QSplashScreen>
#include <QTimer>

std::auto_ptr<ConnectPage> ConnectPage::mInstance;
ConnectPage * ConnectPage::instance()
{
    if (!mInstance.get())
        mInstance.reset(new ConnectPage());
    return mInstance.get();
}
ConnectPage::ConnectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectPage)
{
    ui->setupUi(this);
    setFixedSize(this->size());
    setWindowTitle(qApp->applicationName());
    init();
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont sans(family);
    sans.setPointSize(9);
    ui->pushButton_2->setFont(sans);
    ui->ToPort->setFont(sans);
    ui->pushButton_4->setFont(sans);
    sans.setPointSize(8);
    ui->country_sort->setFont(sans);
    ui->name->setFont(sans);
    ui->load->setFont(sans);
    ui->encryption->setFont(sans);

    fontDB.addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    id = QFontDatabase::addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont open(family);
    open.setPointSize(9);
    ui->all->setFont(open);
    ui->all->setText("All Servers("+QString::number(AuthManager::instance()->mServers.count())+")");
    open.setPointSize(7);
    ui->welclabel->setFont(open);
    ui->connected_label->hide();
    QScrollBar *vbar = ui->listWidget->verticalScrollBar();
    vbar->setStyleSheet("");
    connect(OpenvpnManager::instance(),SIGNAL(HandleConnected()),this,SLOT(StatusConnected()));
    connect(OpenvpnManager::instance(),SIGNAL(HandleDisconnected()),this,SLOT(StatusDisconnected()));
    connect(OpenvpnManager::instance(),SIGNAL(HandleConnecting()),this,SLOT(StatusConnecting()));
//    if(Setting::instance()->reconnect())
//    {

//         if (!OpenvpnManager::instance()->openvpnRunning()) OpenvpnManager::instance()->start();
//    }
}

ConnectPage::~ConnectPage()
{
    delete ui;
}

void ConnectPage::closeEvent(QCloseEvent * event)
{
    event->ignore();
    MainWindow::instance()->quitApplication();
}

void ConnectPage::init()
{
    ListWidgetThread *listthread = new ListWidgetThread(this,ui->listWidget);
    listthread->init();
}

void ConnectPage::StatusConnecting()
{
    QPixmap loadingpix(":/resources/img/settings.png");
    loadingpix = QPixmap(300, 300);
    loadingpix.fill(Qt::magenta);
    QSplashScreen splash(loadingpix);
    splash.show();
}

void ConnectPage::StatusConnected()
{
    ui->distop->hide();
    ui->welclabel->hide();
    ui->connected_label->show();
    g_pTheApp->setWindowIcon(QIcon(":/resources/img/conn_Icon.ico"));

}

void ConnectPage::StatusDisconnected()
{
    ui->distop->show();
    ui->connected_label->hide();
    ui->welclabel->show();
    g_pTheApp->setWindowIcon(QIcon(":/resources/img/normal_icon.ico"));
}

void ConnectPage::updateserver()
{


//    ui->listWidget->clear();
//    for(int i=0;i<AuthManager::instance()->mServers.count();i++ )
//    {
//      Server *server=new Server;
//      server->change_server(i);
//      QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget);
//      ui->listWidget->addItem(listWidgetItem);
//      listWidgetItem->setSizeHint(QSize(780,60));
//      ui->listWidget->setItemWidget(listWidgetItem,server);

//    }

}

void ConnectPage::on_ToPort_clicked()
{
    emit move_Port();
}

void ConnectPage::on_pushButton_4_clicked()
{
    SettingPage::instance()->hide();
    SettingPage::instance()->show();
}

void ConnectPage::on_logout_clicked()
{
    ui->logout->setEnabled(false);
    disconnect(AuthManager::instance(), SIGNAL(loginError(QString)),
            MainWindow::instance(), SLOT(loginError(QString)));
    AuthManager::instance()->logout();
}

void ConnectPage::on_country_sort_clicked()
{

}

