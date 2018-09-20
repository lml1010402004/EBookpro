#include "drawnetwork.h"
#include"utils/application.h"
#include<QDebug>

extern const QString home_pressed;
extern const QString home_unpress;
extern const QString back_unpress;
extern const QString back_pressed;
extern const QString wifi_open;
extern const QString wifi_closed;
QString WIFI1_ICON=":/pic/pics/wifi1_icon.png";

const QString lastpage_unpress = ":/pic/pics/back_unpressed1.png";
const QString lastpage_pressed = ":/pic/pics/back_pressed1.png";
const QString nextpage_unpress = ":/pic/pics/forward_unpressed1.png";
const QString nextpage_pressed = ":/pic/pics/forward_pressed1.png";


int draw_set_net5[16] = {100,320,80,40,50,170,320,80,200,60,20,430,320,80,100,60};
DrawNetwork::DrawNetwork()
{
    mysyssetting = new SysSettings;
}

DrawNetwork::~DrawNetwork()
{
    delete mysyssetting;
}

void DrawNetwork::drawHomeIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,home_pressed);
    }else{
        painter->drawPixmap(rect->rect,home_unpress);
    }
}

void DrawNetwork::drawBackIcon(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,back_pressed);
    }else{
        painter->drawPixmap(rect->rect,back_unpress);
    }
}

void DrawNetwork::drawNetworkTitle(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawNetwork::drawNetworkWifiText(QPainter *painter, myQRect *rect, QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawNetwork::drawNetworkSwitch(QPainter *painter, myQRect *rect)
{
    if(rect->isPressed){
        painter->drawPixmap(rect->rect,wifi_open);
    }else{
        painter->drawPixmap(rect->rect,wifi_closed);
    }
}

void DrawNetwork::drawSearchResultTitle(QPainter *painter, myQRect *rect,QString title)
{
    painter->drawText(rect->rect,title);
}

void DrawNetwork::drawSwitchButton(QPainter *painter, QRect switchbutton, bool checked)
{
    if(checked){
        painter->drawPixmap(switchbutton,wifi_open);
    }else{
        painter->drawPixmap(switchbutton,wifi_closed);
    }
}

void DrawNetwork::drawCurrentWifiItems(QPainter *painter, QList<wifiItem *> *wifilistitem, int currentPage, int totalPages)
{
    if(wifilistitem==NULL){
        return;
    }
    int size = wifilistitem->size();

    //    QList<wifiItem*> templist;

    //    templist= getCurrentPageWifiList(wifilistitem,currentPage,totalPages);


    QRect myrect;
    for(int i=0;i<wifilistitem->size();i++){

        myrect.setX(draw_set_net5[0]-10);
        myrect.setY(draw_set_net5[1]+draw_set_net5[2]*i-5);
        myrect.setWidth(400);
        myrect.setHeight(80);
        painter->drawRect(myrect);//画框

        rect.setX(draw_set_net5[0]);
        rect.setY(draw_set_net5[1]+draw_set_net5[2]*i);
        rect.setWidth(draw_set_net5[3]);
        rect.setHeight(draw_set_net5[4]);

        painter->drawPixmap(rect,WIFI1_ICON);
        rect.setX(draw_set_net5[5]);
        rect.setY(draw_set_net5[6]+draw_set_net5[7]*i+10);
        rect.setWidth(draw_set_net5[8]);
        rect.setHeight(draw_set_net5[9]);
        font.setPixelSize(draw_set_net5[10]);
        painter->setFont(font);
        painter->drawText(rect,wifilistitem->at(i)->wifi_name);

        rect.setX(draw_set_net5[11]);
        rect.setY(draw_set_net5[12]+draw_set_net5[13]*i+10);
        rect.setWidth(draw_set_net5[14]);
        rect.setHeight(draw_set_net5[15]);
        if(wifilistitem->at(i)->WIFI_MAC==mysyssetting->getConnectWifiMac()){
            painter->drawText(rect,QObject::tr("Connected"));
        }else{
            painter->drawText(rect,QObject::tr("Join"));
        }
    }

    //    drawLastAndNextPage(painter,currentPage,totalPages);

}

void DrawNetwork::drawLastAndNextPage(QPainter *painter, int currentPage, int totalPages, myQRect *lastrect, myQRect *pages, myQRect *nextrect)
{
    if(lastrect->isPressed){
        painter->drawPixmap(lastrect->rect,lastpage_pressed);
    }else{
        painter->drawPixmap(lastrect->rect,lastpage_unpress);
    }
    if(nextrect->isPressed){
        painter->drawPixmap(nextrect->rect,nextpage_pressed);
    }else{
        painter->drawPixmap(nextrect->rect,nextpage_unpress);
    }
    painter->drawText(pages->rect,QString::number(currentPage)+"/"+QString::number(totalPages));
}

QList<wifiItem*>* DrawNetwork::getCurrentPageWifiList(QList<wifiItem *> *list, int currentPage, int totalPages)
{
    QList<wifiItem*> *templist = new QList<wifiItem*> ;


    if(currentPage<totalPages){//The data of middle page
        int index =  (currentPage-1)*4;
        for(int i=0;i<4;i++){
            templist->append(list->at(index+i));
        }
    }else if(currentPage==1&&currentPage==totalPages){ //the data of last page
        int tempsize = list->size();
        for(int i=0;i<tempsize;i++){
            templist->append(list->at(i));
        }
    }else if(currentPage>1&&currentPage==totalPages){
        int tempindex = (totalPages-1)*4;
        int size = list->size()%4;
        if(size==0){
            size = 4;
        }
        for(int i=0;i<size;i++){
            templist->append(list->at(tempindex+i));
        }
    }
    return templist;

}
