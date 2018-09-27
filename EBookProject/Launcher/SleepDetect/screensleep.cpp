#include <QDebug>
#include <QThread>
#include "screensleep.h"
#include<QProcess>
#include"syssettings.h"
#include<sys/wait.h>


int tempCount = 0;
int totalCount = 0;
//char buf2[MSG_DATALEN];

int sleepTimeout = 0;

Lcd_backlight *mylcd_backlight;
//extern QProcess *mProcess1;

ScreenSleep::ScreenSleep(int count, int sleep_timeout)
{
    timer = new QTimer();
    timer->setSingleShot(false);

    connect(timer, SIGNAL(timeout()), this, SLOT(onScreenTimeout()));

    sleepTimeout = sleep_timeout;
    //screenTimeout = 1000 * screen_timeout;
    timer->start(1000);//1s.

    mylcd_backlight = new Lcd_backlight;

    totalCount = count;
    //  msg.msgid = msg.create_msg_queue();
}

void ScreenSleep::onResetTimer()
{
    //    qDebug() << "reset screen timeout";
    //    timer->start(screenTimeout);
    tempCount = 0;//重新计时.
}

void ScreenSleep::onScreenTimeout()
{

    //    msg.recv_msg(msg.msgid, MSG_TYPE_OTHER, buf2);
    //    emit signStopRun();
    tempCount++;
    if(tempCount==totalCount){
        qDebug()<<"tempCount=="<<tempCount;
        qDebug()<<"totalCount=="<<totalCount;
        tempCount=0;
        if(mylcd_backlight!=NULL){
            mylcd_backlight->disableLight();
        }
        QProcess  *mProcess1  = new QProcess ;
//        mProcess1->setEnvironment(mProcess1->environment());
//        mProcess1->setWorkingDirectory("/usr/local/app/");
        mProcess1->start("/usr/local/app/SleepScreen");
        qDebug()<<"tempCount==????----"<<tempCount;
        qDebug()<<"totalCount==????----"<<totalCount;
//        wait(NULL);
    }

    //    char cmd[32];
    //    bzero(cmd, 32);
    //    sprintf(cmd, "rtcwake -m mem -s %d", sleepTimeout);
    //    system(cmd);

}
