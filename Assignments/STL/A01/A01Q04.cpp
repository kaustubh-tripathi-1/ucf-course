#include<iostream>
#include<vector>
#include<string>

//@ Prints the array
template <typename DT>
void printArray(DT *array, int size)
{
    if ( size <= 0 )
        return;

    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout<<array[i]<<" ";
    }

    std::cout<<"\n";
}

//@ Selects pivot as the median of 3
template <typename DT>
DT medianOfThree(DT *array, int left, int right)
{
    int middle = left + (right - left) / 2;

    if ( array[left] > array[middle] )
        std::swap(array[left], array[middle]);

    if ( array[left] > array[right] )
        std::swap(array[left], array[right]);

    if ( array[right] < array[middle] )
        std::swap(array[right], array[middle]);

    return array[middle];
}

//@ Hoare's partition
template <typename DT>
int hoarePartition(DT *array, int left, int right)
{
    DT pivot = medianOfThree(array, left, right);
    int leftPtr = left - 1, rightPtr = right + 1;

    while( true )
    {
        do
        {
            leftPtr++;
        } while ( pivot > array[leftPtr] );

        do
        {
            rightPtr--;
        } while ( pivot < array[rightPtr] );

        if ( leftPtr >= rightPtr )
            return rightPtr;

        std::swap(array[leftPtr], array[rightPtr]);
    }

}

//@ Quick sort
template <typename DT>
void quickSort(DT *array, int left, int right)
{
    if ( left >= right )
        return;

    int pivotIndex = hoarePartition(array, left, right);

    quickSort(array, left, pivotIndex);
    quickSort(array, pivotIndex + 1, right);

}

int main()
{
    int nums[] = {34, 2134, -321, 94, 8, 0, 71, 9242, -123, -4};
    // float nums[] = {34.45f, 2134.235f, -321.6f, 94.32f, 8.98f, 0.1f, 71.7f, 9242.23f, -123.1f, -4.9f};
    // double nums[] = {34.45, 2134.235, -321.6, 94.32, 8.98, 0.1, 71.7, 9242.23, -123.1, -4.9};
    // std::string nums[] = {"One", "Two", "Three", "Fifty", "Six"};

    int size = sizeof(nums) / sizeof(nums[0]);

    std::cout<<"Array before sorting -\n";
    printArray(nums, size);

    quickSort(nums, 0, size-1);
    
    std::cout<<"Array after sorting -\n";
    printArray(nums, size);

    std::cin.get();
    return 0;
}

