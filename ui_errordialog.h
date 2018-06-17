/********************************************************************************
** Form generated from reading UI file 'errordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORDIALOG_H
#define UI_ERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ErrorDialog
{
public:
    QFrame *frame;
    QPushButton *Ok_button_2;
    QLabel *label_2;
    QTextEdit *error_txt;

    void setupUi(QDialog *ErrorDialog)
    {
        if (ErrorDialog->objectName().isEmpty())
            ErrorDialog->setObjectName(QStringLiteral("ErrorDialog"));
        ErrorDialog->resize(361, 171);
        frame = new QFrame(ErrorDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 361, 171));
        frame->setStyleSheet(QLatin1String("QFrame\n"
"{\n"
"background-color:#1c1d25;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Ok_button_2 = new QPushButton(frame);
        Ok_button_2->setObjectName(QStringLiteral("Ok_button_2"));
        Ok_button_2->setGeometry(QRect(275, 130, 75, 23));
        QFont font;
        font.setPointSize(9);
        Ok_button_2->setFont(font);
        Ok_button_2->setStyleSheet(QLatin1String("QPushButton {\n"
"\n"
"background-color:#ffb400;\n"
"border-radius:5px;\n"
"color:#000000;\n"
"}"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 10, 101, 21));
        QFont font1;
        font1.setPointSize(14);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color:#ff0000;\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        error_txt = new QTextEdit(frame);
        error_txt->setObjectName(QStringLiteral("error_txt"));
        error_txt->setGeometry(QRect(20, 40, 331, 81));
        QFont font2;
        font2.setPointSize(10);
        error_txt->setFont(font2);
        error_txt->setStyleSheet(QLatin1String("QTextEdit\n"
"{\n"
"color:#ffb400;\n"
"border-radius:0px;\n"
"}"));
        error_txt->setReadOnly(true);

        retranslateUi(ErrorDialog);

        QMetaObject::connectSlotsByName(ErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *ErrorDialog)
    {
        ErrorDialog->setWindowTitle(QApplication::translate("ErrorDialog", "Dialog", Q_NULLPTR));
        Ok_button_2->setText(QApplication::translate("ErrorDialog", "OK", Q_NULLPTR));
        label_2->setText(QApplication::translate("ErrorDialog", "Alert!", Q_NULLPTR));
        error_txt->setHtml(QApplication::translate("ErrorDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Heloo</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ErrorDialog: public Ui_ErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORDIALOG_H
