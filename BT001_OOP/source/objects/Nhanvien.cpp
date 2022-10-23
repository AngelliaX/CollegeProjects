#include <iostream>
#include "Nhanvien.h"
#include "../menuHandler/ANSI_colorCode.h"
#include <string>
using namespace std;

Nhanvien::Nhanvien(){
   
}

Nhanvien::~Nhanvien(){

}


std::istream &operator>>(std::istream &in, Nhanvien &Nv)
{   
    cin.clear();
    fflush(stdin);
    
    std::cout << underline + "Type in the ID: " + reset;
    getline(cin, Nv.Id);

    std::cout << underline + "Type in the Name: " + reset;
    getline(cin, Nv.Name);

    Date Date;
    cin >> Date;
    Nv.Date = Date;

    std::cout << underline + "Type 0 for female, 1 for male: " + reset;
    int temp; cin >> temp;
    if(temp == 0){  
        Nv.Gender = true;
    }else{
        Nv.Gender = false;
    }

    std::cout << underline + "Type the salary: " + reset;
    // string salary;
    // getline(cin, salary);
    // Nv.Salary = atof(salary.c_str());
    cin >> Nv.Salary;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Nhanvien &Nv)
{
    std::string text = Nv.Gender ? "Female" : "Male";
    string date = to_string(Nv.Date.Day)+"/"+to_string(Nv.Date.Month)+"/"+to_string(Nv.Date.Year);
    out << blue+"Id: "+reset+ Nv.Id +", "+blue+"Name: "+reset+Nv.Name+", "+blue+"Date: "+reset+date+", "+blue+"Gender: "+reset+text+", "+blue+"Salary: "+reset+to_string(Nv.Salary);
    return out;
}