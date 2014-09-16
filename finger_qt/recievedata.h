#ifndef RECIEVEDATA_H
#define RECIEVEDATA_H

#include<QWidget>
#include <QtGui>
#include "posix_qextserialport.h"
#include "chart.h"
namespace Ui {
    class recievedata;
}

class recievedata : public QWidget {
    Q_OBJECT
public:
    recievedata(QWidget *parent = 0);
    ~recievedata();
protected:


private:
    Ui::recievedata *ui;
    Posix_QextSerialPort *myCom2;

    friend class chart;
    chart *Chart;

    QTimer *readTimer;
    //QByteArray control_data2;
    QLabel  *wdlabel;
    QLabel  *sdlabel;
    QLabel  *chaobiaolabel;
    QLabel  *shuibiaolabel;
    QLabel  *dianbiaolabel;
    QLabel  *meiqilabel;

    QLabel  *rilabel;
    QLabel  *zhoulabel;
    QLabel  *yuelabel;


    QPushButton *BackButton;
    QLineEdit *lineEdit_wd;
    QLineEdit *lineEdit_sd;

private slots:
     void ReadCom();
     void back();

};

#endif // RECIEVEDATA_H
