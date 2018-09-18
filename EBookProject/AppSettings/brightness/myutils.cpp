#include "myutils.h"




MyUtils::MyUtils()
{
    mysyssettings = new SysSettings;

}

MyUtils::~MyUtils()
{

}

void MyUtils::drawProgressBarForLight(QPainter *painter, int value)
{

    QRect rect;
    for(int i=0;i<value;i++){
        rect.setX(LIGHT_X_START+LIGHT_STEP_INTERVAL*i);
        rect.setY(RECT_Y);
        rect.setWidth(RECT_W);
        rect.setHeight(RECT_HE);
        painter->fillRect(rect,Qt::black);
        painter->drawRect(rect);
        mysyssettings->setBackLight(value);
    }
    for(int j=value;j<TOTAL_LEVELS;j++){
        rect.setX(LIGHT_X_START+LIGHT_STEP_INTERVAL*j);
        rect.setY(RECT_Y);
        rect.setWidth(RECT_W);
        rect.setHeight(RECT_HE);
        painter->fillRect(rect,Qt::white);
        painter->drawRect(rect);
    }
}

int MyUtils::getTheLightValueFromXY(int pos_x, int pos_y, QRect rect)
{
    int temp = 0;
    if(pos_x>rect.x()&&pos_x<rect.x()+rect.width()&&pos_y>rect.y()&&pos_y<rect.y()+rect.height()){
        int t = (pos_x-LIGHT_X_START)%LIGHT_STEP_INTERVAL;//30*8 = 240,表示步进是8,共30级
        if(t==0){
            temp = (pos_x-LIGHT_X_START)/LIGHT_STEP_INTERVAL;
        }else{
            temp = (pos_x-LIGHT_X_START)/LIGHT_STEP_INTERVAL+1;
        }
    }
    return temp;
}



