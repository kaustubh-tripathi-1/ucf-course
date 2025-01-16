#include<iostream>

void printArray(int *, int);
void modifiedBubbleSort(int *, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    // int numbers[] = {24, 58, 11, 67, 92, 43};
    // int numbers[] = {11, 24, 58, 43, 67, 92};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    std::cout<<"Sorting using Modified Bubble Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    modifiedBubbleSort(numbers, size);

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
void modifiedBubbleSort(int *array, int size)
{
    if ( size <= 0 )
    {
        std::cout<<"Invalid array || size provided!\n";
        return;
    }

    int rounds = 0;
    bool swapped = false;

    for ( int roundNumber = 0 ; roundNumber < size - 1 ; roundNumber++ )
    {
        swapped = false;
        for ( int comparisonIndex = 0 ; comparisonIndex < size-roundNumber-1 ; comparisonIndex++ )
        {
            if ( array[comparisonIndex] > array[comparisonIndex+1] )
            {
                int temp = array[comparisonIndex];
                array[comparisonIndex] = array[comparisonIndex+1];
                array[comparisonIndex+1] = temp;
                swapped = true;
            }
        }
        rounds++;
        if ( !swapped )
        {
            std::cout<<"Rounds : "<<rounds<<"\n";
            return;
        }
    }

}