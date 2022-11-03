#include <iostream>
#include "./database/bookControl.h"
#include "./database/studentControl.h"
#include "./terminalUI/menuHandler.h"

#include "./lib/nlohmann/json.hpp"
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
    dataMain.readInputFile();
    dataMain.readStudentData();

    bookControl bookControl;
    bookControl.dataMain = &dataMain;
    
    studentControl studentControl;
    studentControl.dataMain = &dataMain;
    
    menuHandler menuHandler;
    menuHandler.bookControl = &bookControl;
    menuHandler.dataMain = &dataMain;
    menuHandler.libraryMenuUtils.bookControl = &bookControl;

    menuHandler.printMenu();
    return 0;
}

/*Note that will get deleted when submit code

The ID number in input.txt is redundant. We use the order of the vector
*/
