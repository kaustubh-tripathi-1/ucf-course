#include<iostream>

void printNSquaresNaturalNumbers(int num)
{
    if ( num <= 0 )
        return;
    
    printNSquaresNaturalNumbers(num-1);
    std::cout<<(num * num)<<" ";
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the squares of first N natural numbers : \n";
    std::cin>>num;

    if ( num > 0 )
        printNSquaresNaturalNumbers(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}