#ifndef UART_H
#define UART_H

#include <QWidget>
#include <QtGui>
#include "posix_qextserialport.h"
namespace Ui {
    class uart;
}

class uart : public QWidget {
    Q_OBJECT
public:
    uart(QWidget *parent = 0);
    ~uart();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::uart *ui;
    Posix_QextSerialPort *myCom2;
    QTimer *readTimer;
    QByteArray control_data2;
    QPushButton *BackButton;
private slots:
     void ReadCom();
     void back();
};

#endif // UART_H
