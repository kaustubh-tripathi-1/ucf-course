#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &n, int allowNegative);
int checkPrime( int num);
void printPrimeFactors(int);

int main()
{
    int num;
    cout<<"Enter a number to print its Prime Factors -"<<endl;
    validInputCheck(num, 0);

    printPrimeFactors(num);

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

//@ Checks for a Prime Number
int checkPrime( int num)
{
    int i;

    for ( i = 2 ; i*i <= num ; i++)
    {
        if( num % i == 0)
            return 0;
    }

    return 1;   
}

void printPrimeFactors(int num)
{
    int i;

    if ( checkPrime(num) )
    {
        cout<<num<<" is already a Prime Number."<<endl;
        return;
    }

    for ( i = 2 ; i*i <= num ; i++)
    {
        if ( num % i == 0 && checkPrime(i))
            cout<<i<<" ";
    }
    
}