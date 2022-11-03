#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
class dataMain{
    public:

        dataMain();
        ~dataMain();
        struct Book
        {
            int Id;
            std::string Title;
            std::string Code;
            int Amount;
            int In_use;
            std::string Users;
        };
        int readInputFile();
        int saveOutputFile();

        struct Student
        {
            //int Id; doesnt use this
            std::string StudentId;
            std::string Name;
            std::string Class;
            int Inuse;
            std::string Info;
        };
        std::vector <Book> data;
        std::vector <Student> studentData;
        int readStudentData();
        int outputStudentData();
        
};