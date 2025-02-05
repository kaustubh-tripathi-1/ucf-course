#include<iostream>
#include<array>
#include<algorithm>

void modifiedBubbleSort(std::array<int, 10> &nums)
{
    bool swapped = false;

    for ( int roundNumber = 0 ; roundNumber < nums.size() - 1 ; roundNumber++ )
    {
        swapped = false;
        for ( int comparisonIndex = 0 ; comparisonIndex < nums.size()-roundNumber-1 ; comparisonIndex++ )
        {
            if ( nums[comparisonIndex] > nums[comparisonIndex+1] )
            {
                int temp = nums[comparisonIndex];
                nums[comparisonIndex] = nums[comparisonIndex+1];
                nums[comparisonIndex+1] = temp;
                swapped = true;
            }
        }
        if ( !swapped )
        {
            return;
        }
    }

}

//@ Prints the array
void printArray(std::array<int, 10> &nums)
{
    for ( int i = 0 ; i < nums.size() ; i++ )
    {
        std::cout<<nums[i]<<" ";
    }

    std::cout<<"\n";
    
}

int main()
{
    std::array<int, 10> nums = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};

    std::cout<<"Array before sorting :\n";
    printArray(nums);

    // modifiedBubbleSort(nums);

    //& Using standard sort() algo in STL
    std::sort(nums.begin(), nums.end());
    
    std::cout<<"Array after sorting :\n";
    printArray(nums);

    std::cin.get();
    return 0;
}