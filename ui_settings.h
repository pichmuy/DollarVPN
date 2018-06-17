/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QPushButton *connection;
    QPushButton *setting;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(645, 387);
        frame = new QFrame(Settings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-11, 190, 661, 201));
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

        connection = new QPushButton(Settings);
        connection->setObjectName(QStringLiteral("connection"));
        connection->setGeometry(QRect(331, 64, 91, 91));
        connection->setCursor(QCursor(Qt::PointingHandCursor));
        connection->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"\n"
"}"));
        setting = new QPushButton(Settings);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setGeometry(QRect(190, 65, 91, 91));
        setting->setCursor(QCursor(Qt::PointingHandCursor));
        setting->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background:transparent;\n"
"\n"
"}"));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", Q_NULLPTR));
        connection->setText(QString());
        setting->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
