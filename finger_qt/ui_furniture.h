/********************************************************************************
** Form generated from reading ui file 'furniture.ui'
**
** Created: Fri Apr 26 18:58:16 2013
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FURNITURE_H
#define UI_FURNITURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_furniture
{
public:

    void setupUi(QWidget *furniture)
    {
        if (furniture->objectName().isEmpty())
            furniture->setObjectName(QString::fromUtf8("furniture"));
        furniture->resize(400, 300);

        retranslateUi(furniture);

        QMetaObject::connectSlotsByName(furniture);
    } // setupUi

    void retranslateUi(QWidget *furniture)
    {
        furniture->setWindowTitle(QApplication::translate("furniture", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(furniture);
    } // retranslateUi

};

namespace Ui {
    class furniture: public Ui_furniture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FURNITURE_H
