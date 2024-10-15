#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &, int );
void arrayInput(int *, int);
void arrayPrint(int *, int);
void sortArray(int *, int , bool = true);

int main()
{
    int length;
    cout<<"Enter the length for the array :"<<endl;
    validInputCheck(length, 0);

    int numbers[length];

    cout<<"Enter "<<length<<" values for the array -"<<endl;
    arrayInput(numbers, length);

    cout<<"The original array is -"<<endl;
    arrayPrint(numbers, length);

    sortArray(numbers, length);

    cout<<"Ascending sort of the array -"<<endl;
    arrayPrint(numbers, length);

    sortArray(numbers, length, false);

    cout<<"Descending sort of the array -"<<endl;
    arrayPrint(numbers, length);

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

//@ Array Input
void arrayInput(int *ptrarr, int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        cout<<"Enter "<<i+1<<" value - ";
        validInputCheck(ptrarr[i], 1);
    }
}

//@ Array Print
void arrayPrint(int *ptrarr, int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        cout<<ptrarr[i]<<" ";
    }
    cout<<endl;
}

//@ Sort array ascending or descending
void sortArray(int *ptrarr, int size, bool order)
{
    int i, j;

    if ( order )
    {
        for ( i = 0 ; i < size - 1 ; i++)
        {
            for ( j = 0 ; j < size-i-1 ; j++)
            {
                if ( ptrarr[j] > ptrarr[j+1] )
                {
                    int temp = ptrarr[j];
                    ptrarr[j] = ptrarr[j+1];
                    ptrarr[j+1] = temp;
                }
            }
        }
    }
    else
    {
        for ( i = 0 ; i < size - 1 ; i++)
        {
            for ( j = 0 ; j < size-i-1 ; j++)
            {
                if ( ptrarr[j] < ptrarr[j+1] )
                {
                    int temp = ptrarr[j];
                    ptrarr[j] = ptrarr[j+1];
                    ptrarr[j+1] = temp;
                }
            }
        }
    }
    
}