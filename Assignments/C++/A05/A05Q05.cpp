#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int&, int&, int );
void validInputCheck( float &, float &, int );
void validInputCheck( double&, double&, int );
int addNumbers(int, int);
float addNumbers(float, float);
double addNumbers(double, double);

int main()
{
    int num1, num2;
    float num3, num4;
    double num5, num6, sum;

    //$ int addition
    cout<<"Enter 2 numbers to add them -"<<endl;
    validInputCheck(num1, num2, 1);

    sum = addNumbers(num1, num2);

    cout<<"Sum of "<<num1<<" and "<<num2<<" is "<<sum<<endl;

    //$ float addition
    cout<<"Enter 2 numbers to add them -"<<endl;
    validInputCheck(num3, num4, 1);

    sum = addNumbers(num3, num4);

    cout<<"Sum of "<<num3<<" and "<<num4<<" is "<<sum<<endl;

    //$ double addition
    cout<<"Enter 2 numbers to add them -"<<endl;
    validInputCheck(num5, num6, 1);

    sum = addNumbers(num5, num6);

    cout<<"Sum of "<<num5<<" and "<<num6<<" is "<<sum<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Overloaded Functions

//$ Validate User Input of 2 int type values
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

//$ Validate User Input of 2 float type values
void validInputCheck( float &n1, float &n2, int allowNegative)
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

//$ Validate User Input of 2 double type values
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

//$ Function to add 2 int type numbers
int addNumbers(int n1, int n2)
{
    return n1+n2;
}

//$ Function to add 2 float type numbers
float addNumbers(float n1, float n2)
{
    return n1+n2;
}

//$ Function to add 2 double type numbers
double addNumbers(double n1, double n2)
{
    return n1+n2;
}