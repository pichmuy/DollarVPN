/********************************************************************************
** Form generated from reading UI file 'connectpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTPAGE_H
#define UI_CONNECTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectPage
{
public:
    QFrame *frame_3;
    QLabel *welclabel;
    QPushButton *logout;
    QLabel *distop;
    QLabel *connected_label;
    QFrame *frame;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QPushButton *country_sort;
    QPushButton *name;
    QPushButton *encryption;
    QPushButton *load;
    QPushButton *all;
    QFrame *frame_2;
    QLabel *Logolabel;
    QLabel *connlabel;
    QLabel *portlabel;
    QLabel *dashlabel;
    QPushButton *pushButton_2;
    QPushButton *ToPort;
    QPushButton *pushButton_4;

    void setupUi(QWidget *ConnectPage)
    {
        if (ConnectPage->objectName().isEmpty())
            ConnectPage->setObjectName(QStringLiteral("ConnectPage"));
        ConnectPage->resize(1100, 700);
        frame_3 = new QFrame(ConnectPage);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(210, 0, 891, 61));
        frame_3->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#1c1d25;\n"
"}"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        welclabel = new QLabel(frame_3);
        welclabel->setObjectName(QStringLiteral("welclabel"));
        welclabel->setGeometry(QRect(650, 14, 181, 31));
        QFont font;
        font.setPointSize(7);
        welclabel->setFont(font);
        welclabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"}"));
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
"}\n"
""));
        distop = new QLabel(frame_3);
        distop->setObjectName(QStringLiteral("distop"));
        distop->setGeometry(QRect(612, 13, 31, 35));
        distop->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/dis_top.PNG);\n"
"}"));
        connected_label = new QLabel(frame_3);
        connected_label->setObjectName(QStringLiteral("connected_label"));
        connected_label->setGeometry(QRect(607, 9, 221, 41));
        connected_label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/connected.png);\n"
"}"));
        frame = new QFrame(ConnectPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(210, 60, 891, 641));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#242533;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-10, 110, 901, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(verticalLayoutWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color:#242533;\n"
"border:#242533;\n"
"}\n"
"QScrollBar:vertical {              \n"
"		background-color:#ffa800;\n"
"        width:8px;    \n"
"		border-bottom-right-radius:4px;\n"
"		border-bottom-left-radius: 4px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"		background:transparent;\n"
"		border-bottom-right-radius: 4px;\n"
"		border-bottom-left-radius: 4px;\n"
"}\n"
"QScrollBar::sub-page:vertical {\n"
"    background: #2b2d3c;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical {\n"
"    background:#2b2d3c;\n"
"}\n"
"QScrollBar::down-arrow:vertical{    \n"
"height:0px;\n"
"}\n"
"QScrollBar::up-arrow:vertical {\n"
"height:0px;\n"
"}\n"
"   \n"
"\n"
""));

        verticalLayout->addWidget(listWidget);

        country_sort = new QPushButton(frame);
        country_sort->setObjectName(QStringLiteral("country_sort"));
        country_sort->setGeometry(QRect(21, 64, 101, 23));
        country_sort->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#242533;\n"
"color:#979696;\n"
"border:#242533;\n"
"}"));
        name = new QPushButton(frame);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(167, 65, 101, 23));
        name->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#242533;\n"
"color:#979696;\n"
"border:#242533;\n"
"}"));
        encryption = new QPushButton(frame);
        encryption->setObjectName(QStringLiteral("encryption"));
        encryption->setGeometry(QRect(312, 65, 101, 23));
        encryption->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#242533;\n"
"color:#979696;\n"
"border:#242533;\n"
"}"));
        load = new QPushButton(frame);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(528, 64, 101, 23));
        load->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#242533;\n"
"color:#979696;\n"
"border:#242533;\n"
"}"));
        all = new QPushButton(frame);
        all->setObjectName(QStringLiteral("all"));
        all->setGeometry(QRect(30, 20, 101, 23));
        QFont font1;
        font1.setPointSize(9);
        all->setFont(font1);
        all->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#242533;\n"
"color:#ffffff;\n"
"border:#242533;\n"
"}"));
        frame_2 = new QFrame(ConnectPage);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 0, 211, 701));
        frame_2->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#1c1d25;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Logolabel = new QLabel(frame_2);
        Logolabel->setObjectName(QStringLiteral("Logolabel"));
        Logolabel->setGeometry(QRect(36, 20, 131, 121));
        Logolabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/logo1.png);\n"
"}"));
        connlabel = new QLabel(frame_2);
        connlabel->setObjectName(QStringLiteral("connlabel"));
        connlabel->setGeometry(QRect(8, 215, 41, 29));
        connlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/conn2.PNG);\n"
"}"));
        portlabel = new QLabel(frame_2);
        portlabel->setObjectName(QStringLiteral("portlabel"));
        portlabel->setGeometry(QRect(9, 270, 41, 29));
        portlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/port1.PNG);\n"
"}"));
        dashlabel = new QLabel(frame_2);
        dashlabel->setObjectName(QStringLiteral("dashlabel"));
        dashlabel->setGeometry(QRect(14, 327, 30, 25));
        dashlabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/software3.PNG);\n"
"}"));
        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(0, 199, 211, 57));
        QFont font2;
        font2.setPointSize(8);
        pushButton_2->setFont(font2);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:#ffb400;\n"
"border:0px solid #000000;\n"
"}\n"
""));
        ToPort = new QPushButton(frame_2);
        ToPort->setObjectName(QStringLiteral("ToPort"));
        ToPort->setGeometry(QRect(1, 256, 211, 57));
        ToPort->setFont(font2);
        ToPort->setCursor(QCursor(Qt::PointingHandCursor));
        ToPort->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:#445163;\n"
"border:0.1em solid #171920;\n"
"}"));
        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(0, 309, 211, 57));
        pushButton_4->setFont(font2);
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"color:#445163;\n"
"border:0px solid #000000;\n"
"}"));

        retranslateUi(ConnectPage);

        QMetaObject::connectSlotsByName(ConnectPage);
    } // setupUi

    void retranslateUi(QWidget *ConnectPage)
    {
        ConnectPage->setWindowTitle(QApplication::translate("ConnectPage", "Form", Q_NULLPTR));
        welclabel->setText(QApplication::translate("ConnectPage", "Connect to a server to stay anonymous", Q_NULLPTR));
        logout->setText(QString());
        distop->setText(QString());
        connected_label->setText(QString());
        country_sort->setText(QApplication::translate("ConnectPage", "Server Country", Q_NULLPTR));
        name->setText(QApplication::translate("ConnectPage", "Server Name", Q_NULLPTR));
        encryption->setText(QApplication::translate("ConnectPage", "Server Encryption", Q_NULLPTR));
        load->setText(QApplication::translate("ConnectPage", "Server Load", Q_NULLPTR));
        all->setText(QApplication::translate("ConnectPage", "All Servers(1)", Q_NULLPTR));
        Logolabel->setText(QString());
        connlabel->setText(QString());
        portlabel->setText(QString());
        dashlabel->setText(QString());
        pushButton_2->setText(QApplication::translate("ConnectPage", "             CONNECT TO SERVER", Q_NULLPTR));
        ToPort->setText(QApplication::translate("ConnectPage", "PORTFORWARD  ", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ConnectPage", "          SOFTWARE SETTINGS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectPage: public Ui_ConnectPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTPAGE_H
