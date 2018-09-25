#include "settingsleeptime.h"
#include"application.h"
#include"rfile.h"
#include"commonutils.h"
#include<QApplication>
#include"application/pulldownwindow.h"

const int SLEEPTIME_X[]= {60,500,270};
const int SLEEPTIME_Y[] ={48,48,130};
const int SLEEPTIME_W[] ={48,48,100};
const int SLEEPTIME_HE[] = {48,48,30};

extern int LISTVIEW_X[];
extern int LISTVIEW_Y[];
extern int LISTVIEW_ITEM_HEIGHT;


extern PulldownWindow *pulldownwindow;
extern int pulldownwindowrect[];

SettingSleepTime::SettingSleepTime(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();

}

SettingSleepTime::~SettingSleepTime()
{
    delete statusbar,drawsettingsleep;
}

void SettingSleepTime::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed= true;
        this->repaint();
    }

    if(x>LISTVIEW_X[0]&&x<LISTVIEW_X[1]){
        int y0 = LISTVIEW_Y[0];
        int y1 = y0+LISTVIEW_ITEM_HEIGHT;
        int y2 = y1+LISTVIEW_ITEM_HEIGHT;
        int y3 = y2+LISTVIEW_ITEM_HEIGHT;
        int y4 = y3+LISTVIEW_ITEM_HEIGHT;
        int y5 = y4+LISTVIEW_ITEM_HEIGHT;
        if(y>y0&&y<y1){
            time_selected = 0;
        }else if(y>y1&&y<y2){
            time_selected = 1;
        }else if(y>y2&&y<y3){
            time_selected =2;
        }else if(y>y3&&y<y4){
            time_selected = 3;
        }else if(y>y4&&y<y5){
            time_selected = 4;
        }
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

void SettingSleepTime::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);
    drawsettingsleep->drawBackIcon(painter,rectlist->at(SLEEP_TIME_BACK));
    drawsettingsleep->drawHomeIcon(painter,rectlist->at(SLEEP_TIME_HOMEICON));
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawsettingsleep->drawTitle(painter,rectlist->at(SLEEP_TIME_TITLE),tr("Set Time"));
    drawsettingsleep->drawSleepTimeListview(painter,time_selected);
}

void SettingSleepTime::mouseMoveEvent(QMouseEvent *event)
{

}

void SettingSleepTime::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetwidgetIndex) {
    case SLEEP_TIME_BACK:
        this->close();
        break;
    case SLEEP_TIME_HOMEICON:
        this->close();
        qApp->exit(0);
        break;
    default:
        break;
    }
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed= false;
        this->repaint();
    }

}

void SettingSleepTime::init()
{
    time_selected = -1;
    targetwidgetIndex = -1;
    statusbar = new StatusBar(this);
    drawsettingsleep = new drawSettingSleep;
    rectlist = new QList<myQRect*>;
    initView();
}

void SettingSleepTime::initView()
{

    for(int i=0;i<3;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(SLEEPTIME_X[i]);
        myqrect->rect.setY(SLEEPTIME_Y[i]);
        myqrect->rect.setWidth(SLEEPTIME_W[i]);
        myqrect->rect.setHeight(SLEEPTIME_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(SLEEPTIMESET,myqrect,i);
        rectlist->append(myqrect);
    }

}

void SettingSleepTime::initConnections()
{

}
