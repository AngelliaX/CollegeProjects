#pragma once

#include <string>
#include "sqlite3.h"
class dataMain{
    public:
        sqlite3 *db;
        char *zErrMsg = 0;
        char dbURL[50] = "./database/thelibrary.db";
        
        dataMain();
        ~dataMain();
        static int callback(void *, int, char **, char **);
        void connectDB();
        void connectStudentDB();
};