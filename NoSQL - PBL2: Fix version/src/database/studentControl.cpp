#include <iostream>
#include <string>
#include <cstring>
#include "studentControl.h"
using namespace std;



studentControl::studentControl(){
    
}

studentControl::~studentControl(){

}

int studentControl::addStudent(string StudentId,string Name, string Class){
   dataMain::Student student;
   student.StudentId = StudentId;
   student.Name = Name;
   student.Class = Class;

   dataMain->studentData.push_back(student);
   dataMain->outputStudentData();

   fprintf(stdout, "Records inserted successfully\n");
   return 1;   
}

int studentControl::removeStudent(string Id){
   for (int i = 0; i < dataMain->studentData.size(); i++)
   {
      if(dataMain->studentData[i].StudentId.compare(Id) == 0){
         cout << green + "Successfully removed the student named "+ blue + dataMain->studentData[i].Name + reset << endl;
         dataMain->studentData.erase(dataMain->studentData.begin() + i);
         dataMain->outputStudentData();
         return 1;
      }
   }
   cout << red + "Error: Can't find this student on removeStudent" + reset << endl;
   return 0;
}

