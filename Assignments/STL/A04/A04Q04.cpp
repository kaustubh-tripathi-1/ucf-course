#include<iostream>
#include<vector>

int main()
{
    std::vector<int> vec{2, 65, 7, 23, -6};

    std::vector<int>::const_iterator i;
    std::cout<<"Vector elements are :\n";
        
    for ( i = vec.cbegin() ; i != vec.cend() ; i++ )
    {
        std::cout<<*i<<" ";
    }

    std::cout<<"\n";

    std::cin.get();
    return 0;
}