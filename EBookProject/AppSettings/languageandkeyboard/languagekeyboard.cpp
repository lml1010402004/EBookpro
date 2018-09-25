#include "languagekeyboard.h"
#include"application.h"
#include"rfile.h"
#include"commonutils.h"
#include<QApplication>
#include"mainwindow.h"


const int KEYBOARD_X[] ={60,500,240};
const int KEYBOARD_Y[]={48,48,130};
const int KEYBAORD_W[]={48,48,120};
const int KEYBOARD_HE[]={48,48,30};

extern int items_xywh[8][4];
extern int item_text_xywh[8][4];
extern int item_icon_xywh[8][4];


LanguageKeyboard::LanguageKeyboard(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();
}

LanguageKeyboard::~LanguageKeyboard()
{

}

void LanguageKeyboard::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetWidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetWidgetIndex>-1){
        rectlist->at(targetWidgetIndex)->isPressed = true;
        this->repaint();
    }
}

void LanguageKeyboard::mouseMoveEvent(QMouseEvent *event)
{

}

void LanguageKeyboard::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetWidgetIndex) {
    case LANGUAGEKEYBOARD_BACKICON:
        this->close();
        break;
    case LANGUAGKEYBODRD_HOMEICON:
        this->close();
        qApp->exit(0);
        break;
    case LANGUAGEKEBOARD_TITLE:
        break;
    default:
        break;
    }

    if(targetWidgetIndex>-1){
        rectlist->at(targetWidgetIndex)->isPressed = false;
        this->repaint();
    }
}

void LanguageKeyboard::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);

    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawlanguagekeyboard->drawBackIcon(painter,rectlist->at(LANGUAGEKEYBOARD_BACKICON));
    drawlanguagekeyboard->drawHomeIcon(painter,rectlist->at(LANGUAGKEYBODRD_HOMEICON));
    drawlanguagekeyboard->drawLanguageTitle(painter,rectlist->at(LANGUAGEKEBOARD_TITLE),tr("Languages"));

    drawlanguagekeyboard->drawItems(painter,systemitemlist);


}

void LanguageKeyboard::init()
{
    systemitemlist = new QList<SystemItems*>;
    item = new SystemItems;
    item = new SystemItems;
    item->itemrect.setX(items_xywh[0][0]);
    item->itemrect.setY(items_xywh[0][1]);
    item->itemrect.setWidth(items_xywh[0][2]);
    item->itemrect.setHeight(items_xywh[0][3]);

    item->itemtextrect.setX(item_text_xywh[0][0]);
    item->itemtextrect.setY(item_text_xywh[0][1]);
    item->itemtextrect.setWidth(item_text_xywh[0][2]);
    item->itemtextrect.setHeight(item_text_xywh[0][3]);

    item->setItem_text_text(tr("Language"));

    item->itemiconrect.setX(item_icon_xywh[0][0]);
    item->itemiconrect.setY(item_icon_xywh[0][1]);
    item->itemiconrect.setWidth(item_icon_xywh[0][2]);
    item->itemiconrect.setHeight(item_icon_xywh[0][3]);
    //        item->item_icon_path = item_icon_paths[i];
    item->ispressed = false;
    systemitemlist->append(item);


    drawlanguagekeyboard = new DrawLanguagekeyboard;
    statusbar = new StatusBar(this);
    rectlist = new QList<myQRect*>;
    for(int i=0;i<3;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(KEYBOARD_X[i]);
        myqrect->rect.setY(KEYBOARD_Y[i]);
        myqrect->rect.setWidth(KEYBAORD_W[i]);
        myqrect->rect.setHeight(KEYBOARD_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(LANGUAGE_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }


}
