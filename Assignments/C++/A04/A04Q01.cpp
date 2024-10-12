#include<iostream>
#include <limits>
using namespace std;

void validInputCheck(int& , int);
int checkPrime(int );
void printPrime(int, int );

int main()
{
    int num1, num2;

    cout<<"Enter range starting number to print Primes in between -"<<endl;
    validInputCheck(num1, 0);
    cout<<"Enter range ending number to print Primes in between -"<<endl;
    validInputCheck(num2, 0);

    printPrime(num1, num2);

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

//@ Check for Prime Number
int checkPrime(int num)
{
    int i;
    
    if ( num < 2 )
        return 0;   //$ Not Prime

    if ( num == 2 )
        return 1;   //$ 2, Prime

    if ( num % 2 == 0 )
        return 0;   //$ Divisible by 2, Not Prime
    

    for ( i = 3 ; i*i <= num ; i+=2)
    {
        if ( num % i == 0 )
            return 0;   //$ Found Divisor, not a Prime
    }

    return 1;

}

//@ Print Prime Numbers in a range
void printPrime( int numStart, int numEnd )
{
    int i;
    if ( numStart >= numEnd || ( numEnd - numStart == 1 ))
    {
        cout<<"The range is invalid!"<<endl;
        return;
    }

    bool foundPrime = false;
    for ( i = numStart+1 ; i < numEnd ; i++)
    {
        if ( checkPrime(i) )
        {
            cout<<i<<" ";
            foundPrime = true;
        }
    }

    if (!foundPrime)
        cout<<"No primes found in the given range."<<endl;
    
}