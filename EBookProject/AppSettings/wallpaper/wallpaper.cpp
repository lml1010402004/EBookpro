#include "wallpaper.h"
#include"application.h"
#include"rfile.h"
#include"commonutils.h"
#include<QApplication>

const int WALLPAPER_X[] = {60,500,250};
const int WALLPAPER_Y[] = {48,48,130};
const int WALLPAPER_W[] = {48,48,120};
const int WALLPAPER_HE[] ={48,48,40};

const int WALLPAPERS_X[] = {60,230,400};
const int WALLPAPERS_Y = 190;
const int WALLPAPERS_W=140;
const int WALLPAPERS_HE = 180;






WallPaper::WallPaper(QWidget *parent) : QMainWindow(parent)
{

   this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
   this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
   this->setFixedWidth(GLOBAL_FIXED_WIDTH);
   init();

}

WallPaper::~WallPaper()
{

}

void WallPaper::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);

    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

    drawwallpaper->drawBackIcon(painter,rectlist->at(WALLPAPER_BACKICON));
    drawwallpaper->drawHomeIcon(painter,rectlist->at(WALLPAPER_HOMEICON));
    drawwallpaper->drawTitle(painter,rectlist->at(WALLPAPER_TITLE),tr("WallPaper"));
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawwallpaper->drawWallPapers(painter,wallpaperlist);



}

void WallPaper::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }

}

void WallPaper::mouseMoveEvent(QMouseEvent *event)
{

}

void WallPaper::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetwidgetIndex) {
    case 0:
        this->close();
        break;
    case 1:
        this->close();
        qApp->exit(0);
        break;
    default:
        break;
    }

}

void WallPaper::init()
{
  targetwidgetIndex = -1;
  initView();
}

void WallPaper::initView()
{
    drawwallpaper = new DrawWallPaper;
    mysysseting = new SysSettings;
    statusbar = new StatusBar(this);
    index_wallpaper = mysysseting->getWallPaper();
    wallpaperlist = new QList<myQRect*>;

    for(int j=0;j<3;j++){
      rect = new myQRect;
      rect->rect.setX(WALLPAPERS_X[j]);
      rect->rect.setY(WALLPAPERS_Y);
      rect->rect.setWidth(WALLPAPERS_W);
      rect->rect.setHeight(WALLPAPERS_HE);
      wallpaperlist->append(rect);
    }


    rectlist = new QList<myQRect*>;
    for(int i=0;i<3;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(WALLPAPER_X[i]);
        myqrect->rect.setY(WALLPAPER_Y[i]);
        myqrect->rect.setWidth(WALLPAPER_W[i]);
        myqrect->rect.setHeight(WALLPAPER_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(WALLPAPER_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }





}
