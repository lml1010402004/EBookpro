#include "pulldownwindow.h"
#include"QDebug"



const int pulldownrect_x[] = {130,270,410,60,490,0,0,280};
const int pulldownrect_y[]={60,60,60,170,170,0,300,270};
const int pulldown_shortcut_w[]={60,60,60,50,50,600,600,40};
const int pulldown_shortcut_h[]={60,60,60,60,60,300,500,20};

const QString APPSETTINGS = "/usr/local/app/";
const QString apppath ="/usr/local/app/AppSettings";

const int TOTAL_LEVELS  =30;
const int LIGHT_X_START = 120;
const int LIGHT_STEP_INTERVAL = 12;
const int RECT_HE = 70;
const int RECT_Y = 160;
const int RECT_W = 5;

const int alpha = 100;


PulldownWindow::PulldownWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(800);
    this->setFixedWidth(600);

    init();
}

PulldownWindow::~PulldownWindow()
{
    for(int i=0;i<rectlist->size();i++){
        delete rectlist->at(i);
    }
    delete rectlist,myprocess,rectlist,statusbar,mysyssetting;

}

void PulldownWindow::mousePressEvent(QMouseEvent *event)
{

    targetwidgetindex = getTheTargetWidget(event->x(),event->y(),rectlist);
    if(targetwidgetindex>-1){
        rectlist->at(targetwidgetindex)->isPressed = true;
        this->repaint(rectlist->at(targetwidgetindex)->rect);
    }
    refreshLightUI(event->x(),event->y());

}

void PulldownWindow::refreshLightUI(int x,int y)
{
    if(x>lightrect.x()&&x<lightrect.x()+lightrect.width()&&y>lightrect.y()&&y<lightrect.y()+lightrect.height()){
        lightvalue = getTheLightValueFromXY(x,y,lightrect);
        if(lightvalue>0){
            lightarea = true;
            mysyssetting->setBackLight(lightvalue);
            this->repaint();
        }
    }else{
        lightarea = false;
    }
}

void PulldownWindow::mouseMoveEvent(QMouseEvent *event)
{
    refreshLightUI(event->x(),event->y());
}

void PulldownWindow::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug()<<"releaseevent targetwidgetindex=="<<targetwidgetindex;
    if(targetwidgetindex>-1){
        rectlist->at(targetwidgetindex)->isPressed = false;
        switch (targetwidgetindex) {
        case PULLDOWN_WIFI://wifi

            break;
        case PULLDOWN_SETTING://setting
            myprocess->setEnvironment(myprocess->environment());
            myprocess->setWorkingDirectory(APPSETTINGS);
            myprocess->start(apppath);
            break;
        case PULLDOWN_SEARCH://search
            break;
        case PULLDOWN_MINUS://minus
            if(lightvalue>0){
                lightvalue--;
                mysyssetting->setBackLight(lightvalue);
            }
            break;
        case PULLDOWN_PLUS://plus
            if(lightvalue<TOTAL_LEVELS){
                lightvalue++;
                mysyssetting->setBackLight(lightvalue);
            }
            break;
        case PULLDOWN_UP:
        case PULLDOWN_DOWN:
        case PULLDOWN_RECTANGLE:
            if(lightarea==false)
                this->close();
            break;
        default:
            break;
        }
        this->repaint();
        targetwidgetindex = -1;
    }

}

void PulldownWindow::paintEvent(QPaintEvent *event)
{

    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);
    QLineF line(0,40,600,40);
    painter->drawLine(line);



    drawLightMinus(painter,rectlist->at(PULLDOWN_MINUS));
    drawLightPlus(painter,rectlist->at(PULLDOWN_PLUS));

    drawCloseIcon(painter,rectlist->at(PULLDOWN_RECTANGLE));
    drawShortcutIcons(painter,rectlist->at(PULLDOWN_WIFI),rectlist->at(PULLDOWN_SETTING),rectlist->at(PULLDOWN_SEARCH));


    drawProgressBarForLight(painter,mysyssetting->getBackLight());

    drawGrayArea(painter,100,rectlist->at(PULLDOWN_DOWN));
}

void PulldownWindow::drawCloseIcon(QPainter *painter, myQRect* rect)
{

    painter->drawPixmap(rect->rect,closeIcon);

}

void PulldownWindow::drawShortcutArea(QPainter *painter, myQRect* rect)
{
    painter->drawRect(rect->rect);
}

void PulldownWindow::drawGrayArea(QPainter *painter, int al, myQRect* rect)
{
    QBrush brush(QColor(100,100,100,180));
    painter->setBrush(brush);
    painter->drawRoundedRect(rect->rect,0,0);
}

void PulldownWindow::drawShortcutIcons(QPainter *painter, myQRect* rect1, myQRect* rect2, myQRect* rect3)
{
    QRect rect;
    rect.setX(0);
    rect.setY(0);
    rect.setWidth(600);
    rect.setHeight(300);
    painter->drawRoundedRect(rect,0,0);

    if(rect1->isPressed){
        painter->drawPixmap(rect1->rect,wifi_press);
    }else{
        painter->drawPixmap(rect1->rect,wifi_unpress);
    }

    if(rect2->isPressed){
        painter->drawPixmap(rect2->rect,setting_press);
    }else{
        painter->drawPixmap(rect2->rect,setting_unpress);
    }

    if(rect3->isPressed){
        painter->drawPixmap(rect3->rect,search_press);
    }else{
        painter->drawPixmap(rect3->rect,search_unpress);
    }


}

void PulldownWindow::drawLightshortcutandProgressBar(QPainter *painter, QString lightpath, int light_volume, myQRect* rect, QString floatpath)
{
    painter->drawPixmap(rect->rect,lightpath);

}

void PulldownWindow::drawLightPlus(QPainter *painter, myQRect* plusrect)
{
    if(plusrect->isPressed){
        painter->drawPixmap(plusrect->rect,plus_press);
    }else{
        painter->drawPixmap(plusrect->rect,plus_unpress);
    }

}

void PulldownWindow::drawLightMinus(QPainter *painter, myQRect* minusrect)
{
    if(minusrect->isPressed){
        painter->drawPixmap(minusrect->rect,minus_press);
    }else{
        painter->drawPixmap(minusrect->rect,minus_unpress);
    }

}

void PulldownWindow::drawProgressBarForLight(QPainter *painter, int value)
{

    QRect rect;
    for(int i=0;i<value;i++){
        rect.setX(LIGHT_X_START+LIGHT_STEP_INTERVAL*i);
        rect.setY(RECT_Y);
        rect.setWidth(RECT_W);
        rect.setHeight(RECT_HE);
        painter->fillRect(rect,Qt::black);
        painter->drawRect(rect);
        mysyssetting->setBackLight(value);
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

int PulldownWindow::getTheLightValueFromXY(int pos_x, int pos_y, QRect rect)
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

void PulldownWindow::init()
{
    statusbar = new StatusBar(this);
    myprocess = new QProcess(this);
    mysyssetting = new SysSettings;
    mysyssetting->enableBackLight();
    initView();

    lightrect.setX(LIGHT_X_START);
    lightrect.setY(RECT_Y);
    lightrect.setWidth(360);
    lightrect.setHeight(70);
    lightvalue = mysyssetting->getBackLight();
    lightarea = false;

}

void PulldownWindow::initView()
{

    rectlist = new QList<myQRect*>;

    for(int i=0;i<8;i++){
        myrect = new myQRect;
        myrect->rect.setX(pulldownrect_x[i]);
        myrect->rect.setY(pulldownrect_y[i]);
        myrect->rect.setWidth(pulldown_shortcut_w[i]);
        myrect->rect.setHeight(pulldown_shortcut_h[i]);
        myrect->isPressed = false;
        R::assignMacroDefinitions(myrect,i);
        rectlist->append(myrect);
    }

}

int PulldownWindow::getTheTargetWidget(int pos_x, int pos_y, QList<myQRect*> *rectlist)
{

    int targetwidgetindex = -1;
    for(int i=0;i<rectlist->size();i++){
        if(pos_x>rectlist->at(i)->rect.x()&&pos_x<rectlist->at(i)->rect.x()+rectlist->at(i)->rect.width()
                &&pos_y>rectlist->at(i)->rect.y()&&pos_y<rectlist->at(i)->rect.y()+rectlist->at(i)->rect.height()){
            targetwidgetindex = i;
            break;
        }
    }
    return targetwidgetindex;

}


