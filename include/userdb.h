#ifndef USERDB_H
#define USERDB_H
#include "utility.h"
#include "user.h"


class UserDB
{
public:
    static UserDB & getInstance();
    virtual ~UserDB();
    bool loadDatabase();
    bool saveDatabase();
    void add(const User &user);
    bool remove(const string &userID);
    vector<User>::iterator searchById(const string &userID);
    void view();
    const vector<User>& getData() const;

private:
    vector<User> m_data;
    UserDB();
};

#endif // USERDB_H
