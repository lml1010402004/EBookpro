#include "datemodel.h"

dateModel::dateModel()
{

}

bool dateModel::getAutotime() const
{
    return autotime;
}

void dateModel::setAutotime(bool value)
{
    autotime = value;
}

QString dateModel::getTimehour() const
{
    return timehour;
}

void dateModel::setTimehour(const QString &value)
{
    timehour = value;
}

QString dateModel::getDate() const
{
    return date;
}

void dateModel::setDate(const QString &value)
{
    date = value;
}

QString dateModel::getTimezone() const
{
    return timezone;
}

void dateModel::setTimezone(const QString &value)
{
    timezone = value;
}
