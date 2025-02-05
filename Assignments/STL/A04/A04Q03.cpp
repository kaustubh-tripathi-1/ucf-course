#include<iostream>
#include<vector>

int main()
{
    std::vector<std::string> vec = {"Kaustubh", "Tripathi", "Software", "Developer", "Ghaziabad"};
    
    std::cout<<"Vector elements are :\n";
    for ( const auto &str : vec )
        std::cout<<str<<" ";

    std::cout<<"\n";

    std::cin.get();
    return 0;
}