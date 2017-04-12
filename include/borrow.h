#ifndef BORROW_H
#define BORROW_H
#include "date.h"


class Borrow
{
public:
    Borrow();
    string borrowId() const;
    void setBorrowId(const string &borrowId);

    string employeeId() const;
    void setEmployeeId(const string &employeeId);

    Date startDate() const;
    void setStartDate(const Date &startDate);

    Date dueDate() const;
    void setDueDate(const Date &dueDate);

    Date realDate() const;
    void setRealDate(const Date &realDate);
    friend ostream & operator<<(ostream & out,const Borrow &borrow);
    friend istream & operator>>(istream &in,Borrow &borrow);

private:
    string m_borrowId;
    string m_employeeId;
    Date m_startDate;
    Date m_dueDate;
    Date m_realDate;
};

#endif // BORROW_H
