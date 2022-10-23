#include <iostream>
#include "Date.h"
#include "../menuHandler/ANSI_colorCode.h"

using namespace std;

Date::Date(){
   
}

Date::~Date(){

}

std::istream &operator>>(std::istream &in, Date &date)
{   
   cin.clear();
   fflush(stdin);
   string str;
   std::cout << underline + "Type in the Day: " + reset;
   getline(cin, str);
   date.Day = stoi(str);
   
   std::cout << underline + "Type in the Month: " + reset;
   getline(cin, str);
   date.Month = stoi(str);

   std::cout << underline + "Type in the Year: " + reset;
   getline(cin, str);
   date.Year = stoi(str);

   return in;
}