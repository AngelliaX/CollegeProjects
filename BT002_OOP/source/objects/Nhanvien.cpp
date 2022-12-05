#include <iostream>
#include "Nhanvien.h"
#include "Nhanvienkhac.h"
#include "../menuHandler/ANSI_colorCode.h"
#include <string>
using namespace std;

Nhanvien::Nhanvien(){
   
}

Nhanvien::~Nhanvien(){

}

void Nhanvien::edit(Nhanvien &Nv){
    cin.clear();
    fflush(stdin);

    std::cout << underline + "Type in the ID: " + reset;
    getline(cin, Nv.Id);

    std::cout << underline + "Type in the Name: " + reset;
    getline(cin, Nv.Name);

    class Date Date;
    cin >> Date;
    Nv.Date = Date;

    std::cout << underline + "Type 0 for female, 1 for male: " + reset;
    int temp;cin >> temp;
    if(temp == 0){  
        this->Gender = true;
    }else{
        this->Gender = false;
    }
}

std::istream &operator>>(std::istream &in, Nhanvien &Nv)
{   
    Nhanvienhopdong nvhd;
    Nhanvienbienche nvbc;
    
    std::cout << underline + "Nhap 0 neu la nv hop dong, 1 neu la nv bien che " + reset;
    int temp;cin >> temp;
    if(temp == 0){  
        nvhd.loainhanvien = "Nv hop dong";
        Nv.edit(nvhd);
        nvhd.edit(nvhd);
        nvhd.Salary = nvhd.luongcongnhat * nvhd.songaylamviectrongthang;
        Nv = nvhd;
    }else{
        nvbc.loainhanvien = "Nv bien che";
        Nv.edit(nvbc);
        nvbc.edit(nvbc);
        nvbc.Salary = (nvbc.hesoluong * 1390000) * ( (nvbc.thamnienlamviec < 5) ? (1 + 0) : (1 + nvbc.thamnienlamviec/100) );
        Nv = nvbc;
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Nhanvien &Nv)
{
    std::string text = Nv.Gender ? "Female" : "Male";
    string date = to_string(Nv.Date.Day)+"/"+to_string(Nv.Date.Month)+"/"+to_string(Nv.Date.Year);
    out << blue +"Loai: "+reset+ Nv.loainhanvien +", " +blue+"Id: "+reset+ Nv.Id +", "+blue+"Name: "+reset+Nv.Name+", "+blue+"Date: "+reset+date+", "+blue+"Gender: "+reset+text+", "+blue+"Salary: "+reset+to_string(Nv.Salary);
    return out;
}