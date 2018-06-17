#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <stdint.h>
#include <memory>
#include <queue>
#include <QMovie>
#include <QWidget>
#include <loading.h>
#include "connectpage.h"
#include "portforpage.h"
#include "notification.h"
#include <QGraphicsDropShadowEffect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static MainWindow * instance();
    static bool IsExists()
    {
        return (mInstance.get() != NULL);
    }
    static void Cleanup();
    void loginuser(const QString & name, const QString & password);
    void StatusConnecting();
    void StatusConnected();
    void StatusDisconnected();
    void saveCredentials();
    void startWifiWatcher();
    void stopWifiWatcher();
    void BlockOnDisconnect();
    void quitApplication();
    bool mQuitConfirmed;
    ConnectPage *connect_page;
    PortforPage *port_page;


public slots:

    void loginError(QString message);

    void loggedIn();

//	void Finished_EccxorName();

    // connect or login Src depending on auth status
    void ToScr_Primary();

    void logout();
    void moveToPort();
    void moveToConn();
    void popupNotification(QString title,QString msg);
    void errorNotification(QString msg);

signals:

private slots:
    void on_signin_clicked();
    void setButtonIcon(int frame);

    void on_upgrade_clicked();
    void Timer_Constructed();
    void checkWifi();

    void detectInsecureWifiChanged();

    void on_rememberMeButton_clicked();

protected:
    virtual void closeEvent(QCloseEvent * event);

private:
    Ui::MainWindow *ui;
    static std::auto_ptr<MainWindow> mInstance;
    bool _CancelLogin;
    QMovie *loading;
    Loading *loadimage;
    bool _ConnectAfterLogin;
    void enableButtons(bool enabled);
    QGraphicsDropShadowEffect* effect;
    unsigned int _activatedcount;
    std::auto_ptr<QTimer> _timer_icon;
    void DisconnectIconWatcher();

    std::auto_ptr<QTimer> _timer_wifi;
    bool _wifi_processing;
    Notification *notification;


};

#endif // MAINWINDOW_H
