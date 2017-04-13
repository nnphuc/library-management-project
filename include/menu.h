#ifndef MENU_H
#define MENU_H

#include "utility.h"
#include "user.h"
#include "employee.h"
#include "console.h"
#include "book.h"

#include "bookdb.h"
#include "userdb.h"
#include "employeedb.h"
#include "borrowdb.h"

void setTitle(const char *title);
bool login();
Employee inputEmployee();
User inputUser();
Book inputBook();
void saveDatabase();

void addUser();
void addEmployee();
void addBook();

void mainMenu();
void manageUser();
void manageBook();
void manageEmployee();

void searchUser();
void searchBook();
void searchEmployee();

void deleteUser();
void deleteBook();
void deleteEmployee();

void updateUser();
void updateEmployee();
void updateBook();

void borrowBook();
void returnBook();
void appInfo();

void infomation(const char *msg);
void warning(const char *msg);
typedef void (*menu_fn_t)();
struct FUNC{
    char name[20];
    menu_fn_t func;
    FUNC(const char *name,menu_fn_t fn);
};

void init_func(vector<FUNC> &fn);
#endif // MENU_H
