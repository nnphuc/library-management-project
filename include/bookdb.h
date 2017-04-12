#ifndef BOOKDB_H
#define BOOKDB_H
#include "utility.h"
#include "book.h"

class BookDB
{
public:

    static BookDB &getInstance();
    virtual ~BookDB();

    void add(const Book& book);
    bool remove(const string & bookID);
    bool loadDatabase();
    bool saveDatabase();
    vector<Book>::iterator searchById(const string &id);
    vector<Book> search(const string &callNumber,const string &ISBN,
                        const string &title,const string &author);
    void view();
    const vector<Book>& getData() const;


private:
    BookDB();
    vector<Book> m_data;
};

#endif // BOOKDB_H
