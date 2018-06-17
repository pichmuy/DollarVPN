/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *logolabel;
    QLineEdit *eLogin;
    QLabel *label_4;
    QPushButton *rememberMeButton;
    QPushButton *signin;
    QPushButton *upgrade;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1100, 700);
        MainWindow->setStyleSheet(QStringLiteral(""));
        stackedWidget = new QStackedWidget(MainWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1101, 701));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        logolabel = new QLabel(page);
        logolabel->setObjectName(QStringLiteral("logolabel"));
        logolabel->setGeometry(QRect(450, 60, 141, 171));
        logolabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/logo.png);\n"
"}"));
        eLogin = new QLineEdit(page);
        eLogin->setObjectName(QStringLiteral("eLogin"));
        eLogin->setGeometry(QRect(400, 300, 251, 43));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        eLogin->setFont(font);
        eLogin->setStyleSheet(QLatin1String("QLineEdit {\n"
"\n"
"background-color:#ffffff;\n"
"border:#18191e;\n"
"color:#000000;\n"
"padding-left:25px;\n"
"border-radius:10px;\n"
"\n"
"}"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 363, 141, 41));
        QFont font1;
        font1.setPointSize(10);
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#f9ce3b;\n"
"}"));
        rememberMeButton = new QPushButton(page);
        rememberMeButton->setObjectName(QStringLiteral("rememberMeButton"));
        rememberMeButton->setGeometry(QRect(610, 358, 51, 51));
        rememberMeButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#191a1f;\n"
"\n"
"border-image: url(:/resources/img/uncheck.png);\n"
"border:0px;\n"
"\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"\n"
"border-image: url(:/resources/img/check (3).png);\n"
"}"));
        rememberMeButton->setCheckable(true);
        rememberMeButton->setChecked(false);
        signin = new QPushButton(page);
        signin->setObjectName(QStringLiteral("signin"));
        signin->setGeometry(QRect(444, 442, 141, 41));
        QFont font2;
        font2.setFamily(QStringLiteral("Yu Gothic UI"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        signin->setFont(font2);
        signin->setCursor(QCursor(Qt::PointingHandCursor));
        signin->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#f8cd3b;\n"
"border-radius:20px;\n"
"color:#32353e;\n"
"padding-bottom:5px;\n"
"}\n"
"\n"
""));
        upgrade = new QPushButton(page);
        upgrade->setObjectName(QStringLiteral("upgrade"));
        upgrade->setGeometry(QRect(590, 531, 131, 37));
        QFont font3;
        font3.setPointSize(9);
        font3.setStrikeOut(false);
        upgrade->setFont(font3);
        upgrade->setCursor(QCursor(Qt::PointingHandCursor));
        upgrade->setLayoutDirection(Qt::RightToLeft);
        upgrade->setAutoFillBackground(false);
        upgrade->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#191a1f;\n"
"border-radius:12px;\n"
"border-style:solid;\n"
"color:#c4c5c9;\n"
"border:1px solid #ffb400;\n"
"padding-left:5px;\n"
"padding-right:5px;\n"
"\n"
"}"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(350, 530, 211, 37));
        QFont font4;
        font4.setPointSize(7);
        label_3->setFont(font4);
        label_3->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffffff;\n"
"}"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(554, 451, 27, 20));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/signarrow.PNG);\n"
"}"));
        stackedWidget->addWidget(page);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        logolabel->setText(QString());
        eLogin->setText(QString());
        eLogin->setPlaceholderText(QApplication::translate("MainWindow", "Account ID...", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Remember Account ID", Q_NULLPTR));
        rememberMeButton->setText(QString());
        signin->setText(QApplication::translate("MainWindow", "LOGIN", Q_NULLPTR));
        upgrade->setText(QApplication::translate("MainWindow", "CREATE ACCOUNT", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "I  LOST  MY  ACCOUNT  NUMBER", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
