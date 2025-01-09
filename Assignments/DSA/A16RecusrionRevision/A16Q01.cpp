#include<iostream>

int sumOfNNaturalNumbers(int num)
{
    if ( num == 1 )
        return 1;

    return num + sumOfNNaturalNumbers(num-1);
}

int main()
{
    int sum, num;
    std::cout<<"Enter the number upto which you want to know the sum of all natural numbers :\n";
    std::cin>>num;

    if ( num > 0 )
    {
        sum = sumOfNNaturalNumbers(num);
        std::cout<<"The sum of first "<<num<<" Natural numbers is "<<sum<<"\n";
    }
    else
        std::cout<<num<<" is not a natural number.\n";


    while( getchar() != '\n');
    std::cin.get();
    return 0;
}