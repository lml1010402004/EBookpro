#include "network.h"
#include"application.h"
#include"application/rfile.h"
#include"utils/commonutils.h"
#include<QApplication>
#include<QDebug>

const int NETWORK_X[] = {60,500,250,80,250};
const int NETWORK_Y[] = {48,48,130,180,260};
const int NETWORK_W[] = {48,48,100,80,120};
const int NETWORK_HE[] ={48,48,40,30,40};

const int SWITCH_POS[] = {480,180,60,30};


Network::Network(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();
}

Network::~Network()
{
    delete drawnetwork,statusbar,myqrect,rectlist,mysyssetting;
}



void Network::init()
{
    targetwidgetIndex =-1;
    wifi_flag = false;
    mywifiservice = WifiService::getInstance(this);
    connectwifidialog = new ConnectWifiDialog(this);
    mysyssetting = new SysSettings;

    wifilist = new QList<wifiItem*>;

    initConnections();
    initView();
}

void Network::initView()
{
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

    switch_button.setX(SWITCH_POS[0]);
    switch_button.setY(SWITCH_POS[1]);
    switch_button.setWidth(SWITCH_POS[2]);
    switch_button.setHeight(SWITCH_POS[3]);

    drawnetwork = new DrawNetwork;
    statusbar = new StatusBar(this);

}

void Network::initConnections()
{
    mywifiservice->connect(mywifiservice,SIGNAL(sigStatusChanged(QString)),this,SLOT(wifi_StatusChanged(QString)));
    mywifiservice->connect(mywifiservice,SIGNAL(sigRefreshed(QList<TWifi>)),this,SLOT(wifi_RefreshDone(QList<TWifi>)));
//    QObject::connect(connectwifidialog,SIGNAL())

}

void Network::wifi_StatusChanged(QString wifiStatus)
{
    qDebug() << "================== wifi_StatusChanged";
    qDebug() << "================== current wifi status: " << wifiStatus;

    if(wifiStatus.indexOf(QString("SCANNING")) != -1)
    {

    }
    else if(wifiStatus.indexOf(QString("ASSOCIATING")) != -1)
    {


    }
    else if( wifiStatus.indexOf(QString("INACTIVE")) != -1)
    {

    }
    else if(wifiStatus.indexOf(QString("WAY_HANDSHAKE")) != -1)
    {

    }
    else if(wifiStatus.indexOf(QString("COMPLETED")) != -1)
    {
        this->repaint();
    }
    else if(wifiStatus.indexOf(QString("CONNECTED")) != -1)
    {
        qDebug()<<"wifi connect successfully!!!";
        mysyssetting->setConnectWifiMac(targetWifiMac);
        this->repaint();

    }
    else if(wifiStatus.indexOf(QString("DISCONNECTED")) != -1)
    {
        qDebug()<<"wifi disconnect successfully!!!";
        mysyssetting->setConnectWifiMac("");
        this->repaint();

    }
    else if(wifiStatus.indexOf(QString("INTERFACE_DISABLED")) != -1)
    {

    }
    else
    {

    }



}



wifiItem *tempitem;
void Network::wifi_RefreshDone(QList<TWifi> wifi_Lists)
{




    int size = wifi_Lists.length();
    if(size<0){
        return;
    }
    wifilist->clear();
    for(int i=0;i<size;i++){
        tempitem = new wifiItem;
        tempitem->wifi_name = wifi_Lists.at(i).ESSID_NAME;
        tempitem->state_text = wifi_Lists.at(i).ESSID_STATUS;
        tempitem->strength_class = wifi_Lists.at(i).ESSID_SIGNAL;
        tempitem->Encrypt = wifi_Lists.at(i).ESSID_ENCRYP;
        tempitem->WIFI_MAC = wifi_Lists.at(i).ESSID_BSSID;
//        qDebug()<<"wifi_name=="<<tempitem->wifi_name;
        wifilist->append(tempitem);
    }

    if(wifilist->size()%4==0){
        wifiTotalPages = wifilist->size()/4;
    }else{
        wifiTotalPages = wifilist->size()/4+1;
    }

    this->repaint();


}

void Network::connectWifiSlot(QString password)
{

}

void Network::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }
    if(x>SWITCH_POS[0]&&x<SWITCH_POS[0]+SWITCH_POS[2]&&y>SWITCH_POS[1]&&y<SWITCH_POS[1]+SWITCH_POS[3]){
        wifi_flag = !wifi_flag;
        this->repaint();
        if(wifi_flag){
            if(mywifiservice->isEnabled()){
                mywifiservice->doScan();
                mywifiservice->refreshWifiList();
            }else{
                mywifiservice->setEnable(true);
            }
        }else{
                mywifiservice->setEnable(false);
                wifilist->clear();
                mysyssetting->setConnectWifiMac("");

        }
        this->repaint();
    }

}

void Network::mouseMoveEvent(QMouseEvent *event)
{

}

void Network::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetwidgetIndex) {

    case NETWORK_BACKICON:
        this->close();
        break;
    case NETWORK_HOMEICON:
        this->close();
        qApp->exit(0);
        break;
    default:
        break;

    }
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = false;
        targetwidgetIndex =-1;
        this->repaint();
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
    drawnetwork->drawSearchResultTitle(painter,rectlist->at(NETWORK_SEARCHRESULT_TEXT),tr("Results"));
    drawnetwork->drawSwitchButton(painter,switch_button,wifi_flag);

}
