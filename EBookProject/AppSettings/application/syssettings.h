#ifndef SYSSETTINGS_H
#define SYSSETTINGS_H

#include <QtCore/qglobal.h>
#include <QSettings>
#include <QString>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


#if defined(SYSSETTINGS_LIBRARY)
#  define SYSSETTINGSSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SYSSETTINGSSHARED_EXPORT Q_DECL_IMPORT
#endif

#define SYSSETTINGS_FILE    "/syssettings"
#define LCD_BACKLIGHT       "lcd_backlight"
#define AUTO_SLEEP          "auto_sleep"
#define AUTO_POWEROFF       "auto_poweroff"
#define SET_WALLPAPER       "set_wallpaper"
#define SET_SHUTDOWN_WALLPAPER "set_shutdown_wallpaper"
#define CONNECTEDWIFIMAC "connected_wifi_mac"
#define SYSTEM_LANGUAGE "system_language"



#define LCD_BACKLIGHT_DEF       0
#define AUTO_SLEEP_DEF          120
#define AUTO_POWEROFF_DEF       8

typedef enum
{
  AUTO_SLEEP_15S = 15,
  AUTO_SLEEP_30S = 30,
  AUTO_SLEEP_1M = 60,
  AUTO_SLEEP_5M = 5*60,
  AUTO_SLEEP_NEVRE = -1,
}AUTOSLEEP;


typedef enum
{
    ATUO_POWEROFF_8H = 8,
    ATUO_POWEROFF_12H = 12,
    ATUO_POWEROFF_24H = 24,
    ATUO_POWEROFF_48H = 48,
    ATUO_POWEROFF_NEVER = -1,

}AUTOPOWEROFF;

#define LCD_STEP_NUM        (16)
#define LCD_STEP_VAULE      (256/LCD_STEP_NUM)

class Lcd_backlight
{
public:
    Lcd_backlight();

     int getLight();
     void setLight(int value);
     void enableLight();
     void disableLight();

private:

};

class SYSSETTINGSSHARED_EXPORT SysSettings
{

public:
    SysSettings();

    void init();

    int getBackLight();
    int setBackLight(int value);

    int getAutoSleepTime();
    int setAutoSleepTime(int value);

    int getAutoPoweroffTime();
    int setAutoPoweroffTime(int value);

    int enableBackLight();
    int disableBackLight();

    void setWallPaper(int value);
    int getWallPaper();

    void setShutDownWallPaper(int value);
    int getShutDownWallPaper();

    void setConnectWifiMac(QString mac);
    QString getConnectWifiMac();

    void setLanguage(QString str);
    QString getLanguage();

private:
    QSettings *syssettings;
    Lcd_backlight *lcdbacklight;
};

#endif // SYSSETTINGS_H
