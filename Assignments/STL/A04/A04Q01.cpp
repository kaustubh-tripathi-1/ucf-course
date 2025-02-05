#include<iostream>
#include<vector>

int main()
{
    std::vector<int> vec{2, 65, 7, 23, -6};

    std::cout<<"Vector elements are :\n";
    for ( int i = 0 ; i < vec.size() ; i++ )
        std::cout<<vec[i]<<" ";

    std::cout<<"\n";

    std::cin.get();
    return 0;
}