#ifndef MYUTILS_H
#define MYUTILS_H
#include<QPainter>
#include<QRect>
#include"application/syssettings.h"

const int TOTAL_LEVELS  =30;
const int LIGHT_X_START = 125;
const int LIGHT_STEP_INTERVAL = 12;
const int RECT_HE = 70;
const int RECT_Y = 200;
const int RECT_W = 5;

class MyUtils
{
public:
    MyUtils();
    ~MyUtils();

    void drawProgressBarForLight(QPainter *painter,int value);
    int getTheLightValueFromXY(int pos_x,int pos_y,QRect rect);
private:
    SysSettings *mysyssettings;


};

#endif // MYUTILS_H
