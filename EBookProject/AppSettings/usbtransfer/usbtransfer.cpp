#include "usbtransfer.h"
#include"application.h"


UsbTransfer::UsbTransfer(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    this->setFixedHeight(GLOBAL_FIXED_HEIGHT);
    this->setFixedWidth(GLOBAL_FIXED_WIDTH);
}

UsbTransfer::~UsbTransfer()
{

}

void UsbTransfer::init()
{

}
