#include "borrowdetail.h"

BorrowDetail::BorrowDetail()
{

}

string BorrowDetail::bookId() const
{
    return m_bookId;
}

void BorrowDetail::setBookId(const string &bookId)
{
    m_bookId = bookId;
}

string BorrowDetail::borrowId() const
{
    return m_borrowId;
}

void BorrowDetail::setBorrowId(const string &borrowId)
{
    m_borrowId = borrowId;
}
