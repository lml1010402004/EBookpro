#include "syssettings.h"


SysSettings::SysSettings()
{
    QString filename = QString(SYSSETTINGS_FILE);
    syssettings = new QSettings(filename, QSettings::IniFormat);
    lcdbacklight = new Lcd_backlight;
}


void SysSettings::init()
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str= QString(LCD_BACKLIGHT);
    syssettings->setValue(str, LCD_BACKLIGHT_DEF);
    str= QString(AUTO_SLEEP);
    syssettings->setValue(str, AUTO_SLEEP_DEF);
    str= QString(AUTO_POWEROFF);
    syssettings->setValue(str, AUTO_POWEROFF_DEF);
    syssettings->endGroup();
}

int SysSettings::getBackLight()
{
    QString str;
    int value;
    syssettings->beginGroup("Syssettings");
    str= QString(LCD_BACKLIGHT);
    value = syssettings->value(str).toInt();
    syssettings->endGroup();
    return value;
}

int SysSettings::setBackLight(int value)
{
    QString str;
    int oldvalue, level;
    syssettings->beginGroup("Syssettings");
    str= QString(LCD_BACKLIGHT);
    oldvalue = syssettings->value(str).toInt();
    syssettings->setValue(str, value);
    syssettings->endGroup();
    level = value * LCD_STEP_VAULE;
    lcdbacklight->setLight(level);
    return oldvalue;

}

int SysSettings::getAutoSleepTime()
{
    QString str;
    int value;
    syssettings->beginGroup("Syssettings");
    str= QString(AUTO_SLEEP);
    value = syssettings->value(str,30).toInt();
    syssettings->endGroup();
    return value;

}

int SysSettings::setAutoSleepTime(int value)
{
    QString str;
    int oldvalue;
    syssettings->beginGroup("Syssettings");
    str= QString(AUTO_SLEEP);
    oldvalue = syssettings->value(str).toInt();
    syssettings->setValue(str, value);
    syssettings->endGroup();
    return oldvalue;

}

int SysSettings::getAutoPoweroffTime()
{
    QString str;
    int value;
    syssettings->beginGroup("Syssettings");
    str= QString(AUTO_POWEROFF);
    value = syssettings->value(str,86400).toInt();
    syssettings->endGroup();
    return value;

}

int SysSettings::setAutoPoweroffTime(int value)
{
    QString str;
    int oldvalue;
    syssettings->beginGroup("Syssettings");
    str= QString(AUTO_POWEROFF);
    oldvalue = syssettings->value(str).toInt();
    syssettings->setValue(str, value);
    syssettings->endGroup();
    return oldvalue;

}

int SysSettings::enableBackLight()
{
    lcdbacklight->enableLight();

}

int SysSettings::disableBackLight()
{
    lcdbacklight->disableLight();

}

void SysSettings::setWallPaper(int value)
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str = QString(SET_WALLPAPER);
    syssettings->setValue(str,value);
    syssettings->endGroup();

}

int SysSettings::getWallPaper()
{
   QString str;
    syssettings->beginGroup("Syssettings");
    str = QString(SET_WALLPAPER);
    int s = (syssettings->value(str,0).toInt());
    syssettings->endGroup();
    return s;

}

void SysSettings::setShutDownWallPaper(int value)
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str = QString(SET_SHUTDOWN_WALLPAPER);
    syssettings->setValue(str,value);
    syssettings->endGroup();
}

int SysSettings::getShutDownWallPaper()
{
    QString str;
     syssettings->beginGroup("Syssettings");
     str = QString(SET_SHUTDOWN_WALLPAPER);
     int s = (syssettings->value(str,0).toInt());
     syssettings->endGroup();
     return s;

}

void SysSettings::setConnectWifiMac(QString mac)
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str = QString(CONNECTEDWIFIMAC);
    syssettings->setValue(str,mac);
    syssettings->endGroup();

}

QString SysSettings::getConnectWifiMac()
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str = QString(CONNECTEDWIFIMAC);
    QString str1 =syssettings->value(str,"").toString();
    syssettings->endGroup();
    return str1;
}

void SysSettings::setLanguage(QString str)
{
    QString temp;
    syssettings->beginGroup("Syssettings");
    temp = QString(SYSTEM_LANGUAGE);
    syssettings->setValue(temp,str);
    syssettings->endGroup();

}

QString SysSettings::getLanguage()
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str =QString(SYSTEM_LANGUAGE);
    QString str1 = syssettings->value(str,"English").toString();
    syssettings->endGroup();
    return str1;

}

void SysSettings::setRefreshCount(int value)
{

    QString temp;
    syssettings->beginGroup("Syssettings");
    temp = QString(REFRESH_COUNT);
    syssettings->setValue(temp,value);
    syssettings->endGroup();

}

int SysSettings::getRefreshCount()
{
    QString str;
    syssettings->beginGroup("Syssettings");
    str =QString(REFRESH_COUNT);
    int count = syssettings->value(str,0).toInt();
    syssettings->endGroup();
    return count;

}



