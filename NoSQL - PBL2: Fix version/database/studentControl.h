#pragma once
#include <string>
#include "dataMain.h"
#include "../lib/nlohmann/json.hpp"
class studentControl{
    public:
        
        class dataMain *dataMain;
        studentControl();
        ~studentControl();
        int checkExistence(std::string);
};