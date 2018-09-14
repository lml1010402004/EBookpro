#include<string.h>
#include<stdio.h>
#include<QString>
#include<QDebug>
#include "wifiservice.h"
#include<QTextStream>
#include<QFileInfo>
#include<QRegExp>
#include<QTextCodec>
#include<stdlib.h>



WifiService* WifiService::m_Instance = NULL;

WifiService* WifiService::getInstance(QObject *parent)
{
    if(m_Instance)
    {
        return m_Instance;
    }
    m_Instance = new WifiService(parent);
    return m_Instance;
}

WifiService::WifiService(QObject *parent) : QObject(parent)
{
    m_wifiCmd = QString("wpa_cli -p/var/run/wpa_supplicant -iwlan0");
    m_scanFlag = 0;
    m_workTimer = new QTimer(this);
    m_workTimer->setSingleShot(false);

    connect(m_workTimer, SIGNAL(timeout()), this, SLOT(refreshWifiStatus()));
    connect(m_workTimer, SIGNAL(timeout()), this, SLOT(refreshWifiList()));
}


int count = 0;
bool WifiService::isEnabled()
{
   QFileInfo file("/var/tmp/wifi");
       if(file.exists()){
         return true;
       }else {
       return false;
   }
}

void WifiService::setEnable(bool enable)
{
    if (enable)
    {
        if (enableWifi(enable))
        {
            qDebug()<<"enablewifi =true ";
            refreshWifiStatus();
            doScan();
            m_workTimer->start(WORK_TIMER_OUT);
        }
    }
    else
    {
        m_workTimer->stop();
        enableWifi(enable);
    }
}

bool WifiService::enableWifi(bool enable)
{
    char cmd[MAX_LEN];
    bzero(cmd, MAX_LEN);

    if(enable){
         system("/usr/wifi/enablewifi");
//        int ss = sprintf(cmd, "/usr/wifi/enablewifi");
//        qDebug()<<"ss = "<<ss;
    }
    else{
//        int sss = sprintf(cmd, "/usr/wifi/disablewifi");
         system("/usr/wifi/disablewifi");
//        qDebug()<<"sss = "<<sss;
    }
    FILE *pp = popen(cmd, "r");
    if (!pp)
    {
        qDebug() << "enableWifi err!";
        return false;
    }

    pclose(pp);

    return true;
}

void WifiService::readStatus()
{
    char cmd[MAX_LEN];
    char result[MAX_LEN];
    char key[MAX_LEN];
    char value[MAX_LEN];
    bzero(cmd, MAX_LEN);
    bzero(result, MAX_LEN);
    bzero(key, MAX_LEN);
    bzero(value, MAX_LEN);

    sprintf(cmd, "%s status", m_wifiCmd.toLocal8Bit().data());
    FILE *pp = popen(cmd, "r");
    if (!pp)
    {
        qDebug() << "readStatus err!";
        return;
    }

    while(fgets(result, sizeof(result), pp) != NULL)
    {
        sscanf(result, "%[^=]=%s", key, value);

        if(QString(key).indexOf(QString("wpa_state")) != -1)
        {
            m_curWifi.ESSID_STATUS = value;
        }
        else if(QString(key).indexOf(QString("bssid")) != -1)
        {
            m_curWifi.ESSID_BSSID = value;
        }
        else if(QString(key).indexOf(QString("ssid")) != -1)
        {
            m_curWifi.ESSID_NAME = value;
        }
		else if(QString(key).indexOf(QString("ip_address")) != -1)
        {
            if (m_curWifi.ESSID_STATUS.indexOf(QString("COMPLETED")) != -1)
            {
                m_curWifi.ESSID_STATUS = QString("CONNECTED");
                m_curWifi.ESSID_IP = value;
            }
        }
    }

    pclose(pp);
}

void WifiService::refreshWifiStatus()
{
    readStatus();
    if(m_wifiStatus == m_curWifi.ESSID_STATUS)
    {

        return;
    }

    qDebug() << m_curWifi.ESSID_BSSID << m_curWifi.ESSID_NAME << m_curWifi.ESSID_STATUS;
    m_wifiStatus = m_curWifi.ESSID_STATUS;
    emit sigStatusChanged(m_wifiStatus);
}

void WifiService::doScan()
{
    char cmd[MAX_LEN];
    bzero(cmd, MAX_LEN);

    sprintf(cmd, "%s scan", m_wifiCmd.toLocal8Bit().data());
    FILE *pp = popen(cmd, "r");
    if (!pp)
    {
        qDebug() << "doScan err!";
        return;
    }

    pclose(pp);
}

QString WifiService::unicodeToUtf8(QString resStr)
{
    //    ========================wifi.ESSID_NAME=360\xe5\x85\x8d\xe8\xb4\xb9WiFi-31"
       QString temp;
       for(int i=0;i<resStr.length();){
           if(resStr.at(i)=='\\'){
               QString str = resStr.mid(i+2,i+4);
               temp.append(str.mid(0,2).toUShort(0,16));
               i=i+4;
             }else{
               temp.append(resStr.at(i));
               ++i;
           }
       }
//       qDebug()<<"jack====temp="<<temp;
       QTextCodec *codec = QTextCodec::codecForName("UTF-8");
       QString desStr = codec->fromUnicode(temp);
       return QObject::trUtf8(desStr.toLatin1().data());

}

void WifiService::refreshWifiList()
{
    if (m_scanFlag == MAX_SCAN_FLAG)
    {
        m_scanFlag = 0;
        doScan();
    }
    m_scanFlag++;

    char cmd[MAX_LEN];
    char result[MAX_LEN];
    char bssid[MAX_LEN];
    char frequency[MAX_LEN];
    char signal[MAX_LEN];
    char flag[MAX_LEN];
    char ssid[MAX_LEN];
    bzero(cmd, MAX_LEN);
    bzero(result, MAX_LEN);
    bzero(bssid, MAX_LEN);
    bzero(frequency, MAX_LEN);
    bzero(signal, MAX_LEN);
    bzero(flag, MAX_LEN);
    bzero(ssid, MAX_LEN);

    sprintf(cmd, "%s scan_results", m_wifiCmd.toLocal8Bit().data());
    FILE *pp = popen(cmd, "r");
    if (!pp)
    {
        qDebug() << "refreshWifiList err!";
        return;
    }

    fgets(result, sizeof(result), pp);

    m_wifiList.clear();

    while(fgets(result, sizeof(result), pp) != NULL)
    {
        sscanf(result, "%s\t%s\t%s\t%s\t%s\n", bssid, frequency, signal, flag, ssid);

        TWifi wifi;
        wifi.ESSID_NAME =unicodeToUtf8(ssid);
//        wifi.ESSID_NAME = ssid;
        if(QString(flag).indexOf(QString("WPA")) != -1)
        {
            wifi.ESSID_TYPE = "WPA";
        }
        else
        {
            wifi.ESSID_TYPE = "WEP";
        }
        if(QString(flag).indexOf(QString("WPA")) != -1 || QString(flag).indexOf(QString("WEP")) != -1)
        {
            wifi.ESSID_ENCRYP = "YES";
        }
        else
        {
            wifi.ESSID_ENCRYP = "NO";
        }
        wifi.ESSID_PASS = "";
        wifi.ESSID_BSSID = bssid;
        wifi.ESSID_FREQ = frequency;
        wifi.ESSID_SIGNAL = signal;
        wifi.ESSID_FLAG = flag;
        if(wifi.ESSID_BSSID == m_curWifi.ESSID_BSSID)
        {
            wifi.ESSID_STATUS = m_curWifi.ESSID_STATUS;
        }
        else
        {
            wifi.ESSID_STATUS = "";
        }

        m_wifiList.push_back(wifi);
//        qDebug()<<"wifi.ESSID_NAME"<<wifi.ESSID_NAME;
//        qDebug()<<"wifi_ESSID_ENCRYP=="<<wifi.ESSID_ENCRYP;
//        qDebug()<<"wifi.ESSID_TYPE=="<<wifi.ESSID_TYPE;
//        qDebug()<<"=======================================================================";
//        qDebug() << ssid << frequency << signal << flag << bssid << wifi.ESSID_STATUS;
    }

    pclose(pp);

    emit sigRefreshed(m_wifiList);
}

bool WifiService::setCurrentWifi(QString bssid_mac, QString password)
{
    for(QList<TWifi>::Iterator it = m_wifiList.begin(); it != m_wifiList.end(); it++)
    {
        TWifi wifi = *it;
//        qDebug()<<"bssid.mac"<<bssid_mac<<","<<wifi.ESSID_NAME;

        if((bssid_mac.indexOf(wifi.ESSID_BSSID))!=-1)
        {
            qDebug()<<"JACKJACKJACK---wifi.ESSID_BSSID"<<wifi.ESSID_BSSID;
            m_wifiStatus = "";
            m_curWifi = wifi;
            m_curWifi.ESSID_PASS = password;
            break;
        }
    }

    restoreWifi();

    if(!restartWifi())
    {
        return false;
    }

    if(!requestDHCP())
    {
        return false;
    }

    return true;
}

void WifiService::restoreWifi()
{
    char cmdbuf[MAX_LEN];
    char cmdresult[MAX_LEN];

    QString name = m_curWifi.ESSID_NAME;
    QString password = m_curWifi.ESSID_PASS;
    QString encryt = m_curWifi.ESSID_ENCRYP;
    QString type = m_curWifi.ESSID_TYPE;
    qDebug()<<"PASSWORD_TYPE="<<type;
    qDebug()<<"ESSID_NAME="<<name;
    qDebug()<<"PASSWORD="<<password;
    FILE* fp = fopen("/etc/wpa_supplicant.conf", "wb");
    fprintf(fp, "update_config=1\nctrl_interface=/var/run/wpa_supplicant\nap_scan=1\n\n");
    if(encryt.indexOf(QString("NO")) != -1)
    {
        qDebug() << "None Encryption";
        fprintf(fp, "network={\n\tssid=%s\n\tkey_mgmt=NONE\n\tpriority=5\n}\n", name.toAscii().data());
    }
    else if(type.indexOf(QString("WEP")) != -1)
    {
        qDebug() << "WEP Encryption";
        fprintf(fp, "network={\n\tssid=\"%s\"\n\tkey_mgmt=NONE\n\twep_key0=%s\n\twep_tx_keyidx=0\n\tpriority=5\n\tauth_alg=SHARED\n}\n",
                name.toAscii().data(), password.toAscii().data());
    }
    else if(type.indexOf(QString("WPA")) != -1)
    {
        qDebug() << "WPA Encryption";
        bzero(cmdbuf, MAX_LEN);
        bzero(cmdresult, MAX_LEN);
        sprintf(cmdbuf, "wpa_passphrase %s %s", name.toAscii().data(), password.toAscii().data());

        FILE *pp = popen(cmdbuf, "r");
        while(fgets(cmdresult, sizeof(cmdresult), pp))
        {
            fputs(cmdresult, fp);
        }
        pclose(pp);

    }

    fclose(fp);
}

bool WifiService::restartWifi()
{
    bool ret = false;
    char cmd[MAX_LEN];
    char result[MAX_LEN];
    bzero(cmd, MAX_LEN);
    bzero(result, MAX_LEN);

    sprintf(cmd, "%s reconf", m_wifiCmd.toLocal8Bit().data());
    FILE *pp = popen(cmd, "r");
    if (!pp)
    {
        qDebug() << "restartWifi err!";
        return ret;
    }

    while(fgets(result, sizeof(result), pp))
    {
        if (QString(result).indexOf("OK") != -1)
        {
            ret = true;
        }
    }
    pclose(pp);

    return ret;
}

bool WifiService::requestDHCP()
{
    system("killall udhcpc");
    system("udhcpc -i wlan0");
    return true;
}
