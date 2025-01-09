#include<iostream>

void printNEvenNaturalNumbersReverse(int num)
{
    if ( num <= 0 )
        return;
    
    std::cout<<(2 * num)<<" ";
    printNEvenNaturalNumbersReverse(num-1);
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the first N even natural numbers in reverse: \n";
    std::cin>>num;

    if ( num > 0 )
        printNEvenNaturalNumbersReverse(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}