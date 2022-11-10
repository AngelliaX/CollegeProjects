#pragma once

#include <string>
#include "dataMain.h"
#include "../lib/nlohmann/json.hpp"
#include <typeinfo>
class bookControl{
    public:

        class dataMain *dataMain;
        bookControl();
        ~bookControl();
        int checkBookByCode(std::string);
        int checkBookById(int);
        int addBook(std::string,std::string, int);
        int addNewUser(std::string,std::string);
        int removeUser(std::string,std::string);
        int removeBookByID(std::string);
        int editQuantity(std::string,std::string);
};
