#include<iostream>

void printNCubesNaturalNumbers(int num)
{
    if ( num <= 0 )
        return;
    
    printNCubesNaturalNumbers(num-1);
    std::cout<<(num * num * num)<<" ";
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the cubes of first N natural numbers : \n";
    std::cin>>num;

    if ( num > 0 )
        printNCubesNaturalNumbers(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}