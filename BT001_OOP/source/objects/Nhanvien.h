#pragma once
#include <string>
#include "Date.h"

using namespace std;
class Nhanvien{
    public:
        string Id;
        string Name;
        class Date Date;
        bool Gender; //true = female
        double Salary;

        Nhanvien();
        ~Nhanvien();
        friend istream &operator>>(istream &, Nhanvien &);
        friend ostream &operator<<(ostream &, const Nhanvien &);
};
