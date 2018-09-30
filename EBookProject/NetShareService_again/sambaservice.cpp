#include "sambaservice.h"

SambaService* SambaService::m_Instance = NULL;

SambaService* SambaService::getInstance(QObject *parent)
{
    if(m_Instance)
    {
        return m_Instance;
    }

    m_Instance = new SambaService(parent);
    return m_Instance;
}

SambaService::SambaService(QObject *parent) : QObject(parent)
{
    enabled = false;
    wifiService = WifiService::getInstance();
    wifiService->connect(wifiService, SIGNAL(sigStatusChanged(QString)), this, SLOT(wifi_StatusChanged(QString)));
}

void SambaService::setEnable(bool enable)
{
    if (enable)
    {
        system("smbd -D");
    }
    else
    {
        system("killall smbd");
    }

    enabled = enable;
}

void SambaService::wifi_StatusChanged(QString wifiStatus)
{
    if(wifiStatus.indexOf(QString("CONNECTED")) == -1)
    {
        setEnable(false);
    }

}
