/********************************************************************************
** Form generated from reading UI file 'portforpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTFORPAGE_H
#define UI_PORTFORPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PortforPage
{
public:
    QFrame *frame_2;
    QLabel *connlabel;
    QLabel *portlabel;
    QLabel *dashlabel;
    QPushButton *pushButton_2;
    QPushButton *ToPort;
    QPushButton *pushButton_4;
    QLabel *Logolabel;
    QFrame *frame_3;
    QPushButton *logout;
    QLabel *welclabel;
    QLabel *distop;
    QLabel *connected_label;
    QFrame *frame;
    QLineEdit *e_Ports;
    QPushButton *portforward;
    QLabel *status;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget_2;
    QPushButton *location;
    QLabel *label_7;

    void setupUi(QWidget *PortforPage)
    {
        if (PortforPage->objectName().isEmpty())
            PortforPage->setObjectName(QStringLiteral("PortforPage"));
        PortforPage->resize(1100, 700);
        frame_2 = new QFrame(PortforPage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 211, 701));
        frame_2->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#1c1d25;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        connlabel = new QLabel(frame_2);
        connlabel->setObjectName(QStringLiteral("connlabel"));
        connlabel->setGeometry(QRect(11, 214, 41, 29));
        connlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/conn1.PNG);\n"
"}"));
        portlabel = new QLabel(frame_2);
        portlabel->setObjectName(QStringLiteral("portlabel"));
        portlabel->setGeometry(QRect(10, 269, 41, 29));
        portlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/port2.PNG);\n"
"}"));
        dashlabel = new QLabel(frame_2);
        dashlabel->setObjectName(QStringLiteral("dashlabel"));
        dashlabel->setGeometry(QRect(14, 329, 30, 25));
        dashlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/software3.PNG);\n"
"}"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 200, 211, 57));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:#445163;\n"
"border:0px solid #171920;\n"
"}"));
        ToPort = new QPushButton(frame_2);
        ToPort->setObjectName(QStringLiteral("ToPort"));
        ToPort->setGeometry(QRect(0, 256, 211, 57));
        QFont font1;
        font1.setPointSize(8);
        ToPort->setFont(font1);
        ToPort->setCursor(QCursor(Qt::PointingHandCursor));
        ToPort->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:#ffb400;\n"
"border:0.5px solid #171920;\n"
"}"));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 312, 211, 57));
        pushButton_4->setFont(font1);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:#445163;\n"
"border:0px solid #000000;\n"
"}"));
        Logolabel = new QLabel(frame_2);
        Logolabel->setObjectName(QStringLiteral("Logolabel"));
        Logolabel->setGeometry(QRect(35, 20, 131, 121));
        Logolabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/logo1.png);\n"
"}"));
        frame_3 = new QFrame(PortforPage);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(210, 0, 891, 61));
        frame_3->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#1c1d25;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        logout = new QPushButton(frame_3);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(836, 7, 49, 47));
        logout->setMinimumSize(QSize(0, 0));
        logout->setCursor(QCursor(Qt::PointingHandCursor));
        logout->setMouseTracking(false);
        logout->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#1c1d25;\n"
"border:#1c1d25;\n"
"color:#949193;\n"
"image: url(:/resources/img/logout.PNG);\n"
"}"));
        welclabel = new QLabel(frame_3);
        welclabel->setObjectName(QStringLiteral("welclabel"));
        welclabel->setGeometry(QRect(650, 14, 181, 31));
        QFont font2;
        font2.setPointSize(7);
        welclabel->setFont(font2);
        welclabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"}"));
        distop = new QLabel(frame_3);
        distop->setObjectName(QStringLiteral("distop"));
        distop->setGeometry(QRect(613, 13, 31, 35));
        distop->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/dis_top.PNG);\n"
"}"));
        connected_label = new QLabel(frame_3);
        connected_label->setObjectName(QStringLiteral("connected_label"));
        connected_label->setGeometry(QRect(608, 9, 221, 41));
        connected_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/connected.png);\n"
"}"));
        frame = new QFrame(PortforPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(210, 60, 891, 641));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#242533;\n"
"color:#ffffff;\n"
"}"));
        frame->setInputMethodHints(Qt::ImhNone);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        e_Ports = new QLineEdit(frame);
        e_Ports->setObjectName(QStringLiteral("e_Ports"));
        e_Ports->setGeometry(QRect(360, 60, 181, 41));
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        e_Ports->setFont(font3);
        e_Ports->setStyleSheet(QLatin1String("QLineEdit {\n"
"\n"
"background-color:#18191e;\n"
"border:#18191e;\n"
"color:#979696;\n"
"border-radius:10px;\n"
"padding-left:12px;\n"
"\n"
"}"));
        e_Ports->setEchoMode(QLineEdit::Normal);
        e_Ports->setCursorPosition(0);
        e_Ports->setReadOnly(false);
        portforward = new QPushButton(frame);
        portforward->setObjectName(QStringLiteral("portforward"));
        portforward->setGeometry(QRect(630, 60, 181, 41));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(false);
        font4.setWeight(50);
        portforward->setFont(font4);
        portforward->setCursor(QCursor(Qt::PointingHandCursor));
        portforward->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#ffb400;\n"
"border-radius:10px;\n"
"color:#32353e;\n"
"}"));
        status = new QLabel(frame);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(90, 200, 201, 21));
        status->setFont(font3);
        status->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"background-color:#242533;\n"
"}"));
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 300, 761, 311));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(verticalLayoutWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#2b2d3c;\n"
"border:1px solid #414658;\n"
"}"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(frame_4);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:#2b2d3c;\n"
"border:#414658;\n"
"border-radius:0px;\n"
"}\n"
"\n"
"QScrollBar:vertical {              \n"
"		background-color:#ffa800;\n"
"        width:6px;    \n"
"		border-radius:3px;\n"
"		border-color:#bfbfbf;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"		background:transparent;\n"
"}\n"
"QScrollBar::sub-page:vertical {\n"
"    background: #242533;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"    background:#242533;\n"
"}\n"
"QScrollBar::down-arrow:vertical{    \n"
"height:0px;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"height:0px;\n"
"}"));

        verticalLayout->addWidget(listWidget);


        verticalLayout_2->addWidget(frame_4);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 230, 761, 71));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#2b2d3c;\n"
"border:1px solid #414658;\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(89, 250, 201, 31));
        QFont font5;
        font5.setPointSize(10);
        label_2->setFont(font5);
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#2b2d3c;\n"
"color:#cacace;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(438, 250, 91, 31));
        label_3->setFont(font5);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#2b2d3c;\n"
"color:#cacace;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(640, 250, 91, 31));
        label_4->setFont(font5);
        label_4->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#2b2d3c;\n"
"color:#cacace;\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(621, 121, 201, 51));
        QFont font6;
        font6.setPointSize(11);
        label_5->setFont(font6);
        label_5->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#262836;\n"
"color:#53e207;\n"
"padding: 0 0 30 0px;\n"
"border-radius:10px;\n"
"\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(700, 144, 61, 21));
        QFont font7;
        font7.setPointSize(15);
        label_6->setFont(font7);
        label_6->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"background-color:#262836;\n"
"}"));
        verticalLayoutWidget_2 = new QWidget(frame);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(90, 110, 221, 89));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_5 = new QFrame(verticalLayoutWidget_2);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#262836;\n"
"border:#262836;\n"
"}"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_5);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        listWidget_2 = new QListWidget(frame_5);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:#262836;\n"
"border:#262836;\n"
"}"));

        verticalLayout_4->addWidget(listWidget_2);


        verticalLayout_3->addWidget(frame_5);

        location = new QPushButton(frame);
        location->setObjectName(QStringLiteral("location"));
        location->setGeometry(QRect(80, 60, 221, 41));
        location->setFont(font3);
        location->setLayoutDirection(Qt::LeftToRight);
        location->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color:#18191e;\n"
"border:#18191e;\n"
"color:#979696;\n"
"border-radius:10px;\n"
"text-align:left;\n"
"padding-left:14px;\n"
"}"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 60, 41, 41));
        label_7->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"background-color:#18191e;\n"
"border:#18191e;\n"
"color:#979696;\n"
"border-radius:10px;\n"
"padding-left:10px;\n"
"padding-right:0px;\n"
"image: url(:/resources/img/location_drop.PNG);\n"
"}"));

        retranslateUi(PortforPage);

        QMetaObject::connectSlotsByName(PortforPage);
    } // setupUi

    void retranslateUi(QWidget *PortforPage)
    {
        PortforPage->setWindowTitle(QApplication::translate("PortforPage", "Form", Q_NULLPTR));
        connlabel->setText(QString());
        portlabel->setText(QString());
        dashlabel->setText(QString());
        pushButton_2->setText(QApplication::translate("PortforPage", "             CONNECT TO SERVER", Q_NULLPTR));
        ToPort->setText(QApplication::translate("PortforPage", "PORTFORWARD  ", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("PortforPage", "         SOFTWARE SETTINGS", Q_NULLPTR));
        Logolabel->setText(QString());
        logout->setText(QString());
        welclabel->setText(QApplication::translate("PortforPage", "Connect to a server to stay anonymous", Q_NULLPTR));
        distop->setText(QString());
        connected_label->setText(QString());
        e_Ports->setText(QString());
        e_Ports->setPlaceholderText(QApplication::translate("PortforPage", "Port..", Q_NULLPTR));
        portforward->setText(QApplication::translate("PortforPage", "Port Forward", Q_NULLPTR));
        status->setText(QApplication::translate("PortforPage", "Ports opened currently", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("PortforPage", "Location", Q_NULLPTR));
        label_3->setText(QApplication::translate("PortforPage", "Port", Q_NULLPTR));
        label_4->setText(QApplication::translate("PortforPage", "Internal IP", Q_NULLPTR));
        label_5->setText(QApplication::translate("PortforPage", "Portforwarded", Q_NULLPTR));
        label_6->setText(QApplication::translate("PortforPage", "4392", Q_NULLPTR));
        location->setText(QApplication::translate("PortforPage", "Location", Q_NULLPTR));
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PortforPage: public Ui_PortforPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTFORPAGE_H
