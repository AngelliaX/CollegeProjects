#pragma once
#include "../objects/List.h"
class terminalUI{
    public:
        int terminalWidth = 97;
        class List List;
        terminalUI();
        ~terminalUI();
    
        int mainMenu();
        int printTheListUI();
        int getInputOption();
        int addNewObjectUI();
        int deleteObjectUI();
        int updateObjectUI();
        int findObjectUI();
        int quickSortBySalaryUI();
};
