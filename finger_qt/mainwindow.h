#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QMainWindow>
#include <QtGui>
#include <QTimer>
#include <stdio.h>
#include <QString>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <error.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <QDebug>

#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

#include "administrater.h"
#include "telwidget.h"
#include "furniture.h"
#include "musicwidget.h"
#include "message.h"
#include "posix_qextserialport.h"
#include "recievedata.h"
#include "uart.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
     Ui::MainWindow *ui;
      /*两种方法定义*/
     //////////////////////////
     administrater Administrater;
     TelWidget telWidget;
     furniture Furniture;
     uart Uart;

     friend class MusicWidget;
     MusicWidget *Musicwidget;

     friend class Message;
     Message *message;

     friend class recievedata;
     recievedata *Recievedata;

     ///////////////////////////

     /* 系统管理 */
      QPushButton *AdministraterButton;
    /* 手机界面拨号 */
      QPushButton *PhoneButton;
      /* 家电控制 */
      QPushButton *furnitureButton;
      /*播放音乐*/
      QPushButton *MusicButton;
       /*发送短信*/
      QPushButton *MessageButton;
      /* 实时监控 */
       QPushButton *dataButton;

      QPushButton *BackButton;

       QPushButton *uartButton;


 private slots:
     void on_AdministraterButton_clicked();
     void on_PhoneButton_clicked();
     void on_furnitureButton_clicked();
     //void on_dataButton_clicked();


     void back();
     void on_uartButton_clicked();
};

#endif // MAINWINDOW_H
