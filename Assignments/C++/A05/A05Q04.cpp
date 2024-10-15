#include<iostream>
#include <limits>
#include <iomanip>
using namespace std;

void validInputCheck( int&, int&, int );
void validInputCheck( double&, double&, int );
inline int findGreater(int, int);
inline double findGreater(double, double);

int main()
{
    int num1, num2;
    double num3, num4;

    cout<<"Enter 2 numbers to find the greater number -"<<endl;
    validInputCheck(num1, num2, 1);

    int max1 = findGreater(num1, num2); 

    cout<<max1<<" is greater between integers "<<num1<<" and "<<num2<<endl;

    cout<<"Enter 2 numbers to find the greater number -"<<endl;
    validInputCheck(num3, num4, 1);

    double max2 = findGreater(num3, num4); 

    cout<<fixed<<setprecision(4)<<max2<<" is greater between real numbers "<<num3<<" and "<<num4<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Overloaded Functions

//$ Validate User Input of 2 Integer Consts.
void validInputCheck( int &n1, int &n2, int allowNegative)
{
    while ( 1 )
    {
        cout<<"Enter Integers only"<<endl;
        cin>>n1>>n2;

        if( cin && (allowNegative || ( n1 >= 0 && n2 >= 0 ) ))   //& Good State, Input Successful
            break;
        else
        {
            //& Invalid Input, Failure/Bad State
            cout<<"Invalid Input! Enter Again -"<<endl;

            //& Clear the fail/bad state
            cin.clear();

            //& Ignore invalid input until the '\n' char ( end of current line )
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

//$ Validate User Input of 2 Real Consts.
void validInputCheck( double &n1, double &n2, int allowNegative)
{
    while ( 1 )
    {
        cout<<"Enter Real numbers only"<<endl;
        cin>>n1>>n2;

        if( cin && (allowNegative || ( n1 >= 0 && n2 >= 0 ) ))   //& Good State, Input Successful
            break;
        else
        {
            //& Invalid Input, Failure/Bad State
            cout<<"Invalid Input! Enter Again -"<<endl;

            //& Clear the fail/bad state
            cin.clear();

            //& Ignore invalid input until the '\n' char ( end of current line )
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

//@ Overloaded Functions

//$ Integer Constants
int findGreater(int n1, int n2)
{
    return n1>n2 ? n1 : n2;
}

//$ Real Constants
double findGreater(double n1, double n2)
{
    return n1>n2 ? n1 : n2;
}