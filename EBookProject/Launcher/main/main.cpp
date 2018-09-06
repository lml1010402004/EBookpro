#include"HomePage/mainwindow.h"
#include<QApplication>


int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);
    MainWindow w;
    w.show();

    return app.exec();

}
