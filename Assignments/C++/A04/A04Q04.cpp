#include<iostream>
#include <limits>
using namespace std;

void validInputCheck(int& , int );
unsigned long long int factorial(int);
long int combination(int, int);
void printPascalTriangle(int );

int main()
{
    int lines;
    cout<<"Enter the no. of lines you want to print of Pascal's triangle -"<<endl;
    validInputCheck(lines, 0);

    printPascalTriangle(lines);

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

//@ Factorial of a number
unsigned long long int factorial(int num)
{
    unsigned long long int fact = 1;

    for ( int i = num ; i > 1 ; i--)
        fact *= i;
    
    return fact;
}

//@ Calculate combination of n things selecred r at a time
long int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

//@ Print Pascal Triangle
void printPascalTriangle(int lines)
{
    int rows = lines, columns = (2*lines)-1;
    int i, j, k, n=0, r;

    for ( i = 1 ; i <= rows ; i++)
    {
        k = 1;
        r = 0;
        for ( j = 1 ; j <= columns ; j++)
        {
            if ( (j >= (lines+1) - i) && (j <= ((lines - 1) + i)) && k)
            {
                cout<<combination(n, r)<<"   ";
                k = 0;
                r++;
            }
            else
            {
                cout<<"    ";
                k = 1;
            }
        }
        cout<<endl;
        n++;
    }
}