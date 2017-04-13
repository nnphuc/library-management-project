#include "utility.h"

#include "menu.h"


int main(int argc, char *argv[])
{
    if(!dirExists(DB_FOLDER)){
        cout<<"Create folder database!"<<endl;
        mkDir(DB_FOLDER);
    }
    int logCount=0;
    bool loginResult=false;
    while(!(loginResult=login())){
        warning("login fail");

        logCount++;
        if(logCount>5){
            warning("login too many times");
            break;
        }
        _getche();
    }
    if(loginResult){
        mainMenu();
    }
    saveDatabase();
    return 0;
}
