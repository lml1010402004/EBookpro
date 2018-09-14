#ifndef WIFIITEM_H
#define WIFIITEM_H
#include<QString>

class wifiItem
{
public:
    wifiItem();

    int icon_x;
    int icon_y;
    int icon_width;
    int icon_height;
    bool conncted_flag;

    int state_x;
    int state_y;
    int state_width;
    int state_height;
    QString state_text;


    int text_x;
    int text_y;
    int text_width;
    int text_height;
    QString wifi_name;

    int join_x;
    int join_y;
    int join_width;
    int join_height;
    QString join_text;

    QString strength_class;
    QString Encrypt;
    QString WIFI_MAC;





    int getIcon_x() const;
    void setIcon_x(int value);
    int getIcon_y() const;
    void setIcon_y(int value);
    int getIcon_width() const;
    void setIcon_width(int value);
    int getIcon_height() const;
    void setIcon_height(int value);
    bool getConncted_flag() const;
    void setConncted_flag(bool value);
    int getState_x() const;
    void setState_x(int value);
    int getState_y() const;
    void setState_y(int value);
    int getState_width() const;
    void setState_width(int value);
    int getState_height() const;
    void setState_height(int value);
    QString getState_text() const;
    void setState_text(const QString &value);
    int getText_x() const;
    void setText_x(int value);
    int getText_y() const;
    void setText_y(int value);
    int getText_width() const;
    void setText_width(int value);
    int getText_height() const;
    void setText_height(int value);
    QString getWifi_name() const;
    void setWifi_name(const QString &value);
    int getJoin_x() const;
    void setJoin_x(int value);
    int getJoin_y() const;
    void setJoin_y(int value);
    int getJoin_width() const;
    void setJoin_width(int value);
    int getJoin_height() const;
    void setJoin_height(int value);
    QString getJoin_text() const;
    void setJoin_text(const QString &value);
    QString getStrength_class() const;
    void setStrength_class(const QString &value);
    QString getEncrypt() const;
    void setEncrypt(const QString &value);
    QString getWIFI_MAC() const;
    void setWIFI_MAC(const QString &value);
};

#endif // WIFIITEM_H
