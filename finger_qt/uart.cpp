/*  说明：串口调试
 *  功能：
 *
 */
#include "uart.h"
#include "ui_uart.h"

uart::uart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::uart)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);

    BackButton = new QPushButton(this);
    BackButton->setIcon(QPixmap("image/back.jpg"));
    BackButton->setIconSize(QPixmap("image/back.jpg").size());
    BackButton->setGeometry(435,245,39,25);
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

    readTimer = new QTimer(this);
    readTimer->start(1000);
    //设置延时为1000ms,每隔一秒读取缓冲区
    connect(readTimer,SIGNAL(timeout()),this,SLOT(ReadCom()));
    //信号和槽函数关联，延时一段时间，进行读串口操作
}

uart::~uart()
{
    delete ui;
}

void uart::changeEvent(QEvent *e)
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

void uart::ReadCom()
{
    readTimer->stop();
    control_data2.clear();
    control_data2=myCom2->readAll();
    QString temp  = control_data2.data();
    ui->textBrowser->insertPlainText(temp);
    myCom2->flush();

    readTimer->start(1000);

}
void uart::back()
{
    this->close();
}
