#pragma once

using namespace std;
class Date{
    public:
        int Day;
        int Month;
        int Year;

        Date();
        ~Date();

        friend istream &operator>>(istream &, Date &);
};
