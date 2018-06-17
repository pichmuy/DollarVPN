#ifndef CONNECTPAGE_H
#define CONNECTPAGE_H

#include <QWidget>

#include <memory>
#include "server.h"


#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include <QDebug>


namespace Ui {
class ConnectPage;
}

class ConnectPage : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectPage(QWidget *parent = 0);
    static ConnectPage * instance();
    ~ConnectPage();
    QVector <Server*> itemVec;
    static std::auto_ptr<ConnectPage> mInstance;
    static bool IsExists()
    {
        return (mInstance.get() != NULL);
    }
    void on_background();
    void off_background();


public slots:

    void updateserver();

signals:

    void move_Port();

private slots:

    void on_ToPort_clicked();
    void on_pushButton_4_clicked();
    void on_logout_clicked();
    void on_country_sort_clicked();
    void StatusConnected();
    void StatusDisconnected();
    void StatusConnecting();
    void init();

protected:
    virtual void closeEvent(QCloseEvent * event);

private:
    Ui::ConnectPage *ui;

};

#endif // FIRSTPAGE_H
