#include "mainwindow.h"
#include"application.h"
#include"utils/commonutils.h"
#include<QDebug>
#include<QApplication>

const int homexywh[] = {500,48,48,48};
const int setting[] = {260,110,80,60};





int items_xywh[8][4] = {
    {50,170,500,70},
    {50,240,500,70},
    {50,310,500,70},
    {50,380,500,70},
    {50,450,500,70},
    {50,520,500,70},
    {50,590,500,70},
    {50,660,500,70}
};

int item_text_xywh[8][4] = {
    {70,190,200,40},
    {70,260,200,40},
    {70,330,200,40},
    {70,400,200,40},
    {70,470,200,40},
    {70,540,200,40},
    {70,610,200,40},
    {70,680,200,40}
};

int item_icon_xywh[8][4] = {
    {480,180,50,50},
    {480,250,50,50},
    {480,320,50,50},
    {480,390,50,50},
    {480,460,50,50},
    {480,530,50,50},
    {480,600,50,50},
    {480,670,50,50}
};

const QString item_icon_paths[] = {
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png",
    ":/pic/pics/network_icon.png"
};



const QString item_text_text[8] ={
    QObject::tr("Light"),QObject::tr("WallPaper"),QObject::tr("Network"),QObject::tr("USB Transfer"),QObject::tr("DateAndTime"),
    QObject::tr("Language Keyboard"),QObject::tr("Restore"),QObject::tr("Other")
};

const QString system_text = QObject::tr("Setting");



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();

}


MainWindow::~MainWindow(){
    delete myrect,item;
    for(int i=0;i<systemitemlist->size();i++){
        delete systemitemlist->at(i);

    }

    delete drawmainwindow,pulldownwindow,statusbar;


}

void MainWindow::init(){

    targetWidgetIndex = -1;
    initView();

}

void MainWindow::initView(){

    myrect = new myQRect;
    myrect->rect.setX(homexywh[0]);
    myrect->rect.setY(homexywh[1]);
    myrect->rect.setWidth(homexywh[2]);
    myrect->rect.setHeight(homexywh[3]);
    myrect->isPressed = false;//home button

    pulldownwindow = new PulldownWindow(this);
    statusbar = new StatusBar(this);
    drawmainwindow = new DrawMainWindow;


   // initsettingsModules();

}

void MainWindow::initsettingsModules()
{
//    systemitemlist = new QList<SystemItems*>;

//    for(int i=0;i<8;i++){
//        item = new SystemItems;
//        item->itemrect.setX(items_xywh[i][0]);
//        item->itemrect.setY(items_xywh[i][1]);
//        item->itemrect.setWidth(items_xywh[i][2]);
//        item->itemrect.setHeight(items_xywh[i][3]);

//        item->itemtextrect.setX(item_text_xywh[i][0]);
//        item->itemtextrect.setY(item_text_xywh[i][1]);
//        item->itemtextrect.setWidth(item_text_xywh[i][2]);
//        item->itemtextrect.setHeight(item_text_xywh[i][3]);

//        item->setItem_text_text(item_text_text[i]);

//        item->itemiconrect.setX(item_icon_xywh[i][0]);
//        item->itemiconrect.setY(item_icon_xywh[i][1]);
//        item->itemiconrect.setWidth(item_icon_xywh[i][2]);
//        item->itemiconrect.setHeight(item_icon_xywh[i][3]);
//        //        item->item_icon_path = item_icon_paths[i];
//        item->ispressed = false;
//        systemitemlist->append(item);

//    }

}



void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event){
//     QPainter *painter = new QPainter(this);
//    statusbar->drawBattery(painter,30);
//    statusbar->drawPullDownRectangle(painter);
//    statusbar->drawSystemTime(painter,"15:30");
//    statusbar->drawWifiStatus(painter,true);
//    drawmainwindow->drawHomeIcon(painter,myrect);
//    QLineF line(0,100,600,100);
//    painter->drawLine(line);
//    QRect rect;
//    rect.setX(setting[0]);
//    rect.setY(setting[1]);
//    rect.setWidth(setting[2]);
//    rect.setHeight(setting[3]);
//    painter->drawText(rect,system_text);
//    drawmainwindow->drawSettingItems(painter,systemitemlist);

}

void MainWindow::mousePressEvent(QMouseEvent *event){

//    int x = event->x();
//    int y = event->y();
//    if(x>homexywh[0]&&x<homexywh[0]+homexywh[2]&&y>homexywh[1]&&y<homexywh[1]+homexywh[3]){
//        myrect->isPressed = true;
//        this->repaint();
//    }

//    targetWidgetIndex = commonUtils::getTargetIndexInSettingModule(x,y,systemitemlist);
//    if(targetWidgetIndex>-1){
//        systemitemlist->at(targetWidgetIndex)->ispressed = true;
//        this->repaint();
//    }
//    switch (targetWidgetIndex) {
//    case 0:

//        break;
//    case 1:

//        break;
//    default:
//        break;
//    }



}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
            this->close();
            qApp->exit(0);

//    int x = event->x();
//    int y = event->y();
//    if(x>homexywh[0]&&x<homexywh[0]+homexywh[2]&&y>homexywh[1]&&y<homexywh[1]+homexywh[3]){
//        myrect->isPressed = false;
//        qDebug()<<"-------------------setting quit()--------------------";
//        this->close();
//        qApp->exit(0);
//    }

//    if(targetWidgetIndex>-1){
//        systemitemlist->at(targetWidgetIndex)->ispressed = false;
//        this->repaint();
//    }
}
