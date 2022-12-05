#include <iostream>
#include "./menuHandler/terminalUI.h"
#include "./objects/Date.h"
#include "./objects/Quanlinhanvien.h"
#include "./objects/Nhanvien.h"
#include <string>
using namespace std;

// Add some default value to the list
void insertDefaultValue(terminalUI *terminal){
    Date Date; Date.Day = 23; Date.Month = 10; Date.Year = 2022;
    Nhanvien Nv1;
    Nv1.Id = "102210027"; Nv1.Name = "Nguyen Huu Tung"; Nv1.Gender = false; Nv1.Salary = 982; Nv1.Date = Date; Nv1.loainhanvien = "Nv hop dong";
    Nhanvien Nv2;
    Nv2.Id = "102210028"; Nv2.Name = "Tran Hai Duong"; Nv2.Gender = false; Nv2.Salary = 132.772; Nv2.Date = Date; Nv2.loainhanvien = "Nv cong nhat";
    Nhanvien Nv3;
    Nv3.Id = "102210029"; Nv3.Name = "Le Van Luyen"; Nv3.Gender = false; Nv3.Salary = 81.3; Nv3.Date = Date; Nv3.loainhanvien = "Nv hop dong";
    Quanlinhanvien ql1, ql2, ql3;
    ql1.tennguoiquanli = "Nam Cao";
    ql1.array[0] = Nv1;
    ql1.array[1] = Nv2;
    ql1.currentEmptyPos = 2;
    ql2.tennguoiquanli = "Hung Vuong";
    ql2.array[0] = Nv3;
    ql2.currentEmptyPos = 1;
    ql3.tennguoiquanli = "Nguoi Moi";
    ql3.array[0] = Nv3;
    ql3.currentEmptyPos = 1;
    terminal->data = terminal->InsertAtHead(terminal->data,ql3);
    terminal->data = terminal->InsertAtHead(terminal->data,ql2);
    terminal->data = terminal->InsertAtHead(terminal->data,ql1);
}

int main(){
    cout << "\033[2J\033[1;1H";
    
    terminalUI terminalUI;
    insertDefaultValue(&terminalUI);
    //cout << terminalUI.Length(terminalUI.data);
    terminalUI.canonMenu();

    return 0;
}