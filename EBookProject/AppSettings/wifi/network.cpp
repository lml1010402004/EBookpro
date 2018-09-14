#include "network.h"
#include"application.h"
#include"application/rfile.h"
#include"utils/commonutils.h"
#include<QApplication>
#include<QDebug>

const int NETWORK_X[] = {60,500,250,80,250};
const int NETWORK_Y[] = {48,48,130,180,260};
const int NETWORK_W[] = {48,48,100,80,100};
const int NETWORK_HE[] ={48,48,40,30,40};

const int wifiswitch[] ={480,180,80,30};


Network::Network(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();
}

Network::~Network()
{
    delete drawnetwork,statusbar,myqrect,rectlist,wifilist,mywifiservice,switchbutton;
}



void Network::init()
{
    targetwidgetindex = -1;
    initView();
}

void Network::initView()
{
    switchbutton = new myQRect;
    switchbutton->rect.setX(wifiswitch[0]);
    switchbutton->rect.setY(wifiswitch[1]);
    switchbutton->rect.setWidth(wifiswitch[2]);
    switchbutton->rect.setHeight(wifiswitch[3]);
    switchbutton->isPressed = false;

    rectlist = new QList<myQRect*>;
    for(int i=0;i<5;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(NETWORK_X[i]);
        myqrect->rect.setY(NETWORK_Y[i]);
        myqrect->rect.setWidth(NETWORK_W[i]);
        myqrect->rect.setHeight(NETWORK_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(NETWORK_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }

    drawnetwork = new DrawNetwork;
    statusbar = new StatusBar(this);
    wifilist = new  QList<wifiItem*>;
//    mywifiservice = new WifiService(this);

}

void Network::operateWifi()
{
    switchbutton->isPressed = !switchbutton->isPressed;
    this->repaint();
    if(switchbutton->isPressed){


    }else{

    }


    //    if(switchbutton->isPressed){
    //        if(mywifiservice->isEnabled()){
    //            mywifiservice->doScan();
    //            mywifiservice->refreshWifiList();
    //        }else{
    //            mywifiservice->setEnable(true);
    //        }
    //    }else{
    //          mywifiservice->setEnable(false);
    //          wifilist->clear();
    //    }

}

void Network::mousePressEvent(QMouseEvent *event)
{
    targetwidgetindex = commonUtils::getTheTargetWidget(event->x(),event->y(),rectlist);
    if(targetwidgetindex>-1){
        rectlist->at(targetwidgetindex)->isPressed = true;
        this->repaint();
    }

}

void Network::mouseMoveEvent(QMouseEvent *event)
{

}

void Network::mouseReleaseEvent(QMouseEvent *event)
{
    if(targetwidgetindex>-1){
        rectlist->at(targetwidgetindex)->isPressed = false;
        switch (targetwidgetindex) {
        case NETWORK_BACKICON:
            this->close();
            break;
        case NETWORK_HOMEICON:
            this->close();
            qApp->exit(0);
            break;

        default:
            break;
            targetwidgetindex = -1;
            this->repaint();
        }
    }

    //这里处理switchbutton的逻辑
    if(event->x()>switchbutton->rect.x()&&event->x()<switchbutton->rect.x()+switchbutton->rect.width()&&
            event->y()>switchbutton->rect.y()&&event->y()<switchbutton->rect.y()+switchbutton->rect.height()){
        operateWifi();
    }


}

void Network::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

    drawnetwork->drawBackIcon(painter,rectlist->at(NETWORK_BACKICON));
    drawnetwork->drawHomeIcon(painter,rectlist->at(NETWORK_HOMEICON));
    QLineF line(0,100,600,100);
    painter->drawLine(line);
    drawnetwork->drawNetworkTitle(painter,rectlist->at(NETWORK_TITLE),tr("Network"));
    drawnetwork->drawNetworkWifiText(painter,rectlist->at(NETWORK_WIFITEXT),tr("Wifi"));
    drawnetwork->drawNetworkSwitch(painter,switchbutton);
    drawnetwork->drawSearchResultTitle(painter,rectlist->at(NETWORK_SEARCHRESULT_TEXT),tr("Result"));
    //  drawnetwork->drawBackIcon();

}
