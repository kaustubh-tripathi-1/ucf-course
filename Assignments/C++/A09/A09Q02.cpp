#include<iostream>
#include <limits>
using namespace std;

//@ Class for Time
class Time
{
    private :

        int hour, minute, second;
        bool isValid = false;

        bool validTime(int hour, int minute, int second)
        {
            if ( hour >= 0 && hour < 24 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59 )
                return true;
            else
                return false;
        }

    public :

        //$ Sets the Time for an instance, provide it in 24H clock format
        void setTime(int hour, int minute, int second)
        {
            if ( validTime(hour, minute, second) )
            {
                this->hour = hour;
                this->minute = minute;
                this->second = second;
                this->isValid = true;
            }
            else
            {
                cout<<"Invalid Time!"<<endl;
                this->isValid = false;
            }
        }

        //$ Displays the time of an instance
        void showTime()
        {
            if ( isValid )
                cout<<"The time is "<<(hour < 10 ? "0" : "")<<hour<<":"<<(minute < 10 ? "0" : "")<<minute<<":"<<(second < 10 ? "0" : "")<<second<<endl;
            else
                cout<<"Time not set or is invalid!"<<endl;
        }

        //$ Normalize the time values
        void normalize()
        {
            if ( second > 59 )
            {
                second %= 60;
                minute++;
            }
            if ( minute > 59)
            {
                minute %= 60;
                hour++;
            }
            if ( hour > 23 )
                hour %= 24;
        }

        //$ Adds 2 times
        Time addTime(Time secondTime)
        {
            Time temp;

            temp.hour = this->hour + secondTime.hour;
            temp.minute = this->minute + secondTime.minute;
            temp.second = this->second + secondTime.second;

            temp.normalize();
            
            return temp;
        }

        //$ Tells if the time of caller object is greater than the passed object
        bool isGreater(Time secondTime)
        {
            int seconds1, seconds2;

            seconds1 = this->hour*3600 + this->minute*60 + this->second;
            seconds2 = secondTime.hour*3600 + secondTime.minute*60 + secondTime.second;

            
            if( seconds1 > seconds2 )
                return true;
            else
                return false;

                
            //$ Multiple if-else checks logic
            /* if ( this->hour > secondTime.hour )
                return true;
            else if ( this->hour == secondTime.hour && this->minute > secondTime.minute)
                return true;
            else if ( this->minute == secondTime.minute && this->second > secondTime.second)
                return true;
            else
                return false; */
            
        }

};

int main()
{
    Time t1, t2;
    t1.setTime(23, 34, 3);
    t2.setTime(15, 36, 3);

    t1.normalize();
    t2.normalize();

    cout<<"Time 1 is :"<<endl;
    t1.showTime();
    cout<<"Time 2 is :"<<endl;
    t2.showTime();

    Time t3 = t1.addTime(t2);
    cout<<"The added time is :"<<endl;
    t3.showTime();

    if ( t1.isGreater(t2) )
        cout<<"Caller Time is greater than the passed Time"<<endl;
    else
        cout<<"Passed Time is greater than the caller Time"<<endl;

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}