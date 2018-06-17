#include "log.h"
#include "pathhelper.h"
#include "server.h"
#include "ui_server.h"


#include "authmanager.h"
#include "openvpnmanager.h"
#include "setting.h"
#include "wndmanager.h"
#include "portforpage.h"
#include "connectpage.h"
#include "notification.h"
#include <QFontDatabase>
#include <QFont>
#include <QFile>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QIODevice>

std::auto_ptr<Server> Server::mInstance;
Server * Server::instance()
{
    if (!mInstance.get())
        mInstance.reset(new Server());
    return mInstance.get();
}
Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->status->hide();
    QPixmap upgradepixmap(":/resources/img/plus.PNG");
    QIcon buttonicon(upgradepixmap);
    this->ui->disconn->setIcon(buttonicon);
    QPixmap flagpixmap(":/resources/img/flags/NL.png");
    this->ui->flagid->setPixmap(flagpixmap);
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/resources/img/fonts/open-sans.bold.ttf");
    int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/open-sans.bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont sans(family);
    sans.setPointSize(8);
    ui->label->setFont(sans);
    ui->label_2->setFont(sans);
    ui->progressBar->setFont(sans);
    ui->offline->hide();
    fontDB.addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    id = QFontDatabase::addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont semisans(family);
    semisans.setPointSize(7);
    ui->state->setFont(semisans);
    semisans.setPointSize(8);
    ui->country->setFont(semisans);
    semisans.setPointSize(9);
    ui->disconn->setFont(semisans);
    effect	= new QGraphicsDropShadowEffect();

}

Server::~Server()
{
    delete ui;
}

void Server::change_server(int seq)
{
    this->index=seq;
    QString name=AuthManager::instance()->mServers[seq].name;
    QString flag_name=name.mid(0,2);
    QString country=AuthManager::instance()->mServers[seq].country;
    QString flag=":/resources/img/flags/"+flag_name+".png";
    QString state=AuthManager::instance()->mServers[seq].state;
    int load=randInt(10,30);
    ui->label->setText(name);
    if(AuthManager::instance()->mServers[seq].status=="1") this->ui->progressBar->setValue(load);
    else ui->progressBar->setValue(0);
    this->ui->country->setText(country);
    this->ui->state->setText(state);
    QPixmap flagpixmap(flag);
    this->ui->flagid->setPixmap(flagpixmap);
    if(AuthManager::instance()->mServers[seq].status=="0")
    {
        ui->disconn->setText("Offline                 ");
        ui->disconn->setIcon(QIcon());
        ui->disconn->setEnabled(false);
        ui->offline->show();
        ui->frame->setStyleSheet("QFrame{background-color:#262836;}");
        ui->country->setStyleSheet("QLabel{color:#4a4d5c;background-color:#262836;}");
        ui->state->setStyleSheet("QLabel{color:#4a4d5c;background-color:#262836;}");
        ui->label->setStyleSheet("QLabel{color:#4a4d5c;background-color:#262836;}");
        ui->label_2->setStyleSheet("QLabel{color:#4a4d5c;background-color:#262836;}");
        ui->progressBar->setStyleSheet("QProgressBar{border: 7px solid #262836;border-radius:10px;background-color:#4a4d5c;text-align:left;margin-left: 12ex;color:#4a4d5c;}QProgressBar::chunk:horizontal {background: #4a4d5c;border-radius:3px;}");
        ui->disconn->setStyleSheet("QPushButton{background-color:#262836;border-radius:17px;border-style:solid;color:#4a4d5c;border:1.5px solid #4a4d5c;padding-left:5px;padding-right:15px;padding-bottom:3px;}");

    }
}

int Server::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}

void Server::on_disconn_clicked()
{
    this->ui->disconn->setIcon(QIcon());
    if(!OpenvpnManager::instance()->openvpnRunning()) ui->disconn->setText("Connecting...");
    ui->disconn->setEnabled(false);
    QString name=AuthManager::instance()->mServers[index].name;
    QString currentname=Setting::instance()->currentserver.name;

    if (OpenvpnManager::instance()->openvpnRunning()) {
        if(name==currentname)
        {
            OpenvpnManager::instance()->stop();
            ui->disconn->setEnabled(true);
        }
        else {
        OpenvpnManager::instance()->stop();
        connect(OpenvpnManager::instance(),SIGNAL(HandleConnected()),this,SLOT(StatusConnected()));
        connect(OpenvpnManager::instance(),SIGNAL(HandleConnecting()),this,SLOT(StatusConnecting()));
        connect(OpenvpnManager::instance(),SIGNAL(HandleDisconnected()),this,SLOT(StatusDisconnected()));
        Setting::instance()->currentserver=AuthManager::instance()->mServers[index];
        qDebug()<<Setting::instance()->currentserver.ip;
        Create_Conf();
        OpenvpnManager::instance()->start();
        }
    }

    else
    {
        connect(OpenvpnManager::instance(),SIGNAL(HandleConnected()),this,SLOT(StatusConnected()));
        connect(OpenvpnManager::instance(),SIGNAL(HandleConnecting()),this,SLOT(StatusConnecting()));
        connect(OpenvpnManager::instance(),SIGNAL(HandleDisconnected()),this,SLOT(StatusDisconnected()));
        Setting::instance()->currentserver=AuthManager::instance()->mServers[index];
        qDebug()<<Setting::instance()->currentserver.ip;
        Create_Conf();
        OpenvpnManager::instance()->start();
     }
}

void Server::Create_Conf()
{
    QNetworkAccessManager *net=new QNetworkAccessManager();
    QUrl bvpnserver("https://dollarvpn.net/downloads/configs/client.ovpn");
    QNetworkRequest requestserver(bvpnserver);
    QNetworkReply *reply=net->get(requestserver);
    log::logt("After request");
    QEventLoop loop;
    connect(net,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    loop.exec();
    disconnect(net,SIGNAL(finished(QNetworkReply*)),&loop,SLOT(quit()));
    log::logt("Connect Preparing: ");

    QString responses =(QString) reply->readAll();
    responses.replace("<<PROTOCOL>>",Setting::instance()->getProtocol());
    responses.replace("<<SERVER_IP>>",Setting::instance()->currentserver.ip);
    QString port;
    if(Setting::instance()->getProtocol()=="tcp") port="443";
    else port="1194";
    responses.replace("<<SERVER_PORT>>",port);
    qDebug()<<responses;
    QUrl bvpnkey(Setting::instance()->currentserver.config);
    QNetworkRequest requestkey(bvpnkey);
    QNetworkReply *replykey=net->get(requestkey);
    log::logt("After request");
    QEventLoop loops;
    connect(net,SIGNAL(finished(QNetworkReply*)),&loops,SLOT(quit()));
    loops.exec();

    log::logt("Connect Preparing: ");

    QString responsekey =(QString) replykey->readAll();
    qDebug()<<responsekey;
    QString conf=responses+"\n"+responsekey;
    qDebug()<<conf;
    QFile ff(PathHelper::Instance()->openvpnConfigFilename(Setting::instance()->currentserver.name+"-cert.ovpn"));
    if (!ff.open(QIODevice::WriteOnly)) {
        QString se = "Cannot write config file";
        log::logt(se);
        errorMsg(se);
    }
    else{
    QTextStream outputStream(&ff);
    conf.replace("\n","\r\n");
    outputStream<<conf;
    ff.close();
    }
}

void Server::StatusConnecting()
{
   ui->disconn->setEnabled(true);
   blur=0;
   direction=true;

   timer = new QTimer(this);
   connect(timer, SIGNAL(timeout()), this, SLOT(Shadow()));
   timer->start(20);
}

void Server::Shadow()
{
    if(blur>25) direction=false;
    if(blur<1) direction=true;
    if(direction) blur++;
    else blur--;
    effect->setBlurRadius(blur);
    effect->setColor(QColor(255,180,0,255));
    effect->setOffset(0);
    ui->disconn->setGraphicsEffect(effect);
}

void Server::StatusConnected()
{
    ui->disconn->setEnabled(true);
    ui->disconn->setText("Disconnect  ");
    QPixmap upgradepixmap(":/resources/img/minus.PNG");
    QIcon buttonicon(upgradepixmap);
    this->ui->disconn->setIcon(buttonicon);
    timer->stop();
    delete timer;
    effect->setEnabled(false);
    ui->disconn->setGraphicsEffect(effect);
    ui->status->show();
    ui->frame->setStyleSheet("QFrame{background-color:#2b2d3c;}");
    ui->country->setStyleSheet("QLabel{color:#ffffff;background-color:#2b2d3c;}");
    ui->state->setStyleSheet("QLabel{color:#616474;background-color:#2b2d3c;}");
    ui->label->setStyleSheet("QLabel{color:#ffffff;background-color:#2b2d3c;}");
    ui->label_2->setStyleSheet("QLabel{color:#ffffff;background-color:#2b2d3c;}");
    ui->offline->hide();
    ui->progressBar->setStyleSheet("QProgressBar{border: 7px solid #2b2d3c;border-radius:10px;background-color:#4e5160;text-align:left;margin-left: 12ex;color:#ffffff;}QProgressBar::chunk:horizontal {background: #ffb400;border-radius:3px;}");
    ui->disconn->setStyleSheet("QPushButton{background-color:#2b2d3c;border-radius:17px;border-style:solid;color:#c4c5c9;border:1.5px solid #ffb400;padding-left:5px;padding-right:15px;padding-bottom:3px;}");
    disconnect(OpenvpnManager::instance(),SIGNAL(HandleConnected()),this,SLOT(StatusConnected()));
    disconnect(OpenvpnManager::instance(),SIGNAL(HandleConnecting()),this,SLOT(StatusConnecting()));
//    QString localip=PortforPage::instance()->getinternal_ip();
    QString content="Connected to "+Setting::instance()->currentserver.state+"- "+Setting::instance()->currentserver.country;
    content=content+"\nLocal IP: "+PortforPage::instance()->getinternal_ip()+"\nRemote IP : "+Setting::instance()->currentserver.ip;
    setPopupText("Connection Established!\n\n",content);

}

void Server::StatusDisconnected()
{
    ui->disconn->setEnabled(true);
    ui->disconn->setText("Connect     ");
    QPixmap upgradepixmap(":/resources/img/add.PNG");
    QIcon buttonicon(upgradepixmap);
    this->ui->disconn->setIcon(buttonicon);
    effect->setEnabled(false);
    ui->disconn->setGraphicsEffect(effect);
    ui->status->hide();
    ui->frame->setStyleSheet("QFrame{background-color:#262836;}");
    ui->country->setStyleSheet("QLabel{color:#ffffff;background-color:#262836;}");
    ui->state->setStyleSheet("QLabel{color:#616474;background-color:#262836;}");
    ui->label->setStyleSheet("QLabel{color:#ffffff;background-color:#262836;}");
    ui->label_2->setStyleSheet("QLabel{color:#ffffff;background-color:#262836;}");
    ui->offline->hide();
    ui->progressBar->setStyleSheet("QProgressBar{border: 7px solid #262836;border-radius:10px;background-color:#4e5160;text-align:left;margin-left: 12ex;color:#ffffff;}QProgressBar::chunk:horizontal {background: #ffb400;border-radius:3px;}");
    ui->disconn->setStyleSheet("QPushButton{background-color:#262836;border-radius:17px;border-style:solid;color:#c4c5c9;border:1.5px solid #ffb400;padding-left:5px;padding-right:15px;padding-bottom:3px;}");
    disconnect(OpenvpnManager::instance(),SIGNAL(HandleDisconnected()),this,SLOT(StatusDisconnected()));
    setPopupText("Disconnected!\n\n","Disconnected from DollarVPN Service");

}

void Server::on_background()
{
    ui->frame->setStyleSheet("");
}

