#include<iostream>
#include<list>
#include<string>

int main()
{
    std::list<std::string> l1 = {"Tripathi", "Kaustubh", "is", "name", "My"};

    // std::list<std::string>::const_reverse_iterator ri = l1.crbegin(); 
    auto ri = l1.crbegin(); 

    for ( ; ri != l1.crend() ; ri++ )
    {
        std::cout<<*ri<<" ";
    }

    std::cin.get();
    return 0;
}