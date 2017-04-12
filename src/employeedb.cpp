#include "employeedb.h"

EmployeeDB &EmployeeDB::getInstance()
{
    static EmployeeDB *instance=NULL;
    if(instance==NULL){
        instance=new EmployeeDB;
    }
    return *instance;
}

EmployeeDB::EmployeeDB()
{
    loadDatabase();
}

const vector<Employee> &EmployeeDB::getData() const
{
    return m_data;
}


vector<Employee>::iterator EmployeeDB::searchById(const string &id)
{
    return find_if(m_data.begin(),m_data.end(),[id](Employee &employee){
        return employee.id()==id;
    });
}

bool EmployeeDB::loadDatabase()
{
    ifstream file(DB_FOLDER "/" EMPLOYEE_DB DB_EXTENSION,ios::in);
    if(!file || !file.is_open()){
        return false;
    }
    string line;
    getline(file,line);trim(line);
    if(line.size()){
        int size=stoi(line);
        for(int i=0;i<size;i++){
            Employee employee;
            file>>employee;
            add(employee);
        }
    }
    file.close();
    return true;
}

bool EmployeeDB::saveDatabase()
{
    ofstream file(DB_FOLDER "/" EMPLOYEE_DB DB_EXTENSION,ios::out|ios::trunc);

    if(!file.is_open()){
        return false;
    }
    file<<m_data.size()<<endl;
    for(size_t i=0;i<m_data.size();i++){
        file<<m_data[i];
    }
    file.close();
    return true;
}

void EmployeeDB::view()
{
    for(Employee &employee:m_data){
        employee.write();
    }
}

EmployeeDB::~EmployeeDB()
{
    saveDatabase();
}

void EmployeeDB::add(const Employee &employee)
{
    m_data.push_back(employee);
}

bool EmployeeDB::remove(const string &employeeID)
{
    size_t size=m_data.size();
    auto pend=remove_if(m_data.begin(),m_data.end(),[employeeID](Employee &e){
        return e.id()==employeeID;
    });
    m_data.resize(distance(m_data.begin(),pend));
    return size!=m_data.size();
}

