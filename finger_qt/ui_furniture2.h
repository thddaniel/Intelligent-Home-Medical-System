/********************************************************************************
** Form generated from reading ui file 'furniture2.ui'
**
** Created: Fri Apr 26 18:58:16 2013
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FURNITURE2_H
#define UI_FURNITURE2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_furniture2
{
public:

    void setupUi(QWidget *furniture2)
    {
        if (furniture2->objectName().isEmpty())
            furniture2->setObjectName(QString::fromUtf8("furniture2"));
        furniture2->resize(400, 300);

        retranslateUi(furniture2);

        QMetaObject::connectSlotsByName(furniture2);
    } // setupUi

    void retranslateUi(QWidget *furniture2)
    {
        furniture2->setWindowTitle(QApplication::translate("furniture2", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(furniture2);
    } // retranslateUi

};

namespace Ui {
    class furniture2: public Ui_furniture2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FURNITURE2_H
