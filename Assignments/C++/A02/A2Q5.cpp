#include<iostream>
using namespace std;

int main()
{
    double length, breadth, height, volume;

    cout<<"Enter the length, breadth & height of a cuboid to calculate the volume -"<<endl;

    cin>>length>>breadth>>height;

    volume = length * breadth * height;

    cout<<"The volume of the cuboid is -"<<endl<<volume;

    return 0;
    
}