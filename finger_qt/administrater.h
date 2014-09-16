#ifndef ADMINISTRATER_H
#define ADMINISTRATER_H

#include <QtGui/QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QTextCodec>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <QtGui>

class administrater : public QWidget
{
    Q_OBJECT

public:
    administrater(QWidget *parent = 0);
    ~administrater();

     unsigned char numL,numH;

     int flag1,flag2,flag3,flag4,flag5,flag6;
private:
    QVBoxLayout *layoutkey;
    QWidget *verticalwidget;
    QHBoxLayout *mainLayout;

    QLabel *resultlabel;
    QLineEdit *resultLineEdit;
    QPushButton *IncreaseButton;
    QPushButton *DecreaseButton;

    QLabel *showlabel;
    QPushButton *name1Button;
    QPushButton *name2Button;
    QPushButton *name3Button;
    QPushButton *name4Button;
    QPushButton *name5Button;
    QPushButton *name6Button;
    //QPushButton *bellButton;
    QPushButton *BackButton;

private slots:
    void on_increasefingerPushButton_clicked();
    void on_decreasefingerPushButton_clicked();

    void on_name1PushButton_clicked();
    void on_name2PushButton_clicked();
    void on_name3PushButton_clicked();
    void on_name4PushButton_clicked();
    void on_name5PushButton_clicked();
    void on_name6PushButton_clicked();
   // void on_bellPushButton_clicked();
    void back();
};

#endif // ADMINISTRATER_H
