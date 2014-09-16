#ifndef FURNITURE_H
#define FURNITURE_H

#include <QWidget>
#include <QtGui/QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QTextCodec>
#include <stdio.h>
#include "furniture2.h"
#include "posix_qextserialport.h"

namespace Ui {
    class furniture;
}

class furniture : public QWidget {
    Q_OBJECT
public:
    furniture(QWidget *parent = 0);
    ~furniture();

     int flag1,flag2,flag3,flag4,flag5,flag6,flag7,flag8,
         flag9,flag10,flag11,flag12;


protected:
    void changeEvent(QEvent *e);

private:
    Ui::furniture *ui;
    furniture2 Furniture2;
   /* QPushButton *ledButton;
    QPushButton *airButton;
    QPushButton *curtainButton;
    QPushButton *applianceButton;*/
    Posix_QextSerialPort *myCom2;
    QPushButton *BackButton;
    QPushButton *GoButton;

    QLabel *Ledlabel;
    QLabel *airlabel;
    QLabel *curtainlabel;

    QLabel *Led1label;
    QLabel *Led2label;
    QLabel *Led3label;
    QLabel *Led4label;

    QLabel *air1label;
    QLabel *air2label;
    QLabel *air3label;
    QLabel *air4label;

    QLabel *curtain1label;
    QLabel *curtain2label;
    QLabel *curtain3label;
    QLabel *curtain4label;

    QPushButton *Led1Button;
    QPushButton *Led2Button;
    QPushButton *Led3Button;
    QPushButton *Led4Button;

    QPushButton *air1Button;
    QPushButton *air2Button;
    QPushButton *air3Button;
    QPushButton *air4Button;

    QPushButton *curtain1Button;
    QPushButton *curtain2Button;
    QPushButton *curtain3Button;
    QPushButton *curtain4Button;


private slots:
    /*void on_ledButton_clicked();
    void on_airButton_clicked();
    void on_curtainButton_clicked();
    void on_applianceButton_clicked();*/

    void led1show();
    void led2show();
    void led3show();
    void led4show();
    void air1show();
    void air2show();
    void air3show();
    void air4show();
    void curtain1show();
    void curtain2show();
    void curtain3show();
    void curtain4show();
    void back();
    void go();
};

#endif // FURNITURE_H
