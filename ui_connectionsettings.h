/********************************************************************************
** Form generated from reading UI file 'connectionsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONSETTINGS_H
#define UI_CONNECTIONSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectionSettings
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QComboBox *portcombo;
    QPushButton *save;
    QPushButton *cancel;
    QComboBox *portcombo_2;

    void setupUi(QWidget *ConnectionSettings)
    {
        if (ConnectionSettings->objectName().isEmpty())
            ConnectionSettings->setObjectName(QStringLiteral("ConnectionSettings"));
        ConnectionSettings->resize(636, 195);
        horizontalLayout_2 = new QHBoxLayout(ConnectionSettings);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(ConnectionSettings);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#1b1d25;\n"
"color:#ffffff;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 111, 16));
        label->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffb400;\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 30, 111, 16));
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ffb400;\n"
"}"));
        portcombo = new QComboBox(frame);
        portcombo->setObjectName(QStringLiteral("portcombo"));
        portcombo->setGeometry(QRect(100, 60, 200, 40));
        QFont font;
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        portcombo->setFont(font);
        portcombo->setAutoFillBackground(false);
        portcombo->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"background-color:#1b1d25;\n"
"border-radius:10px;\n"
"color:#ffffff;\n"
"border:#374150;\n"
"border:0.8px solid #374150;\n"
"padding-left:20px;\n"
"\n"
"}\n"
"QComboBox::drop-down {border-width: 0px;}\n"
"QComboBox::down-arrow \n"
"{image: url(:/resources/img/combo3.PNG);\n"
" padding-right:20px;\n"
"}"));
        portcombo->setEditable(false);
        portcombo->setInsertPolicy(QComboBox::InsertAtBottom);
        portcombo->setIconSize(QSize(16, 16));
        portcombo->setDuplicatesEnabled(false);
        save = new QPushButton(frame);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(330, 145, 101, 35));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        save->setFont(font1);
        save->setCursor(QCursor(Qt::PointingHandCursor));
        save->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#1b1d25;\n"
"border-radius:17px;\n"
"border-style:solid;\n"
"color:#c4c5c9;\n"
"border:1px solid #ffb400;\n"
"padding-left:5px;\n"
"padding-right:5px;\n"
"\n"
"}"));
        cancel = new QPushButton(frame);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(190, 145, 101, 35));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        cancel->setFont(font2);
        cancel->setCursor(QCursor(Qt::PointingHandCursor));
        cancel->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"background-color:#1b1d25;\n"
"border-radius:17px;\n"
"border-style:solid;\n"
"color:#c4c5c9;\n"
"border:1px solid #374150;\n"
"padding-left:5px;\n"
"padding-right:5px;\n"
"\n"
"}"));
        portcombo_2 = new QComboBox(frame);
        portcombo_2->setObjectName(QStringLiteral("portcombo_2"));
        portcombo_2->setGeometry(QRect(360, 60, 200, 40));
        portcombo_2->setFont(font);
        portcombo_2->setAutoFillBackground(false);
        portcombo_2->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"background-color:#1b1d25;\n"
"border-radius:10px;\n"
"color:#ffffff;\n"
"border:#374150;\n"
"border:0.8px solid #374150;\n"
"padding-left:20px;\n"
"\n"
"}\n"
"QComboBox::drop-down {border-width: 0px;}\n"
"QComboBox::down-arrow \n"
"{image: url(:/resources/img/combo3.PNG);\n"
" padding-right:20px;\n"
"}"));
        portcombo_2->setEditable(false);
        portcombo_2->setInsertPolicy(QComboBox::InsertAtBottom);
        portcombo_2->setIconSize(QSize(16, 16));
        portcombo_2->setDuplicatesEnabled(false);

        horizontalLayout->addWidget(frame);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ConnectionSettings);

        QMetaObject::connectSlotsByName(ConnectionSettings);
    } // setupUi

    void retranslateUi(QWidget *ConnectionSettings)
    {
        ConnectionSettings->setWindowTitle(QApplication::translate("ConnectionSettings", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("ConnectionSettings", "Connection Protocol", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConnectionSettings", "Encryption Protocol", Q_NULLPTR));
        portcombo->clear();
        portcombo->insertItems(0, QStringList()
         << QApplication::translate("ConnectionSettings", "TCP", Q_NULLPTR)
         << QApplication::translate("ConnectionSettings", "UDP", Q_NULLPTR)
        );
        portcombo->setCurrentText(QApplication::translate("ConnectionSettings", "TCP", Q_NULLPTR));
        save->setText(QApplication::translate("ConnectionSettings", "Save", Q_NULLPTR));
        cancel->setText(QApplication::translate("ConnectionSettings", "Cancel", Q_NULLPTR));
        portcombo_2->clear();
        portcombo_2->insertItems(0, QStringList()
         << QApplication::translate("ConnectionSettings", "Advanced Encryption Protocol", Q_NULLPTR)
        );
        portcombo_2->setCurrentText(QApplication::translate("ConnectionSettings", "Advanced Encryption Protocol", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConnectionSettings: public Ui_ConnectionSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONSETTINGS_H
