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

int main()
{
    std::vector<int> vec = {2, 43, 54};

    std::cout<<"Vector before inserting :\n";
    printVector(vec);
    
    vec.insert(vec.end()-1, 3, 25);
    
    std::cout<<"Vector after inserting :\n";
    printVector(vec);

    std::cin.get();
    return 0;
}