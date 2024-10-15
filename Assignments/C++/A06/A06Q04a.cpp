#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &n, int allowNegative);
int gcd( int , int );
int calculateLCM(int, int, int);
int calculateLCM(int, int);

int main()
{
    int num1, num2, num3, lcm=1;
    cout<<"Enter 3 numbers to calculate LCM -"<<endl;
    validInputCheck(num1, 0);
    validInputCheck(num2, 0);
    validInputCheck(num3, 0);

    lcm = calculateLCM(num1, num2, num3);
    cout<<"LCM of "<<num1<<", "<<num2<<" and "<<num3<<" is "<<lcm<<endl;

    lcm = calculateLCM(num1, num2);
    cout<<"LCM of "<<num1<<" and "<<num2<<" is "<<lcm<<endl;


    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of 1 int type value
void validInputCheck( int &n, int allowNegative)
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

int gcd( int a, int b)
{
    if ( b == 0)
        return a;

    return gcd(b, a%b);
}

//& Overloaded Functions

//@ Calculates LCM of 2 numbers
int calculateLCM(int n1, int n2)
{
    return ( n1 * n2) / gcd(n1, n2);
}
//@ Calculates LCM of 3 numbers
int calculateLCM(int n1, int n2, int n3)
{
    return calculateLCM(calculateLCM(n1, n2), n3);
}
