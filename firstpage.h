#ifndef FIRSTPAGE_H
#define FIRSTPAGE_H

#include <QDialog>

namespace Ui {
class FirstPage;
}

class FirstPage : public QDialog
{
    Q_OBJECT

public:
    explicit FirstPage(QWidget *parent = 0);
    ~FirstPage();

private:
    Ui::FirstPage *ui;
};

#endif // FIRSTPAGE_H
