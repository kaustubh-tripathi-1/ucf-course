#include<iostream>
#include <limits>
#include <string>
using namespace std;

class Date
{
    private :

        int d, m, y;
        bool isValid;

        bool isLeapYear(int year) const
        {
            return (y % 4 == 0 && y % 100 != 0) || ( y % 400 == 0);
        }

        int getDaysInMonth(int month, int year) const
        {
            int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if ( month == 2 && isLeapYear(year) )
                return 29;
            else
                return daysInMonth[month-1];
            
        }
        

    public :

        Date(int d = 1, int m = 1, int y = 1900)
        : 
            d(d), m(m), y(y), isValid(true)
        {
            if ( (d <= 0|| d > getDaysInMonth(m, y)) || ( m <= 0 || m > 12 ) || ( y < 1900 || y > 3000 ))
            {
                isValid = false;
                cout<<"Invalid Date values!\n";
            }
        }


        Date(const Date &date)
        :
            d(date.d),
            m(date.m),
            y(date.y),
            isValid(date.isValid)
            {}

        void showDate() const
        {
            if( isValid )
                cout<<"Date is : "<<(d < 10 ? "0" : "")<<d<<"."<<(m < 10 ? "0" : "")<<m<<"."<<y<<endl;
            else
                cout<<"Date cannot be displayed as it is invalid!\n";
        }

};

int main()
{
    Date d1(31, 10, 2024);
    d1.showDate();

    Date d2 = d1;
    d2.showDate();

    Date d3(31,4,2023);
    d3.showDate();
    
    // while ( getchar() != '\n');
    cin.get();
    return 0;
}