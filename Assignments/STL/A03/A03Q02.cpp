#include<iostream>
#include<array>

int main()
{
    std::array<float, 5> arr = {3.2f, 4.8f, 9.1f, 5.5f, 21.3f};

    std::array<float, 5>::iterator i;

    float sum = 0.0;
    for ( i = arr.begin() ; i != arr.end() ; i++ )
        sum += *i;

    std::cout<<"Average is : "<<sum/arr.size()<<"\n";

    std::cin.get();
    return 0;
}