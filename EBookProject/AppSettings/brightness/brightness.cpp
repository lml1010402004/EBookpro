#include "brightness.h"
#include"application.h"
#include"rfile.h"
#include"application/pulldownwindow.h"
#include"utils/commonutils.h"
#include<QApplication>


const int BRIGHTNESS_X[] = {60,500,270,60,490};
const int BRIGHTNESS_Y[] = {48,48,130,210,210};
const int BRIGHTNESS_W[] ={48,48,60,50,50};
const int BRIGHTNESS_HE[] ={48,48,30,60,60};


extern int pulldownwindowrect[];
extern PulldownWindow *pulldownwindow;


Brightness::Brightness(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();
}

Brightness::~Brightness()
{
    delete drawbrightness,statusbar,syssettings;
}

void Brightness::mousePressEvent(QMouseEvent *event)
{
    int x =event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }

    if(x>pulldownwindowrect[0]&&x<(pulldownwindowrect[0]+pulldownwindowrect[2])&&
            y<pulldownwindowrect[3]){
        if(pulldownwindow==NULL){
            pulldownwindow = new PulldownWindow(this);
        }
        pulldownwindow->show();
    }

  refreshLightUI(x,y,lightrect);
}

void Brightness::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,commonUtils::getCurrentTime());
    statusbar->drawWifiStatus(painter,true);

    drawbrightness->drawBackIcon(painter,rectlist->at(LIGHT_BACKICON));
    drawbrightness->drawHomeIcon(painter,rectlist->at(LIGHT_HOMEICON));
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawbrightness->drawTitle(painter,rectlist->at(LIGHT_HOMETITLE),tr("Light"));
    drawbrightness->drawMinusButton(painter,rectlist->at(LIGHT_MINUS));
    drawbrightness->drawPlusButton(painter,rectlist->at(LIGHT_PLUS));
    myutils->drawProgressBarForLight(painter,lightvalue);

}

void Brightness::mouseMoveEvent(QMouseEvent *event)
{
    refreshLightUI(event->x(),event->y(),lightrect);

}

void Brightness::mouseReleaseEvent(QMouseEvent *event)
{
  switch(targetwidgetIndex){
  case LIGHT_BACKICON:
      this->close();
      break;
  case LIGHT_HOMEICON:
      this->close();
      qApp->exit(0);
      break;
  case LIGHT_HOMETITLE:
      break;
  case LIGHT_MINUS:
      if(lightvalue>0)
          lightvalue--;
      break;
  case LIGHT_PLUS:
      if(lightvalue<TOTAL_LEVELS)
          lightvalue++;
      break;
 default:
      break;
  }
  if(targetwidgetIndex>-1){
      rectlist->at(targetwidgetIndex)->isPressed = false;
      targetwidgetIndex = -1;
      this->repaint();
  }
}


void Brightness::init()
{
    syssettings = new SysSettings;
    targetwidgetIndex =-1;
    myutils = new MyUtils();
    lightrect.setX(LIGHT_X_START);
    lightrect.setY(RECT_Y);
    lightrect.setWidth(360);//滑动条的x轴范围
    lightrect.setHeight(70);//滑动条的Y范围

    lightvalue = syssettings->getBackLight();
    initView();
}

void Brightness::initView()
{
    statusbar = new StatusBar(this);
    drawbrightness = new DrawBrightness;
    rectlist = new QList<myQRect*>;
    for(int i=0;i<5;i++){//这里的5对应坐标数组长度
        myqrect = new myQRect;
        myqrect->rect.setX(BRIGHTNESS_X[i]);
        myqrect->rect.setY(BRIGHTNESS_Y[i]);
        myqrect->rect.setWidth(BRIGHTNESS_W[i]);
        myqrect->rect.setHeight(BRIGHTNESS_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(LIGHT_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }

}

void Brightness::initConnections()
{

}

void Brightness::refreshLightUI(int x, int y, QRect lightrect)
{
    if(x>lightrect.x()&&x<lightrect.x()+lightrect.width()&&y>lightrect.y()&&y<lightrect.y()+lightrect.height()){
        lightvalue = myutils->getTheLightValueFromXY(x,y,lightrect);
        if(lightvalue>0){
            syssettings->setBackLight(lightvalue);
            this->repaint();
        }
    }

}
