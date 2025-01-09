#include<iostream>

void printNOddNaturalNumbersReverse(int num)
{
    if ( num <= 0 )
        return;
    
    std::cout<<(2 * num - 1)<<" ";
    printNOddNaturalNumbersReverse(num-1);
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the first N odd natural numbers in reverse: \n";
    std::cin>>num;

    if ( num > 0 )
        printNOddNaturalNumbersReverse(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}