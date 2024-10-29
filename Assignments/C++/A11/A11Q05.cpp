#include<iostream>
#include <limits>
#include <string>
using namespace std;

class Circle
{
    private :

        double radius;

    public :

        Circle() : radius(0) {}

        Circle(double radius) : radius(0)
        {
            if (radius >= 0)
                 this->radius = radius; 
            else
                cout<<"Invalid Radius Value!\n";
        }


};

int main()
{
    

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}