#include "network.h"
#include"application.h"
#include"application/rfile.h"

const int NETWORK_X[] = {60,500,250,80,480,250};
const int NETWORK_Y[] = {48,48,130,180,180,260};
const int NETWORK_W[] = {48,48,100,80,80,120};
const int NETWORK_HE[] ={48,48,40,30,30,40};


Network::Network(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();
}

Network::~Network()
{
    delete drawnetwork,statusbar,myqrect,rectlist;
}



void Network::init()
{
    initView();
}

void Network::initView()
{
    rectlist = new QList<myQRect*>;

    for(int i=0;i<6;i++){
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

}

void Network::mousePressEvent(QMouseEvent *event)
{

}

void Network::mouseMoveEvent(QMouseEvent *event)
{

}

void Network::mouseReleaseEvent(QMouseEvent *event)
{
    this->close();
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
    drawnetwork->drawNetworkTitle(painter,rectlist->at(NETWORK_TITLE),tr("Network"));
    drawnetwork->drawNetworkWifiText(painter,rectlist->at(NETWORK_WIFITEXT),tr("Wifi"));
    drawnetwork->drawNetworkSwitch(painter,rectlist->at(NETWORK_WIFISWITCH));
    drawnetwork->drawSearchResultTitle(painter,rectlist->at(NETWORK_SEARCHRESULT_TEXT),tr("SearchResult"));
    //  drawnetwork->drawBackIcon();

}
