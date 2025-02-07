#include<iostream>
#include<vector>

void printVector(const std::vector<int> &nums)
{
    std::vector<int>::const_iterator i;
    
    for ( i = nums.cbegin() ; i != nums.cend() ; i++ )
    {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";

}
void printVector(const std::vector<std::vector<int>> &nums)
{
    //$ Explicit Iterators
    /* std::vector<std::vector<int>>::const_iterator i;
    std::vector<int>::const_iterator j;
    
    for ( i = nums.cbegin() ; i != nums.cend() ; i++ )
    {
        for ( j = (*i).cbegin() ; j != (*i).cend() ; j++ )
        {
            std::cout<<*j<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n"; */

    //$ Implicit Iterators
    for ( const auto &subVec : nums )
    {
        for ( auto ele : subVec )
        {
            std::cout<<ele<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
            
}

std::vector<std::vector<int>> makeSortedVectors(std::vector<int> &nums)
{
    if (nums.empty())
    return {}; // Edge case: Empty input
    
    //$ Everything is explicit
    /* std::vector<int>::iterator i;
    std::vector<std::vector<int>> sortedVecs{{}};
    std::vector<std::vector<int>>::iterator j = sortedVecs.begin();
    
    for ( i = nums.begin() ; i != nums.end()-1 ; i++ )
    {
        if ( *i < *(i+1))
        {
            (*j).push_back(*i);
        }
        else
        {
            (*j).push_back(*i);
            sortedVecs.push_back({});
            j = sortedVecs.end() - 1; // Move `j` to the newly added vector
        }
    }

    (*j).push_back(nums.back()); */
    
    //$ Implicit with auto use
    /* std::vector<std::vector<int>> sortedVecs{{}};
    auto j = sortedVecs.begin();
    
    for ( auto i = nums.begin() ; i != nums.end()-1 ; i++ )
    {
        if ( *i < *(i+1))
        {
            (*j).push_back(*i);
        }
        else
        {
            (*j).push_back(*i);
            sortedVecs.push_back({});
            j = sortedVecs.end() - 1; // Move `j` to the newly added vector
        }
    }

    (*j).push_back(nums.back()); */

    //$ Optimized version to prevent reallocs
    std::vector<std::vector<int>> sortedVecs;
    sortedVecs.reserve(nums.size());    // Reduce reallocations
    
    std::vector<int> tempVector;
    tempVector.reserve(nums.size());    // Prevent frequent resizing

    tempVector.push_back(nums.at(0));
    for ( size_t i = 1 ; i < nums.size() ; i++ )
    {
        if ( nums.at(i) >= nums.at(i-1))
        {
            tempVector.push_back(nums.at(i));
        }
        else
        {
            sortedVecs.push_back(std::move(tempVector));
            tempVector.clear();
            tempVector.push_back(nums.at(i));
        }
    }

    sortedVecs.push_back(std::move(tempVector)); // Move the last subvector
    return sortedVecs;

}

int main()
{
    try
    {
        std::vector<int> vec = {2, 43, 54, 6, 32, 
                                4, -3, 43 ,54, 432, 
                                -45, 5, 6, 342, 43, 
                                54, -213, 3, 1, 8329};

        std::cout<<"Input Vector :\n";
        printVector(vec);
        
        std::cout<<"Vector of Vectors after dividing the original vector into sub-sorted ones :\n";
        printVector(makeSortedVectors(vec));
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<"\n";
    }
    std::cin.get();
    return 0;
}
