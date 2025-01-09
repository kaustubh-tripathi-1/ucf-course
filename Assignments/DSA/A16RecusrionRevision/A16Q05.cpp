#include<iostream>

unsigned long long int factorial(int num)
{
    if ( num == 1 )
        return 1;

    return num * factorial(num-1);
}

int main()
{
    unsigned long long int fact, num;
    std::cout<<"Enter the number to know its factorial :\n";
    std::cin>>num;

    if ( num > 0 )
    {
        fact = factorial(num);
        std::cout<<"The factorial of "<<num<<" is "<<fact<<"\n";
    }
    else
        std::cout<<num<<" is not a natural number.\n";


    while( getchar() != '\n');
    std::cin.get();
    return 0;
}