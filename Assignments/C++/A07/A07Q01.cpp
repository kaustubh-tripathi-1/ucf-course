#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &n, int allowNegative);
int calculateHCF(int, int);

int main()
{
    int num1, num2;
    cout<<"Enter 2 numbers to calculat HCF -"<<endl;
    validInputCheck(num1, 0);
    validInputCheck(num2, 0);

    int hcf = calculateHCF(num1, num2);

    cout<<"HCF of "<<num1<<" and "<<num2<<" is "<<hcf<<endl;

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

//@ Calculates HCF of 2 nums
int calculateHCF(int n1, int n2)
{
    //$ Recusrion
    if ( n2 == 0)
        return n1;

    return calculateHCF(n2, n1%n2);

    //$ Loops

    /* int hcf = 1, remainder;

    while ( n2 != 0 )
    {
        remainder = n1 % n2;
        n1 = n2;
        n2 = remainder;
    }

    hcf = n1;

    return hcf; */
    
}