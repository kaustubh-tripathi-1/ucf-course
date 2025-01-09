#include<iostream>

void printNSquaresNaturalNumbersReverse(int num)
{
    if ( num <= 0 )
        return;
    
    std::cout<<(num * num)<<" ";
    printNSquaresNaturalNumbersReverse(num-1);
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the squares of first N natural numbers in reverse : \n";
    std::cin>>num;

    if ( num > 0 )
        printNSquaresNaturalNumbersReverse(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}