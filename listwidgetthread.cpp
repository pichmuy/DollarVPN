#include "listwidgetthread.h"

#include <QListWidget>
#include "authmanager.h"
#include "server.h"
#include "mainwindow.h"


ListWidgetThread::ListWidgetThread(QObject *parent,QListWidget *widget):
    QThread(parent)
{
    m_widget = widget;
}

void ListWidgetThread::init()
{
    m_widget->clear();
    for(int i=0;i<AuthManager::instance()->mServers.count();i++ )
    {
      Server *server=new Server;
      server->change_server(i);
      qDebug()<<"Before SGINAL";
      connect(server,SIGNAL(errorMsg(QString)),MainWindow::instance(),SLOT(errorNotification(QString)));
      connect(server,SIGNAL(setPopupText(QString,QString)),MainWindow::instance(),SLOT(popupNotification(QString,QString)));

      QListWidgetItem *listWidgetItem=new QListWidgetItem(m_widget);
      m_widget->addItem(listWidgetItem);
      listWidgetItem->setSizeHint(QSize(780,60));
      m_widget->setItemWidget(listWidgetItem,server);
    }
}
