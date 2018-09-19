#include "wallpaper.h"
#include"application.h"
#include"rfile.h"
#include"commonutils.h"
#include<QApplication>
#include"application/pulldownwindow.h"

const int WALLPAPER_X[] = {60,500,250};
const int WALLPAPER_Y[] = {48,48,130};
const int WALLPAPER_W[] = {48,48,120};
const int WALLPAPER_HE[] ={48,48,40};

const int WALLPAPERS_X[] = {60,230,400};
const int WALLPAPERS_Y = 190;
const int WALLPAPERS_W=140;
const int WALLPAPERS_HE = 180;

const int CHECKBOXGROUP_X[] ={115,285,455};
const int CHECKBOX_W_H = 30;
const int CHECKBOX_Y=390;


extern int pulldownwindowrect[];
extern PulldownWindow *pulldownwindow;




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
    drawwallpaper->drawCheckbox(painter,checkboxs,index_wallpaper);

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
    if(x>pulldownwindowrect[0]&&x<(pulldownwindowrect[0]+pulldownwindowrect[2])&&
            y<pulldownwindowrect[3]){
        if(pulldownwindow==NULL){
            pulldownwindow = new PulldownWindow(this);
        }
        pulldownwindow->show();
    }

    if(y>CHECKBOX_Y&&y<CHECKBOX_Y+CHECKBOX_W_H){
        if(x>CHECKBOXGROUP_X[0]&&x<CHECKBOXGROUP_X[0]+CHECKBOX_W_H){
            index_wallpaper =0;
        }else if(x>CHECKBOXGROUP_X[1]&&x<CHECKBOXGROUP_X[1]+CHECKBOX_W_H){
            index_wallpaper =1;
        }else if(x>CHECKBOXGROUP_X[2]&&x<CHECKBOXGROUP_X[2]+CHECKBOX_W_H){
            index_wallpaper =2;
        }
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
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = false;
        targetwidgetIndex = -1;
        this->repaint();
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
    checkboxs = new QList<myQRect*>;

    for(int k=0;k<3;k++){
        rect = new myQRect;
        rect->rect.setX(CHECKBOXGROUP_X[k]);
        rect->rect.setY(CHECKBOX_Y);
        rect->rect.setWidth(CHECKBOX_W_H);
        rect->rect.setHeight(CHECKBOX_W_H);
        rect->isPressed = false;
        checkboxs->append(rect);
    }

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
