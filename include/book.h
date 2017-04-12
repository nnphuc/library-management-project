#ifndef BOOK_H
#define BOOK_H
#include "utility.h"
#include "console.h"

class Book
{
public:
    Book();
    virtual ~Book();
    string id() const;
    void setId(const string &id);

    string callNumber() const;
    void setCallNumber(const string &callNumber);

    string isbn() const;
    void setIsbn(const string &isbn);

    string title() const;
    void setTitle(const string &title);

    string pubHouse() const;
    void setPubHouse(const string &pubHouse);

    string author() const;
    void setAuthor(const string &author);

    int numOfCopies() const;
    void setNumOfCopies(int numOfCopies);
    friend ostream &operator<<(ostream &output, const Book &book);
    friend istream &operator>>(istream &in, Book &book);
    void read();
    void write();
private:
    string m_id;
    string m_callNumber;
    string m_isbn;
    string m_title;
    string m_pubHouse;
    string m_author;
    int m_numOfCopies;
};

#endif // BOOK_H
