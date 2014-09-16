/********************************************************************************
** Form generated from reading ui file 'opendoor.ui'
**
** Created: Fri Apr 26 18:58:16 2013
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPENDOOR_H
#define UI_OPENDOOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_opendoor
{
public:

    void setupUi(QWidget *opendoor)
    {
        if (opendoor->objectName().isEmpty())
            opendoor->setObjectName(QString::fromUtf8("opendoor"));
        opendoor->resize(400, 300);

        retranslateUi(opendoor);

        QMetaObject::connectSlotsByName(opendoor);
    } // setupUi

    void retranslateUi(QWidget *opendoor)
    {
        opendoor->setWindowTitle(QApplication::translate("opendoor", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(opendoor);
    } // retranslateUi

};

namespace Ui {
    class opendoor: public Ui_opendoor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENDOOR_H
