#include<iostream>
#include <limits>
using namespace std;

void validInputCheck( int &n );
void validInputCheck( int &n, int allowNegative);
void reverseArray(int **p, int start, int end);
void rotateArray(int *pArr, int size, int direction=1, int position=1);

int main()
{
    int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int positions, direction, i;

    cout<<"Original Array -"<<endl;
    for ( i = 0 ; i < 10 ; i++ )
        cout<<numbers[i]<<" ";

    cout<<endl<<"Enter the direction in which you want to rotate the array-"<<endl;
    validInputCheck(direction);
    cout<<"Enter the no. of positions by which you want to rotate the array-"<<endl;
    validInputCheck(positions, 0);

    //$ With direction and position arguments
    rotateArray(numbers, 10, direction, positions);

    //$ Without direction and position arguments
    // rotateArray(numbers, 10);

    cout<<"Rotated Array -"<<endl;
    for ( i = 0 ; i < 10 ; i++ )
        cout<<numbers[i]<<" ";

    while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of direction of rotation, 1 for right and -1 for left
void validInputCheck( int &n )
{
    while ( 1 )
    {
        cin>>n;

        if( cin && ( n == 1 || n == -1 ))   //& Good State, Input Successful
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

//@ Reverse an array
void reverseArray(int *p, int start, int end)
{
    while ( start <= end )
    {
        int temp = p[start];
        p[start] = p[end];
        p[end] = temp;
        start++;
        end--;
    }
}

//@ Rotate array
void rotateArray(int *pArr, int size, int direction, int position)
{
    //$ Simple rotation logic
    /* int i, j;
    position %= size;
    if ( direction == 1 )
    {
        for ( i = 0 ; i < position ; i++)
        {
            int temp = pArr[size-1];
            for ( j = size-2 ; j >= 0 ; j--)
            {
                pArr[j+1] = pArr[j];
            }
            pArr[0] = temp;
        }
    }
    else if ( direction == -1 )
    {
        for ( i = 0 ; i < position ; i++)
        {
            int temp = pArr[0];
            for ( j = 1 ; j <= size-1 ; j++)
            {
                pArr[j-1] = pArr[j];
            }
            pArr[size-1] = temp;
        }
    } */

    //$ Reverse Logic
    
    position %= size;

    //$ Handle edge case where position % size == 0
    if (position == 0)
        return;
    
    if ( direction == 1 )
    {
        reverseArray(pArr, 0, size-1);     
        reverseArray(pArr, 0, position-1); 
        reverseArray(pArr, position, size-1);  
    }
    else if ( direction == -1 )
    {
        reverseArray(pArr, 0, size-1);     
        reverseArray(pArr, size - position, size-1); 
        reverseArray(pArr, 0, size-position-1);  
    }
   
}