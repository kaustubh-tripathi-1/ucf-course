#include<iostream>

void printNNaturalNumbers(int num)
{
    if ( num <= 0 )
        return;
    
    printNNaturalNumbers(num-1);
    std::cout<<num<<" ";
    
}

int main()
{
    int num;
    std::cout<<"Enter a number to print the first N natural numbers : \n";
    std::cin>>num;

    if ( num > 0 )
        printNNaturalNumbers(num);
    else
        std::cout<<num<<" is not a natural number.\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}