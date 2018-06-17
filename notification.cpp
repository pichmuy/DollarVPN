#include "notification.h"

#include <QPainter>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QFontDatabase>

std::auto_ptr<Notification> Notification::mInstance;
Notification * Notification::instance()
{
    if (!mInstance.get())
        mInstance.reset(new Notification());
    return mInstance.get();
}
Notification::Notification(QWidget *parent) : QWidget(parent)
{
        setWindowFlags(Qt::FramelessWindowHint |        // Disable window decoration
                       Qt::Tool |                       // Discard display in a separate window
                       Qt::WindowStaysOnTopHint);       // Set on top of all windows
        setAttribute(Qt::WA_TranslucentBackground);     // Indicates that the background will be transparent
        setAttribute(Qt::WA_ShowWithoutActivating);     // At the show, the widget does not get the focus automatically

        animation.setTargetObject(this);                // Set the target animation
        animation.setPropertyName("popupOpacity");      //
        connect(&animation, &QAbstractAnimation::finished, this, &Notification::hide);

        topic.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        topic.setStyleSheet("QLabel { color : white;"
                             "margin-top: 6px;"
                             "margin-bottom: 6px;"
                             "margin-left: 10px;"
                             "margin-right: 10px; }");
        topic.setMaximumWidth(350);
        topic.setMaximumHeight(50);
        label.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        label.setStyleSheet("QLabel { color : white; "
                            "margin-top: 6px;"
                            "margin-bottom: 6px;"
                            "margin-left: 10px;"
                            "margin-right: 10px; }");
        label.setMaximumWidth(350);
        label.setMaximumHeight(100);
        QFontDatabase fontDB;
        fontDB.addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
        fontDB.addApplicationFont(":/resources/img/fonts/open-sans.semibold.ttf");
        int id = QFontDatabase::addApplicationFont(":/resources/img/fonts/SourceSansPro-Regular.ttf");
        QString family = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont open(family);
        open.setPointSize(10);
        label.setFont(open);
        open.setPointSize(12);
        topic.setFont(open);
        layout.addWidget(&topic, 0, 0);
        layout.addWidget(&label, 1, 0);
        setLayout(&layout);

        timer = new QTimer();
        connect(timer, &QTimer::timeout, this, &Notification::hideAnimation);
}

void Notification::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect roundedRect;
    roundedRect.setX(rect().x() + 5);
    roundedRect.setY(rect().y() + 5);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);

    painter.setBrush(QBrush(QColor(234,62,62,255)));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(roundedRect, 10, 10);
}

void Notification::setPopupText(const QString &title,const QString &text)
{
    topic.setText(title+"\n\n\n");
    label.setText(text);    // Set the text in the Label
    adjustSize();           // With the recalculation notice sizes
}

void Notification::errorMsg(QString msg)
{
    topic.setText("Alert!\n\n\n\n");
    label.setText(msg);
    adjustSize();
}

void Notification::show()
{
    setWindowOpacity(0.0);  // Set the transparency to zero

    animation.setDuration(150);     // Configuring the duration of the animation
    animation.setStartValue(0.0);   // The start value is 0 (fully transparent widget)
    animation.setEndValue(1.0);     // End - completely opaque widget
    setGeometry(parentWidget()->pos().x()+1090-width(),parentWidget()->pos().y()+710-height(),width(),height());

    QWidget::show();

    animation.start();
    timer->start(3000);
}

void Notification::hideAnimation()
{
    timer->stop();
    animation.setDuration(1000);
    animation.setStartValue(1.0);
    animation.setEndValue(0.0);
    animation.start();
}

void Notification::hide()
{
    // If the widget is transparent, then hide it
    if(getPopupOpacity() == 0.0){
        QWidget::hide();
    }
}

void Notification::setPopupOpacity(float opacity)
{
    popupOpacity = opacity;

    setWindowOpacity(opacity);
}

float Notification::getPopupOpacity() const
{
    return popupOpacity;
}
