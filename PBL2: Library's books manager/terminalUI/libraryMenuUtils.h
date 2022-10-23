#pragma once
#include "../database/bookControl.h"
class libraryMenuUtils{
    public:
        int terminalWidth;
        class bookControl bookControl;
        
        libraryMenuUtils();
        ~libraryMenuUtils();
        int addBookUI();
        int removeBook();
        int addUser();
        int removeUser();
       
};