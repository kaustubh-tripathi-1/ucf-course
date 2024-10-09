#include<iostream>
using namespace std;

int main()
{
    double num1, num2;

    cout<<"Enter 2 numbers to swap them -"<<endl;

    cin>>num1>>num2;

    cout<<"Before Swapping -"<<endl<<"Num1 - "<<num1<<" & "<<"Num2 - "<<num2<<"."<<endl;

    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;

    cout<<"After Swapping -"<<endl<<"Num1 - "<<num1<<" & "<<"Num2 - "<<num2<<".";

    while ( getchar() != '\n');

    cin.get();
    return 0;
}