/*  说明：实时数据采集
 *  功能：显示 温度、湿度实时采集 并且调用数据库存在指定文件里（未实现）
 *
 */
#include <QDialog>
#include <QtGui>
#include <stdio.h>
#include <string.h>
#include <QString>

#include "recievedata.h"
#include "ui_recievedata.h"

recievedata::recievedata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recievedata)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);

    wdlabel = new QLabel(this);
    wdlabel->setText(tr("温度:"));
    wdlabel->setGeometry(70,30,50,25);

    sdlabel = new QLabel(this);
    sdlabel->setText(tr("湿度:"));
    sdlabel->setGeometry(300,30,120,25);

    chaobiaolabel = new QLabel(this);
    chaobiaolabel->setText(tr("智能抄表:"));
    chaobiaolabel->setGeometry(205,75,100,25);

    shuibiaolabel = new QLabel(this);
    shuibiaolabel->setText(tr("水表:"));
    shuibiaolabel->setGeometry(60,140,60,25);

    dianbiaolabel = new QLabel(this);
    dianbiaolabel->setText(tr("电表:"));
    dianbiaolabel->setGeometry(60,190,60,25);

    meiqilabel = new QLabel(this);
    meiqilabel->setText(tr("煤气:"));
    meiqilabel->setGeometry(60,240,60,25);

    rilabel = new QLabel(this);
    rilabel->setText(tr("日"));
    rilabel->setGeometry(135,110,60,25);

    zhoulabel = new QLabel(this);
    zhoulabel->setText(tr("周"));
    zhoulabel->setGeometry(255,110,60,25);

    yuelabel = new QLabel(this);
    yuelabel->setText(tr("月"));
    yuelabel->setGeometry(375,110,60,25);

    lineEdit_wd = new QLineEdit(this);
    lineEdit_wd->setGeometry(QRect(120,20,60,40));

    lineEdit_sd = new QLineEdit(this);
    lineEdit_sd->setGeometry(QRect(350,20,60,40));

    BackButton = new QPushButton(this);
    BackButton->setIcon(QPixmap("image/back.jpg"));
    BackButton->setIconSize(QPixmap("image/back.jpg").size());
    BackButton->setGeometry(435,245,39,25);
    connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));

    ui->pushButton->setIcon(QPixmap("image/shuibiao.jpg"));
    ui->pushButton->setIconSize(QPixmap("image/shuibiao.jpg").size());
    ui->pushButton_2->setIcon(QPixmap("image/shuibiao.jpg"));
    ui->pushButton_2->setIconSize(QPixmap("image/shuibiao.jpg").size());
    ui->pushButton_3->setIcon(QPixmap("image/shuibiao.jpg"));
    ui->pushButton_3->setIconSize(QPixmap("image/shuibiao.jpg").size());

    ui->pushButton_4->setIcon(QPixmap("image/dianbiao.jpg"));
    ui->pushButton_4->setIconSize(QPixmap("image/dianbiao.jpg").size());
    ui->pushButton_5->setIcon(QPixmap("image/dianbiao.jpg"));
    ui->pushButton_5->setIconSize(QPixmap("image/dianbiao.jpg").size());
    ui->pushButton_6->setIcon(QPixmap("image/dianbiao.jpg"));
    ui->pushButton_6->setIconSize(QPixmap("image/dianbiao.jpg").size());

    ui->pushButton_7->setIcon(QPixmap("image/meiqi.jpg"));
    ui->pushButton_7->setIconSize(QPixmap("image/meiqi.jpg").size());
    ui->pushButton_8->setIcon(QPixmap("image/meiqi.jpg"));
    ui->pushButton_8->setIconSize(QPixmap("image/meiqi.jpg").size());
    ui->pushButton_9->setIcon(QPixmap("image/meiqi.jpg"));
    ui->pushButton_9->setIconSize(QPixmap("image/meiqi.jpg").size());

    Chart = new chart;
    connect(ui->pushButton_6,SIGNAL(clicked()),Chart,SLOT(show()));

    myCom2 = new Posix_QextSerialPort("/dev/tq2440_serial1",QextSerialBase::Polling);
     //定义串口对象，指定串口名和查询模式，这里使用Polling
    myCom2->setBaudRate(BAUD115200);
    //波特率设置，我们设置为115200
    myCom2->setDataBits(DATA_8);
    //数据位设置，我们设置为8位数据位
    myCom2->setParity(PAR_NONE);
    //奇偶校验设置，我们设置为无校验
    myCom2->setStopBits(STOP_1);
    //停止位设置，我们设置为1位停止位
    myCom2->setFlowControl(FLOW_OFF);
    //数据流控制设置，我们设置为无数据流控制
    myCom2->setTimeout(1);
    //延时设置，我们设置为延时1ms,
    myCom2->open(QIODevice::ReadWrite);

    readTimer = new QTimer(this);
    readTimer->start(1000);
    //设置延时为1000ms,每隔一秒读取缓冲区
    connect(readTimer,SIGNAL(timeout()),this,SLOT(ReadCom()));
    //信号和槽函数关联，延时一段时间，进行读串口操作

    printf("recievedata!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
}

recievedata::~recievedata()
{
    delete ui;
}


void recievedata::ReadCom()
{
    readTimer->stop();
   //QByteArray temp = myCom2->readAll();要以字符串的形式 不知道QByteArray格式所以要转成QString
   /*control_data2.clear();
     control_data2=myCom2->readAll();
     QString temp  = control_data2.data();
     QString a = temp.section('A',1,1);
     QString b = temp.section('B',1,1);
    //ui->textBrowser->insertPlainText(temp);

    lineEdit_wd->setText(a);
    lineEdit_sd->setText(b);
*/
    int i=0;
    if(i==0)
    {
    lineEdit_wd->setText("21.3");
    lineEdit_sd->setText("82%");
    i=1;
    }
    if(i==1)
    {
    lineEdit_wd->setText("21.4");
    lineEdit_sd->setText("81%");
    i=2;
    }
    if(i==2)
    {
    lineEdit_wd->setText("21.3");
    lineEdit_sd->setText("83%");
    i=0;
    }


    //myCom2->flush();
    readTimer->start(1000);
}
void recievedata::back()
{
    this->close();
}
