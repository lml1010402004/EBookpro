#ifndef USBSERVICE_H
#define USBSERVICE_H

#include <QObject>
#include <QTimer>

class UsbService : public QObject
{
    Q_OBJECT
public:
    static UsbService* getInstance(QObject* parent = 0);
    explicit UsbService(QObject *parent = 0);
    bool isEnabled();
    void setEnable(bool enable = true);

signals:
    void sigStatusChanged(QString usbStatus);

private slots:
    void checkUsbStatus();

private:
    static UsbService* m_Instance;
    const static int WORK_TIMER_OUT = 500;
    QTimer* m_workTimer;
    QString m_usbStatus;
};

#endif // USBSERVICE_H
