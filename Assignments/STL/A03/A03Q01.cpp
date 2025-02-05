#include<iostream>
#include<array>

int main()
{
    std::array<int, 5> arr = {3, 4, 9, 5, 21};

    std::array<int, 5>::reverse_iterator i;

    std::cout<<"Printing elements in reverse :\n";
    for ( i = arr.crbegin() ; i != arr.crend() ; i++ )
    {
        std::cout<<*i<<" ";
    }

    std::cin.get();
    return 0;
}