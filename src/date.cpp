#include "date.h"

Date::Date():m_day(1),m_month(1),m_year(1900)
{

}

Date::Date(const Date &other)
{
    if(this==&other){
        return;
    }
    m_day=other.m_day;
    m_month=other.m_month;
    m_year=other.m_year;
}

Date::Date(const string &s)
{
    vector<int> number={1,1,1900};
    vector<string> ddmmyy=split(s,'/');
    for(int i=0;i<min(3,(int)ddmmyy.size());i++){
        number[i]=stoi(ddmmyy[i]);
    }
    m_day=number[0];
    m_month=number[1];
    m_year=number[2];
}

Date::Date(int day,int month,int year):m_day(day),m_month(month),m_year(year)
{

}

istream &operator>>(istream &in, Date &date)
{
    string line;
    in>>line;
    trim(line);
    date=Date(line);
    return in;
}

ostream &operator<<(ostream &out, const Date &date)
{
    out<<date.getDay()<<"/"<<date.getMonth()<<"/"<<date.getYear();
    return out;
}

int Date::getDay() const
{
    return m_day;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getYear() const
{
    return m_year;
}

void Date::setDay(int day)
{
    m_day=day;
}

void Date::setMonth(int month)
{
    m_month=month;
}

void Date::setYear(int year)
{
    m_year=year;
}

bool Date::_isLeapYear(int year) const
{
    return (year%4==0 && year%100!=0) || year%400==0;
}

int Date::_getDayOfMonth(int month,int year) const
{
    if(month!=2){
        return DAYS[month-1];
    }else{
        if(_isLeapYear(year)){
            return DAYS[month-1]+1;
        }else{
            return DAYS[month-1];
        }
    }
}

int Date::_getDayOfYear(int year) const
{
    if(_isLeapYear(year)){
        return 366;
    }else{
        return 365;
    }
}

bool Date::isValid() const
{
    return 1<=m_month && m_month<=12 &&
           1990<=m_year &&
           1<=m_day && m_day<=_getDayOfMonth(m_month,m_year);
}

bool operator<(const Date &date1,const Date &date2)
{
    if(date1.getYear()<date2.getYear()){
        return true;
    }else if(date1.getYear()>date2.getYear()){
        return false;
    }
    // year1 == year2
    if(date1.getMonth()<date2.getMonth()){
        return true;
    }else if(date1.getMonth()>date2.getMonth()){
        return false;
    }
    //month1==month2
    return date1.getDay()<date2.getDay();
}

bool operator==(const Date &date1,const Date &date2)
{
    return date1.getDay()==date2.getDay() &&
           date1.getMonth()==date2.getMonth() &&
           date1.getYear()==date2.getYear();
}

bool operator>(const Date &date1,const Date &date2)
{
    return !(date1<date2) && !(date1==date2);
}

bool operator!=(const Date &date1,const Date &date2)
{
    return !(date1==date2);
}

bool operator>=(const Date &date1,const Date &date2)
{
    return (date1==date2)||(date1>date2);
}

bool operator<=(const Date &date1, const Date &date2)
{
    return (date1==date2)||(date1<date2);
}

Date Date::now()
{
    time_t  cur=time(NULL);
    struct tm * now=localtime(&cur);
    return Date(now->tm_mday,now->tm_mon+1,now->tm_year+1900);
}

void Date::addYear(int year)
{
    m_year+=year;
}

void Date::addMonth(int month)
{
    int add_year=(m_month+month-1)/12;
    m_month=(m_month+month-1)%12+1;
    m_year+=add_year;
}

void Date::addDay(int day)
{
    while(day>=_getDayOfYear(m_year)){
        day-=_getDayOfYear(m_year);
        m_year++;
    }
    while(day+m_day>_getDayOfMonth(m_month,m_year)){
        day-=_getDayOfMonth(m_month,m_year)-m_day+1;
        m_day=1;
        m_month++;
    }
    m_day+=day;
}
