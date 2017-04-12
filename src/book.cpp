#include "book.h"

Book::Book()
{

}

Book::~Book()
{

}

string Book::id() const
{
    return m_id;
}

void Book::setId(const string &id)
{
    m_id = id;
}

string Book::callNumber() const
{
    return m_callNumber;
}

void Book::setCallNumber(const string &callNumber)
{
    m_callNumber = callNumber;
}

string Book::isbn() const
{
    return m_isbn;
}

void Book::setIsbn(const string &isbn)
{
    m_isbn = isbn;
}

string Book::title() const
{
    return m_title;
}

void Book::setTitle(const string &title)
{
    m_title = title;
}

string Book::pubHouse() const
{
    return m_pubHouse;
}

void Book::setPubHouse(const string &pubHouse)
{
    m_pubHouse = pubHouse;
}

string Book::author() const
{
    return m_author;
}

void Book::setAuthor(const string &author)
{
    m_author = author;
}

int Book::numOfCopies() const
{
    return m_numOfCopies;
}

void Book::setNumOfCopies(int numOfCopies)
{
    m_numOfCopies = numOfCopies;
}

void Book::read()
{
    string line;
    setId(UID());
    cout<<right;
    cout<<"["<<setw(15)<<"callNumber]:";
    getline(cin,line); trim(line); setCallNumber(line);
    cout<<"["<<setw(15)<<"isbn]:";
    getline(cin,line); trim(line); setIsbn(line);
    cout<<"["<<setw(15)<<"title]:";
    getline(cin,line); trim(line); setTitle(line);
    cout<<"["<<setw(15)<<"pubHouse]:";
    getline(cin,line); trim(line); setPubHouse(line);
    cout<<"["<<setw(15)<<"author]:";
    getline(cin,line); trim(line); setAuthor(line);
    cout<<"["<<setw(15)<<"numOfcopies]:";
    getline(cin,line); trim(line); setNumOfCopies(stoi(line));
}

void Book::write()
{
    cout<<left;
    cout<<setw(6)<<id()<<"|";
    cout<<setw(8)<<callNumber()<<"|";
    cout<<setw(8)<<isbn()<<"|";
    cout<<setw(30)<<title()<<"|";
    cout<<setw(15)<<pubHouse()<<"|";
    cout<<setw(30)<<author()<<"|";
    cout<<setw(4)<<numOfCopies()<<endl;

}


istream &operator>>(istream &in, Book &book)
{
    string line;
    getline(in,line); trim(line); book.setId(line);
    getline(in,line); trim(line); book.setCallNumber(line);
    getline(in,line); trim(line); book.setIsbn(line);
    getline(in,line); trim(line); book.setTitle(line);
    getline(in,line); trim(line); book.setPubHouse(line);
    getline(in,line); trim(line); book.setAuthor(line);
    getline(in,line); trim(line); book.setNumOfCopies(stoi(line));
    return in;
}

ostream &operator<<(ostream &output, const Book &book)
{
    output<<book.id()<<endl;
    output<<book.callNumber()<<endl;
    output<<book.isbn()<<endl;
    output<<book.title()<<endl;
    output<<book.pubHouse()<<endl;
    output<<book.author()<<endl;
    output<<book.numOfCopies()<<endl;
    return output;
}
