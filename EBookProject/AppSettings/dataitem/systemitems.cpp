#include "systemitems.h"

SystemItems::SystemItems()
{

}


QString SystemItems::getItem_text_text() const
{
    return item_text_text;
}

void SystemItems::setItem_text_text(const QString &value)
{
    item_text_text = value;
}

QString SystemItems::getItem_icon_path() const
{
  return item_icon_path;
}

void SystemItems::setItem_icon_path(const QString &value)
{
    item_icon_path = value;
}


