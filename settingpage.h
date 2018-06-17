#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include "connectionsettings.h"
#include "subsettings.h"

#include <memory>
#include <QWidget>

namespace Ui {
class SettingPage;
}

class SettingPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingPage(QWidget *parent = 0);
    static SettingPage * instance();
    ~SettingPage();
    static bool IsExists()
    {
        return (mInstance.get() != NULL);
    }


public slots:
    void closeevent();
private slots:
    void on_connection_clicked();

    void on_setting_clicked();

    void on_xButton_clicked();

private:
    Ui::SettingPage *ui;
    static std::auto_ptr<SettingPage> mInstance;
    ConnectionSettings *connectionwdg;
    SubSettings *settingswdg;
    void on_settings();
};

#endif // SETTINGPAGE_H
