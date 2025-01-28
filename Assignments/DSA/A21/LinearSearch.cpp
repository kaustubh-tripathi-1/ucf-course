#include<iostream>
#include<vector>

int linearSearch(std::vector<int> &nums, int target)
{
    for ( size_t index = 0 ; index < nums.size() ; index++)
    {
        if ( nums.at(index) == target )
            return index;
    }

    return -1;
}

int main()
{
    std::vector <int> nums = {22, 432, 546, 7678, 87987, 
                    54 ,564 ,42, 65, -32443, 43, -214, 0};    

    int target = 42;
    int result = linearSearch(nums, target);

    if ( result != -1 )
        std::cout<<"The target element "<<target<<" is present in the data set and has index : "<<result<<"\n";
    else
        std::cout<<"The target "<<target<<" is not present in the data set."<<"\n";

    std::cin.get();
    return 0;
}