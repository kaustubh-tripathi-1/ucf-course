#include<iostream>
#include<list>
#include<vector>

void createCustomList(const std::vector<int> &vec, std::list<int> &l)
{
    for ( auto num : vec )
    {
        if ( num % 2 == 0 )
            l.push_front(num);
        else
            l.push_back(num);
    }
}

int main()
{
    std::vector<int> vec = {2, 43, 54, 6, 32 ,4, -3, 43 ,54, 432, -45, 5};
    std::list<int> l;

    createCustomList(vec, l);

    std::cout<<"List with even values at front and odd at back :\n";
    for ( auto num : l )
    {
        std::cout<<num<<" ";
    }

    std::cin.get();
    return 0;
}