#include <iostream>
#include <string>
#include "menuHandler.h"
#include <unistd.h>
using namespace std;

menuHandler::menuHandler(){
    
}

menuHandler::~menuHandler(){

}

int callback_printTheLibrary(void *aClass, int argc, char **argv, char **azColName) {
    class menuHandler* menuHandler = static_cast<class menuHandler*>(aClass);
    
    
    for(int i = 0; i<argc; i++) {  
        if(strcmp(azColName[i], "Id") == 0){
            menuHandler->bookControl.Id = atoi(argv[i]);
        }else if(strcmp(azColName[i], "Title") == 0){
            menuHandler->bookControl.Title = argv[i];
        }else if(strcmp(azColName[i], "Code") == 0){
            menuHandler->bookControl.Code = argv[i];
        }else if(strcmp(azColName[i], "Amount") == 0){
            menuHandler->bookControl.Amount = atoi(argv[i]);
        }else if(strcmp(azColName[i], "In_use") == 0){
            menuHandler->bookControl.In_use = atoi(argv[i]);
        }else if(strcmp(azColName[i], "Users") == 0){
            menuHandler->bookControl.Users = argv[i];
        }
    }
    cout 
    << left << setw(menuHandler->terminalWidth/16) << menuHandler->bookControl.Id << left << setw(menuHandler->terminalWidth/4.2) << menuHandler->bookControl.Title 
    << left << setw(menuHandler->terminalWidth/10.5) << menuHandler->bookControl.Code << left << setw(menuHandler->terminalWidth/15) <<  std::to_string(menuHandler->bookControl.In_use)+"/"+std::to_string(menuHandler->bookControl.Amount) 
    << left << setw(menuHandler->terminalWidth/1.87) << menuHandler->bookControl.Users << "\n";
    return 0;
}

int menuHandler::printTheLibrary(){
    char *sql = (char*) "SELECT * from thelibrary";


    string text = "The Library All Items:";
    cout << string(terminalWidth/3, '=') << text << string(terminalWidth - terminalWidth/3 - text.length(), '=') << '\n';
    cout 
    << left << setw(terminalWidth/16) << "Order" << left << setw(terminalWidth/4.2) << "Title" 
    << left << setw(terminalWidth/10.5) << "Code" << left << setw(terminalWidth/15) << "Amount" << left << setw(terminalWidth/1.87) << "Users" << "\n";
        
    
    int rc = sqlite3_exec(dataMain.db, sql, callback_printTheLibrary, (void*)this, &dataMain.zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error on Select: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    }
    return 1;
}