#include <bits/stdc++.h>
#include<iostream>

void printArray(int *, int);
int hoarePartition(int *, int, int);
void quickSort(int *, int, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    // int numbers[] = { 24, 58, 11, 67, 92, 43, 0, -3 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Quick Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    quickSort(numbers, 0, size-1);

    std::cout<<"\nArray after sorting -\n";
    printArray(numbers, size);

    std::cin.get();
    return 0;
}

//@ Prints the array
void printArray(int *array, int size)
{
    if ( size <= 0 )
    {
        std::cout<<"\nInvalid array || size provided!\n";
        return;
    }

    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout<<array[i]<<" ";
    }

    std::cout<<"\n";
}

//@ Helper Function for Quick Sort that partitions the array, placing the 1st element at its right position
//$ Hoare's partition which is best
int hoarePartition(int *array, int left, int right)
{

    int pivot = array[left];
    int leftPtr = left - 1, rightPtr = right + 1;

    while ( leftPtr < rightPtr )
    {
        do
        {
            leftPtr++;
        } while ( pivot > array[leftPtr] );

        do
        {
            rightPtr--;
        } while ( pivot < array[rightPtr]  );

        if ( leftPtr >= rightPtr )
            return rightPtr;

        std::swap( array[leftPtr], array[rightPtr] );

    }

    return 0;
}

//@ My Hybird logic between lomuto and hoare partition 
int partition(int *array, int left, int right)
{

    int pivot = array[left];
    int leftPtr = left /* - 1 */, rightPtr = right /* + 1 */;

    while ( leftPtr < rightPtr )
    {
        while ( leftPtr < rightPtr && pivot > array[leftPtr] )
            leftPtr++;

        while ( leftPtr < rightPtr && pivot < array[rightPtr] )
            rightPtr--;

        if ( leftPtr >= rightPtr )
            return rightPtr;

        std::swap( array[leftPtr], array[rightPtr] );

    }
    return 0;

}

//@ Sorts the array using Quick Sort Algo.
void quickSort(int *array, int left, int right)
{
    if ( left >= right )
        return;

    //$ For hoare partition
    int pivotIndex = hoarePartition(array, left, right);
    quickSort(array, left, pivotIndex );
    quickSort(array, pivotIndex + 1, right);

    //$ For hybrid partition
    /* int pivotIndex = hoarePartition(array, left, right);
    quickSort(array, left, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, right); */

}