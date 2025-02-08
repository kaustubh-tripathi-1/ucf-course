#include<iostream>
#include<list>

int findMax(const std::list<int> &l)
{
    int max = l.front();
    for ( auto num : l )
    {
        if ( num > max )
            max = num;
    }

    return max;
}

int main()
{
    std::list<int> l = {2, 43, 54, 6, 32 ,4, -3, 43 ,54, 432, -45, 5};

    int max = findMax(l);

    std::cout<<"Max element in the list is : "<<max<<"\n";

    std::cin.get();
    return 0;
}