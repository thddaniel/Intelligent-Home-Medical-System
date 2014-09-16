/*  说明：系统管理
 *  功能：实现 增加指纹、删除所有指纹。通过GPRS模块 呼叫户主。
 *
 */

#include "administrater.h"
extern "C"
{
    #include "fingerprint.h"
    #include "serial.h"
}

administrater::administrater(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background3.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);


    resultlabel = new QLabel(this);
    resultlabel->setText(tr("现存在的用户个数为:"));
    resultlabel->setGeometry(220,45,120,25);

    resultLineEdit = new QLineEdit(this);
    resultLineEdit->setGeometry(345,43,80,30);

    IncreaseButton = new QPushButton(this);
    IncreaseButton->setIcon(QPixmap("image/increase.jpg"));
    IncreaseButton->setIconSize(QPixmap("image/increase.jpg").size());
    IncreaseButton->setGeometry(220,90,96,96);
    //IncreaseButton->setText(tr("添加用户"));
    connect(IncreaseButton,SIGNAL(clicked()),this,SLOT(on_increasefingerPushButton_clicked()));

    DecreaseButton = new QPushButton(this);
    DecreaseButton->setIcon(QPixmap("image/decrease.jpg"));
    DecreaseButton->setIconSize(QPixmap("image/decrease.jpg").size());
    DecreaseButton->setGeometry(330,90,96,96);
    //DecreaseButton->setText(tr("删除指纹"));
    connect(DecreaseButton,SIGNAL(clicked()),this,SLOT(on_decreasefingerPushButton_clicked()));


    /* 呼叫户主 */
    showlabel = new QLabel(this);
    showlabel->setText(tr("呼叫以下户主:"));
    showlabel->setFixedSize(100,30);
    /*
        bellButton = new QPushButton(this);
        //bellButton->setIcon(QPixmap("image/bell.jpg"));
        //bellButton->setIconSize(QPixmap("image/bell.jpg").size());
        bellButton->setGeometry(70,70,150,150);
        connect(bellButton,SIGNAL(clicked()),this,SLOT(on_bellPushButton_clicked()));
    */
        name1Button = new QPushButton(this);
        name1Button->setIcon(QPixmap("image/name1.jpg"));
        name1Button->setIconSize(QPixmap("image/name1.jpg").size());
        name1Button->setFixedSize(100,30);
        connect(name1Button,SIGNAL(clicked()),this,SLOT(on_name1PushButton_clicked()));

        name2Button = new QPushButton(this);
        name2Button->setIcon(QPixmap("image/name2.jpg"));
        name2Button->setIconSize(QPixmap("image/name2.jpg").size());
        name2Button->setFixedSize(100,30);
        connect(name2Button,SIGNAL(clicked()),this,SLOT(on_name2PushButton_clicked()));

        name3Button = new QPushButton(this);
        name3Button->setIcon(QPixmap("image/name3.jpg"));
        name3Button->setIconSize(QPixmap("image/name3.jpg").size());
        name3Button->setFixedSize(100,30);
        connect(name3Button,SIGNAL(clicked()),this,SLOT(on_name3PushButton_clicked()));

        name4Button = new QPushButton(this);
        name4Button->setIcon(QPixmap("image/name4.jpg"));
        name4Button->setIconSize(QPixmap("image/name4.jpg").size());
        name4Button->setFixedSize(100,30);
        connect(name4Button,SIGNAL(clicked()),this,SLOT(on_name4PushButton_clicked()));

        name5Button = new QPushButton(this);
        name5Button->setIcon(QPixmap("image/name5.jpg"));
        name5Button->setIconSize(QPixmap("image/name5.jpg").size());
        name5Button->setFixedSize(100,30);
        connect(name5Button,SIGNAL(clicked()),this,SLOT(on_name5PushButton_clicked()));

        name6Button = new QPushButton(this);
        name6Button->setIcon(QPixmap("image/name6.jpg"));
        name6Button->setIconSize(QPixmap("image/name6.jpg").size());
        name6Button->setFixedSize(100,30);
        connect(name6Button,SIGNAL(clicked()),this,SLOT(on_name6PushButton_clicked()));

        layoutkey =  new QVBoxLayout();
        layoutkey->setMargin(0);
        layoutkey->setSpacing(0);
        layoutkey->addWidget(showlabel);
        layoutkey->addWidget(name1Button);
        layoutkey->addWidget(name2Button);
        layoutkey->addWidget(name3Button);
        layoutkey->addWidget(name4Button);
        layoutkey->addWidget(name5Button);
        layoutkey->addWidget(name6Button);

        verticalwidget = new QWidget(this);
        verticalwidget ->setGeometry(QRect(0,0,120,272));
        mainLayout = new QHBoxLayout(verticalwidget);
        mainLayout->addLayout(layoutkey);

        BackButton = new QPushButton(this);
        BackButton->setIcon(QPixmap("image/back.jpg"));
        BackButton->setIconSize(QPixmap("image/back.jpg").size());
        BackButton->setGeometry(435,245,39,25);
        connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));

        printf("administrater!!!!!ceshi!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

}

administrater::~administrater()
{

}

void administrater::on_increasefingerPushButton_clicked()
{
    UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
    FINGERPRINT_Cmd_Get_Templete_Num();
    FINGERPRINT_Recevice_Data(14);
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
    {
            numL=UART1_FINGERPRINT_RECEVICE_BUFFER[11];
            printf("The effective number of mode:%d\n",numL);
            QString str1 = QString::number(numL);
            resultLineEdit->setText(str1);
    }
    system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/remind.mp3");
    QMessageBox message(QMessageBox::NoIcon,"温馨提示","请输入你的指纹!");

    message.exec();

    printf("please input first finger\n");
    do {
            UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
            FINGERPRINT_Cmd_Get_Img();
            FINGERPRINT_Recevice_Data(12);
        }
    while ( UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x0 );
    printf("first input succeed\n");

    UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
    FINGERPRINT_Cmd_Img_To_Buffer1();
    FINGERPRINT_Recevice_Data(12);
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
    {
            printf("The first feature succeed\n");
    }

    system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/again.mp3");
    QMessageBox message1(QMessageBox::NoIcon,"温馨提示","请再次输入你的指纹!");
    message1.exec();

    printf("Please input the second finger\n");
    do{
            UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
            FINGERPRINT_Cmd_Get_Img();
            FINGERPRINT_Recevice_Data(12);
      }
    while( UART1_FINGERPRINT_RECEVICE_BUFFER[9]!=0x0 );
    printf("The second input succeed\n");

    UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
    FINGERPRINT_Cmd_Img_To_Buffer2();
    FINGERPRINT_Recevice_Data(12);
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
    {
            printf("The second feature succeed\n");
    }

    UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
    FINGERPRINT_Cmd_Reg_Model();
    FINGERPRINT_Recevice_Data(12);
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
    {
            printf("The feature mode succeed\n");
            system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/addok.mp3");
            QMessageBox message(QMessageBox::NoIcon,"温馨提示","指纹增加成功!");

            message.exec();
    }
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0a)
    {
            printf("The feature mode fail\n");
            system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/adderror.mp3");
            QMessageBox::warning(this,"警告","指纹增加失败！",QMessageBox::Yes);
    }

    UART1_FINGERPRINT_RECEVICE_BUFFER[9]=0x01;
    FINGERPRINT_Cmd_Save_Finger(0,numL);
    FINGERPRINT_Recevice_Data(12);
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
    {
            numL++;
            printf("Create the mode:%d\n",numL);
            if(numL==255)
            {
                    numL=0;
            }
    }
    QString str1 = QString::number(numL);
    resultLineEdit->setText(str1);
}

void administrater::on_decreasefingerPushButton_clicked()
{
    FINGERPRINT_Cmd_Delete_All_Model();
    FINGERPRINT_Recevice_Data(12);
    if(UART1_FINGERPRINT_RECEVICE_BUFFER[9]==0x0)
    {
           printf("delete  all  ok\n");
           QMessageBox message(QMessageBox::NoIcon,"温馨提示","已删除全部指纹!");
           message.exec();
           resultLineEdit->setText("0");
    }
}
void administrater::on_name1PushButton_clicked()
{
    int fd;
    int i;

    flag1 = !flag1;
    if(flag1)
    {
        name1Button->setIcon(QPixmap("image/name1.jpg"));
        name1Button->setIconSize(QPixmap("image/name1.jpg").size()); 
    }
    else
    {
        name1Button->setIcon(QPixmap("image/name11.jpg"));
        name1Button->setIconSize(QPixmap("image/name11.jpg").size());

            if(( fd=open_port(fd,0)) < 0){
                    //perror("open_port error");
                    return;
            }

            if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
                    //perror("set_opt error");
                    return;
            }

            write(fd,"ATD13750360325;\r",sizeof("ATD13750360325;\r"));
            sleep(1);

            ::close(fd);
    }

}
void administrater::on_name2PushButton_clicked()
{
    int fd;
    int i;
    flag2=!flag2;
    if(flag2)
    {
        name2Button->setIcon(QPixmap("image/name2.jpg"));
        name2Button->setIconSize(QPixmap("image/name2.jpg").size());

    }
    else
    {
        name2Button->setIcon(QPixmap("image/name22.jpg"));
        name2Button->setIconSize(QPixmap("image/name22.jpg").size());

    }

    if(( fd=open_port(fd,0)) < 0){
            //perror("open_port error");
            return;
    }

    if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
            //perror("set_opt error");
            return;
    }

    //write(fd,"ATD13424986236;\r",sizeof("ATD13424986236;\r"));
    sleep(1);

    ::close(fd);
}
void administrater::on_name3PushButton_clicked()
{
    int fd;
    int i;

    flag3=!flag3;
    if(flag3)
    {
        name3Button->setIcon(QPixmap("image/name3.jpg"));
        name3Button->setIconSize(QPixmap("image/name3.jpg").size());

    }
    else
    {
        name3Button->setIcon(QPixmap("image/name33.jpg"));
        name3Button->setIconSize(QPixmap("image/name33.jpg").size());

    }


    if(( fd=open_port(fd,0)) < 0){
            //perror("open_port error");
            return;
    }

    if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
            //perror("set_opt error");
            return;
    }

    //write(fd,"ATD13631895627;\r",sizeof("ATD13631895627;\r"));
    sleep(1);

    ::close(fd);
}
void administrater::on_name4PushButton_clicked()
{
    int fd;
    int i;

    flag4=!flag4;
    if(flag4)
    {
        name4Button->setIcon(QPixmap("image/name4.jpg"));
        name4Button->setIconSize(QPixmap("image/name4.jpg").size());

    }
    else
    {
        name4Button->setIcon(QPixmap("image/name44.jpg"));
        name4Button->setIconSize(QPixmap("image/name44.jpg").size());

    }


    if(( fd=open_port(fd,0)) < 0){
            //perror("open_port error");
            return;
    }

    if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
            //perror("set_opt error");
            return;
    }

   // write(fd,"ATD13631895627;\r",sizeof("ATD13631895627;\r"));
    sleep(1);

    ::close(fd);
}
void administrater::on_name5PushButton_clicked()
{
    int fd;
    int i;

    flag5=!flag5;
    if(flag5)
    {
        name5Button->setIcon(QPixmap("image/name5.jpg"));
        name5Button->setIconSize(QPixmap("image/name5.jpg").size());

    }
    else
    {
        name5Button->setIcon(QPixmap("image/name55.jpg"));
        name5Button->setIconSize(QPixmap("image/name55.jpg").size());

    }

    if(( fd=open_port(fd,0)) < 0){
            //perror("open_port error");
            return;
    }

    if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
            //perror("set_opt error");
            return;
    }

    //write(fd,"ATD13631895627;\r",sizeof("ATD13631895627;\r"));
    sleep(1);

    ::close(fd);
}
void administrater::on_name6PushButton_clicked()
{
    int fd;
    int i;

    flag6=!flag6;
    if(flag6)
    {
        name6Button->setIcon(QPixmap("image/name6.jpg"));
        name6Button->setIconSize(QPixmap("image/name6.jpg").size());

    }
    else
    {
        name6Button->setIcon(QPixmap("image/name66.jpg"));
        name6Button->setIconSize(QPixmap("image/name66.jpg").size());
        if(( fd=open_port(fd,1)) < 0){
                //perror("open_port error");
                return;
        }

        if(( i=set_opt(fd,9600,8,'N',1) ) < 0){
                //perror("set_opt error");
                return;
        }

        write(fd,"ATD13428283495;\r",sizeof("ATD13428283495;\r"));
        sleep(1);

        ::close(fd);

    }

}

/*
void administrater::on_bellPushButton_clicked()
{
    system("/usr/bin/madplay /opt/qt-4.5/bin/mp3/bell.mp3");
}
*/

void administrater::back()
{
    this->close();
}
