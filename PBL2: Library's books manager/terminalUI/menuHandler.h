#pragma once
#include <string>
#include "libraryMenuUtils.h"
#include "../database/bookControl.h"
#include "../database/studentControl.h"
#include "../database/dataMain.h"
#include "/usr/include/nlohmann/json.hpp"
class menuHandler{
    public:
        int terminalWidth = 150;
        int Id_length = terminalWidth/16;
        int Title_length = terminalWidth/4.2;
        int Code_length = terminalWidth/10.5;
        int Inuse_Amount_length = terminalWidth/15;
        int Users_length = terminalWidth/1.87;
        class dataMain dataMain;
        class bookControl bookControl;
        class studentControl studentControl;
        class libraryMenuUtils libraryMenuUtils;
        
        menuHandler();
        ~menuHandler();
        int printTheLibrary();
        int printMenu();
        int printLibraryMenu();
        int getInputOption();
        int getLibraryInputOption();
        int processingAnimation();
};