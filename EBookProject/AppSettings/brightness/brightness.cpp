#include "brightness.h"
#include"application.h"
#include"rfile.h"

const int BRIGHTNESS_X[] = {60,500,270,90,460};
const int BRIGHTNESS_Y[] = {48,48,130,230,230};
const int BRIGHTNESS_W[] ={48,48,60,50,50};
const int BRIGHTNESS_HE[] ={48,48,30,50,50};

Brightness::Brightness(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();
}

Brightness::~Brightness()
{
  delete drawbrightness,statusbar;
}

void Brightness::mousePressEvent(QMouseEvent *event)
{
 this->close();
}

void Brightness::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

   drawbrightness->drawBackIcon(painter,rectlist->at(LIGHT_BACKICON));
   drawbrightness->drawHomeIcon(painter,rectlist->at(LIGHT_HOMEICON));
   drawbrightness->drawTitle(painter,rectlist->at(LIGHT_HOMETITLE),tr("Light"));





}

void Brightness::mouseMoveEvent(QMouseEvent *event)
{

}

void Brightness::mouseReleaseEvent(QMouseEvent *event)
{

}

void Brightness::init()
{

    initView();

}

void Brightness::initView()
{
  statusbar = new StatusBar(this);
  drawbrightness = new DrawBrightness;
  rectlist = new QList<myQRect*>;
  for(int i=0;i<5;i++){
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
