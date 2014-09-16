/*  说明：一进入的界面
 *  功能：显示 开门 调用指纹模块验证身份
 *
 */
#include "opendoor.h"
#include "ui_opendoor.h"
extern "C"
{
    #include "fingerprint.h"
    #include "serial.h"
}

opendoor::opendoor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::opendoor)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    /* 界面背景 */
    QPixmap BackGroundPixmap;
    BackGroundPixmap.load("image/zhinengjiaju.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(BackGroundPixmap));
    this->setPalette(palette);

    doorButton = new QPushButton(this);
    doorButton->setIcon(QPixmap("image/doorbutton.jpg"));
    doorButton->setIconSize(QPixmap("image/doorbutton.jpg").size());
    doorButton->setGeometry(95,195,316,77);
    connect(doorButton,SIGNAL(clicked()),this,SLOT(on_doorButton_clicked()));


    myCom2 = new Posix_QextSerialPort("/dev/tq2440_serial0",QextSerialBase::Polling);
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
    readTimer->start(100);
    //设置延时为100ms
    connect(readTimer,SIGNAL(timeout()),this,SLOT(ReadCom2()));
    //信号和槽函数关联，延时一段时间，不断的进行读串口操作

}

opendoor::~opendoor()
{
    delete ui;
}

void opendoor::changeEvent(QEvent *e)
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
void opendoor::ReadCom2()
{
     readTimer->stop();
     //QByteArray temp = myCom2->readAll();要以字符串的形式 不知道QByteArray格式所以要转成QString
      control_data2.clear();
      control_data2=myCom2->readAll();
      QString temp  = control_data2.data();
      //myCom2->flush();
      //ui->textBrowser->insertPlainText(temp);


     if(temp=="b") {       //恐吓
          system("/usr/bin/madplay /opt/qt-4.5/bin/wei.mp3");

     }
     if(temp=="t") {       //煤气泄露
          system("/usr/bin/madplay /opt/qt-4.5/bin/gas.mp3");

     }
     if(temp=="I") {       //欢迎光临
          system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/hi.mp3");
     }

      myCom2->flush();
      readTimer->start(100);
 }

void opendoor::on_doorButton_clicked()
{

/*
   QMessageBox::information(this,"提示","请输入指纹");

    system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/remind.mp3");

    QMessageBox message(QMessageBox::NoIcon,"温馨提示","请输入你的指纹!");
   // message.setIconPixmap(QPixmap("image/icon.jpg"));
     message.exec();

      do {
                UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
                FINGERPRINT_Cmd_Get_Img();
                FINGERPRINT_Recevice_Data(12);
           }
        while ( UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x0 );
        //printf("input succeed\n");

        UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
        FINGERPRINT_Cmd_Img_To_Buffer1();
        FINGERPRINT_Recevice_Data(12);
        if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
        {
                //printf("creat feature ok\n");
        }

        FINGERPRINT_Cmd_Search_Finger_Admin();
        FINGERPRINT_Recevice_Data(16);
        if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
        {
                //printf("check pass\n");
                system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/hi.mp3");
                //QMessageBox::StandardButton rb=QMessageBox::question(this,"温馨提示","输入指纹成功，是否开门!",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
                //if(rb == QMessageBox::Yes)
               // {

                    QMessageBox message(QMessageBox::NoIcon,"温馨提示","输入指纹成功，你已进入主控制界面");
                    message.exec();
                    mainWindow.show();
               // }
        }
        else
        {
                system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/error.mp3");
                //printf("check no pass\n");
                QMessageBox::warning(this,"警告","输入指纹错误！",QMessageBox::Yes);
        }
*/
    mainWindow.show();
}
