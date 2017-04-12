#include "borrow.h"

Borrow::Borrow()
{

}

string Borrow::borrowId() const
{
    return m_borrowId;
}

void Borrow::setBorrowId(const string &borrowId)
{
    m_borrowId = borrowId;
}

string Borrow::employeeId() const
{
    return m_employeeId;
}

void Borrow::setEmployeeId(const string &employeeId)
{
    m_employeeId = employeeId;
}

Date Borrow::startDate() const
{
    return m_startDate;
}

void Borrow::setStartDate(const Date &startDate)
{
    m_startDate = startDate;
}

Date Borrow::dueDate() const
{
    return m_dueDate;
}

void Borrow::setDueDate(const Date &dueDate)
{
    m_dueDate = dueDate;
}

Date Borrow::realDate() const
{
    return m_realDate;
}

void Borrow::setRealDate(const Date &realDate)
{
    m_realDate = realDate;
}

istream &operator>>(istream &in, Borrow &borrow)
{
    string line;
    getline(in,line);trim(line); borrow.setBorrowId(line);
    getline(in,line);trim(line); borrow.setEmployeeId(line);
    getline(in,line);trim(line); borrow.setStartDate(line);
    getline(in,line);trim(line); borrow.setDueDate(line);
    getline(in,line);trim(line); borrow.setRealDate(line);
    return in;
}

ostream &operator<<(ostream &out, const Borrow &borrow)
{
    out<<borrow.borrowId()<<endl;
    out<<borrow.employeeId()<<endl;
    out<<borrow.startDate()<<endl;
    out<<borrow.dueDate()<<endl;
    out<<borrow.realDate()<<endl;
    return out;
}
