#ifndef LOADING_H
#define LOADING_H

#include <QMovie>
#include <QThread>
#include <QPushButton>
class Loading : public QThread
{
    Q_OBJECT
public:
    explicit Loading(QObject *parent,QPushButton  *signin);
    QPushButton *m_signin;
    QMovie *loading;
    void run() override;
    void stop();


private slots:
    void setIcon();
};

#endif // LOADING_H
