#pragma once
#include <string>
#include "Nhanvien.h"

using namespace std;

class Nhanvienhopdong : public Nhanvien{
    public:
        double luongcongnhat;
        int songaylamviectrongthang;
        virtual void edit(Nhanvienhopdong &Nv);
};

class Nhanvienbienche : public Nhanvien{
    public:
        double hesoluong;
        double thamnienlamviec;
        virtual void edit(Nhanvienbienche &Nv);
};