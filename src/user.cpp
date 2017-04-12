#include "user.h"

User::User()
{

}

string User::id() const
{
    return m_id;
}

void User::setId(const string &id)
{
    m_id = id;
}

string User::name() const
{
    return m_name;
}

void User::setName(const string &name)
{
    m_name = name;
}

string User::uname() const
{
    return m_uname;
}

void User::setUname(const string &uname)
{
    m_uname = uname;
}

string User::password() const
{
    return m_password;
}

void User::setPassword(const string &password)
{
    m_password = password;
}

string User::email() const
{
    return m_email;
}

void User::setEmail(const string &email)
{
    m_email = email;
}

Date User::birthDate() const
{
    return m_birthDate;
}

void User::setBirthDate(const Date &birthDate)
{
    m_birthDate = birthDate;
}

bool User::gender() const
{
    return m_gender;
}

void User::setGender(bool value)
{
    m_gender = value;
}

string User::getPhoneNumber() const
{
    return m_phoneNumber;
}

void User::setPhoneNumber(const string &phoneNumber)
{
    m_phoneNumber = phoneNumber;
}

string User::getUname() const
{
    return m_uname;
}

void User::read()
{
    string line;
    setId(UID());
    cout<<right;
    cout<<"["<<setw(15)<<"name]:";
    getline(cin,line);trim(line); setName(line);
    cout<<"["<<setw(15)<<"username]:";
    getline(cin,line);trim(line); setUname(line);
    cout<<"["<<setw(15)<<"password]:";
    getline(cin,line);trim(line); setPassword(line);
    cout<<"["<<setw(15)<<"email]:";
    getline(cin,line);trim(line); setEmail(line);
    cout<<"["<<setw(15)<<"birthdate]:";
    getline(cin,line);trim(line); setBirthDate(Date(line));
    cout<<"["<<setw(15)<<"male|female]:";
    getline(cin,line);trim(line); setGender(line=="male");
}

void User::write()
{
    cout<<left;
    cout<<setw(6)<<id()<<"|";
    cout<<setw(20)<<name()<<"|";
    cout<<setw(15)<<uname()<<"|";
    cout<<setw(15)<<password()<<"|";
    cout<<setw(15)<<email()<<"|";
    cout<<setw(8)<<birthDate()<<"|";
    cout<<setw(6)<<(gender()?"male":"female")<<"\n";
}

ifstream &operator>>(ifstream &in, User &user)
{
    string line;
    getline(in,line);trim(line); user.setId(line);
    getline(in,line);trim(line); user.setName(line);
    getline(in,line);trim(line); user.setUname(line);
    getline(in,line);trim(line); user.setPassword(line);
    getline(in,line);trim(line); user.setEmail(line);
    getline(in,line);trim(line); user.setBirthDate(Date(line));
    getline(in,line);trim(line); user.setGender(line=="male");
    return in;
}

ostream &operator<<(ostream &out, const User &user)
{
    out<<user.id()<<endl;
    out<<user.name()<<endl;
    out<<user.uname()<<endl;
    out<<user.password()<<endl;
    out<<user.email()<<endl;
    out<<user.birthDate()<<endl;
    out<<(user.gender()?"male":"female")<<endl;
    return out;
}
