#include<iostream>
#include <limits>
#include <string>
using namespace std;

//@ Class for Time
class Time
{
    private :

        int hr, min, sec;

    public :
        
        //& Constructors
        //$ Default Non-Parameterized Constructor
        Time()
        {
            hr = 0;
            min = 0;
            sec = 0;
        }
        
        //$ Default Parameterized Constructor, 1 args.
        Time(int hr)
        {
            this->hr = hr;
            this->min = 0;
            this->sec = 0;
        }
        //$ Default Parameterized Constructor, 2 args.
        Time(int hr, int min)
        {
            this->hr = hr;
            this->min = min;
            this->sec = 0;
        }
        //$ Default Parameterized Constructor, 3 args.
        Time(int hr, int min, int sec)
        {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }

        //$ Default Parameterized Constructor with Default Values
        /* Time(int hr = 0, int min = 0, int sec = 0)
        {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        } */

        //$ Copy Constructor
        Time( Time &t)
        {
            this->hr = t.hr;
            this->min = t.min;
            this->sec = t.sec;
        }

        /* //& Initializer List
        Time() : hr(0), min(0), sec(0){}
        Time(int hr) : hr(hr), min(0), sec(0){}
        Time(int hr, int min) : hr(hr), min(min), sec(0){}
        Time(int hr, int min, int sec) : hr(hr), min(min), sec(sec){}
        Time(int hr=0, int min=0, int sec=0) : hr(hr), min(min), sec(sec){}
        Time(Time &t) : hr(t.hr), min(t.min), sec(t.sec){} */

};

int main()
{


    // while ( getchar() != '\n');
    cin.get();
    return 0;
}