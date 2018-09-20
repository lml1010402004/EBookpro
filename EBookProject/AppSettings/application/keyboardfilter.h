#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H
#include <QWSServer>
#include"syssettings.h"
#include<QThread>
#include"application/powerkeydetectthread.h"
#include<QObject>

class KeyBoardFilter : public QWSServer::KeyboardFilter
{

public:


    KeyBoardFilter();

    ~KeyBoardFilter();
    bool filter(int unicode, int keycode, int modifiers,
                        bool isPress, bool autoRepeat);


    bool hasTheTargetProcess();


private:

    Lcd_backlight *mylcd_backlight;
    bool isEnableSleepScreen;
    SysSettings *mysettings;
    powerKeyDetectThread *mypowerkeythread;




};

#endif // KEYBOARDFILTER_H
