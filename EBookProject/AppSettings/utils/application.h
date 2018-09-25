#ifndef APPLICATION_H
#define APPLICATION_H
#include<QString>

#define GLOBAL_FIXED_WIDTH 600
#define GLOBAL_FIXED_HEIGHT 800

#define LIGHT_INDEX   0
#define WALLPAPER_INDEX 1
#define NETWORK_INDEX 2
#define NETWORK_CONN_WIFI 22
#define USBTRANSFER_INDEX 3
#define DATEANDTIME_INDEX 4
#define LANGUAGE_INDEX 5
#define RESTORE_INDEX 6
#define OTHER_INDEX 7
#define SLEEPTIMESET 8
#define DEVICEINFO 9

#define TIMEDIALOG 10



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
#define NETWORK_LASTPAGE_BUTTON 5
#define NETWORK_PAGES_TEXT 6
#define NETWORK_NEXTPAGE_BUTTON 7

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

//=======================CONNECT WIFI DIALOG===================
#define CONN_WIFI_TITLE 0
#define CONN_WIFI_TEXT 1
#define CONN_WIFI_EDIT 2
#define CONN_WIFI_CONN_BUTTON 3
#define CONN_WIFI_CANCLE_BUTTON 4

//====================SLEEP TIME SET=====================
#define SLEEP_TIME_BACK 0
#define SLEEP_TIME_HOMEICON 1
#define SLEEP_TIME_TITLE 2

//====================DEVICE INFO================
#define DEVICE_INFO_BACKICON 0
#define DEVICE_INFO_HOMEICON 1
#define DEVICE_INFO_TITLE 2

//===================TIME DIALOG=========================
#define TIMEDIALOG_TITLE 0
#define TIMEDIALOG_YES 1
#define TIMEDIALOG_NO 2




static const QString home_pressed=":/pic/pics/home_pressed.png";
static const QString home_unpress = ":/pic/pics/home_unpress.png";

static const QString back_unpress =":/pic/pics/back_unpress.png";
static const QString back_pressed = ":/pic/pics/back_pressed.png";


static const QString wifi_open=":/pic/pics/open_wifi.png";
static const QString wifi_closed=":/pic/pics/close.png";

#endif // APPLICATION_H
