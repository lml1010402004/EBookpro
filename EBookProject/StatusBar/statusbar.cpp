#include "statusbar.h"
#include<QTime>
#include<QTimer>
#include<QDebug>
#include<QDateTime>
#include<QLineF>
#include<QApplication>

QString RECTANGEPATH =":/pic/pic/pull_rectangle_unpressed.png";
QString WIFIPATH =":/pic/pic/statusbar_wifi.png";
QString LEVEL0 =":/pic/pic/level0.png";
QString LEVEL1 = ":/pic/pic/level1.png";
QString LEVEL2 = ":/pic/pic/level2.png";
QString LEVEL3 = ":/pic/pic/level3.png";
QString LEVEL4 = ":/pic/pic/level4.png";
QString line = ":/pic/pic/line.png";



const int COUNTS = 12;

StatusBar::StatusBar(QWidget *widget):QMainWindow(widget)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedHeight(SCREEN_FIXED_WIDTH);
    this->setFixedHeight(SCREEN_FIXED_HEIGHT);
    syssetting = new SysSettings;


    //    QTimer *testTimer = new QTimer(this);
    //    //将定时器超时信号与槽(功能函数)联系起来
    //    QObject::connect(testTimer,SIGNAL(timeout()),this,SLOT(startMyTimer()));
    //    //开始运行定时器，定时时间间隔为1000ms
    //    testTimer->start(1000*60);
    //    startMyTimer();//第一次获取数值


}

StatusBar::~StatusBar()
{

}


/**
 * @brief commonUtils::getTheBatteryPercentage
 * @return
 */
int StatusBar::getTheBatteryPercentage()
{
    int fd = -1;
    fd= open("/sys/class/power_supply/battery/voltage_now",O_RDONLY);
    char rbuf[8]={'\0'};
    if(fd==-1){
        qDebug()<<"read the voltage fail"<<fd;
        return -1;
    }
    read(fd,&rbuf,8);
    QString str = QString(rbuf);
    str = str.mid(0,2);
    int temp = str.toInt(0,10);
    ::close(fd);//这个是c标准
    return temp;

}


/**
 * draw systemTime in statusBar
 * @brief StatusBar::drawSystemTime
 * @param painter
 */
void StatusBar::drawSystemTime(QPainter *painter,QString time)
{
    controlTheRefreshFrquency();
    font.setPixelSize(22);
    rect.setX(26);
    rect.setY(10);
    rect.setWidth(128);
    rect.setHeight(23);
    painter->setFont(font);
    painter->drawText(rect,Qt::AlignCenter,getTheCurrentTime());

}


/**
 * draw wifistatus in statusBar.
 * @brief StatusBar::drawWifiStatus
 * @param painter
 */
void StatusBar::drawWifiStatus(QPainter *painter,bool flag)
{
    QString mac = syssetting->getConnectWifiMac();
    if(mac.length()<2){
        return;
    }
    rect.setX(420);
    rect.setY(10);
    rect.setWidth(24);
    rect.setHeight(20);
    painter->drawPixmap(rect,WIFIPATH);
}


/**
 * draw battery Information in statusBar.
 * @brief StatusBar::drawBattery
 * @param painter
 */
void StatusBar::drawBattery(QPainter *painter,int percentage)
{

    int per = getTheBatteryPercentage();
    rect.setX(470);
    rect.setY(10);
    rect.setWidth(52);
    rect.setHeight(20);
    if(per<=35){
        painter->drawPixmap(rect,LEVEL0);
    }else if(per>35&&per<=37){
        painter->drawPixmap(rect,LEVEL1);
    }else if(per>37&&per<=39){
        painter->drawPixmap(rect,LEVEL2);
    }else if(per>39&&per<41){
        painter->drawPixmap(rect,LEVEL3);
    }else if(per>=41){
        painter->drawPixmap(rect,LEVEL4);
    }

}


/**
 * @brief StatusBar::drawPullDownRectangle
 * @param painter
 */
void StatusBar::drawPullDownRectangle(QPainter *painter)
{

    rect.setX(280);
    rect.setY(10);
    rect.setWidth(40);
    rect.setHeight(28);
    painter->drawPixmap(rect,RECTANGEPATH);
    rect.setX(0);
    rect.setY(40);
    rect.setWidth(600);
    rect.setHeight(2);
    painter->drawPixmap(rect,line);
}

QString StatusBar::getTheCurrentTime()
{
    QTime current_time = QTime::currentTime();

    QString str = QDateTime::currentDateTime().toString("MM-dd hh:mm");

    //    int hour = current_time.hour();
    //    int min = current_time.minute();
    //    QString hours = QString::number(hour,10);
    //    QString mins = QString::number(min,10);
    //    return QString(hours+":"+mins);
    return str;

}

void StatusBar::controlTheRefreshFrquency()
{
    int temp = syssetting->getRefreshCount();
    if(temp>COUNTS){
        syssetting->setRefreshCount(0);
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_MODE);
    }else{
        syssetting->setRefreshCount(++temp);
        QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);
    }

}



/**
 * @brief StatusBar::startMyTimer
 */
void StatusBar::startMyTimer()
{
    QString  time = getTheCurrentTime();
    int  power = getTheBatteryPercentage();
    emit broadcastTimeAndBattery(time,power);
}

void StatusBar::updateTimeRightNowSlot()
{
    startMyTimer();
}

