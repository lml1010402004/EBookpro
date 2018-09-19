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
#define LIGHT_BACKICON 0
#define LIGHT_HOMEICON 1
#define LIGHT_HOMETITLE 2
#define LIGHT_MINUS 3
#define LIGHT_PLUS 4

//=========================NETWORK_INDEX=============================
#define NETWORK_BACKICON 0
#define NETWORK_HOMEICON 1
#define NETWORK_TITLE 2
#define NETWORK_WIFITEXT 3
#define NETWORK_SEARCHRESULT_TEXT 4

//=========================USB TRANSFER==============================
#define USB_BACKICON 0
#define USB_HOMEICON 1
#define USB_TITLE 2
#define USB_ICON 3
#define USB_STATE 4
#define USB_DATATRANSFER 5
#define USB_CHRGE 6


//=========================RESTORE MODULE==========================
#define RESTORE_BACKICON 0
#define RESTORE_HOMEICON 1
#define RESTORE_TEXT 2
#define RESTORE_CONFIRM_BUTTON 3

//=======================DATEANDTIME MODULE=============================
#define DATEANDTIME_BACKICON 0
#define DATEANDTIME_HOMEICON 1
#define DATEANDTIME_TITLE 2

//=======================LANGUAGEKEYBOARD=============================
#define LANGUAGEKEYBOARD_BACKICON 0
#define LANGUAGKEYBODRD_HOMEICON 1
#define LANGUAGEKEBOARD_TITLE 2

//=======================OTHER MODULE===========================
#define OTHER_BACKICON 0
#define OTHER_HOMEICON 1
#define OTHER_TITLE 2

//=======================WALL PAPEWR======================
#define WALLPAPER_BACKICON 0
#define WALLPAPER_HOMEICON 1
#define WALLPAPER_TITLE 2


static const QString home_pressed=":/pic/pics/home_pressed.png";
static const QString home_unpress = ":/pic/pics/home_unpress.png";

static const QString back_unpress =":/pic/pics/back_unpress.png";
static const QString back_pressed = ":/pic/pics/back_pressed.png";


static const QString wifi_open=":/pic/pics/open_wifi.png";
static const QString wifi_closed=":/pic/pics/close.png";

#endif // APPLICATION_H
