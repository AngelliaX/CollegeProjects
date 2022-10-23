#include <iostream>
#include "./menuHandler/terminalUI.h"
#include "./objects/Date.h"
#include "./objects/List.h"
#include "./objects/Nhanvien.h"
#include <string>
using namespace std;

// Add some default value to the list
void insertDefaultValue(terminalUI *terminal){
    Date Date;
    Date.Day = 23; Date.Month = 10; Date.Year = 2022;
    Nhanvien Nv1;
    Nv1.Id = "102210027"; Nv1.Name = "Nguyen Huu Tung"; Nv1.Gender = false; Nv1.Salary = 982; Nv1.Date = Date;
    Nhanvien Nv2;
    Nv2.Id = "102210028"; Nv2.Name = "Tran Hai Duong"; Nv2.Gender = false; Nv2.Salary = 132.772; Nv2.Date = Date;
    Nhanvien Nv3;
    Nv3.Id = "102210029"; Nv3.Name = "Le Van Luyen"; Nv3.Gender = false; Nv3.Salary = 81.3; Nv3.Date = Date;
    Nhanvien Nv4;
    Nv4.Id = "102210030"; Nv4.Name = "Chi Pu"; Nv4.Gender = true; Nv4.Salary = 132.772; Nv4.Date = Date;
    terminal->List.array[0] = Nv1;
    terminal->List.array[1] = Nv2;
    terminal->List.array[2] = Nv3;
    terminal->List.array[3] = Nv4;
    terminal->List.currentEmptyPos = 4;
}

int main(){
    cout << "\033[2J\033[1;1H";
    
    terminalUI terminalUI;
    insertDefaultValue(&terminalUI);
    
    terminalUI.mainMenu();

    return 0;
}