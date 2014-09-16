/*  说明：输入法
 *  功能：现实一个键盘，调用数据库打开HanzDB.db字库。实现 发短信且中英文转换
 *
 */
#include "input.h"

InPut::InPut(QWidget *parent) :
    QWidget(parent)
{
    this->setMinimumSize(480,150);
    this->setMaximumSize(480,150);
    //this->setWindowTitle(tr("心月输入法"));
    //this->move(100,100);
    this->setGeometry(0,120,480,150);
    this->setWindowFlags( Qt::FramelessWindowHint);

    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/background11.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);


    m_isEnglish = false;
    HanzBuff = new QString;
    Pos=0;

    key_del = new QToolButton;
    key_del->setIcon(QPixmap("image/del.png"));
    key_del->setIconSize(QPixmap("image/del.png").size());
    key_del->setAutoRaise(TRUE);
    connect(key_del,SIGNAL(clicked()),this,SLOT(Press_del()));  //删除

    key_down = new QToolButton;
    key_down->setIcon(QPixmap("image/down.png"));
    key_down->setIconSize(QPixmap("image/down.png").size());
    key_down->setAutoRaise(TRUE);
    connect(key_down,SIGNAL(clicked()),this,SLOT(Press_down())); //字库向上翻页

    key_up = new QToolButton;
    key_up->setIcon(QPixmap("image/up.png"));
    key_up->setIconSize(QPixmap("image/up.png").size());
    key_up->setAutoRaise(TRUE);
    connect(key_up,SIGNAL(clicked()),this,SLOT(Press_up()));    //字库向下翻页

    closeit = new QToolButton;
    closeit->setIcon(QPixmap("image/cha.jpg"));
    closeit->setIconSize(QPixmap("image/cha.jpg").size());
    closeit->setAutoRaise(TRUE);
    connect(closeit,SIGNAL(clicked()),this,SLOT(closeitclicked())); //关闭键盘

    SelectOk = new QToolButton;
    connect(SelectOk,SIGNAL(clicked()),this,SLOT(SelectOK()));
    KeyEdit = new QLineEdit;
//  HzEdit = new QLineEdit;

    HzDis_1 = new QPushButton(tr("心"));
    HzDis_2 = new QPushButton(tr("月"));
    HzDis_3 = new QPushButton(tr("输"));
    HzDis_4 = new QPushButton(tr("入"));
    HzDis_5 = new QPushButton(tr("法"));
    HzDis_6 = new QPushButton(tr("By"));
    HzDis_7 = new QPushButton(tr("-"));
    HzDis_8 = new QPushButton(tr("-"));
    HzDis_9 = new QPushButton(tr("唐"));
    HzDis_10 = new QPushButton(tr("昊"));
    HanzBuff->append(tr("心月输入法--唐昊"));

    connect(HzDis_1,SIGNAL(clicked()),this,SLOT(Select_HzDis_1()));
    connect(HzDis_2,SIGNAL(clicked()),this,SLOT(Select_HzDis_2()));
    connect(HzDis_3,SIGNAL(clicked()),this,SLOT(Select_HzDis_3()));
    connect(HzDis_4,SIGNAL(clicked()),this,SLOT(Select_HzDis_4()));
    connect(HzDis_5,SIGNAL(clicked()),this,SLOT(Select_HzDis_5()));
    connect(HzDis_6,SIGNAL(clicked()),this,SLOT(Select_HzDis_6()));
    connect(HzDis_7,SIGNAL(clicked()),this,SLOT(Select_HzDis_7()));
    connect(HzDis_8,SIGNAL(clicked()),this,SLOT(Select_HzDis_8()));
    connect(HzDis_9,SIGNAL(clicked()),this,SLOT(Select_HzDis_9()));
    connect(HzDis_10,SIGNAL(clicked()),this,SLOT(Select_HzDis_10()));

    key_0  = new QPushButton();
    key_0->setIcon(QPixmap("image/00.jpg"));
    key_0->setIconSize(QPixmap("image/00.jpg").size());
    key_0->setFixedSize(40,25);

    key_1  = new QPushButton();
    key_1->setIcon(QPixmap("image/11.jpg"));
    key_1->setIconSize(QPixmap("image/11.jpg").size());
    key_1->setFixedSize(40,25);

    key_2  = new QPushButton();
    key_2->setIcon(QPixmap("image/22.jpg"));
    key_2->setIconSize(QPixmap("image/22.jpg").size());
    key_2->setFixedSize(40,25);

    key_3  = new QPushButton();
    key_3->setIcon(QPixmap("image/33.jpg"));
    key_3->setIconSize(QPixmap("image/33.jpg").size());
    key_3->setFixedSize(40,25);

    key_4  = new QPushButton();
    key_4->setIcon(QPixmap("image/44.jpg"));
    key_4->setIconSize(QPixmap("image/44.jpg").size());
    key_4->setFixedSize(40,25);

    key_5  = new QPushButton();
    key_5->setIcon(QPixmap("image/55.jpg"));
    key_5->setIconSize(QPixmap("image/55.jpg").size());
    key_5->setFixedSize(40,25);

    key_6  = new QPushButton();
    key_6->setIcon(QPixmap("image/66.jpg"));
    key_6->setIconSize(QPixmap("image/66.jpg").size());
    key_6->setFixedSize(40,25);

    key_7  = new QPushButton();
    key_7->setIcon(QPixmap("image/77.jpg"));
    key_7->setIconSize(QPixmap("image/77.jpg").size());
    key_7->setFixedSize(40,25);

    key_8  = new QPushButton();
    key_8->setIcon(QPixmap("image/88.jpg"));
    key_8->setIconSize(QPixmap("image/88.jpg").size());
    key_8->setFixedSize(40,25);

    key_9  = new QPushButton();
    key_9->setIcon(QPixmap("image/99.jpg"));
    key_9->setIconSize(QPixmap("image/99.jpg").size());
    key_9->setFixedSize(40,25);


    key_A  = new QPushButton();
    key_A->setIcon(QPixmap("image/A.jpg"));
    key_A->setIconSize(QPixmap("image/A.jpg").size());
    key_A->setFixedSize(40,25);

    key_B  = new QPushButton();
    key_B->setIcon(QPixmap("image/B.jpg"));
    key_B->setIconSize(QPixmap("image/B.jpg").size());
    key_B->setFixedSize(40,25);

    key_C  = new QPushButton();
    key_C->setIcon(QPixmap("image/C.jpg"));
    key_C->setIconSize(QPixmap("image/C.jpg").size());
    key_C->setFixedSize(40,25);

    key_D  = new QPushButton();
    key_D->setIcon(QPixmap("image/D.jpg"));
    key_D->setIconSize(QPixmap("image/D.jpg").size());
    key_D->setFixedSize(40,25);

    key_E  = new QPushButton();
    key_E->setIcon(QPixmap("image/E.jpg"));
    key_E->setIconSize(QPixmap("image/E.jpg").size());
    key_E->setFixedSize(40,25);

    key_F  = new QPushButton();
    key_F->setIcon(QPixmap("image/F.jpg"));
    key_F->setIconSize(QPixmap("image/F.jpg").size());
    key_F->setFixedSize(40,25);

    key_G  = new QPushButton();
    key_G->setIcon(QPixmap("image/G.jpg"));
    key_G->setIconSize(QPixmap("image/G.jpg").size());
    key_G->setFixedSize(40,25);

    key_H  = new QPushButton();
    key_H->setIcon(QPixmap("image/H.jpg"));
    key_H->setIconSize(QPixmap("image/H.jpg").size());
    key_H->setFixedSize(40,25);

    key_I  = new QPushButton();
    key_I->setIcon(QPixmap("image/I.jpg"));
    key_I->setIconSize(QPixmap("image/I.jpg").size());
    key_I->setFixedSize(40,25);

    key_J  = new QPushButton();
    key_J->setIcon(QPixmap("image/J.jpg"));
    key_J->setIconSize(QPixmap("image/J.jpg").size());
    key_J->setFixedSize(40,25);

    key_K  = new QPushButton();
    key_K->setIcon(QPixmap("image/K.jpg"));
    key_K->setIconSize(QPixmap("image/K.jpg").size());
    key_K->setFixedSize(40,25);

    key_L  = new QPushButton();
    key_L->setIcon(QPixmap("image/L.jpg"));
    key_L->setIconSize(QPixmap("image/L.jpg").size());
    key_L->setFixedSize(40,25);

    key_M  = new QPushButton();
    key_M->setIcon(QPixmap("image/M.jpg"));
    key_M->setIconSize(QPixmap("image/M.jpg").size());
    key_M->setFixedSize(40,25);

    key_N  = new QPushButton();
    key_N->setIcon(QPixmap("image/N.jpg"));
    key_N->setIconSize(QPixmap("image/N.jpg").size());
    key_N->setFixedSize(40,25);

    key_O  = new QPushButton();
    key_O->setIcon(QPixmap("image/O.jpg"));
    key_O->setIconSize(QPixmap("image/O.jpg").size());
    key_O->setFixedSize(40,25);

    key_P  = new QPushButton();
    key_P->setIcon(QPixmap("image/P.jpg"));
    key_P->setIconSize(QPixmap("image/P.jpg").size());
    key_P->setFixedSize(40,25);

    key_Q  = new QPushButton();
    key_Q->setIcon(QPixmap("image/Q.jpg"));
    key_Q->setIconSize(QPixmap("image/Q.jpg").size());
    key_Q->setFixedSize(40,25);

    key_R  = new QPushButton();
    key_R->setIcon(QPixmap("image/R.jpg"));
    key_R->setIconSize(QPixmap("image/R.jpg").size());
    key_R->setFixedSize(40,25);

    key_S  = new QPushButton();
    key_S->setIcon(QPixmap("image/S.jpg"));
    key_S->setIconSize(QPixmap("image/S.jpg").size());
    key_S->setFixedSize(40,25);

    key_T  = new QPushButton();
    key_T->setIcon(QPixmap("image/T.jpg"));
    key_T->setIconSize(QPixmap("image/T.jpg").size());
    key_T->setFixedSize(40,25);

    key_U  = new QPushButton();
    key_U->setIcon(QPixmap("image/U.jpg"));
    key_U->setIconSize(QPixmap("image/U.jpg").size());
    key_U->setFixedSize(40,25);

    key_V  = new QPushButton();
    key_V->setIcon(QPixmap("image/V.jpg"));
    key_V->setIconSize(QPixmap("image/V.jpg").size());
    key_V->setFixedSize(40,25);

    key_W  = new QPushButton();
    key_W->setIcon(QPixmap("image/W.jpg"));
    key_W->setIconSize(QPixmap("image/W.jpg").size());
    key_W->setFixedSize(40,25);

    key_X  = new QPushButton();
    key_X->setIcon(QPixmap("image/X.jpg"));
    key_X->setIconSize(QPixmap("image/X.jpg").size());
    key_X->setFixedSize(40,25);

    key_Y  = new QPushButton();
    key_Y->setIcon(QPixmap("image/Y.jpg"));
    key_Y->setIconSize(QPixmap("image/Y.jpg").size());
    key_Y->setFixedSize(40,25);

    key_Z  = new QPushButton();
    key_Z->setIcon(QPixmap("image/Z.jpg"));
    key_Z->setIconSize(QPixmap("image/Z.jpg").size());
    key_Z->setFixedSize(40,25);

    juhao  = new QPushButton();
    juhao->setIcon(QPixmap("image/juhao.jpg"));
    juhao->setIconSize(QPixmap("image/juhao.jpg").size());
    juhao->setFixedSize(40,25);

    douhao  = new QPushButton();
    douhao->setIcon(QPixmap("image/douhao.jpg"));
    douhao->setIconSize(QPixmap("image/douhao.jpg").size());
    douhao->setFixedSize(40,25);



    connect(key_A,SIGNAL(clicked()),this,SLOT(Press_A()));
    connect(key_B,SIGNAL(clicked()),this,SLOT(Press_B()));
    connect(key_C,SIGNAL(clicked()),this,SLOT(Press_C()));
    connect(key_D,SIGNAL(clicked()),this,SLOT(Press_D()));
    connect(key_E,SIGNAL(clicked()),this,SLOT(Press_E()));
    connect(key_F,SIGNAL(clicked()),this,SLOT(Press_F()));
    connect(key_G,SIGNAL(clicked()),this,SLOT(Press_G()));
    connect(key_H,SIGNAL(clicked()),this,SLOT(Press_H()));
    connect(key_I,SIGNAL(clicked()),this,SLOT(Press_I()));
    connect(key_J,SIGNAL(clicked()),this,SLOT(Press_J()));
    connect(key_K,SIGNAL(clicked()),this,SLOT(Press_K()));
    connect(key_L,SIGNAL(clicked()),this,SLOT(Press_L()));
    connect(key_M,SIGNAL(clicked()),this,SLOT(Press_M()));
    connect(key_N,SIGNAL(clicked()),this,SLOT(Press_N()));
    connect(key_O,SIGNAL(clicked()),this,SLOT(Press_O()));
    connect(key_P,SIGNAL(clicked()),this,SLOT(Press_P()));
    connect(key_Q,SIGNAL(clicked()),this,SLOT(Press_Q()));
    connect(key_R,SIGNAL(clicked()),this,SLOT(Press_R()));
    connect(key_S,SIGNAL(clicked()),this,SLOT(Press_S()));
    connect(key_T,SIGNAL(clicked()),this,SLOT(Press_T()));
    connect(key_U,SIGNAL(clicked()),this,SLOT(Press_U()));
    connect(key_V,SIGNAL(clicked()),this,SLOT(Press_V()));
    connect(key_W,SIGNAL(clicked()),this,SLOT(Press_W()));
    connect(key_X,SIGNAL(clicked()),this,SLOT(Press_X()));
    connect(key_Y,SIGNAL(clicked()),this,SLOT(Press_Y()));
    connect(key_Z,SIGNAL(clicked()),this,SLOT(Press_Z()));


    connect(key_0,SIGNAL(clicked()),this,SLOT(Press_0()));
    connect(key_1,SIGNAL(clicked()),this,SLOT(Press_1()));
    connect(key_2,SIGNAL(clicked()),this,SLOT(Press_2()));
    connect(key_3,SIGNAL(clicked()),this,SLOT(Press_3()));
    connect(key_4,SIGNAL(clicked()),this,SLOT(Press_4()));
    connect(key_5,SIGNAL(clicked()),this,SLOT(Press_5()));
    connect(key_6,SIGNAL(clicked()),this,SLOT(Press_6()));
    connect(key_7,SIGNAL(clicked()),this,SLOT(Press_7()));
    connect(key_8,SIGNAL(clicked()),this,SLOT(Press_8()));
    connect(key_9,SIGNAL(clicked()),this,SLOT(Press_9()));


     mainLayout = new QVBoxLayout(this);

    layoutkey_5 = new QHBoxLayout();
    layoutkey_5->setMargin(0);
    layoutkey_5->setSpacing(0);
    layoutkey_5->addWidget(HzDis_1);
    layoutkey_5->addWidget(HzDis_2);
    layoutkey_5->addWidget(HzDis_3);
    layoutkey_5->addWidget(HzDis_4);
    layoutkey_5->addWidget(HzDis_5);
    layoutkey_5->addWidget(HzDis_6);
    layoutkey_5->addWidget(HzDis_7);
    layoutkey_5->addWidget(HzDis_8);
    layoutkey_5->addWidget(HzDis_9);
    layoutkey_5->addWidget(HzDis_10);
    layoutkey_5->addWidget(key_down);
    layoutkey_5->addWidget(key_up);
    layoutkey_5->addWidget(closeit);

    layoutkey_4 = new QHBoxLayout();
    layoutkey_4->setMargin(0);
    layoutkey_4->setSpacing(0);
    layoutkey_4->addWidget(key_1);
    layoutkey_4->addWidget(key_2);
    layoutkey_4->addWidget(key_3);
    layoutkey_4->addWidget(key_4);
    layoutkey_4->addWidget(key_5);
    layoutkey_4->addWidget(key_6);
    layoutkey_4->addWidget(key_7);
    layoutkey_4->addWidget(key_8);
    layoutkey_4->addWidget(key_9);
    layoutkey_4->addWidget(key_0);


    layoutkey_1 =  new QHBoxLayout();
    layoutkey_1->setMargin(0);
    layoutkey_1->setSpacing(0);
    layoutkey_1->addWidget(key_Q);
    layoutkey_1->addWidget(key_W);
    layoutkey_1->addWidget(key_E);
    layoutkey_1->addWidget(key_R);
    layoutkey_1->addWidget(key_T);
    layoutkey_1->addWidget(key_Y);
    layoutkey_1->addWidget(key_U);
    layoutkey_1->addWidget(key_I);
    layoutkey_1->addWidget(key_O);
    layoutkey_1->addWidget(key_P);

    layoutkey_2 =  new QHBoxLayout();
    layoutkey_2->setMargin(0);
    layoutkey_2->setSpacing(0);
    layoutkey_2->addWidget(key_A);
    layoutkey_2->addWidget(key_S);
    layoutkey_2->addWidget(key_D);
    layoutkey_2->addWidget(key_F);
    layoutkey_2->addWidget(key_G);
    layoutkey_2->addWidget(key_H);
    layoutkey_2->addWidget(key_J);
    layoutkey_2->addWidget(key_K);
    layoutkey_2->addWidget(key_L);
    layoutkey_2->addWidget(key_del);

    layoutkey_3 =  new QHBoxLayout();
    layoutkey_3->setMargin(0);
    layoutkey_3->setSpacing(0);
    layoutkey_3->addWidget(key_Z);
    layoutkey_3->addWidget(key_X);
    layoutkey_3->addWidget(key_C);
    layoutkey_3->addWidget(key_V);
    layoutkey_3->addWidget(key_B);
    layoutkey_3->addWidget(key_N);
    layoutkey_3->addWidget(key_M);
    layoutkey_3->addWidget(juhao);
    layoutkey_3->addWidget(douhao);
    layoutkey_3->addWidget(SelectOk);

    mainLayout->addLayout(layoutkey_5);
    mainLayout->addLayout(layoutkey_4);
    mainLayout->addLayout(layoutkey_1);
    mainLayout->addLayout(layoutkey_2);
    mainLayout->addLayout(layoutkey_3);
}

void InPut::Press_A()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('a');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('a');
        emit SentHanz();
    }

}

void InPut::Press_B()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('b');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('b');
        emit SentHanz();
    }
}

void InPut::Press_C()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('c');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('c');
        emit SentHanz();
    }
}

void InPut::Press_D()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('d');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('d');
        emit SentHanz();
    }
}

void InPut::Press_E()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('e');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('e');
        emit SentHanz();
    }
}

void InPut::Press_F()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('f');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('f');
        emit SentHanz();
    }
}

void InPut::Press_G()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('g');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('g');
        emit SentHanz();
    }
}

void InPut::Press_H()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('h');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('h');
        emit SentHanz();
    }
}

void InPut::Press_I()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('i');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('i');
        emit SentHanz();
    }
}

void InPut::Press_J()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('j');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('j');
        emit SentHanz();
    }
}

void InPut::Press_K()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('k');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('k');
        emit SentHanz();
    }
}

void InPut::Press_L()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('l');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('l');
        emit SentHanz();
    }
}

void InPut::Press_M()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('m');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('m');
        emit SentHanz();
    }
}

void InPut::Press_N()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('n');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('n');
        emit SentHanz();
    }
}

void InPut::Press_O()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('o');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('o');
        emit SentHanz();
    }
}

void InPut::Press_P()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('p');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('p');
        emit SentHanz();
    }
}

void InPut::Press_Q()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('q');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('q');
        emit SentHanz();
    }
}

void InPut::Press_R()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('r');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('r');
        emit SentHanz();
    }
}

void InPut::Press_S()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('s');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('s');
        emit SentHanz();
    }
}

void InPut::Press_T()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('t');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('t');
        emit SentHanz();
    }
}

void InPut::Press_U()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('u');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('u');
        emit SentHanz();
    }
}

void InPut::Press_V()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('v');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('v');
        emit SentHanz();
    }
}

void InPut::Press_W()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('w');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('w');
        emit SentHanz();
    }
}

void InPut::Press_X()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('x');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('x');
        emit SentHanz();
    }
}

void InPut::Press_Y()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('y');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('y');
        emit SentHanz();
    }
}

void InPut::Press_Z()
{
    if(false == m_isEnglish)
    {
        this->KeyValue.append('z');
        KeyEdit->setText(KeyValue);
        DisPlay();
    }
    else
    {
        strHanZ.append('z');
        emit SentHanz();
    }
}

void InPut::Press_0()
{
    strHanZ.append('0');
    emit SentNum();
}

void InPut::Press_1()
{
    strHanZ.append('1');
    emit SentNum();
}

void InPut::Press_2()
{
    strHanZ.append('2');
    emit SentNum();
}

void InPut::Press_3()
{
    strHanZ.append('3');
    emit SentNum();
}

void InPut::Press_4()
{
    strHanZ.append('4');
    emit SentNum();
}

void InPut::Press_5()
{
    strHanZ.append('5');
    emit SentNum();
}

void InPut::Press_6()
{
    strHanZ.append('6');
    emit SentNum();
}

void InPut::Press_7()
{
    strHanZ.append('7');
    emit SentNum();
}

void InPut::Press_8()
{
    strHanZ.append('8');
    emit SentNum();
}

void InPut::Press_9()
{
    strHanZ.append('9');
    emit SentNum();
}

void InPut::Press_del()
{
    this->KeyValue.clear();
    HanzBuff->clear();
    HzDis_1->setText(tr(" "));
    HzDis_2->setText(tr(" "));
    HzDis_3->setText(tr(" "));
    HzDis_4->setText(tr(" "));
    HzDis_5->setText(tr(" "));
    HzDis_6->setText(tr(" "));
    HzDis_7->setText(tr(" "));
    HzDis_8->setText(tr(" "));
    HzDis_9->setText(tr(" "));
    HzDis_10->setText(tr(" "));
    KeyEdit->setText(this->KeyValue);
    Pos=0;
}

void InPut::Press_down()
{
    Pos++;
    int i=HanzBuff->size();
    for(;i<10*Pos+10;i++)
    {
        HanzBuff->append(" ");
    }
    HzDis_1->setText(HanzBuff->at(10*Pos+0));
    HzDis_2->setText(HanzBuff->at(10*Pos+1));
    HzDis_3->setText(HanzBuff->at(10*Pos+2));
    HzDis_4->setText(HanzBuff->at(10*Pos+3));
    HzDis_5->setText(HanzBuff->at(10*Pos+4));
    HzDis_6->setText(HanzBuff->at(10*Pos+5));
    HzDis_7->setText(HanzBuff->at(10*Pos+6));
    HzDis_8->setText(HanzBuff->at(10*Pos+7));
    HzDis_9->setText(HanzBuff->at(10*Pos+8));
    HzDis_10->setText(HanzBuff->at(10*Pos+9));
}

void InPut::Press_up()
{
    Pos--;
    if(Pos<0)
        Pos=0;
    int i=HanzBuff->size();
    for(;i<10*Pos+10;i++)
    {
        HanzBuff->append(" ");
    }
    HzDis_1->setText(HanzBuff->at(10*Pos+0));
    HzDis_2->setText(HanzBuff->at(10*Pos+1));
    HzDis_3->setText(HanzBuff->at(10*Pos+2));
    HzDis_4->setText(HanzBuff->at(10*Pos+3));
    HzDis_5->setText(HanzBuff->at(10*Pos+4));
    HzDis_6->setText(HanzBuff->at(10*Pos+5));
    HzDis_7->setText(HanzBuff->at(10*Pos+6));
    HzDis_8->setText(HanzBuff->at(10*Pos+7));
    HzDis_9->setText(HanzBuff->at(10*Pos+8));
    HzDis_10->setText(HanzBuff->at(10*Pos+9));
}

void InPut::SeaechHanDB()
{
    QSqlDatabase HanzDB;
    HanzDB = QSqlDatabase::addDatabase("QSQLITE");
    HanzDB.setDatabaseName("HanzDB.db");
    HanzBuff->clear();
    if (HanzDB.open() == true)
    {
        QSqlQuery query("SELECT * FROM zhcn WHERE py=:pinyin");
        query.bindValue(":pinyin",this->KeyValue);
        query.exec();
         while (query.next())
         {
             HanzBuff->append(query.value(2).toString());
         }
         query.clear();
    }
    HanzDB.removeDatabase(HanzDB.connectionName());
    HanzDB.close();
}

void InPut::DisPlay()
{
    SeaechHanDB();
    for(int i=HanzBuff->size()+1;i<11;i++)
    {
        HanzBuff->append(" ");
    }
    HzDis_1->setText(HanzBuff->at(0));
    HzDis_2->setText(HanzBuff->at(1));
    HzDis_3->setText(HanzBuff->at(2));
    HzDis_4->setText(HanzBuff->at(3));
    HzDis_5->setText(HanzBuff->at(4));
    HzDis_6->setText(HanzBuff->at(5));
    HzDis_7->setText(HanzBuff->at(6));
    HzDis_8->setText(HanzBuff->at(7));
    HzDis_9->setText(HanzBuff->at(8));
    HzDis_10->setText(HanzBuff->at(9));
}

void InPut::Select_HzDis_1()
{
    strHanZ.append(HanzBuff->at(10*Pos+0));
//    HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_2()
{
    strHanZ.append(HanzBuff->at(10*Pos+1));
//    HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_3()
{
    strHanZ.append(HanzBuff->at(10*Pos+2));
//    HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_4()
{
    strHanZ.append(HanzBuff->at(10*Pos+3));
//    HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_5()
{
    strHanZ.append(HanzBuff->at(10*Pos+4));
 //   HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_6()
{
    strHanZ.append(HanzBuff->at(10*Pos+5));
 //   HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_7()
{
    strHanZ.append(HanzBuff->at(10*Pos+6));
 //   HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_8()
{
    strHanZ.append(HanzBuff->at(10*Pos+7));
  //  HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_9()
{
    strHanZ.append(HanzBuff->at(10*Pos+8));
 //   HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::Select_HzDis_10()
{
    strHanZ.append(HanzBuff->at(10*Pos+9));
 //   HzEdit->setText(strHanZ);
    emit SentHanz();
    Press_del();
}

void InPut::SelectOK()/*中英文转换*/
{
      m_isEnglish = !m_isEnglish;
//    HzEdit->setText(strHanZ);
//    emit SentHanz();
//    strHanZ.clear();
//    this->hide();
}

void InPut::showNormal()
{
    strHanZ.clear();
    emit SentHanz();
    this->show();
}
void InPut::closeitclicked()
{

   this->close();
}

