#include "location.h"
#include "ui_location.h"
#include "authmanager.h"
#include "wndmanager.h"
#include "portforpage.h"
#include "notification.h"
#include "mainwindow.h"
#include <QFontDatabase>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


std::auto_ptr<Location> Location::mInstance;
Location * Location::instance()
{
    if (!mInstance.get())
        mInstance.reset(new Location());
    return mInstance.get();
}

Location::Location(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Location)
{
    ui->setupUi(this);
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont open(family);
    open.setPointSize(9);
    ui->location_txt->setFont(open);
    open.setPointSize(11);
    ui->port->setFont(open);
    ui->internalIP->setFont(open);
//    connect(this, SIGNAL(closed_port()),PortforPage::instance(),SLOT(refresh_widget()));
}

Location::~Location()
{
    delete ui;
}


void Location::selected()
{

    this->ui->frame->setStyleSheet("background-color: #2b2d3c;");
//    QPixmap logopixmap(":/resources/img/locationon.PNG");
//    this->ui->location_img->setPixmap(logopixmap);
    ui->location_txt->setStyleSheet("QLabel { color:#535454;padding:5px;}");

}

void Location::disselected()
{

    this->ui->frame->setStyleSheet("background-color: #262836;");

//    QPixmap logopixmap(":/resources/img/locationoff.PNG");
//    this->ui->location_img->setPixmap(logopixmap);
    ui->location_txt->setStyleSheet("QLabel { color:#31333d;padding:5px;}");
}

void Location::change_server(int seq)
{
    this->index=seq;
    QString port=AuthManager::instance()->mPorts[seq].port;
    QString ip=AuthManager::instance()->mPorts[seq].ip;
    QString server=AuthManager::instance()->mPorts[seq].server;
    for(int i=0;i<AuthManager::instance()->mServers.count();i++)
    {
        if(server==AuthManager::instance()->mServers[i].id)
        {ui->location_txt->setText(AuthManager::instance()->mServers[i].country+" - "+AuthManager::instance()->mServers[i].state+"("+AuthManager::instance()->mServers[i].name+")");}
    }
    ui->port->setText(port);
    ui->internalIP->setText(ip);
}

void Location::on_pushButton_clicked()
{
    QString portID=AuthManager::instance()->mPorts[index].portID;
    net=new QNetworkAccessManager();
    QUrl bvpn("https://dollarvpn.net/api/1.0/clientapi.php?action=closePort");
    QNetworkRequest request(bvpn);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QUrlQuery postData;
    postData.addQueryItem("tkn",AuthManager::instance()->mAccounttoken);
    postData.addQueryItem("portID",portID);
    qDebug()<<postData.toString();
    reply=net->post(request,postData.toString(QUrl::FullyEncoded).toUtf8());
    connect(net,SIGNAL(finished(QNetworkReply*)),this,SLOT(closePort()));
    ui->pushButton->setEnabled(false);
}

void Location::closePort()
{
    QString responses =(QString) reply->readAll();
    qDebug()<<"OpenPort   "+responses;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responses.toUtf8());
    QJsonObject resultObject=jsonResponse.object();
    int returnresult=resultObject["ecode"].toInt();
    qDebug()<<returnresult;
    if(returnresult==200)
    {
      AuthManager::instance()->mPorts.removeAt(index);
    }
    else if(returnresult==605)
    {
        errorMsg("Port is not open for you.");
    }

}
