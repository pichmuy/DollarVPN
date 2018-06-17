#include "loading.h"
#include <QDebug>
Loading::Loading(QObject *parent,QPushButton *signin):
    QThread(parent)
{
    m_signin = signin;

}

void Loading::run()
{
     loading=new QMovie(":/resources/img/loading.gif");
     connect(loading,SIGNAL(finished()),loading,SLOT(start()));
     connect(loading,SIGNAL(frameChanged(int)),this,SLOT(setIcon()));
     loading->start();
}

void Loading::setIcon()
{
    m_signin->setIcon(QIcon(loading->currentPixmap()));
}

void Loading::stop()
{
    qDebug()<<"hmmm";
    loading->stop();
    qDebug()<<"haha";
    disconnect(loading,SIGNAL(finished()),loading,SLOT(start()));
    disconnect(loading,SIGNAL(frameChanged(int)),this,SLOT(setIcon()));
    this->terminate();
}
