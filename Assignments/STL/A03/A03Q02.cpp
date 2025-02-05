#include<iostream>
#include<array>
#include <numeric>

int main()
{
    std::array<float, 5> arr = {3.2f, 4.8f, 9.1f, 5.5f, 21.3f};

    std::array<float, 5>::iterator i;

    /* float sum = 0.0;
    for ( i = arr.begin() ; i != arr.end() ; i++ )
        sum += *i; */
        
    float sum = std::accumulate(arr.begin(), arr.end(), 0.0f);

    std::cout<<"Average is : "<<sum/arr.size()<<"\n";

    std::cin.get();
    return 0;
}