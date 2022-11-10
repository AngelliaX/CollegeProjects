#pragma once
#include <string>
#include "dataMain.h"
#include "../lib/nlohmann/json.hpp"
#include "../terminalUI/ANSI_colorCode.h"

class studentControl{
    public:
        
        class dataMain *dataMain;
        studentControl();
        ~studentControl();

        int addStudent(std::string, std::string, std::string);
        int removeStudent(std::string);
};