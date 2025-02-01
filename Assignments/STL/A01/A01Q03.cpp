#include<iostream>

template <typename DT>
void printArray(DT *ptrArr, int size)
{
    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout<<ptrArr[i]<<" ";
    }
    std::cout<<"\n";
}

int main()
{
    // double nums[] = {234.5, 59.03, 943.48, -324.4, 82.1};    
    // int nums[] = {234, 59, 943, -324, 82};    
    char nums[] = "Kaustubh Tripathi";    
    int size = sizeof(nums) / sizeof(nums[0]);

    printArray(nums, size);

    std::cin.get();
    return 0;
}