#include "utility.h"


void trim(string &s)
{
    size_t start=0;
    while (start<s.size() && isspace(s[start])){
        start++;
    }
    s=s.substr(start);
    while(s.size()>0 && isspace(s.back())){
        s.pop_back();
    }
}

wchar_t *toWchar_t(const char *c)
{

    const size_t cSize = strlen(c)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, c, cSize);

    return wc;

}

bool mkDir(const char *path)
{
    return CreateDirectoryA(path,NULL);
}

bool dirExists(const char *path)
{

  DWORD ftyp = GetFileAttributesA(path);
  if (ftyp == INVALID_FILE_ATTRIBUTES)
     return false;

  if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
     return true;
  return false;
}

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

string UID()
{
    time_t cur=time(NULL);
    struct tm *now=localtime(&cur);
    char s[20];
    sprintf(s,"%02d%02d%02d",now->tm_mday,now->tm_min,now->tm_sec);
    return string(s);
}

void flushStdin()
{
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    cin.get();
}

int stoi(const string &s){
    int d;
    sscanf(s.c_str(),"%d",&d);
    return d;
}

