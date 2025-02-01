#include<iostream>

template <typename DT>
DT greater(DT n1, DT n2)
{
    if ( n1 < n2 )
        return n1;
    else
        return n2;
}

int main()
{
    double n1 = 65.213, n2 = 65.12;

    double bigger = greater(n1, n2);

    std::cout<<bigger<<"\n";

    std::cin.get();
    return 0;
}