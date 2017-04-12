#include "userdb.h"

UserDB &UserDB::getInstance()
{
    static UserDB *db=NULL;
    if(db==NULL){
        db=new UserDB;
    }
    return *db;
}

UserDB::~UserDB()
{
    saveDatabase();
}

bool UserDB::loadDatabase()
{
    ifstream file(DB_FOLDER "/" USER_DB DB_EXTENSION,ios::in);
    if(!file || !file.is_open()){
        return false;
    }
    string line;
    getline(file,line);trim(line);
    if(line.size()){
        int size=stoi(line);
        for(int i=0;i<size;i++){
            User user;
            file>>user;
            add(user);
        }
    }
    file.close();
    return true;
}

bool UserDB::saveDatabase()
{
    ofstream file(DB_FOLDER "/" USER_DB DB_EXTENSION,ios::out|ios::trunc);
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

void UserDB::add(const User &user)
{
    m_data.push_back(user);
}

bool UserDB::remove(const string &userID)
{
    size_t size=m_data.size();
    auto pend=remove_if(m_data.begin(),m_data.end(),[userID](User &e){
        return e.id()==userID;
    });
    m_data.resize(distance(m_data.begin(),pend));
    return size!=m_data.size();
}

vector<User>::iterator UserDB::searchById(const string &userID)
{
    return find_if(m_data.begin(),m_data.end(),[userID](User &user){
        return user.id()==userID;
    });
}

void UserDB::view()
{
    for(User &user: m_data){
        user.write();
    }
}

const vector<User>& UserDB::getData() const
{
    return m_data;
}

UserDB::UserDB()
{
    loadDatabase();
}
