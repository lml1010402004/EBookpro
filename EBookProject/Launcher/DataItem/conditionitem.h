#ifndef CONDITIONITEM_H
#define CONDITIONITEM_H

#include<QString>
class ConditionItem
{

public :
int circle_x;
int circle_y;
int circle_width;
int circle_height;
QString circle_path;

int text_x;
int text_y;
int text_width;
int text_height;

QString text_str;



public:
    ConditionItem();
    void setCircle_x(int circle_x);
    void setCircle_y(int circle_y);
    void setCircle_width(int circle_width);
    void setCircle_height(int circle_height);
    void setCircle_icon_path(QString path);
    void setCircle(int x,int y,int circle_width,int circle_height,QString circle_path);


    void setText_x(int text_x);
    void setText_y(int text_y);
    void setText_width(int text_width);
    void setText_height(int text_height);
    void setText_str(QString str);
    QString getText_str();
    void setText(int text_x,int text_y,int text_width,int text_height,QString text_str);






};

#endif // CONDITIONITEM_H
