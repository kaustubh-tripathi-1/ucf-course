#include<iostream>

double calculatePower(double, double);

int main()
{
    double result, num, power;
    std::cout<<"Enter 2 +ve numbers to calculate HCF :\n";
    std::cin>>num>>power;

    result = calculatePower(num, power);
    std::cout<<"The result of "<<num<<" to the power of "<<power<<" is "<<result<<"\n";

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}

double calculatePower(double num, double power)
{
    if ( power == 0 )
        return 1;

    if ( power > 0 )
        return num * calculatePower(num, power-1);
    else
        // return  1.0 / num * calculatePower(num, power+1);
        return  1.0 / calculatePower(num, -power);

}