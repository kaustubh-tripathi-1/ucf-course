#include<iostream>
#include <limits>
using namespace std;

void validInputCheck(int& , int);
inline void swap(int &, int &);

int main()
{
    int num1, num2;
    cout<<"Enter a number to swap with another number -"<<endl;
    validInputCheck(num1, 1);
    cout<<"Enter another number to swap with the number -"<<endl;
    validInputCheck(num2, 1);
    
    cout<<"Before Swapping -"<<endl<<"Number 1 - "<<num1<<" , "<<"Number 2  - "<<num2<<endl;
    
    swap(num1, num2);
    
    cout<<"After Swapping -"<<endl<<"Number 1 - "<<num1<<" , "<<"Number 2  - "<<num2<<endl;

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of an Integer
void validInputCheck( int& n, int allowNegative)
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

//@ Swap 2 values with Ref. Var.
void swap(int &n1, int &n2)
{
    int temp;

    temp = n1;
    n1 = n2;
    n2 = temp;
    
}