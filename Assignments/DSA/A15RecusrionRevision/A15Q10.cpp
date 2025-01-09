#include<iostream>

void printNCubesNaturalNumbersReverse(int num)
{
    if ( num <= 0 )
        return;
    
    std::cout<<(num * num * num)<<" ";
    printNCubesNaturalNumbersReverse(num-1);
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the cubes of first N natural numbers in Reverse: \n";
    std::cin>>num;

    if ( num > 0 )
        printNCubesNaturalNumbersReverse(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}