#include<iostream>
#include <limits>
using namespace std;

void validInputCheck(int& , int );
double calculatePower(int, int);

int main()
{
    int num, power;
    cout<<"Enter a number -"<<endl;
    validInputCheck(num, 1);
    cout<<"Enter the power for the number to calculate -"<<endl;
    validInputCheck(power, 1);

    double result = calculatePower(num, power);

    cout<<num<<" to the power of "<<power<<" is "<<result<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of an Integer
void validInputCheck(int& n, int allowNegative)
{
    while ( 1 )
    {
        cin>>n;

        if( cin && (allowNegative || n > 0 ))   //$ Good State, Input Successful
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

//@ Calculate number to the power POWER
double calculatePower(int num, int power)
{
    //$ My logic, Time Complex. O(n)
    /* int i;
    double result=1;
    if ( power == 0 )
        return 1;

    if ( power > 0 )
    {
        for ( i = 0 ; i < power ; i++)
        {
            result *= num;
        }
    }
    else if ( power < 0 )
    {
        for ( i = power ; i < 0 ; i++)
        {
            result *= num;
        }

        result = 1 / result;
        
    }

    return result; */

    //$ Exponentiation by Squaring Logic, Time Complex. O(log n)

    double result = 1;
    int absPower = abs(power);  //$ Take absolute value of power for calculation
    
    while (absPower > 0)
    {
        if ( absPower %2 == 1)  //$ If power is odd, multiply result by num
            result *= num;      

        num *= num;            //$ Square the number
        absPower /= 2;         //$ Reduce power by half
    }

    if ( power < 0 )         //$ If power was negative, invert the result
        result = 1 / result;
    

    return result;
    
}