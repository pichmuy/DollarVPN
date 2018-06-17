#ifndef LOCATIONITEMVIEW_H
#define LOCATIONITEMVIEW_H

#include <QWidget>

namespace Ui {
class LocationItemView;
}

class LocationItemView : public QWidget
{
    Q_OBJECT

public:
    explicit LocationItemView(QWidget *parent = 0);
    ~LocationItemView();
    void change_server(int index);

public slots:
    void selected();
    void disselected();

private:
    Ui::LocationItemView *ui;
    int index;
};

#endif // LOCATIONITEMVIEW_H
