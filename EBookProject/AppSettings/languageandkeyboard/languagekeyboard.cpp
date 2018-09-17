#include "languagekeyboard.h"
#include"application.h"
#include"rfile.h"


const int KEYBOARD_X[] ={60,500,240};
const int KEYBOARD_Y[]={48,48,130};
const int KEYBAORD_W[]={48,48,120};
const int KEYBOARD_HE[]={48,48,30};
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
    this->close();
}

void LanguageKeyboard::mouseMoveEvent(QMouseEvent *event)
{

}

void LanguageKeyboard::mouseReleaseEvent(QMouseEvent *event)
{

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
    drawlanguagekeyboard->drawLanguageTitle(painter,rectlist->at(LANGUAGEKEBOARD_TITLE),tr("Languagekeyboard"));


}

void LanguageKeyboard::init()
{
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
