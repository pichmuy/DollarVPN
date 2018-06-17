/********************************************************************************
** Form generated from reading UI file 'locationitemview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATIONITEMVIEW_H
#define UI_LOCATIONITEMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocationItemView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *location_txt;
    QLabel *location_img;

    void setupUi(QWidget *LocationItemView)
    {
        if (LocationItemView->objectName().isEmpty())
            LocationItemView->setObjectName(QStringLiteral("LocationItemView"));
        LocationItemView->resize(223, 35);
        verticalLayout = new QVBoxLayout(LocationItemView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(LocationItemView);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#262836;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        location_txt = new QLabel(frame);
        location_txt->setObjectName(QStringLiteral("location_txt"));
        QFont font;
        font.setPointSize(10);
        location_txt->setFont(font);
        location_txt->setStyleSheet(QLatin1String("QLabel {\n"
"\n"
"\n"
"color:#535454;\n"
"padding:5px;\n"
"}"));

        horizontalLayout_2->addWidget(location_txt);

        location_img = new QLabel(frame);
        location_img->setObjectName(QStringLiteral("location_img"));
        location_img->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"image: url(:/resources/img/locationoff.PNG);\n"
"}"));
        location_img->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(location_img);


        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LocationItemView);

        QMetaObject::connectSlotsByName(LocationItemView);
    } // setupUi

    void retranslateUi(QWidget *LocationItemView)
    {
        LocationItemView->setWindowTitle(QApplication::translate("LocationItemView", "Form", Q_NULLPTR));
        location_txt->setText(QApplication::translate("LocationItemView", "Netherlands(AMS)              ", Q_NULLPTR));
        location_img->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LocationItemView: public Ui_LocationItemView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATIONITEMVIEW_H
