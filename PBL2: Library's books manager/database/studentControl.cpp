#include <iostream>
#include <string>
#include <cstring>
#include "studentControl.h"
#include "sqlite3.h"
using namespace std;



studentControl::studentControl(){
    
}

studentControl::~studentControl(){

}

int callback_general2(void *NotUsed, int argc, char **argv, char **azColName) {
   for(int i = 0; i<argc; i++) {
      //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   //printf("\n");
   return 0;
}

int studentControl::checkExistence(string StudentId){
   return 0;
}