#include<stdio.h>
#include<conio.h>

void mergeArray( int [], int [], int [], int, int, int);
void sortArray(int [], int);

int main()
{
    int size1, size2, size3;
    int numbers1[10] = {2, 4, 1, 5, 3, 9, 6, 8, 7, 10};
    int numbers2[10] = {33, 44, 11, 55, 33, 99, 66, 88, 77, 10};
    size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    size2 = sizeof(numbers2) / sizeof(numbers2[0]);

    size3 = size1 + size2;

    int merged[size3];

    sortArray( numbers1, size1);
    sortArray( numbers2, size2);

    mergeArray(numbers1, numbers2, merged, size1, size2, size3);

    printf("Here's the Merged Array - \n");

    for( int i=0 ; i< size3 ; i++)
        printf("%d ", merged[i]);

    sortArray(merged, size3);

    printf("Here's the Sorted Array - \n");

    for( int i=0 ; i< size3 ; i++)
        printf("%d ", merged[i]);
    
    getch();
    return 0;
}

//@ Merging 2 Arrays
void mergeArray( int numbers1[], int numbers2[], int merged[], int size1, int size2, int size3)
{
    for( int i=0 ; i<size1 ; i++)
    {
        merged[i] = numbers1[i];
    }

    for( int i=size1, j=0 ; i < size3 ; i++, j++)
    {
        merged[i] = numbers2[j];
    }
}

//@ Sorting the array

void sortArray(int a[], int size)
{
    int i, j, temp;

    for( i=0 ; i < size ; i++)
    {
        for( j=0 ; j < size-i-1 ; j++)
        {
            if( a[j] < a[j+1] )
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}