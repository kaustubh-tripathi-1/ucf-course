#include<iostream>

int sumOfSquaresNNaturalNumbers(int num)
{
    if ( num == 1 )
        return 1;

    return (num * num) + sumOfSquaresNNaturalNumbers(num-1);
}

int main()
{
    int sum, num;
    std::cout<<"Enter a number to know the sum of squares of first N natural numbers :\n";
    std::cin>>num;

    if ( num > 0 )
    {
        sum = sumOfSquaresNNaturalNumbers(num);
        std::cout<<"The sum of squares of first "<<num<<" Natural numbers is "<<sum<<"\n";
    }
    else
        std::cout<<num<<" is not a natural number.\n";


    while( getchar() != '\n');
    std::cin.get();
    return 0;
}