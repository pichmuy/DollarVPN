/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QLabel *status;
    QLabel *country;
    QLabel *state;
    QPushButton *disconn;
    QProgressBar *progressBar;
    QLabel *label_2;
    QLabel *label;
    QLabel *flagid;
    QLabel *offline;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(902, 62);
        Server->setMinimumSize(QSize(0, 62));
        Server->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:#2b2d3c;\n"
"}"));
        verticalLayout = new QVBoxLayout(Server);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(Server);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#262836;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        status = new QLabel(frame);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(7, -5, 8, 101));
        status->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#ffb400;\n"
"}"));
        country = new QLabel(frame);
        country->setObjectName(QStringLiteral("country"));
        country->setGeometry(QRect(70, 13, 91, 16));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        country->setFont(font);
        country->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"background-color:#262836;\n"
"}"));
        country->setTextFormat(Qt::AutoText);
        state = new QLabel(frame);
        state->setObjectName(QStringLiteral("state"));
        state->setGeometry(QRect(70, 28, 81, 16));
        QFont font1;
        font1.setPointSize(8);
        state->setFont(font1);
        state->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#616474;\n"
"background-color:#262836;\n"
"}"));
        disconn = new QPushButton(frame);
        disconn->setObjectName(QStringLiteral("disconn"));
        disconn->setGeometry(QRect(764, 11, 115, 35));
        disconn->setMinimumSize(QSize(90, 35));
        QFont font2;
        font2.setPointSize(9);
        font2.setStrikeOut(false);
        disconn->setFont(font2);
        disconn->setCursor(QCursor(Qt::PointingHandCursor));
        disconn->setLayoutDirection(Qt::RightToLeft);
        disconn->setAutoFillBackground(false);
        disconn->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#262836;\n"
"border-radius:17px;\n"
"border-style:solid;\n"
"color:#c4c5c9;\n"
"border:1.5px solid #ffb400;\n"
"padding-left:5px;\n"
"padding-right:15px;\n"
"padding-bottom:3px;\n"
"}"));
        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(492, 17, 211, 21));
        progressBar->setMaximumSize(QSize(16777215, 21));
        progressBar->setFont(font);
        progressBar->setLayoutDirection(Qt::LeftToRight);
        progressBar->setStyleSheet(QLatin1String("QProgressBar\n"
"{\n"
"\n"
"border: 7px solid #262836;\n"
"border-radius:10px;\n"
"background-color:#4e5160;\n"
"text-align:left;\n"
"margin-left: 12ex;\n"
"color:#ffffff;\n"
"\n"
"}\n"
"QProgressBar::chunk:horizontal {\n"
"background: #ffb400;\n"
"border-radius:3px;\n"
"}"));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(342, 20, 91, 16));
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"background-color:#262836;\n"
"}"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(209, 20, 61, 16));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"background-color:#262836;\n"
"}"));
        flagid = new QLabel(frame);
        flagid->setObjectName(QStringLiteral("flagid"));
        flagid->setGeometry(QRect(38, 17, 25, 25));
        flagid->setMinimumSize(QSize(25, 25));
        flagid->setMaximumSize(QSize(25, 25));
        flagid->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"background-color:#262836;\n"
"}"));
        offline = new QLabel(frame);
        offline->setObjectName(QStringLiteral("offline"));
        offline->setGeometry(QRect(851, 19, 15, 20));
        offline->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/offline.PNG);\n"
"}"));

        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Form", Q_NULLPTR));
        status->setText(QString());
        country->setText(QApplication::translate("Server", "Netherlands", Q_NULLPTR));
        state->setText(QApplication::translate("Server", "Amsterdam", Q_NULLPTR));
        disconn->setText(QApplication::translate("Server", "Connect     ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Server", "XOR & TOR", Q_NULLPTR));
        label->setText(QApplication::translate("Server", "NL(1)", Q_NULLPTR));
        flagid->setText(QString());
        offline->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
