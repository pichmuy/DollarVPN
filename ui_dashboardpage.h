/********************************************************************************
** Form generated from reading UI file 'dashboardpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARDPAGE_H
#define UI_DASHBOARDPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DashBoardPage
{
public:
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;

    void setupUi(QWidget *DashBoardPage)
    {
        if (DashBoardPage->objectName().isEmpty())
            DashBoardPage->setObjectName(QStringLiteral("DashBoardPage"));
        DashBoardPage->resize(532, 261);
        DashBoardPage->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:#000000;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(DashBoardPage);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        frame = new QFrame(DashBoardPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(frame);


        retranslateUi(DashBoardPage);

        QMetaObject::connectSlotsByName(DashBoardPage);
    } // setupUi

    void retranslateUi(QWidget *DashBoardPage)
    {
        DashBoardPage->setWindowTitle(QApplication::translate("DashBoardPage", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("DashBoardPage", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DashBoardPage: public Ui_DashBoardPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARDPAGE_H
