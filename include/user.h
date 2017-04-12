#ifndef USER_H
#define USER_H
#include "utility.h"
#include "date.h"

class User
{
public:
    User();
    string id() const;
    void setId(const string &id);

    string name() const;
    void setName(const string &name);

    string uname() const;
    void setUname(const string &uname);

    string password() const;
    void setPassword(const string &password);

    string email() const;
    void setEmail(const string &email);

    Date birthDate() const;
    void setBirthDate(const Date &birthDate);

    bool gender() const;
    void setGender(bool value);

    string getPhoneNumber() const;
    void setPhoneNumber(const string &phoneNumber);
    string getUname() const;
    friend ostream &operator<<(ostream &out,const User &user);
    friend ifstream &operator>>(ifstream&in,User &user);
    void read();
    void write();

private:
    string m_id;
    string m_name;
    string m_uname;
    string m_password;
    string m_email;
    Date m_birthDate;
    bool m_gender;
    string m_phoneNumber;
};

#endif // USER_H
