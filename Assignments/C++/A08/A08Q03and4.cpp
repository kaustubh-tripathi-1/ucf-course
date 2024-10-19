#include<iostream>
#include <limits>
#include <string>
using namespace std;

//@ Class Date
class Date
{
    private :
        int day, month, year;
        
        bool isValidDate(int day, int month, int year)
        {
            //& Validation of Year and Month
            if ( year < 1950 || year > 2100 || month < 1 || month > 12)
                return false;

            //& Check number of days in each month
            int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            //& Leap year adjustment for February
            if ( isLeapYear(year) && month == 2)
            {
                daysInMonth[1] = 29;
            }

            //& Checking valid day range for the given month
            return day >= 1 && day <= daysInMonth[month - 1];
        }

        //& Checking for Leap year
        bool isLeapYear(int year)
        {
            return ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) );
        }



    public :

        //& Set the date with validation
        void setDate(int d, int m, int y)
        {
            if ( isValidDate(d, m, y) )
            {
                day = d;
                month = m;
                year = y;
            }
            else
            {
                cout<<"Invalid date values provided. Setting to default (01-01-1950)"<<endl;
                day = 1;
                month = 1;
                year = 1950;
            }

        }

        //& Display date in the format: DD.MM.YYYY
        void displayDateNormal()
        {
            cout<<"The date is -"<<endl;
            cout<<(day<10 ? "0" : "")<<day<<"."<<(month<10 ? "0" : "")<<month<<"."<<year<<endl;
        }

        //& Display date in the format: DD-MM-YYYY
        void displayDateHiphen()
        {
            cout<<"The date is -"<<endl;
            cout<<(day<10 ? "0" : "")<<day<<"-"<<(month<10 ? "0" : "")<<month<<"-"<<year<<endl;
        }

        //& Display date in the format: DD-MMM-YYYY (month name)
        void displayDateMonthName()
        {
            string monthName;

            switch(month)
            {
                case 1: monthName = "Jan"; break;
                case 2: monthName = "Feb"; break;
                case 3: monthName = "Mar"; break;
                case 4: monthName = "Apr"; break;
                case 5: monthName = "May"; break;
                case 6: monthName = "Jun"; break;
                case 7: monthName = "Jul"; break;
                case 8: monthName = "Aug"; break;
                case 9: monthName = "Sept"; break;
                case 10: monthName = "Oct"; break;
                case 11: monthName = "Nov"; break;
                case 12: monthName = "Dec"; break;
                default: monthName = "Invalid"; break;
            }
            
            cout<<"The date is -"<<endl;
            cout<<(day<10 ? "0" : "")<<day<<"-"<<monthName<<"-"<<year<<endl;
        }
};

int main()
{
    Date d1;
    d1.setDate(2, 10, 2024);
    d1.displayDateNormal();
    d1.displayDateHiphen();
    d1.displayDateMonthName();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}