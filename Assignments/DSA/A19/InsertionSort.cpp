#include<iostream>

void printArray(int *, int);
void insertionSort(int *, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Insertion Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    insertionSort(numbers, size);

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

//@ Insertion Sort Algo.
void insertionSort(int *array, int size)
{
    if ( size <= 0 )
    {
        std::cout<<"\nInvalid array || size provided!\n";
        return;
    }

    for ( int unsortedIndex = 1 ; unsortedIndex < size ; unsortedIndex++ )    //& Loop will run till size-1
    {
        int currentValue = array[unsortedIndex];   //& Preserve the element so that it doesn't get overwritten
        int sortedIndex = unsortedIndex-1;
        while ( sortedIndex >= 0 && currentValue < array[sortedIndex] )
        {
            array[sortedIndex + 1] = array[sortedIndex];  //& Shift one by one from left to right till it reaches it's correct place in the sub-array
            sortedIndex--;
        }
        array[sortedIndex + 1] = currentValue;    //& Assign current element at it's right index 
    }

}
