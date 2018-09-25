#include "network.h"
#include"application.h"
#include"application/rfile.h"
#include"utils/commonutils.h"
#include<QApplication>
#include<QDebug>
#include"application/pulldownwindow.h"

const int NETWORK_X[] = {60,500,250,80,250,160,282,400};
const int NETWORK_Y[] = {48,48,130,180,260,660,670,660};
const int NETWORK_W[] = {48,48,100,80,120,40,80,40};
const int NETWORK_HE[] ={48,48,40,30,40,40,40,40};

const int SWITCH_POS[] = {480,180,60,30};

const int MAXITEM_EACHPAGE = 4;

extern int draw_set_net5[16];
extern int ITEM_WIDTH;
extern int ITEM_HEIGHT;

extern PulldownWindow *pulldownwindow;
extern int pulldownwindowrect[];

Network::Network(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();
}

Network::~Network()
{
    delete drawnetwork,statusbar,myqrect,rectlist,mysyssetting,currentpagewifilist,connectwifidialog;
}



void Network::init()
{
    first_come_in = true;
    targetwidgetIndex =-1;
    wifiCurrentPage =0;
    wifiTotalPages =0;
    wifi_flag = false;
    mywifiservice = WifiService::getInstance(this);
    connectwifidialog = new ConnectWifiDialog(this);
    mysyssetting = new SysSettings;
    currentpagewifilist = new QList<wifiItem*>;
    wifilist = new QList<wifiItem*>;
    connectwifidialog = new ConnectWifiDialog(this);


    initConnections();
    initView();
}

void Network::initView()
{
    rectlist = new QList<myQRect*>;

    for(int i=0;i<8;i++){
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

QList<wifiItem*>* Network::getCurrentPageWifiList(QList<wifiItem *> *list, int currentPage, int totalPages)
{
    if(list->size()==0){
        return NULL;
    }
    QList<wifiItem*> *templist = new QList<wifiItem*> ;
    if(currentPage<totalPages){//The data of middle page
        int index =  (currentPage-1)*MAXITEM_EACHPAGE;
        for(int i=0;i<MAXITEM_EACHPAGE;i++){
            templist->append(list->at(index+i));
        }
    }else if(currentPage==1&&currentPage==totalPages){ //the data of last page
        int tempsize = list->size();
        for(int i=0;i<tempsize;i++){
            templist->append(list->at(i));
        }
    }else if(currentPage>1&&currentPage==totalPages){
        int tempindex = (totalPages-1)*MAXITEM_EACHPAGE;
        int size = list->size()%MAXITEM_EACHPAGE;
        if(size==0){
            size = MAXITEM_EACHPAGE;
        }
        for(int i=0;i<size;i++){
            templist->append(list->at(tempindex+i));
        }
    }
    return templist;

}

void Network::clickWifiListat(int x, int y, QList<wifiItem *> *list)
{
    if(list==NULL||list->size()==0)
        return ;
    int size = list->size();
    int y1 = draw_set_net5[1];
    int y2 = y1+ITEM_HEIGHT;
    int y3 = y2+ITEM_HEIGHT;
    int y4 = y3+ITEM_HEIGHT;
    int y5 = y4+ITEM_HEIGHT;
    if(x>draw_set_net5[0]-10&&x<draw_set_net5[0]+ITEM_WIDTH){
        if(y>y1&&y<y2&&size>0){
            connectwifidialog->show();
        }else if(y>y2&&y<y3&&size>1){
            connectwifidialog->show();
        }else if(y>y3&&y<y4&&size>2){
            connectwifidialog->show();
        }else if(y>y4&&y<y5&&size>3){
            connectwifidialog->show();
        }
    }

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
        wifilist->append(tempitem);
    }
    if(wifilist->size()%MAXITEM_EACHPAGE==0){
        wifiTotalPages = wifilist->size()/MAXITEM_EACHPAGE;
    }else{
        wifiTotalPages = wifilist->size()/MAXITEM_EACHPAGE+1;
    }
    if(first_come_in){
        first_come_in = false;
        wifiCurrentPage = 1;
        currentpagewifilist = getCurrentPageWifiList(wifilist,wifiCurrentPage,wifiTotalPages);
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
            wifiCurrentPage = 0;
            wifiTotalPages =0;
            first_come_in = true;
            mysyssetting->setConnectWifiMac("");
            currentpagewifilist = getCurrentPageWifiList(wifilist,wifiCurrentPage,wifiTotalPages);
        }
        this->repaint();
    }

    clickWifiListat(x,y,currentpagewifilist);


    if(x>pulldownwindowrect[0]&&x<(pulldownwindowrect[0]+pulldownwindowrect[2])&&
            y<pulldownwindowrect[3]){
        if(pulldownwindow==NULL){
            pulldownwindow = new PulldownWindow(this);
        }
        pulldownwindow->show();
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
    case NETWORK_LASTPAGE_BUTTON:
        if(wifiCurrentPage>1){
            wifiCurrentPage--;
            currentpagewifilist = getCurrentPageWifiList(wifilist,wifiCurrentPage,wifiTotalPages);
        }
        break;
    case NETWORK_PAGES_TEXT:
        break;
    case NETWORK_NEXTPAGE_BUTTON:
        if(wifiCurrentPage<wifiTotalPages)
            wifiCurrentPage++;
        currentpagewifilist = getCurrentPageWifiList(wifilist,wifiCurrentPage,wifiTotalPages);
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
    drawnetwork->drawCurrentWifiItems(painter,currentpagewifilist,wifiCurrentPage,wifiTotalPages);
    drawnetwork->drawLastAndNextPage(painter,wifiCurrentPage,wifiTotalPages,rectlist->at(NETWORK_LASTPAGE_BUTTON),rectlist->at(NETWORK_PAGES_TEXT),rectlist->at(NETWORK_NEXTPAGE_BUTTON));
}
