#ifndef WIFISERVICE_H
#define WIFISERVICE_H

#include<QObject>
#include<QTimer>
#include<QMetaType>
#include<QString>

struct TWifi
{
    QString ESSID_NAME;
    QString ESSID_TYPE;
    QString ESSID_ENCRYP;
    QString ESSID_PASS;
    QString ESSID_BSSID;
    QString ESSID_FREQ;
    QString ESSID_SIGNAL;
    QString ESSID_FLAG;
    QString ESSID_STATUS;
	QString ESSID_IP;
};
Q_DECLARE_METATYPE(TWifi)
Q_DECLARE_METATYPE(QList<TWifi>)

class WifiService : public QObject
{
    Q_OBJECT

public:
    static WifiService* getInstance(QObject* parent = 0);
    explicit WifiService(QObject *parent = 0);
    bool isEnabled();
    void setEnable(bool enable = true);
    TWifi getCurrentWifi() { return m_curWifi; }
    bool setCurrentWifi(QString bssid_mac, QString password = "");
    void doScan();
    QString unicodeToUtf8(QString resStr);



signals:
    void sigScanning();
    void sigDisConnected();
    void sigConnecting();
    void sigConnected();
    void sigRefreshed(QList<TWifi> wifiList);
    void sigStatusChanged(QString wifiStatus);

public slots:
    void refreshWifiStatus();
    void refreshWifiList();

private:
    bool enableWifi(bool enable);
    void readStatus();

    void restoreWifi();
    bool restartWifi();
    bool requestDHCP();

private:
    static WifiService* m_Instance;
    const static int MAX_LEN = 2048;
    const static int WORK_TIMER_OUT = 3000;
    const static int MAX_SCAN_FLAG = 12;
    int m_scanFlag;
    QTimer* m_workTimer;
    QList<TWifi> m_wifiList;
    TWifi m_curWifi;
    QString m_wifiStatus;
    QString m_wifiCmd;
};

#endif // WIFISERVICE_H
