#include<iostream>

int calculateHCF(int num1, int num2);

int main()
{
    int hcf, num1, num2;
    std::cout<<"Enter 2 +ve numbers to calculate HCF :\n";
    std::cin>>num1>>num2;

    if ( num1 > 0 && num2 > 0 )
    {
        hcf = calculateHCF(num1, num2);
        std::cout<<"The HCF of "<<num1<<" and "<<num2<<" is "<<hcf<<"\n";
    }
    else
        std::cout<<"Invalid numbers to calculate HCF.\n";
    

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}

int calculateHCF(int num1, int num2)
{
    if ( num2 == 0 )
        return num1;

    return calculateHCF(num2, num1 % num2);
}