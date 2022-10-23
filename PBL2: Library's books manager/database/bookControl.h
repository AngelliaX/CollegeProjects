#pragma once

#include <string>
#include "dataMain.h"
#include "/usr/include/nlohmann/json.hpp"
#include <typeinfo>
class bookControl{
    public:
        //All this are temporary vars to transfer from callback to main function
        int Id;
        std::string Title;
        std::string Code;
        int Amount;
        int In_use;
        std::string Users;

        class dataMain dataMain;
        bookControl();
        ~bookControl();
        int checkBookByCode(std::string);
        int checkBookById(int);
        int addBook(std::string,std::string, int);
        int addNewUser(std::string,std::string);
        int removeUser(std::string,std::string);
        int removeBookByID(std::string);
};
