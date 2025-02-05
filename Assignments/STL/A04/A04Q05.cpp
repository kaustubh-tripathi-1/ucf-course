#include<iostream>
#include<vector>

std::vector<int> findStrictlySmallerAdjacentElements(const std::vector<int> &nums)
{
    std::vector<int> smaller;

    std::vector<int>::const_iterator i;
        
    for ( i = nums.cbegin()+1 ; i != nums.cend()-1 ; i++ )
    {
        if ( *i < *(i-1) && *i < *(i+1) )
        {
            smaller.push_back(*i);
        }
    }

    /* for (std::size_t i = 1; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])
        {
            smaller.push_back(nums[i]);
        }
    } */

    return smaller;
}

int main()
{
    std::vector<int> vec{2, 65, 7, 23, -6, 5, 89, 324, 4, 9};

    std::vector<int>::const_iterator i;
        
    std::vector<int> smaller = findStrictlySmallerAdjacentElements(vec);

    std::cout<<"Strictly smaller than adjacent elements are :\n";

    for ( i = smaller.cbegin() ; i != smaller.cend() ; i++ )
    {
        std::cout<<*i<<" ";
    }
        
    std::cout<<"\n";

    std::cin.get();
    return 0;
}