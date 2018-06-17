#ifndef SERVER_H
#define SERVER_H


#include <memory>
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QTimer>

namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:

    explicit Server(QWidget *parent = 0);
    ~Server();
    static Server * instance();
    void change_server(int index);
    void on_background();

public slots:

    void StatusConnecting();
    void StatusConnected();
    void StatusDisconnected();

signals:

    void updatelist();
    void errorMsg(QString msg);
    void setPopupText(QString title,QString msg);

private slots:

    void on_disconn_clicked();
    void Shadow();

private:

    Ui::Server *ui;
    static std::auto_ptr<Server> mInstance;
    int index;
    void Create_Conf();
    int randInt(int low, int high);
    QGraphicsDropShadowEffect* effect;
    int blur;
    bool direction;
    QTimer *timer;

};

#endif // SERVER_H
