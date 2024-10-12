#include<iostream>
#include <limits>
using namespace std;

void validInputCheck(int &, int);
int getMaxDigit(int);

int main()
{
    int num;
    cout<<"Enter a number to know the highest digit -"<<endl;
    validInputCheck(num, 1);

    int maxDigit = getMaxDigit(num);

    cout<<"The highest value digit in "<<num<<" is "<<maxDigit<<endl;

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

//@ Finding the highest value digit
int getMaxDigit( int num )
{
    int maxDigit=0, remainder;

    if ( num < 0)
        num = -num;

    while( num )
    {
        remainder = num % 10;

        if ( maxDigit < remainder )
            maxDigit = remainder;
        
        if ( maxDigit == 9)
            break;
        
        num /= 10;
    }
    
    return maxDigit;
    
}