#pragma once
#include "../database/bookControl.h"
#include "../database/studentControl.h"
class libraryMenuUtils{
    public:
        int terminalWidth;
        class bookControl *bookControl;
        class studentControl *studentControl;
        
        libraryMenuUtils();
        ~libraryMenuUtils();
        int addBookUI();
        int removeBook();
        int addUser();
        int removeUser();
        int editQuantity();

        int addStudent();
        int removeStudent();
};