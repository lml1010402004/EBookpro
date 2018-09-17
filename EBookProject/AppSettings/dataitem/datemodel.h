#ifndef DATEMODEL_H
#define DATEMODEL_H
#include<QString>

class dateModel
{
public:
    dateModel();
    QString timezone;
    QString date;
    QString timehour;
    bool autotime;

    QString getTimezone() const;
    void setTimezone(const QString &value);
    QString getDate() const;
    void setDate(const QString &value);
    QString getTimehour() const;
    void setTimehour(const QString &value);
    bool getAutotime() const;
    void setAutotime(bool value);
};

#endif // DATEMODEL_H
