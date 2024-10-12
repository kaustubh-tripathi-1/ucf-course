#include<iostream>
#include <limits>
using namespace std;

void validInputCheck(unsigned long long int &, int);
int checkFibonacci(unsigned long long int );

int main()
{
    unsigned long long int num;
    cout<<"Enter a number to check in Fibonacci Series -"<<endl;
    validInputCheck(num, 0);

    int found = checkFibonacci(num);

    if ( found )
        cout<<num<<" is a term of Fibonacci Series."<<endl;
    else
        cout<<num<<" is not a term of Fibonacci Series."<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of an Integer
void validInputCheck(unsigned long long int& n, int allowNegative)
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

//@ Check number in Fibonacci Series
int checkFibonacci(unsigned long long int num)
{
    unsigned long long int first = 0, second = 1;
    unsigned long long int updatedTerm = first + second;

    if ( num == 0)
        return 1;

    int i=0;
    while ( num >= updatedTerm && i < 93 )
    {
        if ( num == updatedTerm )
            return 1;
        first = second;
        second = updatedTerm;
        updatedTerm = first + second;
        i++;
    }

    return 0;
    
}