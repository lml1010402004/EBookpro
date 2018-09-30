#ifndef SAMBASERVICE_H
#define SAMBASERVICE_H
#include <QObject>
#include "wifiservice.h"

class SambaService: public QObject
{
    Q_OBJECT

public:
    static SambaService* getInstance(QObject* parent = 0);
    SambaService(QObject* parent = 0);
    bool isEnabled() {return enabled;}
    void setEnable(bool enable = true);

private slots:
    void wifi_StatusChanged(QString wifiStatus);

private:
    static SambaService* m_Instance;
     WifiService* wifiService;
     bool enabled;
};

#endif // SAMBASERVICE_H
