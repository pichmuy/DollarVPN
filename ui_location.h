/********************************************************************************
** Form generated from reading UI file 'location.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATION_H
#define UI_LOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Location
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QLabel *location_txt;
    QLabel *location_txt_2;
    QLabel *port;
    QLabel *internalIP;
    QPushButton *pushButton;

    void setupUi(QWidget *Location)
    {
        if (Location->objectName().isEmpty())
            Location->setObjectName(QStringLiteral("Location"));
        Location->resize(761, 62);
        Location->setMinimumSize(QSize(240, 30));
        Location->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_3 = new QHBoxLayout(Location);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(Location);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#2b2d3c;\n"
"border-top:0px solid #414658;\n"
"border-bottom:1px solid #414658;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        location_txt = new QLabel(frame);
        location_txt->setObjectName(QStringLiteral("location_txt"));
        location_txt->setGeometry(QRect(35, 9, 231, 21));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        location_txt->setFont(font);
        location_txt->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"border:0px solid #2b2d3c;\n"
"color:#ffffff;\n"
"}"));
        location_txt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        location_txt_2 = new QLabel(frame);
        location_txt_2->setObjectName(QStringLiteral("location_txt_2"));
        location_txt_2->setGeometry(QRect(31, 29, 58, 26));
        QFont font1;
        font1.setPointSize(10);
        location_txt_2->setFont(font1);
        location_txt_2->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"border:0px solid #2b2d3c;\n"
"color:#ffffff;\n"
"image: url(:/resources/img/port_status.PNG);\n"
"}"));
        port = new QLabel(frame);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(370, 18, 91, 21));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        port->setFont(font2);
        port->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"border:0px solid #2b2d3c;\n"
"color:#ffffff;\n"
"}"));
        port->setAlignment(Qt::AlignCenter);
        internalIP = new QLabel(frame);
        internalIP->setObjectName(QStringLiteral("internalIP"));
        internalIP->setGeometry(QRect(570, 18, 91, 21));
        internalIP->setFont(font2);
        internalIP->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"border:0px solid #2b2d3c;\n"
"color:#ffffff;\n"
"}"));
        internalIP->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(730, 9, 20, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"image: url(:/resources/img/port_tag.PNG);\n"
"border:0px solid #2b2d3c;\n"
"}"));

        horizontalLayout->addWidget(frame);


        horizontalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Location);

        QMetaObject::connectSlotsByName(Location);
    } // setupUi

    void retranslateUi(QWidget *Location)
    {
        Location->setWindowTitle(QApplication::translate("Location", "Form", Q_NULLPTR));
        location_txt->setText(QApplication::translate("Location", "Netherlands - Amsterdam         ", Q_NULLPTR));
        location_txt_2->setText(QString());
        port->setText(QApplication::translate("Location", "2938", Q_NULLPTR));
        internalIP->setText(QApplication::translate("Location", "10.8.0.3", Q_NULLPTR));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Location: public Ui_Location {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATION_H
