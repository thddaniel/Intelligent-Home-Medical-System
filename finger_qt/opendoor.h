#ifndef OPENDOOR_H
#define OPENDOOR_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
    class opendoor;
}

class opendoor : public QWidget {
    Q_OBJECT
public:
    opendoor(QWidget *parent = 0);
    ~opendoor();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::opendoor *ui;
    MainWindow mainWindow;

    Posix_QextSerialPort *myCom2;
    QTimer *readTimer;
    QByteArray control_data2;

    QPushButton *doorButton;




 private slots:
    void on_doorButton_clicked();
    void ReadCom2();


};

#endif // OPENDOOR_H
