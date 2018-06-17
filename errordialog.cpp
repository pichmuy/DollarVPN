#include "errordialog.h"
#include "ui_errordialog.h"

#include <QTextCursor>

std::auto_ptr<ErrorDialog> ErrorDialog::mInstance;

ErrorDialog::ErrorDialog(const QString & msg, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorDialog)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->setupUi(this);
    setWindowTitle("Alert!");
    ui->error_txt->setText(msg);
    QTextCursor cursor = ui->error_txt->textCursor();
    QTextBlockFormat textBlockFormat = cursor.blockFormat();
    textBlockFormat.setAlignment(Qt::AlignCenter);//or another alignment
    cursor.mergeBlockFormat(textBlockFormat);
    ui->error_txt->setTextCursor(cursor);
}

ErrorDialog::~ErrorDialog()
{
    delete ui;
}

void ErrorDialog::on_Ok_button_2_clicked()
{
    hide();
}
