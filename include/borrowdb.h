#ifndef BORROWDB_H
#define BORROWDB_H
#include "utility.h"
#include "borrow.h"

class BorrowDB
{
public:
    static BorrowDB & getInstance();
    virtual ~BorrowDB();
    bool loadDatabase();
    bool saveDatabase();
    void add(Borrow &borrow);
    bool remove(const string &borrowID);
    const vector<Borrow>& getData() const;
    vector<Borrow>::iterator searchByEmployeeId(const string &borrowID);

private:
    BorrowDB();
    vector<Borrow> m_data;
};

#endif // BORROWDB_H
