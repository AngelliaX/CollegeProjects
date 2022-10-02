#pragma once
#include <string>
#include "dataMain.h"
#include "/usr/include/nlohmann/json.hpp"
class studentControl{
    public:
        //All this are temporary vars to transfer from callback to main function
        int Id;
        std::string Name;
        std::string Class;
        std::string StudentId;
        int Amount_in_borrow;
        std::string Book_info;
        
        class dataMain dataMain;
        studentControl();
        ~studentControl();
        int checkExistence(std::string);
};