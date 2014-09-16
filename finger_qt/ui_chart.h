/********************************************************************************
** Form generated from reading ui file 'chart.ui'
**
** Created: Fri Apr 26 18:58:16 2013
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CHART_H
#define UI_CHART_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chart
{
public:

    void setupUi(QWidget *chart)
    {
        if (chart->objectName().isEmpty())
            chart->setObjectName(QString::fromUtf8("chart"));
        chart->resize(400, 300);

        retranslateUi(chart);

        QMetaObject::connectSlotsByName(chart);
    } // setupUi

    void retranslateUi(QWidget *chart)
    {
        chart->setWindowTitle(QApplication::translate("chart", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(chart);
    } // retranslateUi

};

namespace Ui {
    class chart: public Ui_chart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHART_H
