#include<iostream>

void printNNaturalNumbersReverse(int num)
{
    if ( num <= 0 )
        return;
    
    std::cout<<num<<" ";
    printNNaturalNumbersReverse(num-1);
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the first N natural numbers in reverse order: \n";
    std::cin>>num;

    if ( num > 0 )
        printNNaturalNumbersReverse(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}