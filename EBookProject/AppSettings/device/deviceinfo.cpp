#include "deviceinfo.h"
#include"application.h"
#include"rfile.h"
#include"commonutils.h"
#include<QApplication>
#include"application/pulldownwindow.h"

const int DEVICE_X[] = {60,500,270};
const int DEVICE_Y[] = {48,48,130};
const int DEVICE_W[] ={48,48,60};
const int DEVICE_HE[] ={48,48,30};

extern PulldownWindow *pulldownwindow;
extern int pulldownwindowrect[];

 QString KEY[] = {QObject::tr("SN"),QObject::tr("MAC"),QObject::tr("Memory"),QObject::tr("Version")};
 QString VALUE[] = {"","","8G","V1.0"};

DeviceInfo::DeviceInfo(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();

}

DeviceInfo::~DeviceInfo()
{

}

void DeviceInfo::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawdeviceinfo->drawBackIcon(painter,rectlist->at(DEVICE_INFO_BACKICON));
    drawdeviceinfo->drawHomeIcon(painter,rectlist->at(DEVICE_INFO_HOMEICON));
    drawdeviceinfo->drawDeviceInfoTitle(painter,rectlist->at(DEVICE_INFO_TITLE),tr("Parameters"));
    drawdeviceinfo->drawDeviceInfoList(painter,KEY,VALUE);
}

void DeviceInfo::mousePressEvent(QMouseEvent *event)
{
    int x= event->x();
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

}

void DeviceInfo::mouseMoveEvent(QMouseEvent *event)
{

}

void DeviceInfo::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetwidgetIndex) {
    case DEVICE_INFO_BACKICON:
        this->close();
        break;
    case DEVICE_INFO_HOMEICON:
        this->close();
        qApp->exit(0);
        break;
    case DEVICE_INFO_TITLE:
        break;
    default:
        break;
    }
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = false;
        this->repaint();
    }

}

void DeviceInfo::init()
{
    targetwidgetIndex = -1;
    drawdeviceinfo = new DrawDeviceInfo;
    statusbar = new StatusBar(this);
    initView();
}

void DeviceInfo::initView()
{
    rectlist = new QList<myQRect*>;
    for(int i=0;i<3;i++){
        myrect = new myQRect;
        myrect->rect.setX(DEVICE_X[i]);
        myrect->rect.setY(DEVICE_Y[i]);
        myrect->rect.setWidth(DEVICE_W[i]);
        myrect->rect.setHeight(DEVICE_HE[i]);
        RFIle::assignMacroDefinition(DEVICEINFO,myrect,i);
        rectlist->append(myrect);
    }

}
