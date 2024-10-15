#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &, int &, int &, int );
inline int add( int, int, int = 0);

int main()
{
    int num1, num2, num3;
    cout<<"Enter 3 numbers to add -"<<endl;
    validInputCheck(num1, num2, num3, 1);

    cout<<"Adding 1st and 2nd number only -"<<endl;
    int sum = add(num1, num2);
    cout<<"Sum of first 2 numbers is - "<<sum<<endl<<endl;


    cout<<"Adding all numbers -"<<endl;
    sum = add(num1, num2, num3);
    cout<<"Sum of all numbers is - "<<sum<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of 3 Integer
void validInputCheck( int& n1, int &n2, int &n3, int allowNegative)
{
    while ( 1 )
    {
        cin>>n1>>n2>>n3;

        if( cin && (allowNegative || ( n1 >= 0 && n2 >= 0 && n3 >= 0 ) ))   //$ Good State, Input Successful
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

//@ Adding 2 or 3 numbers using default arg
int add(int n1, int n2, int n3)
{
    return n1 + n2 + n3;
}