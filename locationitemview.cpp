#include "locationitemview.h"
#include "ui_locationitemview.h"
#include "authmanager.h"

LocationItemView::LocationItemView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LocationItemView)
{
    ui->setupUi(this);
}

LocationItemView::~LocationItemView()
{
    delete ui;
}


void LocationItemView::selected()
{

    this->ui->frame->setStyleSheet("background-color: #2b2d3c;");
//    QPixmap logopixmap(":/resources/img/locationon.PNG");
//    this->ui->location_img->setPixmap(logopixmap);
    ui->location_img->setStyleSheet("QLabel { image: url(:/resources/img/locationon.PNG); }");
    ui->location_txt->setStyleSheet("QLabel { color:#535454;padding:5px;}");

}

void LocationItemView::disselected()
{

    this->ui->frame->setStyleSheet("background-color: #262836;");

//    QPixmap logopixmap(":/resources/img/locationoff.PNG");
//    this->ui->location_img->setPixmap(logopixmap);
    ui->location_img->setStyleSheet("QLabel { image: url(:/resources/img/locationoff.PNG); }");
    ui->location_txt->setStyleSheet("QLabel { color:#31333d;padding:5px;}");
}

void LocationItemView::change_server(int seq)
{
    this->index=seq;
    QString name=AuthManager::instance()->mServers[seq].name;
    QString flag_name=name.mid(0,2);
    qDebug()<<flag_name;
    QString country=AuthManager::instance()->mServers[seq].country;
    QString state=AuthManager::instance()->mServers[seq].state;
    QString text=country+"("+state+")";
    ui->location_txt->setText(text);
}
