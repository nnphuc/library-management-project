#include "bookdb.h"

BookDB &BookDB::getInstance()
{
    static BookDB *instance=NULL;
    if(instance==NULL){
        instance=new BookDB;
    }
    return *instance;
}

BookDB::~BookDB()
{
    saveDatabase();
}

void BookDB::add(const Book &book)
{
    m_data.push_back(book);
}

bool BookDB::remove(const string &bookID)
{
    size_t size=m_data.size();
    auto pend=remove_if(m_data.begin(),m_data.end(),[bookID](Book &e){
        return e.id()==bookID;
    });
    m_data.resize(distance(m_data.begin(),pend));
    return size!=m_data.size();
}

bool BookDB::loadDatabase()
{
    ifstream file(DB_FOLDER "/" BOOK_DB DB_EXTENSION,ios::in);
    if(!file || !file.is_open()){
        return false;
    }
    string line;
    getline(file,line);trim(line);
    if(line.size()){
        int size=stoi(line);
        for(int i=0;i<size;i++){
            Book book;
            file>>book;
            add(book);
        }
    }
    file.close();
    return true;
}

bool BookDB::saveDatabase()
{
    ofstream file(DB_FOLDER "/" BOOK_DB DB_EXTENSION,ios::out|ios::trunc);
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

vector<Book>::iterator BookDB::searchById(const string &id)
{
    return find_if(m_data.begin(),m_data.end(),[id](Book &book){
        return book.id()==id;
    });
}

vector<Book> BookDB::search(const string &callNumber, const string &ISBN, const string &title, const string &author)
{
    auto it=m_data.begin();
    vector<Book> result;
    auto func=[callNumber,ISBN,title,author](Book &book){
        if(callNumber.size() && book.callNumber()!=callNumber) return false;
        if(ISBN.size() && book.isbn()!=ISBN) return false;
        if(title.size() && book.title()!=title) return false;
        if(author.size() && book.author()!=author) return false;
        return true;
    };
    while ((it=find_if(it,m_data.end(),func))!=m_data.end()){
        result.push_back(*it);
        ++it;
    }
    return result;
}

void BookDB::view()
{
    for(Book & book:m_data){
        book.write();
    }
}

const vector<Book> &BookDB::getData() const
{
    return m_data;
}

BookDB::BookDB()
{
    loadDatabase();
}

