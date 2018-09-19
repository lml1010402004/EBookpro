#include "rfile.h"
#include"application.h"

RFIle::RFIle()
{

}

void RFIle::assignMacroDefinition(int module, myQRect *rect, int index)
{
    switch (module) {
    case LIGHT_INDEX:
        switch (index) {
        case LIGHT_BACKICON:
            rect->xid = LIGHT_BACKICON;
            break;
        case LIGHT_HOMEICON:
            rect->xid = LIGHT_HOMEICON;
            break;
        case LIGHT_HOMETITLE:
            rect->xid = LIGHT_HOMETITLE;
            break;
        case LIGHT_MINUS:
            rect->xid = LIGHT_MINUS;
            break;
        case LIGHT_PLUS:
            rect->xid  = LIGHT_PLUS;
            break;
        default:
            break;
        }

        break;
    case WALLPAPER_INDEX:
        switch (index) {
        case WALLPAPER_BACKICON:
           rect->xid = WALLPAPER_BACKICON;
            break;
        case WALLPAPER_HOMEICON:
            rect->xid = WALLPAPER_HOMEICON;
            break;
        case WALLPAPER_TITLE:
            rect->xid = WALLPAPER_TITLE;
            break;
        default:
            break;
        }
        break;
    case NETWORK_INDEX:
        switch (index) {
        case NETWORK_BACKICON:
            rect->xid = NETWORK_BACKICON;
            break;
        case NETWORK_HOMEICON:
            rect->xid = NETWORK_HOMEICON;
            break;
        case NETWORK_TITLE:
            rect->xid = NETWORK_TITLE;
            break;
        case NETWORK_WIFITEXT:
            rect->xid = NETWORK_WIFITEXT;
            break;
        case NETWORK_SEARCHRESULT_TEXT:
             rect->xid = NETWORK_SEARCHRESULT_TEXT;
            break;

        default:
            break;
        }
        break;
    case USBTRANSFER_INDEX:
        switch (index) {
        case USB_BACKICON:
            rect->xid = USB_BACKICON;
            break;
        case USB_HOMEICON:
            rect->xid = USB_HOMEICON;
            break;
        case USB_TITLE:
            rect->xid = USB_TITLE;
            break;
        case USB_ICON:
            rect->xid = USB_ICON;
            break;
        case USB_STATE:
            rect->xid = USB_STATE;
            break;
        case USB_DATATRANSFER:
            rect->xid = USB_DATATRANSFER;
            break;
        case USB_CHRGE:
            rect->xid = USB_CHRGE;
            break;
        default:
            break;
        }

        break;
    case DATEANDTIME_INDEX:
        switch (index) {
        case DATEANDTIME_BACKICON:
            rect->xid = DATEANDTIME_BACKICON;
            break;
        case DATEANDTIME_HOMEICON:
            rect->xid = DATEANDTIME_HOMEICON;
            break;
        case DATEANDTIME_TITLE:
            rect->xid = DATEANDTIME_TITLE;
            break;
        default:
            break;
        }

        break;
    case LANGUAGE_INDEX:
        switch (index) {
        case LANGUAGEKEYBOARD_BACKICON:
            rect->xid = LANGUAGEKEYBOARD_BACKICON;
            break;
        case LANGUAGKEYBODRD_HOMEICON:
            rect->xid = LANGUAGKEYBODRD_HOMEICON;
            break;
        case LANGUAGEKEBOARD_TITLE:
            rect->xid = LANGUAGEKEBOARD_TITLE;
            break;
        default:
            break;
        }

        break;
    case RESTORE_INDEX:
        switch (index) {
        case RESTORE_BACKICON:
            rect->xid = RESTORE_BACKICON;
            break;
        case RESTORE_HOMEICON:
            rect->xid = RESTORE_HOMEICON;
            break;
        case RESTORE_TEXT:
            rect->xid = RESTORE_TEXT;
            break;
        case RESTORE_CONFIRM_BUTTON:
            rect->xid = RESTORE_CONFIRM_BUTTON;
            break;
        default:
            break;
        }
        break;
    case OTHER_INDEX:
        switch (index) {
        case OTHER_BACKICON:
            rect->xid = OTHER_BACKICON;
            break;
        case OTHER_HOMEICON:
            rect->xid = OTHER_HOMEICON;
            break;
        case OTHER_TITLE:
            rect->xid = OTHER_TITLE;
            break;
        default:
            break;
        }

        break;
    default:
        break;
    }

}

