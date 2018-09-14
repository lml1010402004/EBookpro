#ifndef APPLICATION_H
#define APPLICATION_H
#include<QString>

#define GLOBAL_FIXED_WIDTH 600
#define GLOBAL_FIXED_HEIGHT 800

#define LIGHT_INDEX   0
#define WALLPAPER_INDEX 1
#define NETWORK_INDEX 2
#define USBTRANSFER_INDEX 3
#define DATEANDTIME_INDEX 4
#define LANGUAGE_INDEX 5
#define RESTORE_INDEX 6
#define OTHER_INDEX 7



//=========================LIGHT_INDEX==============================
//=========================NETWORK_INDEX=============================
#define NETWORK_BACKICON 0
#define NETWORK_HOMEICON 1
#define NETWORK_TITLE 2
#define NETWORK_WIFITEXT 3
#define NETWORK_WIFISWITCH 4
#define NETWORK_SEARCHRESULT_TEXT 5



static const QString home_pressed=":/pic/pics/home_pressed.png";
static const QString home_unpress = ":/pic/pics/home_unpress.png";

static const QString back_unpress =":/pic/pics/back_unpress.png";
static const QString back_pressed = ":/pic/pics/back_pressed.png";


static const QString wifi_open=":/pic/pics/open_wifi.png";
static const QString wifi_closed=":/pic/pics/close.png";

#endif // APPLICATION_H
