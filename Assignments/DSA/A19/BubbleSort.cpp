#include<iostream>

void printArray(int *, int);
void bubbleSort(int *, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout<<"Sorting using Bubble Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    bubbleSort(numbers, size);

    std::cout<<"\nArray after sorting -\n";
    printArray(numbers, size);

    std::cin.get();
    return 0;
}

//@ Prints the array
void printArray(int *array, int size)
{
    if ( size <= 0 )
        return;

    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout<<array[i]<<" ";
    }

    std::cout<<"\n";
}

//@ Bubble Sort Algo.
void bubbleSort(int *array, int size)
{
    if ( size <= 0 )
    {
        std::cout<<"Invalid array || size provided!\n";
        return;
    }

    int rounds = 0;
    
    for ( int roundNumber = 0 ; roundNumber < size - 1 ; roundNumber++ )
    {
        for ( int comparisonIndex = 0 ; comparisonIndex < size-roundNumber-1 ; comparisonIndex++ )
        {
            if ( array[comparisonIndex] > array[comparisonIndex+1] )
            {
                int temp = array[comparisonIndex];
                array[comparisonIndex] = array[comparisonIndex+1];
                array[comparisonIndex+1] = temp;
            }
        }
        rounds++;
    }

    std::cout<<"Rounds : "<<rounds<<"\n";
    
}