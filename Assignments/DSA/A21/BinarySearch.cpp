#include<iostream>
#include<vector>

void printData(const std::vector<int> &nums)
{
    if ( nums.size() < 1)
        return;

    for ( int i = 0 ; i < nums.size() ; i++ )
        std::cout<<nums.at(i)<<" ";

    std::cout<<"\n";
}

//@ Function to select the pivot using the Median-of-Three method
int medianOfThree(std::vector<int> &arr, int left, int right)  
{
    int mid = left + (right - left) / 2;

    // Arrange [arr[left], arr[mid], arr[right]] in sorted order
    if (arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);

    if (arr[left] > arr[right])
        std::swap(arr[left], arr[right]);

    if (arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    // The median is now at `arr[mid]`, move it to `arr[left]`
    std::swap(arr[mid], arr[left]);

    return arr[left];  // Return pivot
}

//@ Hoare's partition which is best
int hoarePartition(std::vector<int> &array, int left, int right)
{

    // int pivot = array[left];    //$ Pivot is always the 1st element
    int pivot = medianOfThree(array, left, right);  //$ Selecting median of left, middle and right as pivot
    int leftPtr = left - 1, rightPtr = right + 1;

    while ( true )
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

}

//@ Sorts the array using Quick Sort Algo.
void quickSort(std::vector<int> &array, int left, int right)
{
    if ( left >= right )
        return;

    //$ For hoare partition
    int pivotIndex = hoarePartition(array, left, right);
    quickSort(array, left, pivotIndex );
    quickSort(array, pivotIndex + 1, right);

}

//@ Binary Search
size_t binarySearch(const std::vector<int> &nums, int target, size_t left, size_t right)
{
    //& Recursive approach
    /* if ( left > right )
        return -1;
    
    size_t middle = left + ( right - left ) / 2;
    if ( target == nums[middle])
        return middle;
    else if ( target < nums[middle])
        return binarySearch(nums, target, left, middle - 1);
    else
        return binarySearch(nums, target, middle + 1, right);

    return -1; */

    //& Iterative approach
    if ( left > right )
        return -1;

    while ( left <= right )
    {
        size_t middle = left + ( right - left ) / 2;

        if ( target == nums[middle] )
            return middle;
        else if ( target < nums[middle] )
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
        
}

int main()
{
    std::vector <int> nums = {22, 432, 546, 7678, 87987, 54 ,564 ,42, 65, -32443, 43, -214, 0};    

    int target = 43;

    std::cout<<"Sorting using Quick Sort -\n\n";
    std::cout<<"Data before sorting -\n";
    printData(nums);

    quickSort(nums, 0, nums.size() - 1);

    std::cout<<"\nData after sorting -\n";
    printData(nums);
    
    size_t result = binarySearch(nums, target, 0, (nums.size() - 1 ));

    if ( result != -1 )
        std::cout<<"\n\nThe target element "<<target<<" is present in the data set and has index : "<<result<<"\n";
    else
        std::cout<<"\n\nThe target "<<target<<" is not present in the data set."<<"\n";

    std::cin.get();
    return 0;
}