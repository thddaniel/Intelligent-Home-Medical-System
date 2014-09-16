/********************************************************************************
** Form generated from reading ui file 'uart.ui'
**
** Created: Fri Apr 26 18:58:16 2013
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_UART_H
#define UI_UART_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_uart
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *uart)
    {
        if (uart->objectName().isEmpty())
            uart->setObjectName(QString::fromUtf8("uart"));
        uart->resize(480, 272);
        textBrowser = new QTextBrowser(uart);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(50, 10, 361, 241));

        retranslateUi(uart);

        QMetaObject::connectSlotsByName(uart);
    } // setupUi

    void retranslateUi(QWidget *uart)
    {
        uart->setWindowTitle(QApplication::translate("uart", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(uart);
    } // retranslateUi

};

namespace Ui {
    class uart: public Ui_uart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UART_H
