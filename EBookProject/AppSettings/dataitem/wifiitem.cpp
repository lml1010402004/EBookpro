#include "wifiitem.h"

wifiItem::wifiItem()
{

}

QString wifiItem::getWIFI_MAC() const
{
    return WIFI_MAC;
}

void wifiItem::setWIFI_MAC(const QString &value)
{
    WIFI_MAC = value;
}

QString wifiItem::getEncrypt() const
{
    return Encrypt;
}

void wifiItem::setEncrypt(const QString &value)
{
    Encrypt = value;
}

QString wifiItem::getStrength_class() const
{
    return strength_class;
}

void wifiItem::setStrength_class(const QString &value)
{
    strength_class = value;
}

QString wifiItem::getJoin_text() const
{
    return join_text;
}

void wifiItem::setJoin_text(const QString &value)
{
    join_text = value;
}

int wifiItem::getJoin_height() const
{
    return join_height;
}

void wifiItem::setJoin_height(int value)
{
    join_height = value;
}

int wifiItem::getJoin_width() const
{
    return join_width;
}

void wifiItem::setJoin_width(int value)
{
    join_width = value;
}

int wifiItem::getJoin_y() const
{
    return join_y;
}

void wifiItem::setJoin_y(int value)
{
    join_y = value;
}

int wifiItem::getJoin_x() const
{
    return join_x;
}

void wifiItem::setJoin_x(int value)
{
    join_x = value;
}

QString wifiItem::getWifi_name() const
{
    return wifi_name;
}

void wifiItem::setWifi_name(const QString &value)
{
    wifi_name = value;
}

int wifiItem::getText_height() const
{
    return text_height;
}

void wifiItem::setText_height(int value)
{
    text_height = value;
}

int wifiItem::getText_width() const
{
    return text_width;
}

void wifiItem::setText_width(int value)
{
    text_width = value;
}

int wifiItem::getText_y() const
{
    return text_y;
}

void wifiItem::setText_y(int value)
{
    text_y = value;
}

int wifiItem::getText_x() const
{
    return text_x;
}

void wifiItem::setText_x(int value)
{
    text_x = value;
}

QString wifiItem::getState_text() const
{
    return state_text;
}

void wifiItem::setState_text(const QString &value)
{
    state_text = value;
}

int wifiItem::getState_height() const
{
    return state_height;
}

void wifiItem::setState_height(int value)
{
    state_height = value;
}

int wifiItem::getState_width() const
{
    return state_width;
}

void wifiItem::setState_width(int value)
{
    state_width = value;
}

int wifiItem::getState_y() const
{
    return state_y;
}

void wifiItem::setState_y(int value)
{
    state_y = value;
}

int wifiItem::getState_x() const
{
    return state_x;
}

void wifiItem::setState_x(int value)
{
    state_x = value;
}

bool wifiItem::getConncted_flag() const
{
    return conncted_flag;
}

void wifiItem::setConncted_flag(bool value)
{
    conncted_flag = value;
}

int wifiItem::getIcon_height() const
{
    return icon_height;
}

void wifiItem::setIcon_height(int value)
{
    icon_height = value;
}

int wifiItem::getIcon_width() const
{
    return icon_width;
}

void wifiItem::setIcon_width(int value)
{
    icon_width = value;
}

int wifiItem::getIcon_y() const
{
    return icon_y;
}

void wifiItem::setIcon_y(int value)
{
    icon_y = value;
}

int wifiItem::getIcon_x() const
{
    return icon_x;
}

void wifiItem::setIcon_x(int value)
{
    icon_x = value;
}
