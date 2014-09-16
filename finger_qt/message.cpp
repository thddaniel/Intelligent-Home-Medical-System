/*  说明：短信界面
 *  功能：打开键盘，可输入电话号码 ，并且可以显示短信内容 然后通过GPRS发送到指定的电话号码上
 *
 */
#include "message.h"
#include <string.h>
#include<QString>

Message::Message(QWidget *parent)
    : QWidget(parent)
{
    //this->setMinimumSize(480,122);
    //this->setMaximumSize(480,122);
    this->setGeometry(0,0,480,272);
    this->setWindowFlags( Qt::FramelessWindowHint);

    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background1.jpg");

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);

    telnum = new QLineEdit(this);
    telnum->setGeometry(40,10,150,30);

    mescontent = new QTextEdit(this);
    mescontent->setGeometry(250,10,200,90);

    pushButtonTdel = new QPushButton(this);
    pushButtonTdel->setIcon(QPixmap("image/del1.jpg"));
    pushButtonTdel->setIconSize(QPixmap("image/del1.jpg").size());
    pushButtonTdel->setGeometry(195,15,34,20);
    connect(pushButtonTdel,SIGNAL(clicked()),this,SLOT(shuziback()));

    pushButtonMdel = new QPushButton(this);
    pushButtonMdel->setIcon(QPixmap("image/del1.jpg"));
    pushButtonMdel->setIconSize(QPixmap("image/del1.jpg").size());
    pushButtonMdel->setGeometry(415,105,34,20);
    connect(pushButtonMdel,SIGNAL(clicked()),this,SLOT(zimuback()));

    pushButtonSend = new QPushButton(this);
    pushButtonSend->setIcon(QPixmap("image/send2.jpg"));
    pushButtonSend->setIconSize(QPixmap("image/send2.jpg").size());
    pushButtonSend->setGeometry(40,63,64,34);
    connect(pushButtonSend,SIGNAL(clicked()),this,SLOT(send()));

    pushButtonExit = new QPushButton(this);
    pushButtonExit->setIcon(QPixmap("image/back.jpg"));
    pushButtonExit->setIconSize(QPixmap("image/back.jpg").size());
    pushButtonExit->setGeometry(435,245,39,25);
    connect(pushButtonExit,SIGNAL(clicked()),this,SLOT(exit()));


    Input = new InPut(this);
    Input->setWindowModality(Qt::WindowModal);
    //Input->showNormal();
    //Input->show();
    Input->close();
    connect(telnum,SIGNAL(selectionChanged()),Input,SLOT(showNormal()));          //选中telnum出现键盘
    connect(Input,SIGNAL(SentNum()),this,SLOT(EditTelnum()));

    connect(mescontent,SIGNAL(selectionChanged()),Input,SLOT(showNormal()));      //选中mescontent出现键盘
    connect(Input,SIGNAL(SentHanz()),this,SLOT(EditMescontent()));

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
    //延时设置，我们设置为延时1s,
    myCom->open(QIODevice::ReadWrite);
}


Message::~Message()
{

}


void Message::EditTelnum()
{
    telnum->setText(Input->strHanZ);
//  Input->strHanZ.clear();
}


void Message::EditMescontent()
{
    mescontent->setText(Input->strHanZ);
//  Input->strHanZ.clear();
}


void Message::send(){
    if(this->mescontent->toPlainText()=="")
    {
        QMessageBox::information(this,tr("错误"),tr("短信内容不能为空"));
        return;
    }

    if(telnum->text()=="")
    {
        QMessageBox::information(this,tr("错误"),tr("电话号码不能为空"));
        return;
    }
    else
    {   
      QMessageBox::information(this,tr("是否确认发送"),"yes");
      contentdecode();
      //qDebug()<<content;

      ReventPhone();
      SendMsg(phone,content);
     }
}


void Message::zimuback()
{
    QString text=mescontent->toPlainText();
    text.chop(1);
    mescontent->setText(text);
}


void Message::shuziback()
{
    QString text=telnum->text();
    text.chop(1);
    telnum->setText(text);
}


void Message::exit()
{
    this->close();
}


void Message::ReventPhone()  //电话号码转格式，原：15913236869；转后：5119236368f9
{
   char count=0,i,tmp;
   char buff[40]={'\0'};

    bzero(phone,40);

   strcpy(buff,telnum->text().toLatin1().data());

    char *ch=buff;

   if(buff[0]=='1')  //前面要加86
   {
      phone[0]='8';
      phone[1]='6';
      count=2;
   }

   while(*ch)
   {
      phone[count]=*ch++;
      count++;
   }

   if(count%2)   //奇数位要加F
        phone[count]='f';
   for(i=0;i<count;i+=2)  //奇偶位对调
   {
        tmp=phone[i];
        phone[i]=phone[i+1];
        phone[i+1]=tmp;
   }
}


void Message::contentdecode()  //把中文转成unicode编码
{
    int tempint,temp1,temp2,temp3,temp4;
    char *ch=content;
    bzero(content,600);
    QString str=mescontent->toPlainText();
    for(int i=0;i<str.length();i++)
    {
        tempint=str[i].unicode();
        temp1=(tempint&0xF000)>>12;
        if(temp1>9)
            *(ch++)=temp1-10+'A';
        else
            *(ch++)=temp1+'0';

        temp2=(tempint&0x0F00)>>8;
        if(temp2>9)
            *(ch++)=temp2-10+'A';
        else
            *(ch++)=temp2+'0';

        temp3=(tempint&0x00F0)>>4;
        if(temp3>9)
            *(ch++)=temp3-10+'A';
        else
            *(ch++)=temp3+'0';

        temp4=tempint&0x000F;
        if(temp4>9)
            *(ch++)=temp4-10+'A';
        else
            *(ch++)=temp4+'0';
    }
}


void Message::SendMsg(char *buff,char *buff1)   //发送中文短信
{
  char send[600] ;
  char message[600]={'\0'};
  int len1,len2;
  char len[10]={'\0'};
  char cmgs[20];
  char head[] = "0011000D91"; 
  char phoafter[] ="000801";

  len1= strlen(buff1);
  len1 /=2;
  len2 = len1+15;
  sprintf(cmgs,"AT+CMGS=0%d\r",len2);

  myCom->write("AT+CMGF=0\r");
  sleep(2);
  myCom->write(cmgs);
  sleep(2);

  strcpy(send,head);

  strcat(send,buff);
  strcat(send,phoafter);

  sprintf(len,"0%d",len1);
  strcat(send,len);
  
  sprintf(message,"%s\x1A",buff1);
  strcat(send,message);
  
  myCom->write(send);
  sleep(2);
  myCom->flush();  //clear all data
  return;
}
