#include<iostream>

void binary(int num)
{
    if ( num == 0 )
        return;

    binary(num/2);
    std::cout<<num%2;
}

int main()
{
    int num;
    std::cout<<"Enter the number to know its sum of digits :\n";
    std::cin>>num;

    if ( num > 0 )
    {
        std::cout<<"The binary of "<<num<<" is -\n";
        binary(num);
    }
    else if ( num == 0 )
        std::cout<<"The binary of "<<num<<" is - 0\n";
    else
        std::cout<<"Just calculate the 2's complement of the binary of "<<num<<" yourself.";


    while( getchar() != '\n');
    std::cin.get();
    return 0;
}