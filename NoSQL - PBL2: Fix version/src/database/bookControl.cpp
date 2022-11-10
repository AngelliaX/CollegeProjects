#include <iostream>
#include <string>
#include <cstring>
#include "bookControl.h"
#include "../terminalUI/ANSI_colorCode.h"
using namespace std;



bookControl::bookControl(){
    
}

bookControl::~bookControl(){

}

int bookControl::checkBookByCode(string code){
    int num = dataMain->data.size();
    for (int i = 0; i < num; i++)
    {
        if(dataMain->data[i].Code.compare(code) == 0){
            return 1;
        }
    }
    return 0;
}

int bookControl::checkBookById(int Id){
    int num = dataMain->data.size();
    for (int i = 0; i < num; i++)
    {
        if(i == Id){
            return 1;
        }
    }
    return 0;
}

int bookControl::addBook(string Title,string Code, int Amount){
    dataMain::Book book;
    book.Id = dataMain->data.size();
    book.Title = Title;
    book.Code = Code;
    book.Amount = Amount;
    book.In_use = 0;
    book.Users = "[]";

    if(checkBookByCode(Code)){
        cout << "Error: Book already existed in addBook" << endl;
        return 0;
    }
    dataMain->data.push_back(book);
    fprintf(stdout, "Records inserted successfully\n");
    return 1;
}

int bookControl::addNewUser(string UserCode, string BookId){
    int Id = stoi(BookId);
    if(!checkBookById(Id)){
        cout << "Error: Book Not Found on addNewUser" << endl;
        return 0;
    }

    if(dataMain->data[Id].In_use >= dataMain->data[Id].Amount){
        cout << "Error: Book is out of stock on addNewUser" << endl;
        return 0;
    }else{
        nlohmann::json js = nlohmann::json::parse(dataMain->data[Id].Users);
        auto new_pos = js.insert(js.end(), UserCode);
        dataMain->data[Id].Users = js.dump();
        dataMain->data[Id].In_use = dataMain->data[Id].In_use +1;
    }
    return 1;
}

int bookControl::removeUser(string UserCode, string BookId){
    int Id = stoi(BookId);
    if(!checkBookById(Id)){
        cout << "Error: Book Not Found on addNewUser" << endl;
        return 0;
    }

    nlohmann::json js = nlohmann::json::parse(dataMain->data[Id].Users);
    int temp = -1;
    for (auto& var : js.items())
    {   
        temp++;
        if(var.value().dump().compare("\""+UserCode+"\"") == 0){  
            js.erase( js.begin() +  temp);
            dataMain->data[Id].Users = js.dump();
            dataMain->data[Id].In_use = dataMain->data[Id].In_use -1;
            return 1;
        }
    }
    cout << red + "Can't find that student on the list\n" << flush;
    return 0;
}

int bookControl::removeBookByID(string Id){
    if(!checkBookById(stoi(Id))){
        cout << red + "Error: Book Not Found on removeBookByID" + reset << endl;
        return 0;
    }
    cout << green + "Successfully removed the book named "+ blue + dataMain->data[stoi(Id)].Title + reset << endl;
    dataMain->data.erase(dataMain->data.begin() + stoi(Id));
    return 0;
}

int bookControl::editQuantity(string BookId,string newQuantity){
    int Id = stoi(BookId);
    if(!checkBookById(Id)){
        cout << "Error: Book Not Found on editQuantity" << endl;
        return 0;
    }

    if(stoi(newQuantity) < dataMain->data[Id].In_use){
        cout << "Error: New quantity cannot be lower then the current users" << endl;
        return 0;
    }else{
        dataMain->data[Id].Amount = stoi(newQuantity);
    }
    return 1;
}