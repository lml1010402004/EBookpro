#include "usbtransfer.h"
#include"application.h"
#include"rfile.h"
#include"utils/commonutils.h"
#include<QApplication>

const int USB_X[] = {60,500,250,210,260,120,340};
const int USB_Y[] = {48,48,130,210,380,460,460};
const int USB_W[] = {48,48,100,180,80,140,140};
const int USB_HE[] = {48,48,40,80,30,40,40};

extern int homexywh[];

UsbTransfer::UsbTransfer(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
    init();

}

UsbTransfer::~UsbTransfer()
{
    for(int i=0;i<rectlist->size();i++){
        delete rectlist->at(i);
    }
    delete statusbar,drawusbtransfer,rectlist,myqrect;
}

void UsbTransfer::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetiIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetiIndex>-1){
        rectlist->at(targetwidgetiIndex)->isPressed = true;
        this->repaint();
    }





}

void UsbTransfer::paintEvent(QPaintEvent *event)
{
    QPainter *painter =new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);
    QLineF line(0,100,600,100);
    painter->drawLine(line);

    drawusbtransfer->drawBackIcon(painter,rectlist->at(USB_BACKICON));
    drawusbtransfer->drawHomeIcon(painter,rectlist->at(USB_HOMEICON));
    drawusbtransfer->drawLogo(painter,rectlist->at(USB_ICON));
    drawusbtransfer->drawTitle(painter,rectlist->at(USB_TITLE),tr("USB_TRANS"));
    drawusbtransfer->drawState(painter,rectlist->at(USB_STATE),tr("Unconn"));
    drawusbtransfer->drawDataTransfer(painter,rectlist->at(USB_DATATRANSFER));
    drawusbtransfer->drawChargeOnly(painter,rectlist->at(USB_CHRGE));



}

void UsbTransfer::mouseReleaseEvent(QMouseEvent *event)
{
    switch (targetwidgetiIndex) {
    case 0:
        this->close();
        break;
    case 1:
        this->close();
        qApp->exit(0);
        break;
    case 5:
        //transfer data funciton
        if(!usbservice->isEnabled()){
          usbservice->setEnable(true);
        }
        break;
    case 6:
        usbservice->setEnable(false);
        this->close();
        //check all the data in the directory.
//        QList<localDire>
        break;
    default:
        break;
    }
    if(targetwidgetiIndex>-1){
        rectlist->at(targetwidgetiIndex)->isPressed = false;
        targetwidgetiIndex = -1;
        this->repaint();
    }

}

void UsbTransfer::init()
{
    targetwidgetiIndex = -1;
    usbservice = UsbService::getInstance(this);

    initView();

}

void UsbTransfer::initView()
{
    statusbar = new StatusBar(this);
    drawusbtransfer = new DrawUsbtransfer();
    rectlist = new QList<myQRect*>;

    for(int i=0;i<7;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(USB_X[i]);
        myqrect->rect.setY(USB_Y[i]);
        myqrect->rect.setWidth(USB_W[i]);
        myqrect->rect.setHeight(USB_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(USBTRANSFER_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }


}
