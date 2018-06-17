#include "settingpage.h"
#include "ui_settingpage.h"

#include "connectionsettings.h"
#include "subsettings.h"

#include <QPixmap>
#include <QPalette>
#include <QListWidgetItem>
#include <QDebug>
#include <QSettings>

std::auto_ptr<SettingPage> SettingPage::mInstance;
SettingPage * SettingPage::instance()
{
    if (!mInstance.get())
        mInstance.reset(new SettingPage());
    return mInstance.get();
}
SettingPage::SettingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPage)
{

    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint,true);
    setFixedSize(this->size());
    setWindowTitle("Settings");
    QPixmap upgradepixmap(":/resources/img/x.PNG");
    QIcon buttonicon(upgradepixmap);
    this->ui->xButton->setIcon(buttonicon);
    QPixmap pixmap(":/resources/img/ques.PNG");
    QIcon icon(pixmap);
    this->ui->que_button->setIcon(icon);
    QPixmap bkgnd(":/resources/img/connection.png");
    bkgnd=bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget);

    ui->listWidget->addItem(listWidgetItem);
    settingswdg=new SubSettings;
    connectionwdg=new ConnectionSettings;
    listWidgetItem->setSizeHint(QSize(600,250));
    ui->listWidget->setItemWidget(listWidgetItem, settingswdg);
    connect(settingswdg,SIGNAL(closeevent()),this,SLOT(closeevent()));
    connect(connectionwdg,SIGNAL(closeevent()),this,SLOT(closeevent()));


}

SettingPage::~SettingPage()
{
    delete ui;

}

void SettingPage::closeevent()
{

    SettingPage::instance()->hide();
}

void SettingPage::on_connection_clicked()
{

    QPixmap bkgnd(":/resources/img/settings.png");
    bkgnd=bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget);
    ui->listWidget->takeItem(0);
    ui->listWidget->addItem(listWidgetItem);
    connectionwdg=new ConnectionSettings;
    listWidgetItem->setSizeHint(QSize(600,250));
    ui->listWidget->setItemWidget(listWidgetItem, connectionwdg);
}

void SettingPage::on_setting_clicked()
{
    QPixmap bkgnd(":/resources/img/connection.png");
    bkgnd=bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    QListWidgetItem *listWidgetItem=new QListWidgetItem(ui->listWidget);
    ui->listWidget->takeItem(0);
    ui->listWidget->addItem(listWidgetItem);
    settingswdg=new SubSettings;
    listWidgetItem->setSizeHint(QSize(630,250));
    ui->listWidget->setItemWidget(listWidgetItem, settingswdg);
}

void SettingPage::on_xButton_clicked()
{
    hide();
}



