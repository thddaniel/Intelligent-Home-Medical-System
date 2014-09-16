/*  说明：家电控制
 *  功能：利用串口 实现 灯光控制、抽风控制、窗帘控制
 *
 */

#include "furniture.h"
#include "ui_furniture.h"

furniture::furniture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::furniture)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background4.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);
    /* 主按钮 */
   /* ledButton = new QPushButton(this);
   // ledButton->setIcon(QPixmap("image/increase.jpg"));
   // ledButton->setIconSize(QPixmap("image/increase.jpg").size());
    ledButton->setGeometry(15,20,90,40);
    //IncreaseButton->setText(tr("添加用户"));
    connect(ledButton,SIGNAL(clicked()),this,SLOT(on_ledButton_clicked()));

    airButton = new QPushButton(this);
   // airButton->setIcon(QPixmap("image/increase.jpg"));
   // airButton->setIconSize(QPixmap("image/increase.jpg").size());
    airButton->setGeometry(135,20,90,40);
    //airButton->setText(tr("添加用户"));
    connect(airButton,SIGNAL(clicked()),this,SLOT(on_airButton_clicked()));

    curtainButton = new QPushButton(this);
   // curtainButton->setIcon(QPixmap("image/increase.jpg"));
   // curtainButton->setIconSize(QPixmap("image/increase.jpg").size());
    curtainButton->setGeometry(255,20,90,40);
    //curtainButton->setText(tr("添加用户"));
    connect(curtainButton,SIGNAL(clicked()),this,SLOT(on_curtainButton_clicked()));

    applianceButton = new QPushButton(this);
   // applianceButton->setIcon(QPixmap("image/increase.jpg"));
   // applianceButton->setIconSize(QPixmap("image/increase.jpg").size());
    applianceButton->setGeometry(375,20,90,40);
    //applianceButton->setText(tr("添加用户"));
    connect(applianceButton,SIGNAL(clicked()),this,SLOT(on_applianceButton_clicked()));
    */
    Ledlabel = new QLabel(this);
    Ledlabel->setText(tr("灯光控制"));
    Ledlabel->setStyleSheet("color:red");
    //Ledlabel->setIcon(QPixmap("image/dengguang.jpg"));
    //Ledlabel->setIconSize(QPixmap("image/dengguang.jpg").size());
    Ledlabel->setGeometry(15,35,90,25);

    airlabel = new QLabel(this);
    airlabel->setText(tr("抽风控制"));
    airlabel->setStyleSheet("color:red");
    airlabel->setGeometry(15,110,90,25);

    curtainlabel = new QLabel(this);
    curtainlabel->setText(tr("窗帘控制"));
    curtainlabel->setStyleSheet("color:red");
    curtainlabel->setGeometry(15,185,90,25);

    Led1label = new QLabel(this);
    Led1label->setText(tr("大厅灯"));
    Led1label->setGeometry(110,71,120,25);
    Led1Button = new QPushButton(this);
    Led1Button->setIcon(QPixmap("image/led1off.jpg"));
    Led1Button->setIconSize(QPixmap("image/led1off.jpg").size());
    Led1Button->setGeometry(100,20,60,49);
    connect(Led1Button,SIGNAL(clicked()),this,SLOT(led1show()));

    Led2label = new QLabel(this);
    Led2label->setText(tr("卧室灯"));
    Led2label->setGeometry(200,71,120,25);
    Led2Button = new QPushButton(this);
    Led2Button->setIcon(QPixmap("image/led1off.jpg"));
    Led2Button->setIconSize(QPixmap("image/led1off.jpg").size());
    Led2Button->setGeometry(190,20,60,49);
    connect(Led2Button,SIGNAL(clicked()),this,SLOT(led2show()));

    Led3label = new QLabel(this);
    Led3label->setText(tr("厨房灯"));
    Led3label->setGeometry(290,71,120,25);
    Led3Button = new QPushButton(this);
    Led3Button->setIcon(QPixmap("image/led1off.jpg"));
    Led3Button->setIconSize(QPixmap("image/led1off.jpg").size());
    Led3Button->setGeometry(280,20,60,49);
    connect(Led3Button,SIGNAL(clicked()),this,SLOT(led3show()));

    Led4label = new QLabel(this);
    Led4label->setText(tr("走廊灯"));
    Led4label->setGeometry(380,71,120,25);
    Led4Button = new QPushButton(this);
    Led4Button->setIcon(QPixmap("image/led1off.jpg"));
    Led4Button->setIconSize(QPixmap("image/led1off.jpg").size());
    Led4Button->setGeometry(370,20,60,49);
    connect(Led4Button,SIGNAL(clicked()),this,SLOT(led4show()));

    air1label = new QLabel(this);
    air1label->setText(tr("大厅空调"));
    air1label->setGeometry(100,146,120,25);
    air1Button = new QPushButton(this);
    air1Button->setIcon(QPixmap("image/air1off.jpg"));
    air1Button->setIconSize(QPixmap("image/air1off.jpg").size());
    air1Button->setGeometry(100,95,60,49);
    connect(air1Button,SIGNAL(clicked()),this,SLOT(air1show()));

    air2label = new QLabel(this);
    air2label->setText(tr("卧室空调"));
    air2label->setGeometry(190,146,120,25);
    air2Button = new QPushButton(this);
    air2Button->setIcon(QPixmap("image/air1off.jpg"));
    air2Button->setIconSize(QPixmap("image/air1off.jpg").size());
    air2Button->setGeometry(190,95,60,49);
    connect(air2Button,SIGNAL(clicked()),this,SLOT(air2show()));

    air3label = new QLabel(this);
    air3label->setText(tr("厨房抽风"));
    air3label->setGeometry(280,146,120,25);
    air3Button = new QPushButton(this);
    air3Button->setIcon(QPixmap("image/air1off.jpg"));
    air3Button->setIconSize(QPixmap("image/air1off.jpg").size());
    air3Button->setGeometry(280,95,60,49);
    connect(air3Button,SIGNAL(clicked()),this,SLOT(air3show()));

    air4label = new QLabel(this);
    air4label->setText(tr("散热系统"));
    air4label->setGeometry(370,146,120,25);
    air4Button = new QPushButton(this);
    air4Button->setIcon(QPixmap("image/air1off.jpg"));
    air4Button->setIconSize(QPixmap("image/air1off.jpg").size());
    air4Button->setGeometry(370,95,60,49);
    connect(air4Button,SIGNAL(clicked()),this,SLOT(air4show()));

    curtain1label = new QLabel(this);
    curtain1label->setText(tr("大厅窗帘"));
    curtain1label->setGeometry(100,221,120,25);
    curtain1Button = new QPushButton(this);
    curtain1Button->setIcon(QPixmap("image/curtain1off.jpg"));
    curtain1Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
    curtain1Button->setGeometry(100,170,60,49);
    connect(curtain1Button,SIGNAL(clicked()),this,SLOT(curtain1show()));

    curtain2label = new QLabel(this);
    curtain2label->setText(tr("卧室窗帘"));
    curtain2label->setGeometry(190,221,120,25);
    curtain2Button = new QPushButton(this);
    curtain2Button->setIcon(QPixmap("image/curtain1off.jpg"));
    curtain2Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
    curtain2Button->setGeometry(190,170,60,49);
    connect(curtain2Button,SIGNAL(clicked()),this,SLOT(curtain2show()));

    curtain3label = new QLabel(this);
    curtain3label->setText(tr("书房窗帘"));
    curtain3label->setGeometry(280,221,120,25);
    curtain3Button = new QPushButton(this);
    curtain3Button->setIcon(QPixmap("image/curtain1off.jpg"));
    curtain3Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
    curtain3Button->setGeometry(280,170,60,49);
    connect(curtain3Button,SIGNAL(clicked()),this,SLOT(curtain3show()));

    curtain4label = new QLabel(this);
    curtain4label->setText(tr("厕所窗帘"));
    curtain4label->setGeometry(370,221,120,25);
    curtain4Button = new QPushButton(this);
    curtain4Button->setIcon(QPixmap("image/curtain1off.jpg"));
    curtain4Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
    curtain4Button->setGeometry(370,170,60,49);
    connect(curtain4Button,SIGNAL(clicked()),this,SLOT(curtain4show()));
    
    BackButton = new QPushButton(this);
    BackButton->setIcon(QPixmap("image/back.jpg"));
    BackButton->setIconSize(QPixmap("image/back.jpg").size());
    BackButton->setGeometry(0,245,39,25);
    connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));

    GoButton = new QPushButton(this);
    GoButton->setIcon(QPixmap("image/go.jpg"));
    GoButton->setIconSize(QPixmap("image/go.jpg").size());
    GoButton->setGeometry(435,245,39,26);
    connect(GoButton,SIGNAL(clicked()),this,SLOT(go()));

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

furniture::~furniture()
{
    delete ui;
}

void furniture::changeEvent(QEvent *e)
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
void furniture::led1show()
{
    flag1 = !flag1;
    if(flag1){
        Led1Button->setIcon(QPixmap("image/led1off.jpg"));
        Led1Button->setIconSize(QPixmap("image/led1off.jpg").size());
        Led1Button->setGeometry(100,20,60,49);
        myCom2->write("2");
    }
    else{
        Led1Button->setIcon(QPixmap("image/led1on.jpg"));
        Led1Button->setIconSize(QPixmap("image/led1on.jpg").size());
        Led1Button->setGeometry(100,20,60,49);
        myCom2->write("1");
    }
}

void furniture::led2show()
{
    flag2 = !flag2;
    if(flag2){
        Led2Button->setIcon(QPixmap("image/led1off.jpg"));
        Led2Button->setIconSize(QPixmap("image/led1off.jpg").size());
        Led2Button->setGeometry(190,20,60,49);
        myCom2->write("4");
    }
    else{
        Led2Button->setIcon(QPixmap("image/led1on.jpg"));
        Led2Button->setIconSize(QPixmap("image/led1on.jpg").size());
        Led2Button->setGeometry(190,20,60,49);
        myCom2->write("3");
    }
}

void furniture::led3show()
{
    flag3 = !flag3;
    if(flag3){
        Led3Button->setIcon(QPixmap("image/led1off.jpg"));
        Led3Button->setIconSize(QPixmap("image/led1off.jpg").size());
        Led3Button->setGeometry(280,20,60,49);
        myCom2->write("6");
    }
    else{
        Led3Button->setIcon(QPixmap("image/led1on.jpg"));
        Led3Button->setIconSize(QPixmap("image/led1on.jpg").size());
        Led3Button->setGeometry(280,20,60,49);
        myCom2->write("5");
    }
}

void furniture::led4show()
{
    flag4 = !flag4;
    if(flag4){
        Led4Button->setIcon(QPixmap("image/led1off.jpg"));
        Led4Button->setIconSize(QPixmap("image/led1off.jpg").size());
        Led4Button->setGeometry(370,20,60,49);
        myCom2->write("8");
    }
    else{
        Led4Button->setIcon(QPixmap("image/led1on.jpg"));
        Led4Button->setIconSize(QPixmap("image/led1on.jpg").size());
        Led4Button->setGeometry(370,20,60,49);
        myCom2->write("7");
    }
}

void furniture::air1show()
{
    flag5 = !flag5;
    if(flag5){
        air1Button->setIcon(QPixmap("image/air1off.jpg"));
        air1Button->setIconSize(QPixmap("image/air1off.jpg").size());
        air1Button->setGeometry(100,95,60,49);
        myCom2->write("a");
    }
    else{
        air1Button->setIcon(QPixmap("image/air1on.jpg"));
        air1Button->setIconSize(QPixmap("image/air1on.jpg").size());
        air1Button->setGeometry(100,95,60,49);
        myCom2->write("9");
    }
}

void furniture::air2show()
{
    flag6 = !flag6;
    if(flag6){
        air2Button->setIcon(QPixmap("image/air1off.jpg"));
        air2Button->setIconSize(QPixmap("image/air1off.jpg").size());
        air2Button->setGeometry(190,95,60,49);
        myCom2->write("c");
    }
    else{
        air2Button->setIcon(QPixmap("image/air1on.jpg"));
        air2Button->setIconSize(QPixmap("image/air1on.jpg").size());
        air2Button->setGeometry(190,95,60,49);
        myCom2->write("b");
    }
}

void furniture::air3show()
{
    flag7 = !flag7;
    if(flag7){
        air3Button->setIcon(QPixmap("image/air1off.jpg"));
        air3Button->setIconSize(QPixmap("image/air1off.jpg").size());
        air3Button->setGeometry(280,95,60,49);
        myCom2->write("e");
    }
    else{
        air3Button->setIcon(QPixmap("image/air1on.jpg"));
        air3Button->setIconSize(QPixmap("image/air1on.jpg").size());
        air3Button->setGeometry(280,95,60,49);
        myCom2->write("d");
    }
}

void furniture::air4show()
{
    flag8 = !flag8;
    if(flag8){
        air4Button->setIcon(QPixmap("image/air1off.jpg"));
        air4Button->setIconSize(QPixmap("image/air1off.jpg").size());
        air4Button->setGeometry(370,95,60,49);
        myCom2->write("g");
    }
    else{
        air4Button->setIcon(QPixmap("image/air1on.jpg"));
        air4Button->setIconSize(QPixmap("image/air1on.jpg").size());
        air4Button->setGeometry(370,95,60,49);
        myCom2->write("f");
    }
}

void furniture::curtain1show()
{
    flag9 = !flag9;
    if(flag9){
        curtain1Button->setIcon(QPixmap("image/curtain1off.jpg"));
        curtain1Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
        curtain1Button->setGeometry(100,170,60,49);
        myCom2->write("i");
    }
    else{
        curtain1Button->setIcon(QPixmap("image/curtain1on.jpg"));
        curtain1Button->setIconSize(QPixmap("image/curtain1on.jpg").size());
        curtain1Button->setGeometry(100,170,60,49);
        myCom2->write("h");
    }
}

void furniture::curtain2show()
{
    flag10 = !flag10;
    if(flag10){
        curtain2Button->setIcon(QPixmap("image/curtain1off.jpg"));
        curtain2Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
        curtain2Button->setGeometry(190,170,60,49);
        myCom2->write("k");
    }
    else{
        curtain2Button->setIcon(QPixmap("image/curtain1on.jpg"));
        curtain2Button->setIconSize(QPixmap("image/curtain1on.jpg").size());
        curtain2Button->setGeometry(190,170,60,49);
        myCom2->write("j");
    }
}

void furniture::curtain3show()
{
    flag11 = !flag11;
    if(flag11){
        curtain3Button->setIcon(QPixmap("image/curtain1off.jpg"));
        curtain3Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
        curtain3Button->setGeometry(280,170,60,49);
        myCom2->write("m");
    }
    else{
        curtain3Button->setIcon(QPixmap("image/curtain1on.jpg"));
        curtain3Button->setIconSize(QPixmap("image/curtain1on.jpg").size());
        curtain3Button->setGeometry(280,170,60,49);
        myCom2->write("l");
    }
}

void furniture::curtain4show()
{
    flag12 = !flag12;
    if(flag12){
        curtain4Button->setIcon(QPixmap("image/curtain1off.jpg"));
        curtain4Button->setIconSize(QPixmap("image/curtain1off.jpg").size());
        curtain4Button->setGeometry(370,170,60,49);
        myCom2->write("o");
    }
    else{
        curtain4Button->setIcon(QPixmap("image/curtain1on.jpg"));
        curtain4Button->setIconSize(QPixmap("image/curtain1on.jpg").size());
        curtain4Button->setGeometry(370,170,60,49);
        myCom2->write("n");
    }
}


/*void furniture::on_ledButton_clicked()
{

}
void furniture::on_airButton_clicked()
{

}
void furniture::on_curtainButton_clicked()
{

}
void furniture::on_applianceButton_clicked()
{

}
*/
void furniture::back()
{
    this->close();
}
void furniture::go()
{
    Furniture2.show();
}
