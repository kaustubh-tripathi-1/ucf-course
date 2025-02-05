#include<iostream>
#include<array>
#include<algorithm>

int main()
{
    std::array<int, 10> arr;
    
    std::array<int, 10>::iterator i;

    std::cout<<"Enter 10 elements to find the max :\n";
    for ( i = arr.begin() ; i != arr.end() ; i++ )
    {
        std::cin>>*i;
    }

    /* auto max = arr.front();
    for ( auto ele : arr )
    {
        if ( max < ele )
            max = ele;
    } */

    auto max = *std::max_element(arr.begin(), arr.end());

    std::cout<<"Largest element is : "<<max<<"\n";
    

    std::cin.get();
    return 0;
}