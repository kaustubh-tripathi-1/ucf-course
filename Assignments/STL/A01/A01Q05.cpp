#include<iostream>
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

//@ Find the max
template <typename DT>
void findMax(DT *array, int size)
{
    DT max = array[0];

    for ( int i = 0 ; i < size ; i++ )
    {
        if ( max < array[i] )
        {
            max = array[i];
        }
    }

    std::cout<<"The max element is : "<<max<<"\n";
}

int main()
{
    // int nums[] = {34, 2134, -321, 94, 8, 0, 71, 9242, -123, -4};
    // float nums[] = {34.45f, 2134.235f, -321.6f, 94.32f, 8.98f, 0.1f, 71.7f, 9242.23f, -123.1f, -4.9f};
    // double nums[] = {34.45, 2134.235, -321.6, 94.32, 8.98, 0.1, 71.7, 9242.23, -123.1, -4.9};
    std::string nums[] = {"One", "Two", "Three", "Fifty", "Six"};

    int size = sizeof(nums) / sizeof(nums[0]);

    std::cout<<"Array elements -\n";
    printArray(nums, size);

    findMax(nums, size);
    
    std::cin.get();
    return 0;
}

