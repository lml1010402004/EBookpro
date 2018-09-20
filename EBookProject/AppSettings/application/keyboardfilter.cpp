#include "keyboardfilter.h"
#include <QDebug>
#include<QProcess>
#include<sys/wait.h>
#include<QTimer>
QProcess *mProcess1;



bool KeyBoardFilter::hasTheTargetProcess(){

    char cmd[128] = "ps -a | grep SleepScreen | awk '{print $3}' ";
    char buf[1024] = {0};

    FILE *pp = popen(cmd, "r");


    if (pp != NULL)
    {
        fread(buf, 1, sizeof(buf), pp);
        QString str = buf;
        if(str.contains("SleepScreen")){
            return true;}else{
            return false;
        }
        pclose(pp);

    }
    return false;

}

//void KeyBoardFilter::update()
//{
//        QProcess *mProcess = new QProcess();
//        mProcess->setEnvironment(mProcess->environment());
//        mProcess->setWorkingDirectory("/usr/local/app/");
//        mProcess->start(SleepApp,QStringList("ShutDownMachine"));
//        return ;

//}

KeyBoardFilter::KeyBoardFilter()
{
     mProcess1  = new QProcess ;
    mylcd_backlight = new Lcd_backlight;
    isEnableSleepScreen = true;
    mysettings = new SysSettings;
}

KeyBoardFilter::~KeyBoardFilter()
{
    delete mProcess1;
    mProcess1 = NULL;
}


bool KeyBoardFilter::filter(int unicode, int keycode, int modifiers,
                            bool isPress, bool autoRepeat)
{



    if(Qt::Key_PowerDown == keycode && !isPress)
    {


        //qDebug()<<"KeyBoardFilter::filter keycode=" << keycode<<",isPress="<<isPress;

        if(isEnableSleepScreen)
        {
            system("/usr/wifi/disablewifi");
            if(mylcd_backlight!=NULL){
                mylcd_backlight->disableLight();
            }
                qDebug()<<"come out ...";
            if(!hasTheTargetProcess()){
                qDebug()<<"come in ...";
                if(mProcess1==NULL)
                mProcess1  = new QProcess ;
                mProcess1->setEnvironment(mProcess1->environment());
                mProcess1->setWorkingDirectory("/usr/local/app/");
                mProcess1->start("/usr/local/app/SleepScreen");
                wait(NULL);
            }
            isEnableSleepScreen = false;
        }
        else{
            mylcd_backlight->enableLight();
            int lastValue = mysettings->getBackLight();
            mylcd_backlight->setLight(lastValue*10);
            isEnableSleepScreen = true;
        }
    }
    return false;
}
