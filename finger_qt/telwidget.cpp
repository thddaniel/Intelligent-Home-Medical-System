/*  说明：拨打电话
 *  功能：
 *
 */
#include <QDialog>
#include <QtGui>
#include <stdio.h>
#include <string.h>
#include <QString>

#include "telwidget.h"


TelWidget::TelWidget(QWidget *parent) :
    QWidget(parent)
{
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);

    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background2.jpg");

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));

    this->setPalette(palette);

    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(QRect(140,20,200,40));

    pushButton0  = new QPushButton();
    pushButton0->setIcon(QPixmap("image/0.jpg"));
    pushButton0->setIconSize(QPixmap("image/0.jpg").size());
    pushButton0->setFixedSize(80,45);

    pushButton1  = new QPushButton();
    pushButton1->setIcon(QPixmap("image/1.jpg"));
    pushButton1->setIconSize(QPixmap("image/1.jpg").size());
    pushButton1->setFixedSize(80,45);

    pushButton2  = new QPushButton();
    pushButton2->setIcon(QPixmap("image/2.jpg"));
    pushButton2->setIconSize(QPixmap("image/2.jpg").size());
    pushButton2->setFixedSize(80,45);

    pushButton3  = new QPushButton();
    pushButton3->setIcon(QPixmap("image/3.jpg"));
    pushButton3->setIconSize(QPixmap("image/3.jpg").size());
    pushButton3->setFixedSize(80,45);

    pushButton4  = new QPushButton();
    pushButton4->setIcon(QPixmap("image/4.jpg"));
    pushButton4->setIconSize(QPixmap("image/4.jpg").size());
    pushButton4->setFixedSize(80,45);

    pushButton5  = new QPushButton();
    pushButton5->setIcon(QPixmap("image/5.jpg"));
    pushButton5->setIconSize(QPixmap("image/5.jpg").size());
    pushButton5->setFixedSize(80,45);

    pushButton6  = new QPushButton();
    pushButton6->setIcon(QPixmap("image/6.jpg"));
    pushButton6->setIconSize(QPixmap("image/6.jpg").size());
    pushButton6->setFixedSize(80,45);

    pushButton7  = new QPushButton();
    pushButton7->setIcon(QPixmap("image/7.jpg"));
    pushButton7->setIconSize(QPixmap("image/7.jpg").size());
    pushButton7->setFixedSize(80,45);

    pushButton8  = new QPushButton();
    pushButton8->setIcon(QPixmap("image/8.jpg"));
    pushButton8->setIconSize(QPixmap("image/8.jpg").size());
    pushButton8->setFixedSize(80,45);

    pushButton9  = new QPushButton();
    pushButton9->setIcon(QPixmap("image/9.jpg"));
    pushButton9->setIconSize(QPixmap("image/9.jpg").size());
    pushButton9->setFixedSize(80,45);

    StopButton    = new QPushButton();
    StopButton->setIcon(QPixmap("image/stop.jpg"));
    StopButton->setIconSize(QPixmap("image/stop.jpg").size());
    StopButton->setFixedSize(80,45);

    CallButton    = new QPushButton();
    CallButton->setIcon(QPixmap("image/call.jpg"));
    CallButton->setIconSize(QPixmap("image/call.jpg").size());
    CallButton->setFixedSize(80,45);

    ListenButton  = new QPushButton();
    ListenButton->setIcon(QPixmap("image/listen.jpg"));
    ListenButton->setIconSize(QPixmap("image/listen.jpg").size());
    ListenButton->setFixedSize(80,45);

    BackButton    = new QPushButton();
    BackButton->setIcon(QPixmap("image/back1.jpg"));
    BackButton->setIconSize(QPixmap("image/back1.jpg").size());
    BackButton->setFixedSize(80,45);

    CloseButton   = new QPushButton();
    CloseButton->setIcon(QPixmap("image/close.jpg"));
    CloseButton->setIconSize(QPixmap("image/close.jpg").size());
    CloseButton->setFixedSize(80,45);

    connect(pushButton1,SIGNAL(clicked()),this,SLOT(press_1()));
    connect(pushButton2,SIGNAL(clicked()),this,SLOT(press_2()));
    connect(pushButton3,SIGNAL(clicked()),this,SLOT(press_3()));
    connect(pushButton4,SIGNAL(clicked()),this,SLOT(press_4()));
    connect(pushButton5,SIGNAL(clicked()),this,SLOT(press_5()));
    connect(pushButton6,SIGNAL(clicked()),this,SLOT(press_6()));
    connect(pushButton7,SIGNAL(clicked()),this,SLOT(press_7()));
    connect(pushButton8,SIGNAL(clicked()),this,SLOT(press_8()));
    connect(pushButton9,SIGNAL(clicked()),this,SLOT(press_9()));
    connect(pushButton0,SIGNAL(clicked()),this,SLOT(press_0()));

    connect(StopButton,SIGNAL(clicked()),this,SLOT(stop()));
    connect(CallButton,SIGNAL(clicked()),this,SLOT(call()));
    connect(CloseButton,SIGNAL(clicked()),this,SLOT(exit()));
    connect(ListenButton,SIGNAL(clicked()),this,SLOT(listen()));
    connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));
    //telbookcmb->setEditable(false);
    //telbookcmb->setVisible(false);
    lineEdit->setEnabled(true);
    lineEdit->setVisible(true);



    layoutkey_1 =  new QHBoxLayout();
    layoutkey_1->setMargin(0);
    layoutkey_1->setSpacing(5);
    layoutkey_1->addWidget(pushButton1);
    layoutkey_1->addWidget(pushButton2);
    layoutkey_1->addWidget(pushButton3);
    layoutkey_1->addWidget(pushButton0);
    layoutkey_1->addWidget(BackButton);



    layoutkey_2 =  new QHBoxLayout();
    layoutkey_2->setMargin(0);
    layoutkey_2->setSpacing(5);
    layoutkey_2->addWidget(pushButton4);
    layoutkey_2->addWidget(pushButton5);
    layoutkey_2->addWidget(pushButton6);
    layoutkey_2->addWidget(CallButton);
    layoutkey_2->addWidget(ListenButton);


    layoutkey_3 =  new QHBoxLayout();
    layoutkey_3->setMargin(0);
    layoutkey_3->setSpacing(5);
    layoutkey_3->addWidget(pushButton7);
    layoutkey_3->addWidget(pushButton8);
    layoutkey_3->addWidget(pushButton9);
    layoutkey_3->addWidget(StopButton);
    layoutkey_3->addWidget(CloseButton);


    verticalwidget = new QWidget(this);
    verticalwidget ->setGeometry(QRect(0,70,480,190));
    mainLayout = new QVBoxLayout(verticalwidget);
    mainLayout->addLayout(layoutkey_1);
    mainLayout->addLayout(layoutkey_2);
    mainLayout->addLayout(layoutkey_3);

    myCom = new Posix_QextSerialPort("/dev/tq2440_serial0",QextSerialBase::Polling);
     //定义串口对象，指定串口名和查询模式，这里使用Polling

    myCom->setBaudRate(BAUD9600);
    //波特率设置，我们设置为9600

    myCom->setDataBits(DATA_8);
    //数据位设置，我们设置为8位数据位

    myCom->setParity(PAR_NONE);
    //奇偶校验设置，我们设置为无校验

    myCom->setStopBits(STOP_1);
    //停止位设置，我们设置为1位停止位

    myCom->setFlowControl(FLOW_OFF);
    //数据流控制设置，我们设置为无数据流控制

    myCom->setTimeout(1);
    //延时设置，我们设置为延时1ms,

    myCom->open(QIODevice::ReadWrite);


}


void TelWidget::press_0()
{
    KeyValue=0;
    lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}


void TelWidget::press_1()
{
   KeyValue=1;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_2()
{
   KeyValue=2;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_3()
{
   KeyValue=3;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_4()
{
   KeyValue=4;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_5()
{
   KeyValue=5;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_6()
{
   KeyValue=6;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_7()
{
   KeyValue=7;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::press_8()
{
   KeyValue=8;
   lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}


void TelWidget::press_9()
{
    KeyValue=9;
    lineEdit->setText(lineEdit->text()+QString::number(KeyValue));
}

void TelWidget::back()
{
    QString text=lineEdit->text();
    text.chop(1);
    lineEdit->setText(text);
    qDebug()<<"erase ok\n";
}


void TelWidget::call()
{
    char buff[20]={'\0'};
    

    QMessageBox::information(this,"from text","yes");

    strcpy(buff,lineEdit->text().toLatin1().data());
    
    Call(buff);
    
}


void TelWidget::listen(){
    HandUp();
}


void TelWidget::stop(){
    HangDown();   
}

void TelWidget::exit()
{
    this->close();
}


void TelWidget::HangDown()
{
    myCom->write("ATH\r");
    sleep(1);
    myCom->flush();//clear all data
    return;
}


void TelWidget::HandUp()
{
    myCom->write("ATA\r");
    sleep(1);
    myCom->flush();//clear all data
    return;
}


void TelWidget::Call(const char *buff1) //打电话,先打指定电话,扩充后随意
{
    char callnumber[100]={'\0'};
    sprintf(callnumber,"ATD%s;\r",buff1);
    myCom->write(callnumber);
    sleep(1);
    myCom->flush();//clear all data
    return;
}

