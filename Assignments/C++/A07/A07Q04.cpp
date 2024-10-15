#include<iostream>
#include <limits>
using namespace std;

void swapArrays(int *, int, int *, int);

int main()
{
    int numbers1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int numbers2[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int i;
    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    int size2 = sizeof(numbers2) / sizeof(numbers2[0]);

    cout<<"Arrays before swapping -"<<endl;

    cout<<"Array 1 -"<<endl;
    for ( i = 0 ; i < size1 ; i++) 
        cout<<numbers1[i]<<" ";
    
    cout<<endl<<"Array 2 -"<<endl;
    for ( i = 0 ; i < size2 ; i++) 
        cout<<numbers2[i]<<" ";


    swapArrays(numbers1, size1, numbers2, size2);

    cout<<endl<<"\nArrays after swapping -"<<endl;

    cout<<"Array 1 -"<<endl;
    for ( i = 0 ; i < size1 ; i++) 
        cout<<numbers1[i]<<" ";
    
    cout<<endl<<"Array 2 -"<<endl;
    for ( i = 0 ; i < size2 ; i++) 
        cout<<numbers2[i]<<" ";

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Swaps 2 arrays
void swapArrays(int *num1, int size1, int *num2, int size2)
{
    if (size1 == 0 || size2 == 0)
    {
        cout << "One of the arrays is empty. Cannot swap." << endl;
        return;
    }
    
    for ( int i = 0 ; i < (size1<size2?size1:size2) ; i++)
    {
        int temp = num1[i];
        num1[i] = num2[i];
        num2[i] = temp;
    }
}