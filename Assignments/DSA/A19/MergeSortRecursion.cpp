#include<iostream>

void printArray(int *, int);
void mergeArrays(int *, int , int , int , int );
void mergeSort(int *, int, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    // int numbers[] = { 24, 58, 11, 67, 92, 43, 0, -3 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Merge Sort -\n\n";
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

//@ Merges the 2 sorted arrays
void mergeArrays(int *array, int leftOfFirstArray, int rightOfFirstArray, int leftOfSecondArray, int rightOfSecondArray)
{

    int sizeOfFirstArray = rightOfFirstArray - leftOfFirstArray + 1;
    int sizeOfSecondArray = rightOfSecondArray - leftOfSecondArray + 1;
    int newArrayIndex = 0, newArraySize = sizeOfFirstArray + sizeOfSecondArray, indexOfFirstArray = leftOfFirstArray, indexOfSecondArray = leftOfSecondArray;
    int *newArray = new int[newArraySize];  //& Create a temporary array for merging

    //& Merge in a sorted manner, placing the smaller value first in the merged array
    while ( indexOfFirstArray <= rightOfFirstArray && indexOfSecondArray <= rightOfSecondArray  )
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

    //& Copy the rest of the values of left sub-array (if left)
    while ( indexOfFirstArray <= rightOfFirstArray )
    {
        newArray[newArrayIndex] = array[indexOfFirstArray];
        indexOfFirstArray++;
        newArrayIndex++;
    }

    //& Copy the rest of the values of right sub-array (if left)
    while ( indexOfSecondArray <= rightOfSecondArray )
    {
        newArray[newArrayIndex] = array[indexOfSecondArray];
        indexOfSecondArray++;
        newArrayIndex++;
    }

    int left = leftOfFirstArray;

    //& Copy the merged array values to the original sub-array
    for ( newArrayIndex = 0 ; newArrayIndex < newArraySize && left <= rightOfSecondArray ; newArrayIndex++, left++ )
    {
        array[left] = newArray[newArrayIndex];
    }

    delete newArray;    //& Delete the temporary merged array
    
}

//@ Recursive method to sort an array with Merge-Sort
void mergeSort(int *array, int left, int right)
{
    if ( left >= right || left < 0 || right < 0 )
        return;

    int middle = ( left + right ) / 2;

    mergeSort( array, left, middle );   //& Recursive call for left sub-array
    mergeSort( array, middle + 1, right );  //& Recursive call for right sub-array

    mergeArrays(array, left, middle, middle + 1, right);    //& Merge 2 sub-arrays
}