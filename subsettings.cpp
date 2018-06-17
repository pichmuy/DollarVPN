#include "subsettings.h"
#include "ui_subsettings.h"
#include <stdexcept>
#include "setting.h"
#include "settingpage.h"
#include <QDebug>
#include <QFontDatabase>
#include <QFont>
std::auto_ptr<SubSettings> SubSettings::mInstance;
SubSettings * SubSettings::instance()
{
    if (!mInstance.get())
        mInstance.reset(new SubSettings());
    return mInstance.get();
}
SubSettings::SubSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubSettings)
{
    ui->setupUi(this);
    QFontDatabase fontDB;
    fontDB.addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont sans(family);
    sans.setPointSize(8);
    ui->label->setFont(sans);
    ui->label_2->setFont(sans);
    ui->label_3->setFont(sans);
    ui->label_4->setFont(sans);
    ui->label_5->setFont(sans);
    ui->label_6->setFont(sans);
    ui->autoConnectCheckBox->setChecked(Setting::instance()->autoconnect());
    ui->killSwitchCheckBox->setChecked(Setting::instance()->blockOnDisconnect());
    ui->reconnectCheckBox->setChecked(Setting::instance()->reconnect());
    ui->startupCheckBox->setChecked(Setting::instance()->startup());
    ui->insecureWifiCheckBox->setChecked(Setting::instance()->detectInsecureWifi());
}

SubSettings::~SubSettings()
{
    delete ui;
}

void SubSettings::on_save_clicked()
{
//    bool startupcheckbox=ui->autoConnectCheckBox->isChecked();
//    qDebug()<<startupcheckbox;
//    emit closeevent();
    Setting::instance()->setStartup(ui->startupCheckBox->isChecked());
    Setting::instance()->setAutoconnect(ui->autoConnectCheckBox->isChecked());
    Setting::instance()->setReconnect(ui->reconnectCheckBox->isChecked());
    Setting::instance()->setDetectInsecureWifi(ui->insecureWifiCheckBox->isChecked());
    Setting::instance()->setBlockOnDisconnect(ui->killSwitchCheckBox->isChecked());
    SettingPage::instance()->hide();
}


void SubSettings::on_cancel_clicked()
{
//   emit closeevent();
    ui->autoConnectCheckBox->setChecked(Setting::instance()->autoconnect());
    ui->killSwitchCheckBox->setChecked(Setting::instance()->blockOnDisconnect());
    ui->reconnectCheckBox->setChecked(Setting::instance()->reconnect());
    ui->startupCheckBox->setChecked(Setting::instance()->startup());
    ui->insecureWifiCheckBox->setChecked(Setting::instance()->detectInsecureWifi());
    SettingPage::instance()->hide();
}

