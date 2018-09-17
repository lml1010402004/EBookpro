#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "usbservice.h"

UsbService* UsbService::m_Instance = NULL;

UsbService* UsbService::getInstance(QObject *parent)
{
    if(m_Instance)
    {
        return m_Instance;
    }

    m_Instance = new UsbService(parent);
    return m_Instance;
}

UsbService::UsbService(QObject *parent) : QObject(parent)
{
    m_workTimer = new QTimer(this);
    m_workTimer->setSingleShot(false);
    connect(m_workTimer, SIGNAL(timeout()), this, SLOT(checkUsbStatus()));
    m_workTimer->start(WORK_TIMER_OUT);
}

void UsbService::checkUsbStatus()
{

    QFile stateFile("/sys/class/android_usb/android0/state");
    if(!stateFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open usb state file failed!";
        return;
    }

    QTextStream valueInput(&stateFile);
    QString state = valueInput.readLine();
    if(state == m_usbStatus)
    {
        stateFile.close();
        return;
    }

    m_usbStatus = state;
    stateFile.close();
    qDebug()<<"m_usbStatus=="<<m_usbStatus;
    emit sigStatusChanged(m_usbStatus);
}

bool UsbService::isEnabled()
{
    bool enable = false;

    QFile lunFile("/sys/class/android_usb/android0/f_mass_storage/lun/file");
    if(!lunFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Open usb lun file failed!";
        return enable;
    }

    QTextStream valueInput(&lunFile);
    QString value = valueInput.readLine();
    //qDebug() << "Usb lun file value: " << value;
    if (value.indexOf(QString("/dev/mmcblk0p1")) != -1)
    {
        enable = true;
    }

    lunFile.close();

    return enable;
}

void UsbService::setEnable(bool enable)
{
    QFile lunFile("/sys/class/android_usb/android0/f_mass_storage/lun/file");
    if(!lunFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        qDebug() << "Open usb lun file failed!";
        return;
    }

    QString value(enable ? "/dev/mmcblk0p1" : "");
    QTextStream valueOutput(&lunFile);
    valueOutput << value << endl;
    lunFile.close();
}
