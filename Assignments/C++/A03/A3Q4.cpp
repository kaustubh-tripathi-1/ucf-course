#include<iostream>
using namespace std;

int main()
{
    int num1, num2, greater;

    cout<<"Enter 2 numbers to find the greater one -"<<endl;

    cin>>num1>>num2;

    greater = (num1 > num2 ? num1 : num2);

    cout<<"The greater value is "<<greater;

    while ( getchar() != '\n');

    cin.get();
    return 0;
}