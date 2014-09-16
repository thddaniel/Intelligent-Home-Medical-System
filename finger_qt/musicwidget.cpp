/*  说明：音乐播放器界面
 *  功能：读取指定路径的音乐 可调节声音大小等
 *
 */
#include <QPalette>
#include "musicwidget.h"
#include <QThread>
#include <QLayout>
MusicWidget::MusicWidget(QWidget *parent) :
        QWidget(parent,Qt::FramelessWindowHint | Qt::WindowSystemMenuHint)

{
    mute_state = 0;
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    //setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    //setGeometry(0,0,480,272);
    /*QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background3.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);*/

    QPixmap pix;
    madpalyerProcess = new QProcess;
    pix.load("image/player_skin.png",0,Qt::AvoidDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(pix.mask());
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::red);

    volumelabel1=new QLabel(tr("Vol:"),this);
    volumelabel1->setPalette(palette);
    volumelabel1->setGeometry(208,138,48,16);
    volumelabel2=new QLabel(tr("10"),this);
    volumelabel2->setPalette(palette);
    volumelabel2->setGeometry(245,138,48,16);

    timelable = new QLabel(tr("00:00:00"),this);
    timelable->setPalette(palette);
    timelable->setGeometry(85,168,55,17);

    MusicTitleLabe = new QLabel(tr("更新播放列表"),this);
    MusicTitleLabe->setPalette(palette);
    MusicTitleLabe->setGeometry(QRect(110,203,500,17));//setGeometry(QRect(135,208,120,16))

    MusicTime = new QTimer(this);
    connect(MusicTime,SIGNAL(timeout()),this,SLOT(on_Debug()));
    MusicTime->start(1000);

     ArtistPic.load("image/fish.png");



    volume=new QSlider(this);
    volume->setOrientation(Qt::Vertical);
    volume->setRange(0,100);
    volume->setTickInterval(1);
    volume->setValue(10);
    volume->setBackgroundRole(QPalette::Window);
    volume->setGeometry(291,128,15,97);
    connect(volume,SIGNAL(valueChanged(int)),this,SLOT(volume_change(int)));

    mute=new QToolButton(this);
    mute->setIcon(QPixmap("image/Mute.png"));
    mute->setIconSize(QPixmap("image/Mute.png").size());
    mute->setAutoRaise(TRUE);
    mute->setGeometry(QRect(7,171,QPixmap("image/Mute.png").width(),QPixmap("image/Mute.png").height()));
    connect(mute,SIGNAL(clicked()),this,SLOT(mute_on_off()));


    volstatus = new QLabel(tr("停止"),this);
    volstatus->setPalette(palette);
    volstatus->setGeometry(QRect(88,150,51,17));//setGeometry(QRect(135,208,120,16))

///////////////////////////////////////////////////////////////////////////////////////////
    UpdateListButton = new QToolButton(this);
    UpdateListButton->setIcon(QPixmap("image/Update.png"));
    UpdateListButton->setIconSize(QPixmap("image/Update.png").size());
    UpdateListButton->setAutoRaise(TRUE);
    UpdateListButton->setGeometry(QRect(68,104,QPixmap("image/Update.png").width(),QPixmap("image/Update.png").height()));
    connect(UpdateListButton,SIGNAL(clicked()),this,SLOT(on_UpdateListButton_clicked()));

    PrevButton = new QToolButton(this);
    PrevButton->setIcon(QPixmap("image/Prev.png"));
    PrevButton->setIconSize(QPixmap("image/Prev.png").size());
    PrevButton->setAutoRaise(TRUE);
    PrevButton->setGeometry(QRect(106,104,QPixmap("image/Prev.png").width(),QPixmap("image/Prev.png").height()));
    connect(PrevButton,SIGNAL(clicked()),this,SLOT(on_PrevButton_clicked()));

    PlayButton = new QToolButton(this);
    PlayButton->setIcon(QPixmap("image/Play.png"));
    PlayButton->setIconSize(QPixmap("image/Play.png").size());
    PlayButton->setAutoRaise(TRUE);
    PlayButton->setGeometry(QRect(143,104,QPixmap("image/Play.png").width(),QPixmap("image/Play.png").height()));
    connect(PlayButton,SIGNAL(clicked()),this,SLOT(on_PlayButton_clicked()));

    NextSongButton = new QToolButton(this);
    NextSongButton->setIcon(QPixmap("image/Next.png"));
    NextSongButton->setIconSize(QPixmap("image/Next.png").size());
    NextSongButton->setAutoRaise(TRUE);
    NextSongButton->setGeometry(QRect(179,104,QPixmap("image/Next.png").width(),QPixmap("image/Next.png").height()));
    connect(NextSongButton,SIGNAL(clicked()),this,SLOT(on_NextSongButton_clicked()));

    StopButton = new QToolButton(this);
    StopButton->setIcon(QPixmap("image/Stop.png"));
    StopButton->setIconSize(QPixmap("image/Stop.png").size());
    StopButton->setAutoRaise(TRUE);
    StopButton->setGeometry(QRect(216,104,QPixmap("image/Stop.png").width(),QPixmap("image/Stop.png").height()));
    connect(StopButton,SIGNAL(clicked()),this,SLOT(close()));

/////////////////////////////////////////////////////////////////////////////////////////////

    CloseButton = new QToolButton(this);
    CloseButton->setIcon(QPixmap("image/Close.png"));
    CloseButton->setIconSize(QPixmap("image/Close.png").size());
    CloseButton->setAutoRaise(TRUE);
    CloseButton->setGeometry(QRect(264,205,QPixmap("image/Close.png").width(),QPixmap("image/Close.png").height()));
    connect(CloseButton,SIGNAL(clicked()),this,SLOT(on_StopButton_clicked()));
/////////////////////////////////////////////////////////////////////////////////////////////

}

void MusicWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("image/player_skin.png"));
    painter.drawPixmap(QRectF(142,133,ArtistPic.width()/ArtistPic.height()*67,67),ArtistPic,QRectF(0,0,ArtistPic.width(),ArtistPic.height()));
}

void MusicWidget::volume_change(int value)
{
    volumelabel2->setNum(value);
    mixer_fd=open("/dev/mixer",O_RDWR);
    ioctl(mixer_fd,MIXER_WRITE(0),&value);
    volumelabel1->show();
    volumelabel2->show();
}
void MusicWidget::mute_on_off()
{
    int value;
    value= volume->value();
    mixer_fd=open("/dev/mixer",O_RDWR);
    if(mute_state==0)
    {
        value=0;
        mute_state=1;
        ioctl(mixer_fd,MIXER_WRITE(0),&value);
        mute->setIcon(QPixmap("image/Mute_2.png"));
        mute->setIconSize(QPixmap("image/Mute_2.png").size());
        mute->setAutoRaise(TRUE);
        mute->setGeometry(QRect(7,171,QPixmap("image/Mute_2.png").width(),QPixmap("image/Mute_2.png").height()));
        volstatus->setText(tr("静音"));
    }
  else if(mute_state==1)
  {
    mute_state=0;
    ioctl(mixer_fd,MIXER_WRITE(0),&value);
    mute->setIcon(QPixmap("image/Mute.png"));
    mute->setIconSize(QPixmap("image/Mute.png").size());
    mute->setAutoRaise(TRUE);
    mute->setGeometry(QRect(7,171,QPixmap("image/Mute.png").width(),QPixmap("image/Mute.png").height()));
    volstatus->setText(tr("立体声"));
  }
}

//// Play Music
void MusicWidget::on_PlayButton_clicked()
{

    if(madpalyerProcess->state() == (QProcess::NotRunning))
    {
        const QString madplayerPath("/usr/bin/madplay");
        QStringList args;
        args<<"-qv";
        args<<CurrentSong;
        madpalyerProcess->setProcessChannelMode(QProcess::MergedChannels);
        madpalyerProcess->start(madplayerPath,args);
        PlayButton->setIcon(QPixmap("image/Play_2.png"));
        PlayButton->setIconSize(QPixmap("image/Play_2.png").size());
        PlayButton->setAutoRaise(TRUE);
        volstatus->setText(tr("立体声"));
    }
    else if(madpalyerProcess->state() != (QProcess::NotRunning))
    {
        system("killall -9 madplay");
        madpalyerProcess->close();
        PlayButton->setIcon(QPixmap("image/Play.png"));
        PlayButton->setIconSize(QPixmap("image/Play.png").size());
        PlayButton->setAutoRaise(TRUE);
        volstatus->setText(tr("停止"));
    }
}
/**********************************************/
/*********UpDate PlayList  Form SDCard *****/
/**********************************************/
void MusicWidget::on_UpdateListButton_clicked()
{
    QStringList files,filetype;
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    int num=0;
    filetype <<"*.mp3"<<"*.wav";
    PlayList.removeAll("*");
    QDir dir("/opt/qt-4.5/bin/");
    QFileInfo tempFileInfo;
    QProgressDialog progressDialog(this);
    progressDialog.setWindowModality(Qt::WindowModal);
    progressDialog.setMinimumDuration(10);
    QFileInfoList list=dir.entryInfoList(filetype,QDir::Files);
    progressDialog.setCancelButtonText(tr("&取消"));
    progressDialog.setRange(0, list.size());
    progressDialog.setWindowTitle(tr("更新播放列表"));

    for (int i = 0; i < list.size(); ++i)
    {
        progressDialog.setValue(i);
        tempFileInfo=list.at(i);
        num ++;
        files<<"/opt/qt-4.5/bin/"+tempFileInfo.fileName();//Add "mp3" and "wav" files to PlayList
        progressDialog.setLabelText(tr("找到 %1 of %2...").arg(num).arg(list.size()));
        if(progressDialog.wasCanceled())
            return ;

    }
    PlayList = files;
    CurrentSong<<PlayList;
    UpdateListButton->setIcon(QPixmap("image/Update_2.png"));
    UpdateListButton->setIconSize(QPixmap("image/Update_2.png").size());
    UpdateListButton->setAutoRaise(TRUE);
    MusicTitleLabe->setText(tr("更新完成"));
}

void MusicWidget::on_NextSongButton_clicked()
{
    if(madpalyerProcess->state() != (QProcess::NotRunning))
    {
        system("killall -9 madplay");
        madpalyerProcess->close();
    }
    if(CurrentSong. isEmpty() == false)
    {
        OldPlist.prepend(CurrentSong.at(0));
        CurrentSong.removeFirst();
        on_PlayButton_clicked();
    }
}

void MusicWidget::on_PrevButton_clicked()
{
    if(madpalyerProcess->state() != (QProcess::NotRunning))
    {
        system("killall -9 madplay");
        madpalyerProcess->close();
    }
    if(OldPlist.isEmpty() == false)
    {
        CurrentSong.prepend(OldPlist.at(0));
        OldPlist.removeFirst();
        if(madpalyerProcess->state() == (QProcess::NotRunning))
        {
            const QString madplayerPath("/usr/bin/madplay");
            madpalyerProcess->setProcessChannelMode(QProcess::MergedChannels);
            madpalyerProcess->start(madplayerPath,OldPlist);
            PlayButton->setIcon(QPixmap("image/Play_2.png"));
            PlayButton->setIconSize(QPixmap("image/Play_2.png").size());
            PlayButton->setAutoRaise(TRUE);
        }
        else if(madpalyerProcess->state() != (QProcess::NotRunning))
        {
            system("killall -9 madplay");
            madpalyerProcess->close();
            PlayButton->setIcon(QPixmap("image/Play.png"));
            PlayButton->setIconSize(QPixmap("image/Play.png").size());
            PlayButton->setAutoRaise(TRUE);
        }
    }
}
void MusicWidget::on_StopButton_clicked()
{
    if(madpalyerProcess->state() != (QProcess::NotRunning))
    {
        madpalyerProcess->terminate();
        madpalyerProcess->write("quit\n");
    }
    this->close();
}
void MusicWidget::on_Debug()
{
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::red);
    QByteArray result = madpalyerProcess->readAll();
    QTextCodec *codec = QTextCodec::codecForName("gb2312");
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));

    QString qstrTemp = QString(result);
    result = qstrTemp.mid(qstrTemp.indexOf("Title"), 45).toLocal8Bit();
    //debugCom->write(result);
    QString debugstring=codec->toUnicode(result);

    MusicTitleLabe->setPalette(pa);
    if(debugstring.size()>2)
    {
        if(debugstring.at(0)!='T')
            timelable->setText(debugstring);
        else
        {
            QString title="";
            for(int i=0;i<debugstring.size();i++)
            {
                if(debugstring.at(i)>0xff)
                    title+=debugstring.at(i);
            }
            MusicTitleLabe->setText(title);
        }
    }
    volumelabel1->hide();
    volumelabel2->hide();
}
