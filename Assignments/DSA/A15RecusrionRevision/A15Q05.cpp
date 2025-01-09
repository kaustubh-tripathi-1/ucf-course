#include<iostream>

void printNEvenNaturalNumbers(int num)
{
    if ( num <= 0 )
        return;
    
    printNEvenNaturalNumbers(num-1);
    std::cout<<(2 * num)<<" ";
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the first N even natural numbers : \n";
    std::cin>>num;

    if ( num > 0 )
        printNEvenNaturalNumbers(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}