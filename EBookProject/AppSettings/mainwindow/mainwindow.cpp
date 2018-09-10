#include "mainwindow.h"
#include"application.h"

const int homexywh[] = {500,48,48,48};

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);

    init();

}


MainWindow::~MainWindow(){

}

void MainWindow::init(){


    initView();

}

void MainWindow::initView(){

    myrect = new myQRect;
    myrect->rect.setX(homexywh[0]);
    myrect->rect.setY(homexywh[1]);
    myrect->rect.setWidth(homexywh[2]);
    myrect->rect.setHeight(homexywh[3]);
    myrect->isPressed = false;//home button

    pulldownwindow = new PulldownWindow(this);
    statusbar = new StatusBar(this);
    drawmainwindow = new DrawMainWindow;

}



void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event){
  QPainter *painter = new QPainter(this);
  statusbar->drawBattery(painter,30);
  statusbar->drawPullDownRectangle(painter);
  statusbar->drawSystemTime(painter,"15:30");
  statusbar->drawWifiStatus(painter,true);

  drawmainwindow->drawHomeIcon(painter,myrect);



}

void MainWindow::mousePressEvent(QMouseEvent *event){

 int x = event->x();
 int y = event->y();
if(x>homexywh[0]&&x<homexywh[0]+homexywh[2]&&y>homexywh[1]&&y<homexywh[1]+homexywh[3]){
   myrect->isPressed = true;
   this->repaint();
}

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
  int x = event->x();
  int y = event->y();

  if(x>homexywh[0]&&x<homexywh[0]+homexywh[2]&&y>homexywh[1]&&y<homexywh[1]+homexywh[3]){
     myrect->isPressed = false;
     this->close();
//     this->repaint();
  }
}
