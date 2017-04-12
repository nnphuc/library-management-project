#ifndef UTILITY_H
#define UTILITY_H

#ifdef __WIN32__
#include <windows.h>
#include <tchar.h>
#include <conio.h>
#endif


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <istream>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <utility>
#include <locale>




#define DB_FOLDER "database"
#define DB_EXTENSION ".txt"
#define EMPLOYEE_DB "employee"
#define BOOK_DB "book"
#define CHECKIN_DB "checkin"
#define USER_DB "user"
#define BORROW_DB "borrow"
#define BORROWDETAIL_DB "borrowdetail"



using namespace std;

#define endl '\n'

void trim(std::string &s);
wchar_t * toWchar_t(const char *c);
bool mkDir(const char *path);
bool dirExists(const char *path);

template<typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> split(const std::string &s, char delim);
std::string UID();
void flushStdin();
int stoi(const string &s);


#endif // UTILITY_H
