#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &n, int allowNegative);
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

//@ Finds the next Prime number
int nextPrime(int num)
{
    int next = num+1;
    
    while ( !checkPrime(next) )
        next++;

    return next;
    
}

//& Overloaded Functions
//@ Calculates LCM of 3 numbers
int calculateLCM(int n1, int n2, int n3)
{
    int lcm=1;
    int prime=2;
    while ( n1 > 1 || n2 > 1 || n3 > 1)
    {
        if ( n1 % prime == 0 || n2 % prime == 0 || n3 % prime == 0)
        {
            if ( n1 % prime == 0 )
            {
                n1 /= prime;
            }
            if ( n2 % prime == 0 )
            {
                n2 /= prime;
            }
            if ( n3 % prime == 0 )
            {
                n3 /= prime;
            }
            lcm *= prime;
        }
        else
            prime = nextPrime(prime);
    }
    
    return lcm;
}

//@ Calculates LCM of 2 numbers
int calculateLCM(int n1, int n2)
{
    int lcm=1;
    int prime=2;
    while ( n1 > 1 || n2 > 1 )
    {
        if ( n1 % prime == 0 || n2 % prime == 0 )
        {
            if ( n1 % prime == 0 )
            {
                n1 /= prime;
            }
            if ( n2 % prime == 0 )
            {
                n2 /= prime;
            }
            
            lcm *= prime;
        }
        else
            prime = nextPrime(prime);
    }
    
    return lcm;
}