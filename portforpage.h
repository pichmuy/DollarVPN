#ifndef PORTFORPAGE_H
#define PORTFORPAGE_H


#include <location.h>
#include "common.h"
#include "locationitemview.h"
#include <QWidget>
#include <memory>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QList>

namespace Ui {
class PortforPage;
}

class PortforPage : public QWidget
{
    Q_OBJECT

public:
    explicit PortforPage(QWidget *parent = 0);
    static PortforPage * instance();
    ~PortforPage();
    LocationItemView *current_locationitem;
    LocationItemView *selected_locationitem;

    static std::auto_ptr<PortforPage> mInstance;
    static bool IsExists()
    {
        return (mInstance.get() != NULL);
    }
    void Validate_e_Ports();
    QString getinternal_ip();

public slots:
    void refresh_widget();
    void getPort();
    void getPortRequest();

protected:

    virtual void closeEvent(QCloseEvent * event);
    bool eventFilter(QObject *obj, QEvent *event);//in Dialog header

signals:

    void select_ping();
    void disselect_ping();
    void move_Conn();
    void errorMsg(QString);

private slots:

    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_listWidget_clicked(const QModelIndex &index);
    void on_logout_clicked();
    void StatusConnected();
    void StatusDisconnected();
    void openPort();
    void on_portforward_clicked();

    void on_location_clicked();

    void on_listWidget_2_clicked(const QModelIndex &index);

private:
    Ui::PortforPage *ui;
    QNetworkReply *reply;
    QNetworkAccessManager * net;
    QString ports;
    int pastindex;
    QList<Port> oldPorts;
};

#endif // PORTPAGE_H
