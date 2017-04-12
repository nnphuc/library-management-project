#include "utility.h"

#include "menu.h"


int main(int argc, char *argv[])
{
    if(!dirExists(DB_FOLDER)){
        cout<<"Create folder database!"<<endl;
        mkDir(DB_FOLDER);
    }
    mainMenu();
    saveDatabase();
    return 0;
}
