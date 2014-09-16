#ifndef INPUT_H
#define INPUT_H

#include <QWidget>
#include <QLabel>
#include <QSlider>
#include <QtGui>
#include <QTextStream>
#include <QTextCodec>
#include <QPushButton>
#include <QLineEdit>
#include <QtSql>


class InPut : public QWidget
{
    Q_OBJECT
public:
    explicit InPut(QWidget *parent = 0);

    QString KeyValue;    
    QLineEdit *KeyEdit;
 //   QLineEdit *HzEdit;
    QString strHanZ;

    QToolButton *key_del;
    QToolButton *key_down;
    QToolButton *key_up;
    QToolButton *SelectOk;
    QToolButton *closeit;

    QHBoxLayout *layoutkey_1;
    QHBoxLayout *layoutkey_2;
    QHBoxLayout *layoutkey_3;
    QHBoxLayout *layoutkey_4;
    QHBoxLayout *layoutkey_5;
    QVBoxLayout *mainLayout;
/*public slots:
    void showNormal();*/
signals:
    void SentHanz();
    void SentNum();

private slots:
    /*****************/
    void Press_A();
    void Press_B();
    void Press_C();
    void Press_D();
    void Press_E();
    void Press_F();
    void Press_G();
    void Press_H();
    void Press_I();
    void Press_J();
    void Press_K();
    void Press_L();
    void Press_M();
    void Press_N();
    void Press_O();
    void Press_P();
    void Press_Q();
    void Press_R();
    void Press_S();
    void Press_T();
    void Press_U();
    void Press_V();
    void Press_W();
    void Press_X();
    void Press_Y();
    void Press_Z();

    void Press_0();
    void Press_1();
    void Press_2();
    void Press_3();
    void Press_4();
    void Press_5();
    void Press_6();
    void Press_7();
    void Press_8();
    void Press_9();


    void Select_HzDis_1();
    void Select_HzDis_2();
    void Select_HzDis_3();
    void Select_HzDis_4();
    void Select_HzDis_5();
    void Select_HzDis_6();
    void Select_HzDis_7();
    void Select_HzDis_8();
    void Select_HzDis_9();
    void Select_HzDis_10();

    void SelectOK();

    void Press_del();
    void Press_down();
    void Press_up();
    void showNormal();
    void closeitclicked();
    /*****************/
private:
    QPushButton *key_A;
    QPushButton *key_B;
    QPushButton *key_C;
    QPushButton *key_D;
    QPushButton *key_E;
    QPushButton *key_F;
    QPushButton *key_G;
    QPushButton *key_H;
    QPushButton *key_I;
    QPushButton *key_J;
    QPushButton *key_K;
    QPushButton *key_L;
    QPushButton *key_M;
    QPushButton *key_N;
    QPushButton *key_O;
    QPushButton *key_P;
    QPushButton *key_Q;
    QPushButton *key_R;
    QPushButton *key_S;
    QPushButton *key_T;
    QPushButton *key_U;
    QPushButton *key_V;
    QPushButton *key_W;
    QPushButton *key_X;
    QPushButton *key_Y;
    QPushButton *key_Z;


    QPushButton *juhao;
    QPushButton *douhao;

    QPushButton *key_0;
    QPushButton *key_1;
    QPushButton *key_2;
    QPushButton *key_3;
    QPushButton *key_4;
    QPushButton *key_5;
    QPushButton *key_6;
    QPushButton *key_7;
    QPushButton *key_8;
    QPushButton *key_9;


    QPushButton *HzDis_1;
    QPushButton *HzDis_2;
    QPushButton *HzDis_3;
    QPushButton *HzDis_4;
    QPushButton *HzDis_5;
    QPushButton *HzDis_6;
    QPushButton *HzDis_7;
    QPushButton *HzDis_8;
    QPushButton *HzDis_9;
    QPushButton *HzDis_10;

    void SeaechHanDB();
    void DisPlay();
    QString *HanzBuff;
    int Pos;
    bool m_isEnglish;
};

#endif // INPUT_H
