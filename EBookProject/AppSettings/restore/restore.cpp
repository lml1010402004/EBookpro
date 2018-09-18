#include "restore.h"
#include"application.h"
#include"rfile.h"
#include"utils/commonutils.h"
#include<QApplication>
const int RESTORE_X[] = {60,500,250,230};
const int RESTORE_Y[] ={48,48,240,310};
const int RESTORE_W[] ={48,48,140,140};
const int RESTORE_HE[] ={48,48,30,60};


/**
  格式化磁盘
 * @brief formattingDisk
 */
void formattingDisk()
{
    system("umount /user");
    sleep(1);
    system("mkfs.vfat /dev/block/by-name/UDISK");
    sleep(1);
    system("reboot");

}

Restore::Restore(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}

Restore::~Restore()
{
    delete statusbar,drawrestore,myconfirmdialog;

}

void Restore::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter(this);
    statusbar->drawBattery(painter,30);
    statusbar->drawPullDownRectangle(painter);
    statusbar->drawSystemTime(painter,"15:30");
    statusbar->drawWifiStatus(painter,true);


    drawrestore->drawBackIcon(painter,rectlist->at(RESTORE_BACKICON));
    drawrestore->drawHomeIcon(painter,rectlist->at(RESTORE_HOMEICON));
    QLineF line(0,100,600,100);
    painter->drawLine(line);
    drawrestore->drawTitle(painter,rectlist->at(RESTORE_TEXT),tr("Restore"));
    drawrestore->drawConfirmButton(painter,rectlist->at(RESTORE_CONFIRM_BUTTON),tr("Confirm"));



}

void Restore::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    targetwidgetIndex = commonUtils::getTheTargetWidget(x,y,rectlist);

    if(targetwidgetIndex>-1){
        rectlist->at(targetwidgetIndex)->isPressed = true;
        this->repaint();
    }

}

void Restore::mouseMoveEvent(QMouseEvent *event)
{

}

void Restore::mouseReleaseEvent(QMouseEvent *event)
{
    switch(targetwidgetIndex){
    case RESTORE_BACKICON:
        this->close();
        break;
    case RESTORE_HOMEICON:
        this->close();
        qApp->exit(0);
        break;
    case RESTORE_TEXT:
        break;
    case RESTORE_CONFIRM_BUTTON:
        if(myconfirmdialog==NULL)
            myconfirmdialog = new confirmDialog(this);
        myconfirmdialog->show();
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

void Restore::init()
{
    targetwidgetIndex = -1;
    initView();
}

void Restore::initView()
{
    rectlist = new QList<myQRect*>;

    for(int i=0;i<4;i++){
        myqrect = new myQRect;
        myqrect->rect.setX(RESTORE_X[i]);
        myqrect->rect.setY(RESTORE_Y[i]);
        myqrect->rect.setWidth(RESTORE_W[i]);
        myqrect->rect.setHeight(RESTORE_HE[i]);
        myqrect->isPressed = false;
        RFIle::assignMacroDefinition(RESTORE_INDEX,myqrect,i);
        rectlist->append(myqrect);
    }

    drawrestore = new DrawRestore;
    myconfirmdialog = new confirmDialog(this);
    statusbar = new StatusBar(this);

}
