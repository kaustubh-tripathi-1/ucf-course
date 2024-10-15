#include<iostream>
#include <limits>
using namespace std;

void mergeArrays(int *, int&, int *, int, int *, int);

int main()
{
    int numbers1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int numbers2[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int i;
    int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    int size2 = sizeof(numbers2) / sizeof(numbers2[0]);

    cout<<"Arrays before merging -"<<endl;

    cout<<"Array 1 -"<<endl;
    for ( i = 0 ; i < size1 ; i++) 
        cout<<numbers1[i]<<" ";
    
    cout<<endl<<"Array 2 -"<<endl;
    for ( i = 0 ; i < size2 ; i++) 
        cout<<numbers2[i]<<" ";

    int mergedArray[20] = {0};
    int size3 = size1 + size2;
    mergeArrays(numbers1, size1, numbers2, size2, mergedArray, size3);

    cout<<"Merged Array -"<<endl;
    for ( i = 0 ; i < size3 ; i++) 
        cout<<mergedArray[i]<<" ";
    
    

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Merge 2 arrays
void mergeArrays(int *num1, int& size1, int *num2, int size2, int *mergedArray, int size3)
{
    //$ Normal merge without checking greater or lesser values
    /* if (size1 == 0 || size2 == 0)
    {
        cout << "One of the arrays is empty. Cannot swap." << endl;
        return;
    }
    
    int i, j;
    for (  i = 0 ; i < size1 ; i++)
        mergedArray[i] = num1[i];

    for ( j = 0;  j < size2; i++, j++)
        mergedArray[i] = num2[j]; */



    //$ Merge with checking greater or lesser values
    int i, j, k;

    for ( i = 0, j = 0, k = 0 ; i < size1 && j < size2 ; k++)
    {
        if ( num1[i] < num2[j] )
        {
            mergedArray[k] = num1[i];
            i++;
        }
        else
        {
            mergedArray[k] = num2[j];
            j++;
        }
    }

    while ( i < size1 )
    {
        mergedArray[k] = num1[i];
        i++;
        k++;
    }
    while ( j < size1 )
    {
        mergedArray[k] = num2[j];
        j++;
        k++;
    }

}