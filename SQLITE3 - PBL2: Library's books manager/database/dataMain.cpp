#include <iostream>
#include <string>
#include <cstring>
#include "dataMain.h"
#include "sqlite3.h"
using namespace std;

dataMain::dataMain(){
    connectDB();
    connectStudentDB();
}

dataMain::~dataMain(){
    sqlite3_close(db);
}

int dataMain::callback(void *NotUsed, int argc, char **argv, char **azColName) {
   for(int i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void dataMain::connectDB(){
    int res = sqlite3_open(this->dbURL, &db);
    if(res){  
        fprintf(stderr, "Can't find database, create one: %s\n", sqlite3_errmsg(db));
    }
    
    char *sql = (char*) 
        "CREATE TABLE IF NOT EXISTS thelibrary("  \
        "Id integer primary key autoincrement    NOT NULL," \
        "Title           TEXT    NOT NULL," \
        "Code            TEXT     NOT NULL," \
        "Amount          INT," \
        "In_use          INT," \
        "Users           TEXT );";

    /* Execute SQL statement */
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error on Connect: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void dataMain::connectStudentDB(){
    int res = sqlite3_open(this->dbURL, &db);
    if(res){  
        fprintf(stderr, "Can't find database, create one: %s\n", sqlite3_errmsg(db));
    }
    
    char *sql = (char*) 
        "CREATE TABLE IF NOT EXISTS studentinfo("  \
        "Id integer primary key autoincrement    NOT NULL," \
        "Name           TEXT    NOT NULL," \
        "Class            TEXT     NOT NULL," \
        "StudentId            TEXT     NOT NULL," \
        "Amount_in_borrow          INT," \
        "Book_info           TEXT );";

    /* Execute SQL statement */
    int rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error on Connect: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}