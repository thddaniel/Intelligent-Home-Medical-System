/********************************************************************************
** Form generated from reading ui file 'recievedata.ui'
**
** Created: Fri Apr 26 18:58:16 2013
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_RECIEVEDATA_H
#define UI_RECIEVEDATA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recievedata
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QWidget *recievedata)
    {
        if (recievedata->objectName().isEmpty())
            recievedata->setObjectName(QString::fromUtf8("recievedata"));
        recievedata->resize(480, 272);
        pushButton = new QPushButton(recievedata);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 130, 60, 40));
        pushButton_2 = new QPushButton(recievedata);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 130, 60, 40));
        pushButton_3 = new QPushButton(recievedata);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 130, 60, 40));
        pushButton_4 = new QPushButton(recievedata);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 180, 60, 40));
        pushButton_5 = new QPushButton(recievedata);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 180, 60, 40));
        pushButton_6 = new QPushButton(recievedata);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(360, 180, 60, 40));
        pushButton_7 = new QPushButton(recievedata);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(120, 230, 60, 40));
        pushButton_8 = new QPushButton(recievedata);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(240, 230, 60, 40));
        pushButton_9 = new QPushButton(recievedata);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(360, 230, 60, 40));

        retranslateUi(recievedata);

        QMetaObject::connectSlotsByName(recievedata);
    } // setupUi

    void retranslateUi(QWidget *recievedata)
    {
        recievedata->setWindowTitle(QApplication::translate("recievedata", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
        pushButton_9->setText(QString());
        Q_UNUSED(recievedata);
    } // retranslateUi

};

namespace Ui {
    class recievedata: public Ui_recievedata {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECIEVEDATA_H
