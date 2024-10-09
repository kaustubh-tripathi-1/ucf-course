#include<iostream>
using namespace std;

#define PI 3.1428

int main()
{
    double radius, area;

    cout<<"Enter the radius to Calculate Area of the circle -"<<endl;    

    cin>>radius;

    area = PI * radius * radius;

    cout<<"The area of the circle with radius "<<radius<<" is "<<area;

    return 0;
    
}