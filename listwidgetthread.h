#ifndef LISTWIDGETTHREAD_H
#define LISTWIDGETTHREAD_H

#include <QThread>
#include <QListWidget>
#include <QObject>
class ListWidgetThread:public QThread
{
     Q_OBJECT
public:
    explicit ListWidgetThread(QObject *parent, QListWidget *widget);
    void init();
    ListWidgetThread();
private:
    QListWidget *m_widget;
};

#endif // LISTWIDGETTHREAD_H
