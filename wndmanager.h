#ifndef WNDMANAGER_H
#define WNDMANAGER_H



#include <memory>
#include <QObject>
#include <QWidget>

#include <QPointer>

class WndManager : public QObject
{
    Q_OBJECT
public:
    static void Cleanup()
    {
        if (mInstance.get() != NULL) delete mInstance.release();
    }
    QWidget * currentWidget;
    explicit WndManager(QObject *parent = 0);
    static WndManager * instance();
    QWidget * ScrVisible();	 // NULL if no visible
    void ToConn();
    void ToPort();
    void ToDash();
    QWidget * ScrVisibleDialog();
    void trans(const QPoint & p, QWidget * to);
    void CloseAll();
    void ToFront(QWidget * w);
    void ErrMsg(const QString & msg);
    void ToPrimary();
    void HideThis(QWidget * scr);
    void SavePos();
    QPoint CurrPos();

    void ToFront();


signals:

public slots:

private:

    static std::auto_ptr<WndManager> mInstance;
    void trans(QWidget * from, QWidget * to);
    void SaveAndHide(QWidget * from);
    void SaveCoords(QWidget * from);
    int _x;
    int _y;
    void DoTrans(QWidget * to);
    void ApplyCoords(QWidget * to);

};

#endif // WNDMANAGER_H
