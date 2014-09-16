/*  说明：显示图表折线图 （未完成）
 */

#include "chart.h"
#include "ui_chart.h"

chart::chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chart)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
    setGeometry(0,0,480,272);
    QPixmap testBackGroundPixmap;
    testBackGroundPixmap.load("image/chart.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(testBackGroundPixmap));
    this->setPalette(palette);

    BackButton = new QPushButton(this);
    BackButton->setIcon(QPixmap("image/back.jpg"));
    BackButton->setIconSize(QPixmap("image/back.jpg").size());
    BackButton->setGeometry(435,245,39,25);
    connect(BackButton,SIGNAL(clicked()),this,SLOT(back()));
}

chart::~chart()
{
    delete ui;
}

void chart::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void chart::back()
{
    this->close();
}
