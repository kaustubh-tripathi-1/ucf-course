#include<iostream>
#include <limits>
using namespace std;

class Time
{
    private :
        int hour, minutes, seconds;

        bool isValidTime(int hour, int minutes, int seconds)
        {
            return (hour >= 0 && hour < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
        }

    public :

        void setTime( int h=0, int m=0, int s=0)
        {
            if ( isValidTime(h, m, s) )
            {
                hour = h;
                minutes = m;
                seconds = s;
            }
            else
            {
                cout<<"Invalid time values provided. Setting to default (00:00:00)"<<endl;
                hour = 0;
                minutes = 0;
                seconds = 0;
            }

        }

        void displayTime()
        {
            cout<<"The Time is -"<<endl;
            cout<<(hour<10 ? "0" : "")<<hour<<":"<<(minutes<10 ? "0" : "")<<minutes<<":"<<(seconds<10 ? "0" : "")<<seconds<<endl;
        }
};

int main()
{
    Time t1;

    t1.setTime(13, 8, 1);
    t1.displayTime();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}