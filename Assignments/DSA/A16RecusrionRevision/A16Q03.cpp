#include<iostream>

int sumOfNEvenNaturalNumbers(int num)
{
    if ( num == 1 )
        return 2*num;

    return (2 * num) + sumOfNEvenNaturalNumbers(num-1);
}

int main()
{
    int sum, num;
    std::cout<<"Enter the number upto which you want to know the sum of even natural numbers :\n";
    std::cin>>num;

    if ( num > 0 )
    {
        sum = sumOfNEvenNaturalNumbers(num);
        std::cout<<"The sum of first "<<num<<" Even Natural numbers is "<<sum<<"\n";
    }
    else
        std::cout<<num<<" is not a natural number.\n";


    while( getchar() != '\n');
    std::cin.get();
    return 0;
}