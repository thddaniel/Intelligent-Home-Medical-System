/*  说明：家电控制
 *  功能：利用串口 实现个性化模式控制、其余的一些控制。
 *
 */
#include "furniture2.h"
#include "ui_furniture2.h"

furniture2::furniture2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::furniture2)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background4.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);

    Ledlabel = new QLabel(this);
    Ledlabel->setText(tr("个性化模式"));
    Ledlabel->setStyleSheet("color:red");
    Ledlabel->setGeometry(15,35,90,25);

    otherlabel = new QLabel(this);
    otherlabel->setText(tr("其余控制"));
    otherlabel->setStyleSheet("color:red");
    otherlabel->setGeometry(15,110,90,25);

    Led1label = new QLabel(this);
    Led1label->setText(tr("离家模式"));
    Led1label->setGeometry(100,71,120,25);
    Led1Button = new QPushButton(this);
    Led1Button->setIcon(QPixmap("image/shiwaioff.jpg"));
    Led1Button->setIconSize(QPixmap("image/shiwaioff.jpg").size());
    Led1Button->setGeometry(100,20,60,49);
    connect(Led1Button,SIGNAL(clicked()),this,SLOT(led1show()));

    Led2label = new QLabel(this);
    Led2label->setText(tr("在家模式"));
    Led2label->setGeometry(190,71,120,25);
    Led2Button = new QPushButton(this);
    Led2Button->setIcon(QPixmap("image/zaijiaoff.jpg"));
    Led2Button->setIconSize(QPixmap("image/zaijiaoff.jpg").size());
    Led2Button->setGeometry(190,20,60,49);
    connect(Led2Button,SIGNAL(clicked()),this,SLOT(led2show()));

    Led3label = new QLabel(this);
    Led3label->setText(tr("睡眠模式"));
    Led3label->setGeometry(280,71,120,25);
    Led3Button = new QPushButton(this);
    Led3Button->setIcon(QPixmap("image/sleepoff.jpg"));
    Led3Button->setIconSize(QPixmap("image/sleepoff.jpg").size());
    Led3Button->setGeometry(280,20,60,49);
    connect(Led3Button,SIGNAL(clicked()),this,SLOT(led3show()));

    Led4label = new QLabel(this);
    Led4label->setText(tr("起床模式"));
    Led4label->setGeometry(380,71,120,25);
    Led4Button = new QPushButton(this);
    Led4Button->setIcon(QPixmap("image/qichuangoff.jpg"));
    Led4Button->setIconSize(QPixmap("image/qichuangoff.jpg").size());
    Led4Button->setGeometry(370,20,60,49);
    connect(Led4Button,SIGNAL(clicked()),this,SLOT(led4show()));

    other1label = new QLabel(this);
    other1label->setText(tr("大门控制"));
    other1label->setGeometry(100,146,120,25);
    other1Button = new QPushButton(this);
    other1Button->setIcon(QPixmap("image/damenoff.jpg"));
    other1Button->setIconSize(QPixmap("image/damenoff.jpg").size());
    other1Button->setGeometry(100,95,60,49);
    connect(other1Button,SIGNAL(clicked()),this,SLOT(other1show()));

    other2label = new QLabel(this);
    other2label->setText(tr("电视控制"));
    other2label->setGeometry(190,146,120,25);
    other2Button = new QPushButton(this);
    other2Button->setIcon(QPixmap("image/tvoff.jpg"));
    other2Button->setIconSize(QPixmap("image/tvoff.jpg").size());
    other2Button->setGeometry(190,95,60,49);
    connect(other2Button,SIGNAL(clicked()),this,SLOT(other2show()));

    other3label = new QLabel(this);
    other3label->setText(tr("煲饭控制"));
    other3label->setGeometry(280,146,120,25);
    other3Button = new QPushButton(this);
    other3Button->setIcon(QPixmap("image/baofanoff.jpg"));
    other3Button->setIconSize(QPixmap("image/baofanoff.jpg").size());
    other3Button->setGeometry(280,95,60,49);
    connect(other3Button,SIGNAL(clicked()),this,SLOT(other3show()));

    other4label = new QLabel(this);
    other4label->setText(tr("喷水控制"));
    other4label->setGeometry(370,146,120,25);
    other4Button = new QPushButton(this);
    other4Button->setIcon(QPixmap("image/jiaoshuioff.jpg"));
    other4Button->setIconSize(QPixmap("image/jiaoshuioff.jpg").size());
    other4Button->setGeometry(370,95,60,49);
    connect(other4Button,SIGNAL(clicked()),this,SLOT(other4show()));

    BackButton = new QPushButton(this);
    BackButton->setIcon(QPixmap("image/back.jpg"));
    BackButton->setIconSize(QPixmap("image/back.jpg").size());
    BackButton->setGeometry(0,245,39,25);
    connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));

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

    //myCom2->write("ATH\r");
}

furniture2::~furniture2()
{
    delete ui;
}

void furniture2::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void furniture2::led1show()
{
    flag1 = !flag1;
    if(flag1){
        Led1Button->setIcon(QPixmap("image/shiwaioff.jpg"));
        Led1Button->setIconSize(QPixmap("image/shiwaioff.jpg").size());
        Led1Button->setGeometry(100,20,60,49);
        myCom2->write("y");
    }
    else{
        Led1Button->setIcon(QPixmap("image/shiwaion.jpg"));
        Led1Button->setIconSize(QPixmap("image/shiwaion.jpg").size());
        Led1Button->setGeometry(100,20,60,49);
        myCom2->write("x");
    }
}

void furniture2::led2show()
{
    flag2 = !flag2;
    if(flag2){
        Led2Button->setIcon(QPixmap("image/zaijiaoff.jpg"));
        Led2Button->setIconSize(QPixmap("image/zaijiaoff.jpg").size());
        Led2Button->setGeometry(190,20,60,49);
        myCom2->write("A");
    }
    else{
        Led2Button->setIcon(QPixmap("image/zaijiaon.jpg"));
        Led2Button->setIconSize(QPixmap("image/zaijiaon.jpg").size());
        Led2Button->setGeometry(190,20,60,49);
        myCom2->write("z");
    }
}

void furniture2::led3show()
{
    flag3 = !flag3;
    if(flag3){
        Led3Button->setIcon(QPixmap("image/sleepoff.jpg"));
        Led3Button->setIconSize(QPixmap("image/sleepoff.jpg").size());
        Led3Button->setGeometry(280,20,60,49);
        myCom2->write("C");
    }
    else{
        Led3Button->setIcon(QPixmap("image/sleepon.jpg"));
        Led3Button->setIconSize(QPixmap("image/sleepon.jpg").size());
        Led3Button->setGeometry(280,20,60,49);
        myCom2->write("B");
    }
}

void furniture2::led4show()
{
    flag4 = !flag4;
    if(flag4){
        Led4Button->setIcon(QPixmap("image/qichuangoff.jpg"));
        Led4Button->setIconSize(QPixmap("image/qichuangoff.jpg").size());
        Led4Button->setGeometry(370,20,60,49);
        myCom2->write("E");
    }
    else{
        Led4Button->setIcon(QPixmap("image/qichuangon.jpg"));
        Led4Button->setIconSize(QPixmap("image/qichuangon.jpg").size());
        Led4Button->setGeometry(370,20,60,49);
        myCom2->write("D");
    }
}

void furniture2::other1show()
{
    flag5 = !flag5;
    if(flag5){
        other1Button->setIcon(QPixmap("image/damenoff.jpg"));
        other1Button->setIconSize(QPixmap("image/damenoff.jpg").size());
        other1Button->setGeometry(100,95,60,49);
        myCom2->write("q");
    }
    else{
        other1Button->setIcon(QPixmap("image/damenon.jpg"));
        other1Button->setIconSize(QPixmap("image/damenon.jpg").size());
        other1Button->setGeometry(100,95,60,49);
        myCom2->write("p");
    }
}

void furniture2::other2show()
{
    flag6 = !flag6;
    if(flag6){
        other2Button->setIcon(QPixmap("image/tvoff.jpg"));
        other2Button->setIconSize(QPixmap("image/tvoff.jpg").size());
        other2Button->setGeometry(190,95,60,49);
        myCom2->write("s");
    }
    else{
        other2Button->setIcon(QPixmap("image/tvon.jpg"));
        other2Button->setIconSize(QPixmap("image/tvon.jpg").size());
        other2Button->setGeometry(190,95,60,49);
        myCom2->write("r");
    }
}

void furniture2::other3show()
{
    flag7 = !flag7;
    if(flag7){
        other3Button->setIcon(QPixmap("image/baofanoff.jpg"));
        other3Button->setIconSize(QPixmap("image/baofanoff.jpg").size());
        other3Button->setGeometry(280,95,60,49);
        myCom2->write("u");
    }
    else{
        other3Button->setIcon(QPixmap("image/baofanon.jpg"));
        other3Button->setIconSize(QPixmap("image/baofanon.jpg").size());
        other3Button->setGeometry(280,95,60,49);
        myCom2->write("t");
    }
}

void furniture2::other4show()
{
    flag8 = !flag8;
    if(flag8){
        other4Button->setIcon(QPixmap("image/jiaoshuioff.jpg"));
        other4Button->setIconSize(QPixmap("image/jiaoshuioff.jpg").size());
        other4Button->setGeometry(370,95,60,49);
        myCom2->write("w");
    }
    else{
        other4Button->setIcon(QPixmap("image/jiaoshuion.jpg"));
        other4Button->setIconSize(QPixmap("image/jiaoshuion.jpg").size());
        other4Button->setGeometry(370,95,60,49);
        myCom2->write("v");
    }
}

void furniture2::back()
{
    this->close();
}

