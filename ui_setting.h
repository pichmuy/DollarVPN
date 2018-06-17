/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QPushButton *setting;
    QPushButton *connection;
    QPushButton *pushButton;

    void setupUi(QWidget *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(645, 387);
        frame = new QFrame(Setting);
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

        setting = new QPushButton(Setting);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setGeometry(QRect(210, 70, 91, 91));
        setting->setCursor(QCursor(Qt::PointingHandCursor));
        setting->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"\n"
"}"));
        connection = new QPushButton(Setting);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(350, 70, 91, 91));
        connection->setCursor(QCursor(Qt::PointingHandCursor));
        connection->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"\n"
"}"));
        pushButton = new QPushButton(Setting);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(613, 0, 31, 21));

        retranslateUi(Setting);

        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QWidget *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Form", Q_NULLPTR));
        setting->setText(QString());
        connection->setText(QString());
        pushButton->setText(QApplication::translate("Setting", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
