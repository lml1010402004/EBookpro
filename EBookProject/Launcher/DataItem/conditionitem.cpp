#include "conditionitem.h"

ConditionItem::ConditionItem()
{


}


/**
 * @brief ConditionItem::setCircle_x
 * @param circle_x
 */
void ConditionItem::setCircle_x(int circle_x)
{

    this->circle_x = circle_y;
}


/**
 * @brief ConditionItem::setCircle_y
 * @param circle_y
 */
void ConditionItem::setCircle_y(int circle_y)
{
    this->circle_y = circle_y;
}


/**
 * @brief ConditionItem::setCircle_width
 * @param circle_width
 */
void ConditionItem::setCircle_width(int circle_width)
{
    this->circle_width = circle_width;

}


/**
 * @brief ConditionItem::setCircle_height
 * @param circle_height
 */
void ConditionItem::setCircle_height(int circle_height)
{
this->circle_height = circle_height;
}


/**
 * @brief ConditionItem::setCircle_icon_path
 * @param path
 */
void ConditionItem::setCircle_icon_path(QString path)
{
   this->circle_path = path;
}


/**
 * @brief ConditionItem::setCircle
 * @param x
 * @param y
 * @param circle_width
 * @param circle_height
 * @param circle_path
 */
void ConditionItem::setCircle(int x, int y, int circle_width, int circle_height, QString circle_path)
{
 this->circle_x = x;
 this->circle_y =y;
 this->circle_width = circle_width;
    this->circle_height = circle_height;
    this->circle_path = circle_path;
}


/**
 * @brief ConditionItem::setText_x
 * @param text_x
 */
void ConditionItem::setText_x(int text_x)
{
    this->text_x = text_x;

}


/**
 * @brief ConditionItem::setText_y
 * @param text_y
 */
void ConditionItem::setText_y(int text_y)
{

    this->text_y = text_y;
}


/**
 * @brief ConditionItem::setText_width
 * @param text_width
 */
void ConditionItem::setText_width(int text_width)
{
  this->text_width = text_width;
}


/**
 * @brief ConditionItem::setText_height
 * @param text_height
 */
void ConditionItem::setText_height(int text_height)
{
this->text_height = text_height;
}


/**
 * @brief ConditionItem::setText_str
 * @param str
 */
void ConditionItem::setText_str(QString str)
{
    this->text_str = str;
}

QString ConditionItem::getText_str()
{
    return text_str;
}


/**
 * @brief ConditionItem::setText
 * @param text_x
 * @param text_y
 * @param text_width
 * @param text_height
 * @param text_str
 */
void ConditionItem::setText(int text_x, int text_y, int text_width, int text_height, QString text_str)
{
this->text_x = text_x;
    this->text_y = text_y;
    this->text_width = text_width;
    this->text_height = text_height;
    this->text_str = text_str;
}
