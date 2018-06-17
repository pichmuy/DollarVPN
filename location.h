#ifndef LOCATION_H
#define LOCATION_H

#include <memory>
#include <queue>
#include <stdint.h>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class Location;
}

class Location : public QWidget
{
    Q_OBJECT

public:
    explicit Location(QWidget *parent = 0);
    static Location * instance();
    ~Location();
    void change_server(int index);

public slots:
     void selected();
     void disselected();

signals:

     void closed_port();
     void errorMsg(QString msg);

private slots:
     void on_pushButton_clicked();
     void closePort();

private:
    Ui::Location *ui;
    static std::auto_ptr<Location> mInstance;
    int index;
    QNetworkAccessManager *net;
    QNetworkReply *reply;
};

#endif // LOCATION_H
