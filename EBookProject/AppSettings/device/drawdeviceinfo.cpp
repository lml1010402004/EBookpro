#include "drawdeviceinfo.h"
#include"utils/application.h"
extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;

const int DEVICEINFO_X[] = {70,530,100,400};
const int DEVICEINFO_Y[] = {170,170,220,220};
const int DEVICEINFO_W = 150;
const int DEVICEINFO_HE = 90;

DrawDeviceInfo::DrawDeviceInfo()
{

}

DrawDeviceInfo::~DrawDeviceInfo()
{

}

void DrawDeviceInfo::drawHomeIcon(QPainter *painter,myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawDeviceInfo::drawBackIcon(QPainter *painter,myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawDeviceInfo::drawDeviceInfoList(QPainter *painter, QString group[],QString group1[])
{
    QRect myqrect;
    for(int i=0;i<4;i++){
      QLineF line(DEVICEINFO_X[0],DEVICEINFO_Y[0]+DEVICEINFO_HE*i,DEVICEINFO_X[1],DEVICEINFO_Y[1]+DEVICEINFO_HE*i);
      painter->drawLine(line);
      myqrect.setX(DEVICEINFO_X[2]);
      myqrect.setY(DEVICEINFO_Y[2]+DEVICEINFO_HE*i-10);
      myqrect.setWidth(DEVICEINFO_W);
      myqrect.setHeight(DEVICEINFO_HE-50);
      painter->drawText(myqrect,group[i]);

      myqrect.setX(DEVICEINFO_X[3]);
      myqrect.setY(DEVICEINFO_Y[3]+DEVICEINFO_HE*i-10);
      myqrect.setWidth(DEVICEINFO_W);
      myqrect.setHeight(DEVICEINFO_HE-50);
      painter->drawText(myqrect,group1[i]);
    }
    QLineF line1(DEVICEINFO_X[0],DEVICEINFO_Y[0]+DEVICEINFO_HE*4,DEVICEINFO_X[1],DEVICEINFO_Y[1]+DEVICEINFO_HE*4);
 painter->drawLine(line1);

}

void DrawDeviceInfo::drawDeviceInfoTitle(QPainter *painter,myQRect *rect, QString str)
{
 painter->drawText(rect->rect,str);
}
