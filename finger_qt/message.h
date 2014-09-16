#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtGui/QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <stdio.h>
#include "input.h"
#include "posix_qextserialport.h"


class Message : public QWidget
{
    Q_OBJECT

public:
    Message(QWidget *parent = 0);
    ~Message();

    friend class InPut;
    InPut *Input;

    int editflag;
    char content[600];
    char phone[40];

    void SendMsg(char *buff,char *buff1);
    void ReventPhone();


private:
    Posix_QextSerialPort *myCom;

    QLineEdit *telnum;
    QTextEdit *mescontent;
    QPushButton *pushButtonSend;
    QPushButton *pushButtonTdel;
    QPushButton *pushButtonMdel;
    QPushButton *pushButtonExit;

     void contentdecode();

private slots:
    void EditTelnum();
    void EditMescontent();

    void send();           //发送短信
    void exit();
    void zimuback();  //字母返回
    void shuziback(); //数字返回
};

#endif // MESSAGE_H
