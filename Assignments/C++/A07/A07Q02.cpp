#include<iostream>
#include <limits>
using namespace std;
constexpr double PI = 3.1415;

void validInputCheck( double &n, int allowNegative);
double calculateVolume( double radius);
double calculateVolume( double radius, double height);
double calculateVolume( double length, double breadth, double height);

int main()
{
    double radius, height, volume1, volume2, volume3, length, breadth, heightCone;

    //$ Volume of Cuboid
    cout<<"Enter length, breadth and height to calculate volume of cuboid -"<<endl;
    validInputCheck(length, 0);
    validInputCheck(breadth, 0);
    validInputCheck(height, 0);

    volume1 = calculateVolume( length, breadth, height);

    cout<<"The volume of cuboid is "<<volume1<<endl;

    //$ Volume of Cone
    cout<<"Enter radius and height to calculate volume of Cone -"<<endl;
    validInputCheck(radius, 0);
    validInputCheck(heightCone, 0);

    volume2 = calculateVolume( radius, heightCone );

    cout<<"The volume of Cone is "<<volume2<<endl;

    //$ Volume of Sphere
    cout<<"Enter radius to calculate volume of sphere -"<<endl;
    validInputCheck(radius, 0);

    volume3 = calculateVolume( radius );

    cout<<"The volume of sphere is "<<volume3<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of 1 int type value
void validInputCheck( double &n, int allowNegative)
{
    while ( 1 )
    {
        cin>>n;

        if( cin && (allowNegative || ( n >= 0  ) ))   //& Good State, Input Successful
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

//@ OVerloaded Functions

//$ For Volume of Sphere
double calculateVolume( double radius)
{
    return ( (4.0/3) * PI * (radius * radius * radius) );
}

//$ For Volume of Cone
double calculateVolume( double radius, double height)
{
    return ( (1.0/3) * PI * radius * radius * height );
}

//$ For Volume of Cuboid
double calculateVolume( double length, double breadth, double height)
{
    return length * breadth * height;
}