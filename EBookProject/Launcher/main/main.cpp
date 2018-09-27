#include"HomePage/mainwindow.h"
#include<QApplication>
#include<QTextCodec>
#include<QFont>
#include"Application/keyboard.h"
#include"Application/keyboardfilter.h"
#include"Application/pinyinim.h"
#include"SleepDetect/eventthread.h"
#include"SleepDetect/screensleep.h"
#include"syssettings.h"


KeyBoardFilter *keyboardfilter;


void startSleepDetect(){
    SysSettings  *sys_a2 = new SysSettings;
    int screenTimeout = sys_a2->getAutoSleepTime();
    //     int sleepTimeout = sys_a2->getAutoPoweroffTime();
    EventThread *event3Thread = new EventThread("/dev/input/event3");
    EventThread *event4Thread = new EventThread("/dev/input/event4");
    ScreenSleep *screenSleep = new ScreenSleep(60, screenTimeout);

    //     screenSleep->connect(screenSleep, SIGNAL(signStopRun()), event3Thread, SLOT(onStopRun()));
    //     screenSleep->connect(screenSleep, SIGNAL(signStopRun()), event4Thread, SLOT(onStopRun()));

    event3Thread->connect(event3Thread, SIGNAL(signResetTimer()), screenSleep, SLOT(onResetTimer()));
    event4Thread->connect(event4Thread, SIGNAL(signResetTimer()), screenSleep, SLOT(onResetTimer()));
    event3Thread->start();
    event4Thread->start();
    //     delete sys_a2;
}



int main(int argc,char *argv[]){

    QApplication app(argc,argv);
    QApplication::setScreenUpdateMode(QApplication::EINK_GC16_LOCAL_MODE);
    //设置支持汉字字体显示==开始===
    QFont font;
    font.setFamily(("Microsoft YaHei"));
    app.setFont(font);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    //设置支持汉字显示==结束==

    PinyinIM   *pinyinIM = new PinyinIM();
    //pinyinIM->connect(pinyinIM, SIGNAL(sigConfirmString(QString)), this, SLOT(pinyinIMConfirmStringS(QString)));
    QWSServer::setCurrentInputMethod(pinyinIM);
    keyboardfilter = new KeyBoardFilter;

    QWSServer::addKeyboardFilter(keyboardfilter);

    startSleepDetect();

    MainWindow w;
    w.show();
    return app.exec();

}
