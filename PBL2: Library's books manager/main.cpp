#include <iostream>
#include "./database/bookControl.h"
#include "./database/studentControl.h"
#include "./terminalUI/menuHandler.h"

#include "/usr/include/nlohmann/json.hpp"
#include <string>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using json = nlohmann::json;


int main(){
    
    cout << "\033[2J\033[1;1H";

    dataMain dataMain;
    bookControl bookControl;
    bookControl.dataMain = dataMain;

    studentControl studentControl;
    studentControl.dataMain = dataMain;
    
    menuHandler menuHandler;
    menuHandler.dataMain = dataMain;
    

    menuHandler.printMenu();
    //bookControl.removeUser("0123321","20");
    return 0;
}

//https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
