#include <bits/stdc++.h>
#include<iostream>

void printArray(int *, int);
int hoarePartition(int *, int, int);
void mergeSort(int *, int, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    // int numbers[] = { 24, 58, 11, 67, 92, 43, 0, -3 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Quick Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    mergeSort(numbers, 0, size-1);

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

void mergeArrays(int *array, int leftOfFirstArray, int rightOfFirstArray, int leftOfSecondArray, int rightOfSecondArray, int size1, int size2)
{

    int newArrayIndex = 0, newArraySize = size1 + size2, indexOfFirstArray = leftOfFirstArray, indexOfSecondArray = leftOfSecondArray;
    int *newArray = new int[newArraySize];

    while ( indexOfFirstArray < size1 && indexOfSecondArray <= size2  )
    {
        if ( array[indexOfFirstArray] < array[indexOfSecondArray]  )
        {
            newArray[newArrayIndex] = array[indexOfFirstArray];
            indexOfFirstArray++;
        }
        else
        {
            newArray[newArrayIndex] = array[indexOfSecondArray];
            indexOfSecondArray++;
        }
        newArrayIndex++;
    }

    while ( indexOfFirstArray < size1 )
    {
        newArray[newArrayIndex] = array[indexOfFirstArray];
        indexOfFirstArray++;
        newArrayIndex++;
    }

    while ( indexOfSecondArray <= size2 )
    {
        newArray[newArrayIndex] = array[indexOfSecondArray];
        indexOfSecondArray++;
        newArrayIndex++;
    }

    int left = leftOfFirstArray;

    for ( newArrayIndex = 0 ; newArrayIndex < newArraySize && left <= rightOfSecondArray ; newArrayIndex++, left++ )
    {
        array[left] = newArray[newArrayIndex];
    }

    delete newArray;
    
}

void mergeSort(int *array, int left, int right)
{
    if ( left >= right || left < 0 || right < 0 )
        return;

    int middle = ( left + right ) / 2;

    mergeSort( array, left, middle );
    mergeSort( array, middle + 1, right );

    int size1 = left + right, size2 = left + right;
    mergeArrays(array, left, middle, middle + 1, right, size1, size2);
}