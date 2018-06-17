#ifndef SUBSETTINGS_H
#define SUBSETTINGS_H


#include <memory>
#include <QWidget>

namespace Ui {
class SubSettings;
}

class SubSettings : public QWidget
{
    Q_OBJECT

public:
    explicit SubSettings(QWidget *parent = 0);
    static SubSettings * instance();
    ~SubSettings();
signals:
    void closeevent();

private slots:
    void on_save_clicked();

    void on_cancel_clicked();


private:
    Ui::SubSettings *ui;
    static std::auto_ptr<SubSettings> mInstance;
    void close_signal();
};

#endif // SUBSETTINGS_H
