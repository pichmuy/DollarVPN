#include "connectionsettings.h"
#include "setting.h"
#include "settingpage.h"
#include "ui_connectionsettings.h"



std::auto_ptr<ConnectionSettings> ConnectionSettings::mInstance;
ConnectionSettings * ConnectionSettings::instance()
{
    if (!mInstance.get())
        mInstance.reset(new ConnectionSettings());
    return mInstance.get();
}
ConnectionSettings::ConnectionSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionSettings)
{
    ui->setupUi(this);
    if(Setting::instance()->getProtocol()=="tcp") ui->portcombo->setCurrentIndex(0);
    else ui->portcombo->setCurrentIndex(1);
}

ConnectionSettings::~ConnectionSettings()
{
    delete ui;
}

void ConnectionSettings::on_save_clicked()
{
//    emit closeevent();
    SettingPage::instance()->hide();
}

void ConnectionSettings::on_cancel_clicked()
{
//    emit closeevent();
    SettingPage::instance()->hide();
}

void ConnectionSettings::on_portcombo_currentIndexChanged(int index)
{
    if(index==0){
        Setting::instance()->setProtocol("tcp");
    }
    else Setting::instance()->setProtocol("udp");

}
