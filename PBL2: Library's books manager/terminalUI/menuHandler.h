#pragma once
#include <string>
#include "../database/bookControl.h"
#include "../database/studentControl.h"
#include "../database/dataMain.h"
#include "/usr/include/nlohmann/json.hpp"
class menuHandler{
    public:
        int terminalWidth = 150;
        class dataMain dataMain;
        class bookControl bookControl;
        class studentControl studentControl;
        menuHandler();
        ~menuHandler();
        int printTheLibrary();
};