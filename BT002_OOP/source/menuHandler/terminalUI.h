#pragma once
#include "../objects/Quanlinhanvien.h"
class terminalUI{
    public:
        int terminalWidth = 97;
        
        struct Node {
            class Quanlinhanvien Quanlinhanvien;
            struct Node * next;
        };

        typedef struct Node NODE;

        NODE * data = NULL;

        class Quanlinhanvien Quanlinhanvien;
        int currentIndex = 0;

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

        //======================================

        int canonMenu();
        int canongetInputOption();
        NODE * CreateNewNode(class Quanlinhanvien);
        void Display(NODE * tail);
        NODE * InsertAtHead(NODE * tail, class Quanlinhanvien);
        NODE * InsertAtEnd(NODE * tail, class Quanlinhanvien Quanlinhanvien);
        template <typename T>
        NODE * InsertAtArbitrary(NODE * tail, class Quanlinhanvien Quanlinhanvien, T location);
        void getQuanlinhanvien();
        void setQuanlinhanvien();
        int Length(NODE * tail);
        NODE * DeleteByLocation(NODE * tail);
        void themnguoiquanli();
        void timnguoiquanli();
        NODE * sortQuanli(NODE * tail);
};
