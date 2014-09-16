#ifndef TELWIDGET_H
#define TELWIDGET_H

#include<QWidget>
#include <QtGui>
#include "posix_qextserialport.h"

class TelWidget:public QWidget
{
    Q_OBJECT
 public:
    explicit TelWidget(QWidget *parent = 0);
    
    void HangDown();
    void HandUp();
    void Call(const char *buff1);

     int KeyValue;

     QHBoxLayout *layoutkey_1;
     QHBoxLayout *layoutkey_2;
     QHBoxLayout *layoutkey_3;

     QWidget *verticalwidget;
     QVBoxLayout *mainLayout;


 public slots:
    void press_0();
    void press_1();
    void press_2();
    void press_3();
    void press_4();
    void press_5();
    void press_6();
    void press_7();
    void press_8();
    void press_9();

    void back();
    void call();
    void stop();
    void listen();
    void exit();


private:
    Posix_QextSerialPort *myCom;

    QPushButton *pushButton0;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton6;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;

    QPushButton *StopButton;
    QPushButton *CallButton;
    QPushButton *CloseButton;
    QPushButton *ListenButton;
    QPushButton *BackButton;

    //QComboBox *telbookcmb;
    QLineEdit *lineEdit;

    QBrush brush;
};

#endif // TELWIDGET_H
