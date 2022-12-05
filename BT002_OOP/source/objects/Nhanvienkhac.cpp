#include <iostream>
#include "Nhanvienkhac.h"
#include "../menuHandler/ANSI_colorCode.h"
#include <string>
using namespace std;

void Nhanvienhopdong::edit(Nhanvienhopdong &Nv)
{   
    cin.clear();
    fflush(stdin);

    std::cout << underline + "Nhap luong cong nhat: " + reset;
    cin >> Nv.luongcongnhat;

    std::cout << underline + "Nhap so ngay lam viec trong thang: " + reset;
    cin >> Nv.songaylamviectrongthang;
}

void Nhanvienbienche::edit(Nhanvienbienche &Nv)
{   
    cin.clear();
    fflush(stdin);

    std::cout << underline + "Nhap he so luong: " + reset;
    cin >> Nv.hesoluong;

    std::cout << underline + "Nhap tham nien lam viec: " + reset;
    cin >> Nv.thamnienlamviec;
}