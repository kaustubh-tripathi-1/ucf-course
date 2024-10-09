#include<iostream>
using namespace std;

int main()
{
    int numbers[] = {3, 45, 54, 4, 34, 7, 893, 93, 634, 67};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    int sum = 0;

    cout<<"The array elements are -"<<endl;

    for ( int i = 0 ; i < size ; i++)
    {
        cout<<numbers[i]<<" ";
    }

    cout<<endl;

    for ( int i = 0 ; i < size ; i++)
    {
        sum += numbers[i];
    }

    cout<<"The sum of all elements of the array is "<<sum;

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}