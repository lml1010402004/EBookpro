#include "mydialog.h"
#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //===中文翻译
        QTranslator tsor;           //创建翻译器
        tsor.load(":/pics/MTPServiceEng.qm");    //加载语言包
        a.installTranslator(&tsor); //安装翻译器


    MyDialog w;
    w.show();

    return a.exec();
}
