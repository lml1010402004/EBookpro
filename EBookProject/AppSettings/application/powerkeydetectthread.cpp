#include "powerkeydetectthread.h"
#include<QProcess>
#include<QDebug>

extern QString SleepApp;
int counts =6;
bool pressState;
powerKeyDetectThread::powerKeyDetectThread()
{

}

void powerKeyDetectThread::run()
{
    while(counts>0&&pressState){
            counts--;
            sleep(1);
             qDebug()<<"pressState=="<<pressState;
            if(counts==1){
                //这里需要直接关机
                 emit shutDownEBooksignal();

            }
        }



}
