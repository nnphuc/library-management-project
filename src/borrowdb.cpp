#include "borrowdb.h"

BorrowDB &BorrowDB::getInstance()
{

    static BorrowDB *instance=NULL;
    if(instance==NULL){
        instance=new BorrowDB;
    }
    return *instance;
}

BorrowDB::~BorrowDB()
{
    saveDatabase();
}

bool BorrowDB::loadDatabase()
{
    ifstream file(DB_FOLDER "/" BORROW_DB DB_EXTENSION,ios::in);
    if(!file || !file.is_open()){
        return false;
    }
    string line;
    getline(file,line);trim(line);
    if(line.size()){
        int size=stoi(line);
        for(int i=0;i<size;i++){
            Borrow borrow;
            file>>borrow;
            add(borrow);
        }
    }
    file.close();
    return true;
}

bool BorrowDB::saveDatabase()
{
    ofstream file(DB_FOLDER "/" BORROW_DB DB_EXTENSION,ios::out|ios::trunc);
    if(!file.is_open()){
        return false;
    }
    file<<m_data.size()<<endl;
    for(size_t i=0;i<m_data.size();i++){
        file<<m_data[i];
    }
    file.close();
    cout<<"save"<<endl;
    return true;
}

void BorrowDB::add(Borrow &borrow)
{
    m_data.push_back(borrow);
}

bool BorrowDB::remove(const string &borrowID)
{
    size_t size=m_data.size();
    auto pend=remove_if(m_data.begin(),m_data.end(),[borrowID](Borrow &e){
        return e.borrowId()==borrowID;
    });
    m_data.resize(distance(m_data.begin(),pend));
    return size!=m_data.size();
}

BorrowDB::BorrowDB()
{
    loadDatabase();
}

const vector<Borrow> &BorrowDB::getData() const
{
    return m_data;
}

vector<Borrow>::iterator BorrowDB::searchByEmployeeId(const string &id)
{
    return find_if(m_data.begin(),m_data.end(),[id](Borrow &borrow){
        return borrow.employeeId()==id;
    });
}

