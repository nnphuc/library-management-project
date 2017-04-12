#ifndef DATE_H
#define DATE_H
#include "utility.h"

static const int DAYS[12]={31,28,31,30,31,30,31,31,30,31,30,31};
class Date
{
public:
    Date();
    Date(const Date &other);
    Date(const string & s);
    Date(int,int,int);
    friend bool operator<(const Date &,const Date &);
    friend bool operator==(const Date &,const Date &);
    friend bool operator <=(const Date &,const Date &);
    friend bool operator >(const Date &,const Date &);
    friend bool operator !=(const Date &,const Date &);
    friend bool operator >=(const Date &,const Date &);
    friend ostream &operator<<(ostream &out,const Date &date);
    friend istream &operator>>(istream &in,Date &date);
    bool isValid() const;
    int getDay() const;
    int getYear() const;
    int getMonth() const;
    void setDay(int);
    void setMonth(int);
    void setYear(int);
    void addDay(int);
    void addMonth(int);
    void addYear(int);
    static Date now();
private:
    int m_day,m_month,m_year;
    bool _isLeapYear(int) const;
    int _getDayOfMonth(int ,int) const;
    int _getDayOfYear(int) const;
};
#endif // DATE_H
