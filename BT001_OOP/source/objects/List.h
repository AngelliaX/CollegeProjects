#pragma once
#include "Nhanvien.h"


class List{
    public:
        int size = 15;
        int currentEmptyPos = 0;
        Nhanvien *array = new Nhanvien[size];
        

        List();
        ~List();
        int checkCapicity();

        //int printTheList(); in terminalUI
        int addNewObject(Nhanvien Nv, int Pos);
        int updateObject(int Pos);
        int deleteObject(int Pos);
        //int searchBySalary(double Num); in terminalUI
        int quickSortBySalary(int left,int right,bool(*mode)( double , double));
        
        
        
};
