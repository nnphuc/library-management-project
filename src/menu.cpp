#include "menu.h"

void infomation(const char *msg)
{
    Console con;
    con.setTextColor(Console::BLUE);
    cout<<msg<<endl;
    con.setTextColor(Console::WHITE);
}
void warning(const char *msg)
{
    Console con;
    con.setTextColor(Console::YELLOW);
    cout<<msg<<endl;
    con.setTextColor(Console::WHITE);
}

FUNC::FUNC(const char *name,menu_fn_t fn)
{
    strcpy(this->name,name);
    this->func=fn;
}
void init_func(const char *title,const vector<FUNC> &fn)
{
    setTitle(title);
    for(size_t i=1;i<fn.size();i++){
        cout<<i<<". "<<fn[i].name<<endl;
    }
    cout<<0<<". "<<fn[0].name<<endl;
    size_t cmd;
    cin>>cmd;
    flushStdin();
    if(cmd>=fn.size()){
        return;
    }else{
        (fn[cmd].func)();
    }
}

void setTitle(const char *title)
{
    Console console;
    console.clear();
    console.setTitle(title);
    console.setTextColor(Console::LIGHT_AQUA);
    cout<<title<<endl;
    console.setTextColor(Console::LIGHT_RED);
    for(int i=0;i<console.getWidth();i++){
        cout<<"-";
    }
    console.setTextColor(Console::WHITE);
}

bool login()
{
    setTitle("LOGIN");
    string username,password;
    cout<<"username: "; cin>>username;
    cout<<"password: "; cin>>password;
    UserDB &userdb=UserDB::getInstance();
    bool hasRoot=false;
    for(const User& user: userdb.getData()){
        if(user.uname()==ROOT_USERNAME && user.password()==ROOT_PASSWORD){
            hasRoot= true;
            break;
        }

    }
    if(!hasRoot){
        User root;
        root.setId(UID());
        root.setPassword(ROOT_PASSWORD);
        root.setUname(ROOT_USERNAME);
        userdb.add(root);
    }
    for(const User& user: userdb.getData()){
        if(user.uname()==username && user.password()==password){
            return true;
        }
    }
    return false;
}

void saveDatabase()
{
    BookDB &bookdb=BookDB::getInstance();
    delete &bookdb;
    EmployeeDB &employeedb=EmployeeDB::getInstance();
    delete &employeedb;
    UserDB &userdb=UserDB::getInstance();
    delete &userdb;
    BorrowDB &borrowdb=BorrowDB::getInstance();
    delete &borrowdb;
}


Employee inputEmployee()
{
    Employee employee;
    employee.read();
    return employee;
}


User inputUser()
{
    User user;
    user.read();
    return user;
}

Book inputBook()
{
    Book book;
    book.read();
    return book;
}

void addUser()
{
    setTitle("ADD USER");
    UserDB &db=UserDB::getInstance();
    User user=inputUser();
    db.add(user);
    user.write();
}

void addEmployee()
{
    setTitle("ADD EMPLOYEE");
    EmployeeDB &db=EmployeeDB::getInstance();
    Employee employee=inputEmployee();
    db.add(employee);
    employee.write();
}

void addBook()
{
    setTitle("ADD BOOK");
    BookDB &db=BookDB::getInstance();
    Book book=inputBook();
    db.add(book);
    book.write();
}

void mainMenu()
{
    init_func("MAIN MENU",{
        FUNC("exit",[](){ saveDatabase(); exit(0);}),
        FUNC("manage user",manageUser),
        FUNC("manage employee",manageEmployee),
        FUNC("manage book",manageBook),
        FUNC("borrow book",borrowBook),
        FUNC("return book",returnBook),
        FUNC("infomation",appInfo)
    });
}

void manageUser()
{
    init_func("MANAGE USER",{
        FUNC("back",mainMenu),
        FUNC("add user",addUser),
        FUNC("search user",searchUser),
        FUNC("update user",updateUser),
        FUNC("delete user",deleteUser),
        FUNC("view",[](){UserDB::getInstance().view();}),
    });
    _getche();
    manageUser();
}

void manageBook()
{
    init_func("MANAGE USER",{
        FUNC("back",mainMenu),
        FUNC("add book",addBook),
        FUNC("search book",searchBook),
        FUNC("update book",updateBook),
        FUNC("delete book",deleteBook),
        FUNC("view",[](){BookDB::getInstance().view();}),
    });
    _getche();
    manageBook();
}

void manageEmployee()
{
     init_func("MANAGE EMPLOYEE",{
        FUNC("back",mainMenu),
        FUNC("add employee",addEmployee),
        FUNC("search employee",searchEmployee),
        FUNC("update employee",updateEmployee),
        FUNC("delete employee",deleteEmployee),
        FUNC("view",[](){EmployeeDB::getInstance().view();}),
    });
    _getche();
    manageEmployee();
}

void searchUser(){
    setTitle("SEARCH USER");
    cout<<"please type userid: ";
    string id;
    cin>>id;
    flushStdin();
    auto ret=UserDB::getInstance().searchById(id);
    if(ret!=UserDB::getInstance().getData().end()){
        ret->write();
    }else{
        warning("NO DATA FOUND!");
    }
}

void searchBook()
{
    setTitle("SEARCH BOOK");
    cout<<"please type bookid: ";
    string id;
    cin>>id;
    flushStdin();
    auto ret=BookDB::getInstance().searchById(id);
    if(ret!=BookDB::getInstance().getData().end()){
        ret->write();
    }else{
        warning("NO DATA FOUND!");
    }
}

void searchEmployee()
{
    setTitle("SEARCH EMPLOYEE");
    cout<<"please type employee id: ";
    string id;
    cin>>id;
    flushStdin();
    vector<Employee>::iterator ret=EmployeeDB::getInstance().searchById(id);
    if(ret!=EmployeeDB::getInstance().getData().end()){
        ret->write();
    }else{
        warning("NO DATA FOUND!");
    }
}



void deleteUser()
{
    setTitle("DELETE USER");
    cout<<"please type id: ";
    string id;
    cin>>id;
    flushStdin();
    if(UserDB::getInstance().remove(id)){
        infomation("delete success!");
    }else{
        warning("delete fail!");
    }
}

void deleteEmployee()
{
    setTitle("DELETE EMPLOYEE");
    cout<<"please type id: ";
    string id;
    cin>>id;
    flushStdin();
    if(EmployeeDB::getInstance().remove(id)){
        infomation("delete success!");
    }else{
        warning("delete fail!");
    }
}

void deleteBook()
{
    setTitle("DELETE BOOK");
    cout<<"please type id: ";
    string id;
    cin>>id;
    flushStdin();
    if(BookDB::getInstance().remove(id)){
        infomation("delete success!");
    }else{
        warning("delete fail!");
    }
}

void updateUser()
{
    setTitle("UPDATE USER");
    cout<<"please type id: ";
    string id;
    cin>>id;
    flushStdin();
    auto ret=UserDB::getInstance().searchById(id);
    if(ret!=UserDB::getInstance().getData().end()){
        ret->read();
        ret->write();
    }else{
        warning("NO DATA FOUND!");
    }
}

void updateBook()
{
    setTitle("UPDATE BOOK");
    cout<<"please type id: ";
    string id;
    cin>>id;
    flushStdin();
    auto ret=BookDB::getInstance().searchById(id);
    if(ret!=BookDB::getInstance().getData().end()){
        ret->read();
        ret->write();
    }else{
        warning("NO DATA FOUND!");
    }
}



void updateEmployee()
{
    setTitle("UPDATE EMPLOYEE");
    cout<<"please type id: ";
    string id;
    cin>>id;
    flushStdin();
    auto ret=EmployeeDB::getInstance().searchById(id);
    if(ret!=EmployeeDB::getInstance().getData().end()){
        ret->read();
        ret->write();
    }else{
        warning("NO DATA FOUND!");
    }
}

void borrowBook()
{
    setTitle("BORROW BOOK");
    cout<<"please type employee id:";
    string employeeid;
    getline(cin,employeeid);
    cout<<"please type book id:";
    string bookid;
    getline(cin,bookid);

    auto eIter=EmployeeDB::getInstance().searchById(employeeid);
    auto bIter=BookDB::getInstance().searchById(bookid);
    if(eIter==EmployeeDB::getInstance().getData().end() ||
            bIter==BookDB::getInstance().getData().end()){
        warning("input id error");
    }else{
        Borrow borrow;
        borrow.setBorrowId(UID());
        borrow.setStartDate(Date::now());
        Date dueDate=Date::now();
        dueDate.addDay(10);
        borrow.setDueDate(dueDate);
        BorrowDB::getInstance().add(borrow);
        cout<<"BOOK:"<<endl;
        bIter->write();
        cout<<"EMPLOYEE:"<<endl;
        eIter->write();
        cout<<"status:";
        cout<<"start date:"<<borrow.startDate()<<endl;
        cout<<"due date:"<<borrow.dueDate()<<endl;
    }

    _getche();
}

void returnBook()
{
    setTitle("RETURN BOOK");
    cout<<"please type employee id:";
    string employeeid;
    getline(cin,employeeid);
    cout<<"please type book id:";
    string bookid;
    getline(cin,bookid);

    auto eIter=EmployeeDB::getInstance().searchById(employeeid);
    auto bIter=BookDB::getInstance().searchById(bookid);
    if(eIter==EmployeeDB::getInstance().getData().end() ||
            bIter==BookDB::getInstance().getData().end()){
        warning("input id error");
    }else{
        BorrowDB &db=BorrowDB::getInstance();
        auto ans=db.searchByEmployeeId(employeeid);
        if(ans!=db.getData().end()){
            Borrow borrow=*ans;
            cout<<"start date:"<<borrow.startDate()<<endl;
            cout<<"due date:"<<borrow.dueDate()<<endl;
            cout<<"now: "<<Date::now()<<endl;
        }else{
            warning("error!");
        }
    }
    _getche();
}


void appInfo(){
    setTitle("INFOMATION");
    infomation("This app written by:");
    infomation("Nguyen Ngoc Phuc");
    infomation("Nguyen Minh Tam");
    infomation("Tran Viet Ha");
    _getche();
    mainMenu();
}
