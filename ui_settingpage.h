/********************************************************************************
** Form generated from reading UI file 'settingpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGPAGE_H
#define UI_SETTINGPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingPage
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QPushButton *setting;
    QPushButton *connection;
    QPushButton *xButton;
    QPushButton *que_button;
    QLabel *label;

    void setupUi(QWidget *SettingPage)
    {
        if (SettingPage->objectName().isEmpty())
            SettingPage->setObjectName(QStringLiteral("SettingPage"));
        SettingPage->resize(645, 387);
        frame = new QFrame(SettingPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 190, 661, 201));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(frame);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"border:#1b1d25;\n"
"}"));

        horizontalLayout->addWidget(listWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        setting = new QPushButton(SettingPage);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setGeometry(QRect(210, 70, 91, 91));
        setting->setCursor(QCursor(Qt::PointingHandCursor));
        setting->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"\n"
"}"));
        connection = new QPushButton(SettingPage);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(350, 70, 91, 91));
        connection->setCursor(QCursor(Qt::PointingHandCursor));
        connection->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"\n"
"}"));
        xButton = new QPushButton(SettingPage);
        xButton->setObjectName(QStringLiteral("xButton"));
        xButton->setGeometry(QRect(623, 0, 21, 21));
        xButton->setCursor(QCursor(Qt::PointingHandCursor));
        xButton->setAutoFillBackground(false);
        xButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"image: url(:/resources/img/x.PNG);\n"
"}"));
        xButton->setIconSize(QSize(21, 21));
        que_button = new QPushButton(SettingPage);
        que_button->setObjectName(QStringLiteral("que_button"));
        que_button->setGeometry(QRect(600, 0, 21, 21));
        que_button->setCursor(QCursor(Qt::PointingHandCursor));
        que_button->setIconSize(QSize(21, 21));
        label = new QLabel(SettingPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(4, 5, 150, 22));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/software.PNG);\n"
"}"));

        retranslateUi(SettingPage);

        QMetaObject::connectSlotsByName(SettingPage);
    } // setupUi

    void retranslateUi(QWidget *SettingPage)
    {
        SettingPage->setWindowTitle(QApplication::translate("SettingPage", "Form", Q_NULLPTR));
        setting->setText(QString());
        connection->setText(QString());
        xButton->setText(QString());
        que_button->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SettingPage: public Ui_SettingPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGPAGE_H
