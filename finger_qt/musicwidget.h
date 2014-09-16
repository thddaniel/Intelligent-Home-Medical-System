#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QtGui>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/soundcard.h>//声卡头文件
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <QTextStream>
#include <QTextCodec>
#include <unistd.h>
#include <QPushButton>
#include <QThread>

class MusicWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MusicWidget(QWidget *parent = 0);
    QLabel *volumelabel1;
    QLabel *volumelabel2;
    QLabel *timelable;
    QSlider *volume;
    QLabel *volstatus;
    QToolButton *mute;
    int  mixer_fd;
    int mute_state;
    QProcess *madpalyerProcess;
protected:
    void paintEvent(QPaintEvent *event);
    QStringList CurrentSong;
    QStringList PlayList;
    QStringList OldPlist;
private:
    QPoint dragPosition;
    QTimer *MusicTime;

public slots:
    void volume_change(int value);
    void mute_on_off();
    void on_PlayButton_clicked();
    void on_StopButton_clicked();
    void on_NextSongButton_clicked();
    void on_UpdateListButton_clicked();
    void on_PrevButton_clicked();
    void on_Debug();
private:
    QToolButton *PlayButton;
    QToolButton *StopButton;
    QToolButton *PrevButton;
    QToolButton *NextSongButton;
    QToolButton *UpdateListButton;
    QToolButton *CloseButton;
    QLabel *MusicTitleLabe;
    QPixmap ArtistPic;
};

#endif // MUSICWIDGET_H
