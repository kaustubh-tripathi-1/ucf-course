#include<iostream>
#include<list>
#include<vector>

void createList(const std::vector<int> &vec, std::list<int> &l)
{
    for ( auto num : vec )
    {
        l.push_back(num);
    }
}

int main()
{
    std::vector<int> vec = {2, 43, 54, 6, 32 ,4, -3, 43 ,54, 432, -45, 5};
    std::list<int> l;

    createList(vec, l);

    for ( auto num : l )
    {
        std::cout<<num<<" ";
    }

    std::cin.get();
    return 0;
}