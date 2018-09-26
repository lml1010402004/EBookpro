#include "connectwifidialog.h"
#include<QHBoxLayout>
#include<QCursor>
#include<QApplication>
#include"rfile.h"
#include"application.h"
#include"commonutils.h"

const int CONN_WIFI_X[] = {120,30,30,30,245};
const int CONN_WIFI_Y[] = {30,90,100,200,200};
const int CONN_WIFI_W[] = {100,100,340,125,125};
const int CONN_WIFI_HE[] = {30,30,30,40,40};


ConnectWifiDialog::ConnectWifiDialog(QWidget *parent) : QDialog(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setGeometry(QRect(100,150,400,300));
    QHBoxLayout *midlayout = new QHBoxLayout;
    mylineedit = new QLineEdit(this);
    midlayout->addWidget(mylineedit);
    midlayout->setGeometry(QRect(0,0,400,300));

    setLayout(midlayout);
    QCursor cursor(0);
    mylineedit->setCursor(cursor);
    init();
}

ConnectWifiDialog::~ConnectWifiDialog()
{
    for(int i=0;i<rectlist->size();i++){
        delete rectlist->at(i);
    }
    delete mylineedit,drawconnectwifidialog,rectlist,myqrect;
}

void ConnectWifiDialog::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    drawconnectwifidialog->drawTargetWifiTitle(painter,rectlist->at(CONN_WIFI_TITLE),"RE-TEST");
    drawconnectwifidialog->drawWifiText(painter,rectlist->at(CONN_WIFI_TEXT),tr("Notice"));
    drawconnectwifidialog->drawConnOrCancleButton(painter,rectlist->at(CONN_WIFI_CONN_BUTTON),tr("Conn"));
    drawconnectwifidialog->drawConnOrCancleButton(painter,rectlist->at(CONN_WIFI_CANCLE_BUTTON),tr("Cancle"));

}

void ConnectWifiDialog::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }

}

void ConnectWifiDialog::mouseReleaseEvent(QMouseEvent *event)
{
    switch(targetwidgetIndex){
    case CONN_WIFI_CONN_BUTTON:
        if( !mylineedit->text().isEmpty()){
            emit closeWindows1(mylineedit->text());
            mylineedit->clear();
        }
        break;
    case CONN_WIFI_CANCLE_BUTTON:
        break;
    default:
        break;
    }
    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = false;
        targetwidgetIndex = -1;
        this->repaint();
    }

}

void ConnectWifiDialog::init()
{
    drawconnectwifidialog = new DrawConnectWifiDialog;
    initView();
    initConnections();
}

void ConnectWifiDialog::initView()
{
    rectlist = new QList<myQRect*>;
    for(int i=0;i<5;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(CONN_WIFI_X[i]);
        myqrect->rect.setY(CONN_WIFI_Y[i]);
        myqrect->rect.setWidth(CONN_WIFI_W[i]);
        myqrect->rect.setHeight(CONN_WIFI_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(NETWORK_CONN_WIFI,myqrect,i);
        rectlist->append(myqrect);
    }
}

void ConnectWifiDialog::initConnections()
{

}
