#include "mydialog.h"

#include<QDebug>

#define SCALE_CONST 2.34

#define FIX_WIDTH 600*SCALE_CONST
#define FIX_HEIGHT 800*SCALE_CONST
#define SETTING_TITLE_POINT_SIZE 16
#define SETTING_TITLE_SPACE_Y 3
#define TITLE_SPACE_Y 40*SCALE_CONST




MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(FIX_HEIGHT);
    this->setFixedWidth(FIX_WIDTH);

    init();

}

MyDialog::~MyDialog()
{

}


/**
 * @brief MyDialog::paintEvent
 * @param event
 */
void MyDialog::paintEvent(QPaintEvent *event)
{

    painter = new QPainter(this);
    //brush the screen for removing the screen.
    rect.setRect(0,0,600*SCALE_CONST,800*SCALE_CONST);
    painter->fillRect(rect,QBrush(Qt::white));

    pixmap.load(":/pics/pics/back.png");
    painter->drawPixmap(20*SCALE_CONST,20*SCALE_CONST,20*SCALE_CONST,20*SCALE_CONST,pixmap);

    line.setLine(60*SCALE_CONST,20*SCALE_CONST,60*SCALE_CONST,40*SCALE_CONST);
    painter->drawLine(line);

    font.setPointSize(SETTING_TITLE_POINT_SIZE);

    rect.setX(0);
    rect.setY(4*SCALE_CONST);
    rect.setWidth(FIX_WIDTH);
    rect.setHeight(TITLE_SPACE_Y);
    painter->setFont(font);
    painter->drawText(rect,Qt::AlignCenter,QObject::tr("Wlan Transfer Book"));


    line.setLine(0,60*SCALE_CONST,FIX_WIDTH,60*SCALE_CONST);//the height of the title space.
    painter->drawLine(line);
    font.setPointSize(10);
    painter->setFont(font);
    paintContent(painter);
    paintWifiStatus(painter);
    paintStartMTPService(painter);

    delete painter;
    painter = NULL;

}


/**
 * @brief MyDialog::mousePressEvent
 * @param event
 */
void MyDialog::mousePressEvent(QMouseEvent *event)
{
qDebug()<<"event.x"<<event->x();
qDebug()<<"event.y"<<event->y();

int x = event->x();
int y = event->y();
    if(x>20*SCALE_CONST&&x<560*SCALE_CONST&&y>690*SCALE_CONST&&y<750*SCALE_CONST){
        startMTPService();
    }else if(x<60*SCALE_CONST&&y<60*SCALE_CONST){
        this->close();
    }

}


/**
 * start the MTP service.
 * @brief MyDialog::startMTPService
 */
void MyDialog::startMTPService()
{
     wifi = WifiService::getInstance();

    if(wifi->isEnabled()){
         qDebug()<<"========================"<<wifi->getCurrentWifi().ESSID_STATUS;
       if(wifi->getCurrentWifi().ESSID_STATUS.indexOf(QString("CONNECTED"))!=-1){
           qDebug()<<"start samba.............";
             samba = SambaService::getInstance();
             if(!flag){
             samba->setEnable(true);
             flag = true;
             }else{
              samba->setEnable(false);
              flag = false;
             }
        }
  }else{

  qDebug()<<"wifi is not connected, please connect ";

    }

    this->repaint();


}


/**
 * @brief MyDialog::init
 */
void MyDialog::init()
{

   flag = false;


}

void MyDialog::paintContent(QPainter *painter)
{
   rect.setWidth(FIX_WIDTH);
   rect.setHeight(600*SCALE_CONST);
   rect.setX(0);
   rect.setY(40*SCALE_CONST);
   painter->drawText(rect,Qt::AlignCenter,tr("Operate Introduction....."));
}


/**
 * @brief MyDialog::paintWifiStatus
 */
void MyDialog::paintWifiStatus(QPainter *painter)
{

    rect.setX(20*SCALE_CONST);
    rect.setY(640*SCALE_CONST);
    rect.setWidth(FIX_WIDTH);
    rect.setHeight(40*SCALE_CONST);
    painter->drawText(rect,Qt::AlignLeft,tr("Wifi status:connected"));


}


/**
 * @brief MyDialog::paintStartMTPService
 */
void MyDialog::paintStartMTPService(QPainter *painter)
{
    rect.setX(20*SCALE_CONST);
    rect.setY(690*SCALE_CONST);
    rect.setHeight(60*SCALE_CONST);
    rect.setWidth(560*SCALE_CONST);
    painter->drawRect(rect);
    if(!flag){
    painter->drawText(rect,Qt::AlignCenter,tr("Start Service"));
    }else{
        painter->drawText(rect,Qt::AlignCenter,tr("End Service"));
    }

}
