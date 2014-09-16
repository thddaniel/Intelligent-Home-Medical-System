#ifndef FURNITURE2_H
#define FURNITURE2_H

#include <QWidget>
#include <QtGui/QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QTextCodec>
#include <stdio.h>
#include "posix_qextserialport.h"

namespace Ui {
    class furniture2;
}

class furniture2 : public QWidget {
    Q_OBJECT
public:
    furniture2(QWidget *parent = 0);
    ~furniture2();
     int flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::furniture2 *ui;
    Posix_QextSerialPort *myCom2;
    QLabel *Ledlabel;
    QLabel *otherlabel;

   QLabel *Led1label;
    QLabel *Led2label;
    QLabel *Led3label;
    QLabel *Led4label;

    QLabel *other1label;
    QLabel *other2label;
    QLabel *other3label;
    QLabel *other4label;

    QPushButton *Led1Button;
    QPushButton *Led2Button;
    QPushButton *Led3Button;
    QPushButton *Led4Button;

    QPushButton *other1Button;
    QPushButton *other2Button;
    QPushButton *other3Button;
    QPushButton *other4Button;

    QPushButton *BackButton;

private slots:
    void led1show();
    void led2show();
    void led3show();
    void led4show();
    void other1show();
    void other2show();
    void other3show();
    void other4show();
    void back();

};

#endif // FURNITURE2_H
