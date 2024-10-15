#include<iostream>
#include <limits>
using namespace std;
#define PI 3.1428

void validInputCheck( double&, int );
void validInputCheck( double&, double&, int );
void validInputCheck( float&, float&, int );
double calculateArea(double);
double calculateArea(double, double);
float calculateArea(float, float);

int main()
{
    double radius, length, breadth, area;
    float base, height;
    cout<<"Enter the radius of the circle to calculate area -"<<endl;
    validInputCheck(radius, 0);

    area = calculateArea(radius);

    cout<<"Area of circle is "<<area<<endl;

    cout<<"Enter the length and breadth of rectangle to calculate area -"<<endl;
    validInputCheck(length, breadth, 0);

    area = calculateArea(length, breadth);

    cout<<"Area of rectangle is "<<area<<endl;

    cout<<"Enter the base and height of triangle to calculate area -"<<endl;
    validInputCheck(base, height, 0);

    area = calculateArea(base, height);

    cout<<"Area of triangle is "<<area<<endl;
    
    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of a Real Consts.
void validInputCheck( double &n, int allowNegative)
{
    while ( 1 )
    {
        cin>>n;

        if( cin && (allowNegative || n >= 0 ))   //$ Good State, Input Successful
            break;
        else
        {
            //$ Invalid Input, Failure/Bad State
            cout<<"Invalid Input! Enter Again -"<<endl;

            //$ Clear the fail/bad state
            cin.clear();

            //$ Ignore invalid input until the '\n' char ( end of current line )
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

//@ Validate User Input of 2 Real Consts.
void validInputCheck( double& n1, double &n2, int allowNegative)
{
    while ( 1 )
    {
        cin>>n1>>n2;

        if( cin && (allowNegative || ( n1 >= 0 && n2 >= 0 ) ))   //$ Good State, Input Successful
            break;
        else
        {
            //$ Invalid Input, Failure/Bad State
            cout<<"Invalid Input! Enter Again -"<<endl;

            //$ Clear the fail/bad state
            cin.clear();

            //$ Ignore invalid input until the '\n' char ( end of current line )
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

//@ Validate User Input of 2 Real Consts.
void validInputCheck( float& n1, float &n2, int allowNegative)
{
    while ( 1 )
    {
        cin>>n1>>n2;

        if( cin && (allowNegative || ( n1 >= 0 && n2 >= 0 ) ))   //$ Good State, Input Successful
            break;
        else
        {
            //$ Invalid Input, Failure/Bad State
            cout<<"Invalid Input! Enter Again -"<<endl;

            //$ Clear the fail/bad state
            cin.clear();

            //$ Ignore invalid input until the '\n' char ( end of current line )
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
            
        }
    }
}

//@ Function Overloading

//$ Function for Area of Circle
double calculateArea(double radius)
{
    return PI * radius * radius;
}

//$ Function for Area of Rectangle
double calculateArea(double length, double breadth)
{
    return length * breadth;
}

//$ Function for Area of Triangle
float calculateArea(float base, float height)
{
    return ( 0.5 * base * height ) ;
}

