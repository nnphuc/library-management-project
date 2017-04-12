#ifndef BORROWDETAIL_H
#define BORROWDETAIL_H
#include "utility.h"


class BorrowDetail
{
public:
    BorrowDetail();
    string bookId() const;
    void setBookId(const string &bookId);

    string borrowId() const;
    void setBorrowId(const string &borrowId);

private:
    string m_bookId;
    string m_borrowId;

};

#endif // BORROWDETAIL_H
