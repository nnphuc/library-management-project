#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "utility.h"
#include "date.h"


class Employee
{
public:
    Employee();
    virtual ~Employee();
    string id() const;
    void setId(const string &id);

    string name() const;
    void setName(const string &name);

    string address() const;
    void setAddress(const string &address);

    string phoneNumber() const;
    void setPhoneNumber(const string &phoneNumber);

    string department() const;
    void setDepartment(const string &department);

    string email() const;
    void setEmail(const string &email);

    bool gender() const;
    void setGender(bool gender);
    friend ostream &operator<<(ostream &output, const Employee &employee);
    friend istream &operator>>(istream &in,Employee &employee);

    void read();
    void write();
private:
    string m_id;
    string m_name;
    string m_address;
    string m_phoneNumber;
    string m_department;
    string m_email;
    bool m_gender;
};

#endif // EMPLOYEE_H
