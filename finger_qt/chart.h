#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QtGui>
namespace Ui {
    class chart;
}

class chart : public QWidget {
    Q_OBJECT
public:
    chart(QWidget *parent = 0);
    ~chart();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::chart *ui;
    QPushButton *BackButton;
private slots:

    void back();
};

#endif // CHART_H
