#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);
    MainWindow w;
    w.show();

    return a.exec();
}
