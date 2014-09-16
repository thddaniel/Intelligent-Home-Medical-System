/*  说明：主界面
 *  功能：显示 设置、电话、短信、音乐、家电控制、实时采集
 *
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

extern "C"
{
    #include "fingerprint.h"
    #include "serial.h"
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*界面大小*/
    /*ui->setupUi(this);
    this->setMinimumSize(480,272);
    this->setMaximumSize(480,272);
    this->setWindowFlags( Qt::FramelessWindowHint);*/
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    /* 界面背景 */
    QPixmap BackGroundPixmap;
    BackGroundPixmap.load("image/main_background.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(BackGroundPixmap));
    this->setPalette(palette);

    /*系统管理-增加指纹删除指纹*/
    AdministraterButton = new QPushButton(this);
    AdministraterButton->setIcon(QPixmap("image/shezhi.jpg"));
    AdministraterButton->setIconSize(QPixmap("image/shezhi.jpg").size());
    AdministraterButton->setGeometry(20,10,80,90);
    connect(AdministraterButton,SIGNAL(clicked()),this,SLOT(on_AdministraterButton_clicked()));

    /* 手机界面拨号 */
    PhoneButton = new QPushButton(this);
    PhoneButton->setIcon(QPixmap("image/dianhua.jpg"));
    PhoneButton->setIconSize(QPixmap("image/dianhua.jpg").size());
    PhoneButton->setGeometry(140,10,80,90);
    connect(PhoneButton,SIGNAL(clicked()),this,SLOT(on_PhoneButton_clicked()));

    /*发送短信*/
    MessageButton = new QPushButton(this);
    MessageButton->setIcon(QPixmap("image/duanxin.jpg"));
    MessageButton->setIconSize(QPixmap("image/duanxin.jpg").size());
    MessageButton->setGeometry(260,10,80,90);
    //qDebug()<<"hello world";
    message = new Message;
    connect(MessageButton,SIGNAL(clicked()),message,SLOT(show()));

    /*播放音乐*/
    MusicButton = new QPushButton(this);
    MusicButton->setIcon(QPixmap("image/yinyue.jpg"));
    MusicButton->setIconSize(QPixmap("image/yinyue.jpg").size());
    MusicButton->setGeometry(380,10,80,90);
    Musicwidget = new MusicWidget;
    Musicwidget->setGeometry(84,40,480,272);
    connect(MusicButton,SIGNAL(clicked()),Musicwidget,SLOT(show()));

    /* 家电控制#include <QTextCodec> */
    furnitureButton = new QPushButton(this);
    furnitureButton->setIcon(QPixmap("image/jiadian.jpg"));
    furnitureButton->setIconSize(QPixmap("image/jiadian.jpg").size());
    furnitureButton->setGeometry(20,130,80,90);
    connect(furnitureButton,SIGNAL(clicked()),this,SLOT(on_furnitureButton_clicked()));

    /*察看数据 温度 湿度等 */
    dataButton = new QPushButton(this);
    dataButton->setIcon(QPixmap("image/caiji.jpg"));
    dataButton->setIconSize(QPixmap("image/caiji.jpg").size());
    dataButton->setGeometry(140,130,80,90);
    Recievedata = new recievedata;
    connect(dataButton,SIGNAL(clicked()),Recievedata,SLOT(show()));

    /* 关门 */
    BackButton = new QPushButton(this);
    BackButton->setText(tr("关门"));
    BackButton->setGeometry(435,245,45,25);
    connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));

    /* 串口调试 */
    uartButton = new QPushButton(this);
    uartButton->setText(tr("调试"));
    uartButton->setGeometry(435,200,45,25);
    connect(uartButton,SIGNAL(clicked()),this,SLOT(on_uartButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


void MainWindow::on_AdministraterButton_clicked()
{
  Administrater.show();
}

void MainWindow::on_PhoneButton_clicked()
{
  telWidget.show();
}
/*
void MainWindow::on_dataButton_clicked()
{
  Recievedata.show();
}*/
void MainWindow::on_furnitureButton_clicked()
{
  Furniture.show();
}
void MainWindow::back()
{
    this->close();
}
void MainWindow::on_uartButton_clicked()
{
   Uart.show();
}

