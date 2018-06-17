#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H


#include <memory>
#include <QWidget>

namespace Ui {
class ConnectionSettings;
}

class ConnectionSettings : public QWidget
{
    Q_OBJECT

public:
    explicit ConnectionSettings(QWidget *parent = 0);
    static ConnectionSettings * instance();
    ~ConnectionSettings();

signals:
    void closeevent();
private slots:
    void on_save_clicked();

    void on_cancel_clicked();

    void on_portcombo_currentIndexChanged(int index);

private:
    Ui::ConnectionSettings *ui;
    static std::auto_ptr<ConnectionSettings> mInstance;
};

#endif // CONNECTIONSETTINGS_H
