#include <QtGui/QApplication>
#include "opendoor.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QFont font("wenquanyi",13,QFont::Bold);
    a.setFont(font);
    opendoor w;
    w.resize(480,272);
    w.show();
    return a.exec();
}
