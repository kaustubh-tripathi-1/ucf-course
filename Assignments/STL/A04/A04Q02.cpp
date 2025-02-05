#include<iostream>
#include<vector>

int main()
{
    std::vector<float> vec{2.3f, 65.5f, 7.9f, 23.1f, -6.6f};

    std::cout<<"Vector elements are :\n";
    for ( int i = 0 ; i < vec.size() ; i++ )
        std::cout<<vec.at(i)<<" ";

    std::cout<<"\n";

    std::cin.get();
    return 0;
}