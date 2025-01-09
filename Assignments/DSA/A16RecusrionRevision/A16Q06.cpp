#include<iostream>

int sumOfDigits(int num)
{
    if ( num == 0 )
        return 0;

    return (num % 10) + sumOfDigits(num / 10);
}

int main()
{
    int sum, num;
    std::cout<<"Enter the number to know its sum of digits :\n";
    std::cin>>num;

    if ( num != 0 )
    {
        sum = sumOfDigits(num);
        std::cout<<"The sum Of Digits of "<<num<<" is "<<sum<<"\n";
    }
    else
        std::cout<<"The sum Of Digits of "<<num<<" is "<<0<<"\n";


    while( getchar() != '\n');
    std::cin.get();
    return 0;
}