#ifndef SYSTEMITEMS_H
#define SYSTEMITEMS_H
#include<QString>
#include<QRect>

class SystemItems
{
public:
    SystemItems();


    QRect itemrect;

    QRect itemtextrect;
    QString item_text_text;

    QRect itemiconrect;
    QString item_icon_path;

public:


    QString getItem_text_text() const;
    void setItem_text_text(const QString &value);
    QString getItem_icon_path() const;
    void setItem_icon_path(const QString &value);
};

#endif // SYSTEMITEMS_H
