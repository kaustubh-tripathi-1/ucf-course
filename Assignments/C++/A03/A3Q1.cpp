#include<iostream>
using namespace std;

int main()
{
    double num1, num2, num3, average;

    cout<<"Enter 3 numbers to calculate their average -"<<endl;

    cin>>num1>>num2>>num3;

    average = (num1 + num2 + num3) / 3.0 ;

    cout<<"The average of "<<num1<<", "<<num2<<" & "<<num3<<" is "<<average;

    return 0;
}