#include "employee.h"

Employee::Employee()
{

}

Employee::~Employee()
{

}

string Employee::id() const
{
    return m_id;
}

void Employee::setId(const string &id)
{
    m_id = id;
}

string Employee::name() const
{
    return m_name;
}

void Employee::setName(const string &name)
{
    m_name = name;
}

string Employee::address() const
{
    return m_address;
}

void Employee::setAddress(const string &address)
{
    m_address = address;
}

string Employee::phoneNumber() const
{
    return m_phoneNumber;
}

void Employee::setPhoneNumber(const string &phoneNumber)
{
    m_phoneNumber = phoneNumber;
}

string Employee::department() const
{
    return m_department;
}

void Employee::setDepartment(const string &department)
{
    m_department = department;
}

string Employee::email() const
{
    return m_email;
}

void Employee::setEmail(const string &email)
{
    m_email = email;
}

bool Employee::gender() const
{
    return m_gender;
}

void Employee::setGender(bool gender)
{
    m_gender = gender;
}

void Employee::read()
{
    string line;
    setId(UID());
    cout<<right;
    cout<<"["<<setw(15)<<"name]:";
    getline(cin,line);trim(line); setName(line);
    cout<<"["<<setw(15)<<"address]:";
    getline(cin,line);trim(line); setAddress(line);
    cout<<"["<<setw(15)<<"phoneNumber]:";
    getline(cin,line);trim(line); setPhoneNumber(line);
    cout<<"["<<setw(15)<<"department]:";
    getline(cin,line);trim(line); setDepartment(line);
    cout<<"["<<setw(15)<<"email]:";
    getline(cin,line);trim(line); setEmail(line);
    cout<<"["<<setw(15)<<"male|female]:";
    getline(cin,line);trim(line); setGender(line=="male");
}

void Employee::write()
{
    cout<<left;
    cout<<setw(6)<<id()<<"|";
    cout<<setw(20)<<name()<<"|";
    cout<<setw(30)<<address()<<"|";
    cout<<setw(12)<<phoneNumber()<<"|";
    cout<<setw(20)<<department()<<"|";
    cout<<setw(20)<<email()<<"|";
    cout<<setw(6)<<(gender()?"male":"female")<<"\n";

}

istream &operator>>(istream &in, Employee &employee)
{
    string line;
    getline(in,line);trim(line); employee.setId(line);
    getline(in,line);trim(line); employee.setName(line);
    getline(in,line);trim(line); employee.setAddress(line);
    getline(in,line);trim(line); employee.setPhoneNumber(line);
    getline(in,line);trim(line); employee.setDepartment(line);
    getline(in,line);trim(line); employee.setEmail(line);
    getline(in,line);trim(line); employee.setGender(line=="male");
    return in;
}

ostream &operator<<(ostream &output, const Employee &employee)
{
    output<<employee.id()<<endl;
    output<<employee.name()<<endl;
    output<<employee.address()<<endl;
    output<<employee.phoneNumber()<<endl;
    output<<employee.department()<<endl;
    output<<employee.email()<<endl;
    output<<(employee.gender()?"male":"female")<<endl;
    return output;

}
