#include<iostream>

void printArray(int *, int);
void selectionSort(int *, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Insertion Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    selectionSort(numbers, size);

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

//@ Selection Sort Algo.
void selectionSort(int *array, int size)
{
    
    for ( int currentIndex = 0 ; currentIndex < size ; currentIndex++ )
    {
        int compareIndex, minValueIndex = currentIndex;

        //& Find the smallest element in the rest of the array ( excluding current value )
        for ( compareIndex = currentIndex+1 ; compareIndex < size ; compareIndex++ )
        {
            if ( array[compareIndex] < array[minValueIndex] )
            {
                minValueIndex = compareIndex;
            }
        }

        //& Swap the current element with the smallest one in the sub-array
        if ( currentIndex != minValueIndex )
        {
            int temp = array[currentIndex];
            array[currentIndex] = array[minValueIndex];
            array[minValueIndex] = temp;
        }
    }

}