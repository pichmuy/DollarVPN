#include "portforpage.h"
#include "ui_portforpage.h"


#include "authmanager.h"
#include "wndmanager.h"
#include "settingpage.h"
#include "location.h"
#include "mainwindow.h"
#include "setting.h"
#include "openvpnmanager.h"
#include "common.h"
#include "notification.h"
#include "locationitemview.h"
#include <QStandardItemModel>
#include <QFontDatabase>
#include <QFont>
#include <QDomNodeList>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QTcpSocket>
#include <QScrollBar>
#include <QAbstractItemView>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimer>

std::auto_ptr<PortforPage> PortforPage::mInstance;
PortforPage * PortforPage::instance()
{
    if (!mInstance.get())
        mInstance.reset(new PortforPage());
    return mInstance.get();
}
PortforPage::PortforPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PortforPage)
{
    ui->setupUi(this);
    setFixedSize(this->size());
    setWindowTitle(qApp->applicationName());
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont sans(family);
    sans.setPointSize(9);
    ui->pushButton_2->setFont(sans);
    ui->ToPort->setFont(sans);
    ui->pushButton_4->setFont(sans);
    sans.setPointSize(10);
    ui->status->setFont(sans);
    ui->label_2->setFont(sans);
    ui->label_3->setFont(sans);
    ui->label_4->setFont(sans);
    ui->label_5->setFont(sans);
    ui->label_5->hide();
    ui->frame_5->hide();
    fontDB.addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    id = QFontDatabase::addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont san(family);
    san.setPointSize(7);
    ui->welclabel->setFont(san);
    ui->connected_label->hide();
    san.setPointSize(10);
    ui->location->setFont(san);
    ui->e_Ports->setFont(san);
    san.setPointSize(11);
    ui->portforward->setFont(san);
    fontDB.addApplicationFont(":/resources/img/fonts/SourceSansPro-Bold.ttf");
    id = QFontDatabase::addApplicationFont(":/resources/img/fonts/SourceSansPro-Bold.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont open(family);
    open.setPointSize(14);
    ui->label_6->setFont(open);
    ui->label_6->hide();
    ui->e_Ports->installEventFilter(this);

    connect(OpenvpnManager::instance(),SIGNAL(HandleConnected()),this,SLOT(StatusConnected()));
    connect(OpenvpnManager::instance(),SIGNAL(HandleDisconnected()),this,SLOT(StatusDisconnected()));
    ui->listWidget->clear();
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getPortRequest()));
    timer->start(5000);
//    QScrollBar *vbar = ui->listWidget->verticalScrollBar();
//    vbar->setStyleSheet("");

}

PortforPage::~PortforPage()
{
    delete ui;
}

void PortforPage::closeEvent(QCloseEvent * event)
{
    event->ignore();
    MainWindow::instance()->quitApplication();
}

bool PortforPage::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->e_Ports && event->type() == QEvent::KeyPress)
    {
        Validate_e_Ports();
    }
    return QObject::eventFilter(obj, event);
}

void PortforPage::StatusConnected()
{
    ui->distop->hide();
    ui->welclabel->hide();
    ui->connected_label->show();
}

void PortforPage::StatusDisconnected()
{
    ui->distop->show();
    ui->connected_label->hide();
    ui->welclabel->show();
    ui->label_5->hide();
    ui->label_6->hide();
}

void PortforPage::on_pushButton_2_clicked()
{
    emit move_Conn();
}

QString PortforPage::getinternal_ip()
{
    QTcpSocket socket;
    socket.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable
    if (socket.waitForConnected()) {
        qDebug()
            << "local IPv4 address for Internet connectivity is"
            << socket.localAddress();
        return socket.localAddress().toString();
    } else {
        return "undefined";
    }
}

void PortforPage::on_pushButton_4_clicked()
{
    ui->frame_5->hide();
    SettingPage::instance()->hide();
    SettingPage::instance()->show();
}

//void PortforPage::on_location_clicked()
//{
//    ui->frame_4->show();
//    ui->listWidget->clear();
//    for(int i=0;i<AuthManager::instance()->mServers.count();i++ )
//    {
//      Location *location=new Location;
//      location->change_server(i);
//      QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget);
//      ui->listWidget->addItem(listWidgetItem);
//      listWidgetItem->setSizeHint(QSize(240,43));
//      ui->listWidget->setItemWidget(listWidgetItem,location);

//    }
//}

static const char * gs_sPortsNorm =
        "QLineEdit {background-color:#18191e;border:#18191e;color:#979696;border-radius:10px;"
        "padding-left:12px;}";
static const char * gs_sPortsErr =
        "QLineEdit {background-color:#18191e;border:#18191e;color:red;border-radius:10px;"
        "padding-left:12px;}";
void PortforPage::Validate_e_Ports()
{
    if (IsValidPort(ui->e_Ports->text())) {
        ui->e_Ports->setStyleSheet(gs_sPortsNorm);
//        Setting::instance()->setForwardPorts(ui->e_Ports->text());
    } else
        ui->e_Ports->setStyleSheet(gs_sPortsErr);
}

//bool PortforPage::IsPortsValid(USet * out_ports)	// = NULL)
//{
//    bool valid = true;
//    if (out_ports != NULL)
//        out_ports->clear();
//    bool tmp;
//    int count = 0;
//    if (!ui->e_Ports->text().trimmed().isEmpty()) {
//        QStringList pp = ui->e_Ports->text().split(",");
//        for (int k = 0; k < pp.length(); ++k) {
//            if (!IsValidPort(pp[k])) {
//                valid = false;
//                if (out_ports != NULL)
//                    out_ports->clear();
//                break;
//            } else {
//                if (out_ports != NULL)
//                    out_ports->insert(pp[k].toInt(&tmp));
//                ++count;
//            }
//        }
//    }

//    if (valid)
//        if (count > PORT_FORWARD_MAX)
//            valid = false;

//    return valid;
//}

//USet PortforPage::Ports()
//{
//    USet pp;
//    if (!IsPortsValid(&pp))
//        pp.clear();
//    return pp;
//}



void PortforPage::on_listWidget_clicked(const QModelIndex &index)
{
    ui->frame_5->hide();
//    if(currentindex!=pastindex)
//    {
//     qDebug()<<pastindex;
//     QListWidgetItem *pastitem=ui->listWidget->item(pastindex);
//     Location *past_location=qobject_cast<Location*>(ui->listWidget->itemWidget(pastitem));
//     connect(this,SIGNAL(disselect_ping()),past_location,SLOT(disselected()));
//     emit disselect_ping();

//    QListWidgetItem *listitem=ui->listWidget->currentItem();
//    selected_location=qobject_cast<Location*>(ui->listWidget->itemWidget(listitem));
//    QString loc=AuthManager::instance()->mServers[currentindex].country+"-"+AuthManager::instance()->mServers[currentindex].state;
//    ui->location->setText(loc);
//    connect(this,SIGNAL(select_ping()),selected_location,SLOT(selected()));
//    emit select_ping();
//    pastindex=currentindex;
//    disconnect(this,SIGNAL(select_ping()),selected_location,SLOT(selected()));
//    disconnect(this,SIGNAL(disselect_ping()),past_location,SLOT(disselected()));
}

void PortforPage::on_logout_clicked()
{
    ui->frame_5->hide();
    ui->logout->setEnabled(false);
    AuthManager::instance()->logout();
}

void PortforPage::on_portforward_clicked()
{
   ui->frame_5->hide();
   if(ui->location->text()=="Location")
   {
       errorMsg("Please select the location.");
   }
   else
   {
       if(OpenvpnManager::instance()->openvpnRunning())
       {
           Validate_e_Ports();
           ui->portforward->setEnabled(false);
           qDebug()<<ui->listWidget_2->currentRow();
           QString sid=AuthManager::instance()->mServers[ui->listWidget_2->currentRow()].id;
           ports=ui->e_Ports->text();
           net=new QNetworkAccessManager();
           QUrl bvpn("https://dollarvpn.net/api/1.0/clientapi.php?action=openPort");
           QNetworkRequest request(bvpn);
           request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
           QUrlQuery postData;
           postData.addQueryItem("tkn",AuthManager::instance()->mAccounttoken);
           postData.addQueryItem("port",ports);
           postData.addQueryItem("sid",sid);
           postData.addQueryItem("ip",getinternal_ip());
           qDebug()<<postData.toString();
           reply=net->post(request,postData.toString(QUrl::FullyEncoded).toUtf8());
           connect(net,SIGNAL(finished(QNetworkReply*)),this,SLOT(openPort()));
       }
       else{
           errorMsg("You are not connected to vpn server now.");
       }
   }
}

void PortforPage::openPort()
{
    QString responses =(QString) reply->readAll();
    qDebug()<<"OpenPort   "+responses;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(responses.toUtf8());
    QJsonObject resultObject=jsonResponse.object();
    int returnresult=resultObject["ecode"].toInt();
    qDebug()<<returnresult;
    if(returnresult==200)
    {
        Port addedport;
        addedport.ip=getinternal_ip();
        addedport.port=ui->e_Ports->text();
        addedport.server=AuthManager::instance()->mServers[ui->listWidget_2->currentRow()].id;
        AuthManager::instance()->mPorts.append(addedport);
        refresh_widget();
        ui->label_6->setText(ports);
        ui->label_6->show();
        ui->label_5->show();
    }
    else if(returnresult==201)
    {
        errorMsg("Missing or invalid Parameter");
    }
    else if(returnresult==505)
    {
        errorMsg("Token is invalid/Expired   ");
    }
    else if(returnresult==600)
    {
        errorMsg("Port is open        ");
    }
    else if(returnresult==601)
    {
        errorMsg("Port is black listed     ");
    }
    else if(returnresult==602)
    {
        errorMsg("Port is not a valid port number");
    }
    else if(returnresult==603)
    {
        errorMsg("IP is not valid         ");
    }
    else if(returnresult==604)
    {
        errorMsg("IP is not validServer does not exist or is offline");
    }
    ui->portforward->setEnabled(true);
}

void PortforPage::refresh_widget()
{
    ui->listWidget->clear();
    qDebug()<<"refresh called";
    for(int i=0;i<AuthManager::instance()->mPorts.count();i++ )
    {
          Location *location=new Location;
          location->change_server(i);
          connect(location,SIGNAL(errorMsg(QString)),MainWindow::instance(),SLOT(errorNotification(QString)));
          QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget);
          ui->listWidget->addItem(listWidgetItem);
          listWidgetItem->setSizeHint(QSize(700,62));
          ui->listWidget->setItemWidget(listWidgetItem,location);
    }
    oldPorts=AuthManager::instance()->mPorts;
}

void PortforPage::getPort()
{
    QString member=(QString) reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(member.toUtf8());
    QJsonObject initialObject=jsonResponse.object();
    QJsonArray jsonObjectserver=initialObject.value("ports").toArray();
    QList<Port> mPorts;
    for(int i=0;i<jsonObjectserver.count();i++ )
    {
    QJsonObject resultObject=jsonObjectserver.at(i).toObject();
    Port port_item;
    port_item.portID=resultObject.value("portID").toString();
    port_item.port=resultObject.value("port").toString();
    port_item.ip=resultObject.value("ip").toString();
    port_item.server=resultObject.value("server").toString();
    mPorts.append(port_item);
    }
    disconnect(net,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPort()));
    if(mPorts.count()!=AuthManager::instance()->mPorts.count())
    {
        refresh_widget();
        AuthManager::instance()->mPorts=mPorts;
    }
    if(oldPorts.count()!=AuthManager::instance()->mPorts.count()) refresh_widget();
}

void PortforPage::getPortRequest()
{
    net=new QNetworkAccessManager();
    QUrl bvpn("https://dollarvpn.net/api/1.0/clientapi.php?action=getPorts");
    QNetworkRequest request(bvpn);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QUrlQuery postData;
    postData.addQueryItem("tkn",AuthManager::instance()->mAccounttoken);
    reply=net->post(request,postData.toString(QUrl::FullyEncoded).toUtf8());
    connect(net,SIGNAL(finished(QNetworkReply*)),this,SLOT(getPort()));
}

void PortforPage::on_location_clicked()
{

    ui->listWidget_2->clear();
    for(int i=0;i<AuthManager::instance()->mServers.count();i++ )
    {
      LocationItemView *locationitem=new LocationItemView;
      locationitem->change_server(i);
      QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget_2);
      ui->listWidget_2->addItem(listWidgetItem);
      listWidgetItem->setSizeHint(QSize(220,31));
      ui->listWidget_2->setItemWidget(listWidgetItem,locationitem);

    }
    ui->frame_5->show();
}

void PortforPage::on_listWidget_2_clicked(const QModelIndex &index)
{

    int currentindex=ui->listWidget_2->currentRow();
//    if(currentindex!=pastindex)
//    {
     qDebug()<<pastindex;
     QListWidgetItem *pastitem=ui->listWidget_2->item(pastindex);
     LocationItemView *past_location=qobject_cast<LocationItemView*>(ui->listWidget_2->itemWidget(pastitem));
     connect(this,SIGNAL(disselect_ping()),past_location,SLOT(disselected()));
     emit disselect_ping();

    QListWidgetItem *listitem=ui->listWidget_2->currentItem();
    selected_locationitem=qobject_cast<LocationItemView*>(ui->listWidget_2->itemWidget(listitem));
    QString loc=AuthManager::instance()->mServers[currentindex].country+"("+AuthManager::instance()->mServers[currentindex].state+")";
    ui->location->setText(loc);
    connect(this,SIGNAL(select_ping()),selected_locationitem,SLOT(selected()));
    emit select_ping();
    pastindex=currentindex;
    disconnect(this,SIGNAL(select_ping()),selected_locationitem,SLOT(selected()));
    disconnect(this,SIGNAL(disselect_ping()),past_location,SLOT(disselected()));
    ui->frame_5->hide();
}
