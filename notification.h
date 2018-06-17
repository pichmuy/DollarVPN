#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>
#include <QTimer>
#include <stdint.h>
#include <memory>
#include <queue>
class Notification : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

    void setPopupOpacity(float opacity);
    float getPopupOpacity() const;
public:
    explicit Notification(QWidget *parent = nullptr);
    static Notification * instance();
    void errorMsg(QString msg);
signals:

protected:
    void paintEvent(QPaintEvent *event);    // The background will be drawn through the redraw method

public slots:
    void setPopupText(const QString& title,const QString& text); // Setting text notification
    void show();
private slots:
    void hideAnimation();                   // Slot start the animation hide
    void hide();
private:
    QLabel topic;
    QLabel label;
    QGridLayout layout;
    QPropertyAnimation animation;
    float popupOpacity;
    QTimer *timer;
    static std::auto_ptr<Notification> mInstance;
};

#endif // NOTIFICATION_H
