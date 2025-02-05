#include<iostream>
#include<array>

int main()
{
    std::array<int, 10> arr;
    
    std::array<int, 10>::iterator i;

    for ( i = arr.begin() ; i != arr.end() ; i++ )
    {
        std::cin>>*i;
    }

    auto max = arr.front();
    for ( auto ele : arr )
    {
        if ( max < ele )
            max = ele;
    }

    std::cout<<"Largest element is : "<<max<<"\n";
    

    std::cin.get();
    return 0;
}