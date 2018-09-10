#include "wallpaperitem.h"

WallPaperItem::WallPaperItem()
{

}

int WallPaperItem::getWall_x() const
{
    return wall_x;
}

void WallPaperItem::setWall_x(int value)
{
    wall_x = value;
}

int WallPaperItem::getWall_y() const
{
    return wall_y;
}

void WallPaperItem::setWall_y(int value)
{
    wall_y = value;
}

int WallPaperItem::getWall_width() const
{
    return wall_width;
}

void WallPaperItem::setWall_width(int value)
{
    wall_width = value;
}

int WallPaperItem::getWall_height() const
{
    return wall_height;
}

void WallPaperItem::setWall_height(int value)
{
    wall_height = value;
}

QString WallPaperItem::getWall_path() const
{
    return wall_path;
}

void WallPaperItem::setWall_path(const QString &value)
{
    wall_path = value;
}

int WallPaperItem::getCheckbox_x() const
{
    return checkbox_x;
}

void WallPaperItem::setCheckbox_x(int value)
{
    checkbox_x = value;
}

int WallPaperItem::getCheckbox_y() const
{
    return checkbox_y;
}

void WallPaperItem::setCheckbox_y(int value)
{
    checkbox_y = value;
}

int WallPaperItem::getCheckbox_width() const
{
    return checkbox_width;
}

void WallPaperItem::setCheckbox_width(int value)
{
    checkbox_width = value;
}

int WallPaperItem::getCheckbox_height() const
{
    return checkbox_height;
}

void WallPaperItem::setCheckbox_height(int value)
{
    checkbox_height = value;
}

bool WallPaperItem::getCheckflag() const
{
    return checkflag;
}

void WallPaperItem::setCheckflag(bool value)
{
    checkflag = value;
}

