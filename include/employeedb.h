#ifndef EMPLOYEEDB_H
#define EMPLOYEEDB_H
#include "utility.h"
#include "employee.h"

class EmployeeDB
{
public:

    static EmployeeDB &getInstance();
    virtual ~EmployeeDB();
    void add(const Employee &employee);
    bool remove(const string & employeeID);
    const vector<Employee>& getData() const;

    vector<Employee>::iterator searchById(const string &id);
    bool loadDatabase();
    bool saveDatabase();
    void view();

private:
    EmployeeDB();
    vector<Employee> m_data;

};

#endif // EMPLOYEEDB_H
