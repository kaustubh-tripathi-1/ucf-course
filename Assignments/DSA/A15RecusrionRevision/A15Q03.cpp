#include<iostream>

void printNOddNaturalNumbers(int num)
{
    if ( num <= 0 )
        return;
    
    printNOddNaturalNumbers(num-1);
    std::cout<<(2 * num - 1)<<" ";
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the first N odd natural numbers : \n";
    std::cin>>num;

    if ( num > 0 )
        printNOddNaturalNumbers(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}