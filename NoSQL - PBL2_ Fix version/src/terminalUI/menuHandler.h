#pragma once
#include <string>
#include "libraryMenuUtils.h"
#include "../database/bookControl.h"
#include "../database/studentControl.h"
#include "../database/dataMain.h"
#include "../lib/nlohmann/json.hpp"
class menuHandler{
    public:
        int terminalWidth = 105;
        
        int Id_length = terminalWidth/16;
        int Title_length = terminalWidth/4.2;
        int Code_length = terminalWidth/10.5;
        int Inuse_Amount_length = terminalWidth/15;
        int Users_length = terminalWidth/1.87;
        
        class dataMain *dataMain;
        class libraryMenuUtils libraryMenuUtils;
        
        menuHandler();
        ~menuHandler();
        int printTheLibrary();
        int printMenu();
        int printLibraryMenu();
        int getInputOption();
        int getLibraryInputOption();
        int processingAnimation();
        int about();

        //int Id_length = terminalWidth/16;
        int StudentId_length = terminalWidth/10.5;
        int Name_length = terminalWidth/4.2;
        int Class_length = terminalWidth/15;
        int Inuse_length = terminalWidth/15;
        int Info_length = terminalWidth/2.12;
        int printStudentData();
        int printStudentMenuOption();
        int getStudentInputOption();
};