#include <iostream>
#include <string>
#include <cstring>
#include "bookControl.h"
#include "sqlite3.h"
using namespace std;



bookControl::bookControl(){
    
}

bookControl::~bookControl(){

}

int callback_general(void *NotUsed, int argc, char **argv, char **azColName) {
   for(int i = 0; i<argc; i++) {
      //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   //printf("\n");
   return 0;
}

int callback_onCheckBook(void *aClass, int argc, char **argv, char **azColName) {
    class bookControl* bookControl = static_cast<class bookControl*>(aClass);
    string code = bookControl->Code;
   
    for(int i = 0; i<argc; i++) {
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        if(strcmp(azColName[i], "Code") == 0){
            if(strcmp(argv[i], code.c_str()) == 0){
                //cout << "Book found ++" << endl;
                return 1;
            }
        }
    }
    return 0;
}

int bookControl::checkBookByCode(string code){
    this->Code = code;
    /* Create SQL statement */
    char *sql = (char*) 
        "SELECT * from thelibrary";

    /* Execute SQL statement */
    int rc = sqlite3_exec(dataMain.db, sql, callback_onCheckBook, (void*)this, &dataMain.zErrMsg);
    
    if( rc != SQLITE_OK ) {
        if(strcmp(dataMain.zErrMsg, "query aborted") == 0){
            sqlite3_free(dataMain.zErrMsg);
            return 1;
        }
        fprintf(stderr, "SQL error on Select: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    }
    return 0;
}

int bookControl::addBook(string Title,string Code, int Amount){
    /* Create SQL statement */
    string str = "INSERT INTO thelibrary (Title,Code,Amount,In_use,Users) VALUES ('"+Title+"', '"+Code+"', "+ std::to_string(Amount)+", 0, '[]');";
    char char_array[str.length() + 1];
    strcpy(char_array, str.c_str());
    char* sql = char_array;

    if(checkBookByCode(Code)){
        cout << "Error: Book already existed in addBook" << endl;
        return 0;
    }

    int rc = sqlite3_exec(dataMain.db, sql, callback_general, 0, &dataMain.zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error on Insert: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    } else {
        fprintf(stdout, "Records inserted successfully\n");
    }
    return 1;
}


int callback_getDatabaseValue(void *aClass, int argc, char **argv, char **azColName) {
    class bookControl* bookControl = static_cast<class bookControl*>(aClass);
    string code = bookControl->Code;
    
    int isThisField = 0;
    for(int i = 0; i<argc; i++) {
        //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        if(strcmp(azColName[i], "Code") == 0){
            if(strcmp(argv[i], code.c_str()) == 0){
                bookControl->Id = atoi(argv[0]);
                isThisField = 1;
                continue;
            }
        }
        if(isThisField){
            if(strcmp(azColName[i], "Amount") == 0){
                bookControl->Amount = atoi(argv[i]);
            }else if(strcmp(azColName[i], "In_use") == 0){
                bookControl->In_use = atoi(argv[i]);
            }else if(strcmp(azColName[i], "Users") == 0){
                bookControl->Users = argv[i];
            }
        }
    }
    return 0;
}

int bookControl::addNewUser(string UserCode, string BookCode){
    if(!checkBookByCode(BookCode)){
        cout << "Error: Book Not Found on addNewUser" << endl;
        return 0;
    }

    char *sql = (char*) "SELECT * from thelibrary";

    /* Execute SQL statement */
    int rc = sqlite3_exec(dataMain.db, sql, callback_getDatabaseValue, (void*)this, &dataMain.zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error on Select: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    }

    if(this->In_use >= this->Amount){
        cout << "Error: Book is out of stock on addNewUser" << endl;
        return 0;
    }else{
        nlohmann::json js = nlohmann::json::parse(this->Users);
        auto new_pos = js.insert(js.end(), UserCode);

        string str = "UPDATE thelibrary set In_use = "+std::to_string(this->In_use +1)+", Users = '"+this->Users+"' where ID = "+std::to_string(this->Id)+"; SELECT * from thelibrary";
        char char_array[str.length() + 1];
        strcpy(char_array, str.c_str());
        char* sql = char_array;
        
        
        int rc = sqlite3_exec(dataMain.db, sql, callback_general, 0, &dataMain.zErrMsg);
        if( rc != SQLITE_OK ){
            fprintf(stderr, "SQL error on Update on addNewUser: %s\n", dataMain.zErrMsg);
            sqlite3_free(dataMain.zErrMsg);
        }
    }
    return 1;
}

int bookControl::removeUser(string UserCode, string BookCode){
     if(!checkBookByCode(BookCode)){
        cout << "Error: Book Not Found on addNewUser" << endl;
        return 0;
    }

    char *sql = (char*) "SELECT * from thelibrary";

    /* Execute SQL statement */
    int rc = sqlite3_exec(dataMain.db, sql, callback_getDatabaseValue, (void*)this, &dataMain.zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error on Select: %s\n", dataMain.zErrMsg);
        sqlite3_free(dataMain.zErrMsg);
    }

    nlohmann::json js = nlohmann::json::parse(this->Users);
    int temp = -1;
    for (auto& var : js.items())
    {   
        temp++;
        if(var.value().dump().compare("\""+UserCode+"\"") == 0){  
            
            js.erase( js.begin() +  temp);
            string str = "UPDATE thelibrary set In_use = "+std::to_string(this->In_use -1)+", Users = '"+js.dump()+"' where ID = "+std::to_string(this->Id)+"; SELECT * from thelibrary";
            char char_array[str.length() + 1];
            strcpy(char_array, str.c_str());
            char* sql = char_array;
        
            int rc = sqlite3_exec(dataMain.db, sql, callback_general, 0, &dataMain.zErrMsg);
            if( rc != SQLITE_OK ){
                fprintf(stderr, "SQL error on Update on removeUser: %s\n", dataMain.zErrMsg);
                sqlite3_free(dataMain.zErrMsg);
            }
            return 1;
        }
    }
    return 0;
}