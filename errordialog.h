#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>
#include <memory>
#include <queue>
#include <stdint.h>
namespace Ui {
class ErrorDialog;
}

class ErrorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ErrorDialog(const QString & msg,QWidget *parent = 0);
    static ErrorDialog * instance();
    ~ErrorDialog();

private slots:
    void on_Ok_button_2_clicked();

private:
    Ui::ErrorDialog *ui;
    static std::auto_ptr<ErrorDialog> mInstance;
};

#endif // ERRORDIALOG_H
