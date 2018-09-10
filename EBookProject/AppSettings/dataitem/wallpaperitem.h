#ifndef WALLPAPERITEM_H
#define WALLPAPERITEM_H

#include<QString>

class WallPaperItem
{
public:
    WallPaperItem();


    int getWall_x() const;
    void setWall_x(int value);

    int getWall_y() const;
    void setWall_y(int value);

    int getWall_width() const;
    void setWall_width(int value);

    int getWall_height() const;
    void setWall_height(int value);

    QString getWall_path() const;
    void setWall_path(const QString &value);

    int getCheckbox_x() const;
    void setCheckbox_x(int value);

    int getCheckbox_y() const;
    void setCheckbox_y(int value);

    int getCheckbox_width() const;
    void setCheckbox_width(int value);

    int getCheckbox_height() const;
    void setCheckbox_height(int value);

    bool getCheckflag() const;
    void setCheckflag(bool value);

private:
    int wall_x;
    int wall_y;
    int wall_width;
    int wall_height;
    QString wall_path;
    int checkbox_x;
    int checkbox_y;
    int checkbox_width;
    int checkbox_height;
    bool checkflag;
};

#endif // WALLPAPERITEM_H
