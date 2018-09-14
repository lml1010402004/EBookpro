#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>
#include<QProcess>
#include<QCoreApplication>
#include<QDebug>
#include<QApplication>
#include<signal.h>

QString str;
MainWindow::MainWindow(QWidget *parent,char *arg[]) :
    QDialog(parent)
{
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);
    flag_shutdown = false;
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedHeight(FIXED_HEIGHT);
    this->setFixedWidth(FIXED_WIDTH);
    for(int i=0;i<sizeof(arg);i++){
        str.append(arg[i]);
    }
    if(str.contains("ShutDownMachine")){
        flag_shutdown = true;
    }
    m_workTimer = new QTimer(this);
    connect(m_workTimer, SIGNAL(timeout()), this, SLOT(HanderSleep()));
    m_workTimer->start(WORK_TIMER_OUT);
    init();
}

MainWindow::~MainWindow()
{
    delete m_workTimer,painter;
    m_workTimer = NULL;
    painter = NULL;

}


void MainWindow::paintEvent(QPaintEvent *event)
{

    painter = new QPainter(this);
    rect.setRect(0,0,600,800);
    painter->fillRect(rect,QBrush(Qt::white));


    drawBackground();
    delete painter;
    painter = NULL;
}

void MainWindow::drawBackground()
{
    if(flag_shutdown){
        if(setting->getLanguage().contains("Chinese")){
            pixmap.load(":/pic/pics/sleep_bg22_cn.png");
        }else{
            pixmap.load(":/pic/pics/sleep_bg22.png");
        }
    }else{
        //here we need changing the UI .
        int index=setting->getWallPaper();
        switch (index) {
        case 0:
            if(setting->getLanguage().contains("Chinese")){
                pixmap.load(":/pic/pics/sleep_bg2_cn.png");
            }else{
                pixmap.load(":/pic/pics/sleep_bg2.png");
            }
            break;
        case 1:
            if(setting->getLanguage().contains("Chinese")){
                pixmap.load(":/pic/pics/sleep_bg3_cn.png");
            }else{
                pixmap.load(":/pic/pics/sleep_bg3.png");
            }
            break;
        case 2:
            if(setting->getLanguage().contains("Chinese")){
                pixmap.load(":/pic/pics/slee_bg4_cn.png");
            }else{
                pixmap.load(":/pic/pics/sleep_bg4.png");
            }
            break;
        default:
            break;
        }


    }
    painter->drawPixmap(0,0,FIXED_WIDTH,FIXED_HEIGHT,pixmap);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key_value = event->key();
    switch(key_value){
    case Qt::Key_PowerDown:
        //    m_lcdbacklight.enableLight();
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);
        kill(getpid(),100);
        this->close();
        exit(0);
        break;

    }

}

void MainWindow::init()
{
    setting = new SysSettings;

}


void MainWindow::HanderSleep()
{
    if(str.contains("ShutDownMachine")){//=="ShutDownMachine"

        QProcess::execute("poweroff");
    }else{
        sleep(1);
        flag_shutdown = false;
        m_workTimer->stop();
        //    m_lcdbacklight.disableLight();

        QFile powerFile("/sys/power/state");
        if(!powerFile.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            qDebug() << "Open power state file failed!";
            return;
        }

        QString value("mem");

        qDebug() << "cmd=" << value << endl;
        qDebug() << "cmd=" << value << endl;

        QTextStream valueOutput(&powerFile);
        valueOutput << value << endl;
        powerFile.close();
    }
}
