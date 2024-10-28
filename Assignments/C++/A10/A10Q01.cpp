#include<iostream>
#include <limits>
using namespace std;

//@ Class Cuboid
class Cuboid
{
    private :

        double length, breadth, height;

    public :

        //% Constructors

        //& Default Constructors
        
        //$ Default Constructor with 0 args.
        Cuboid()
        {
            length = 0;
            breadth = 0;
            height = 0;
        }
        
        //$ Default Constructor with 3 args. and with default args.
        Cuboid( double length=0, double breadth=0, double height=0 )
        {
            this->length = length;
            this->breadth = breadth;
            this->height = height;
        }

        //& Copy Constructors
        
        Cuboid(const Cuboid &obj)
        {
            this->length = obj.length;
            this->breadth = obj.breadth;
            this->height = obj.height;
        }

        //% Initializer List

        /* Cuboid() : length(0), breadth(0), height(0) {}
        Cuboid(double length) : length(length), breadth(0), height(0) {}
        Cuboid(double length, double breadth) : length(length), breadth(breadth), height(0) {}
        Cuboid(double length, double breadth, double height) : length(length), breadth(breadth), height(height) {}
        Cuboid(const Cuboid &obj) : length(obj.length), breadth(obj.breadth), height(obj.height) {} */


};

int main()
{
    

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}