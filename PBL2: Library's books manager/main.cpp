#include <iostream>
#include "./database/bookControl.h"
#include "./database/studentControl.h"
#include "./terminalUI/menuHandler.h"
#include "/usr/include/nlohmann/json.hpp"
#include <string>

using namespace std;
using json = nlohmann::json;

int main(){
    // cout << "\033[2J\033[1;1H";
    //     cout << "hello\n";
    //     sleep(1);
    //     cout << "\033[2J\033[1;1H";        
    //     cout << "toi day\n";
    //     sleep(1);
    //     cout << "\033[2J\033[1;1H";
    // return 0;
    cout << "\033[2J\033[1;1H";
    dataMain dataMain;
    bookControl bookControl;
    bookControl.dataMain = dataMain;

    studentControl studentControl;
    studentControl.dataMain = dataMain;
    
    menuHandler menuHandler;
    menuHandler.dataMain = dataMain;

    menuHandler.printTheLibrary();
    cout << "Program finishes running" << endl;

    return 0;
}


//https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
