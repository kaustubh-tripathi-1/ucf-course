#include<iostream>
#include <limits>
using namespace std;



class Circle
{
    private :
        double radius;
        static constexpr double PI = 3.1428;
        
    public :

        bool setRadius(double r)
        {
            if( r > 0 )
            {
                radius = r;
                return true;
            }
            else
            {
                cout<<"Invalid Radius!"<<endl;;
                return false;
            }
        }

        double getRadius()
        {
            return radius;
        }

        void displayRadius() const
        {
            cout << "Radius is - " << radius << endl;
        }

        double calculateArea() const
        {
            return PI * radius * radius;
        }

        double calculateCircumference() const
        {
            return 2 * PI * radius; 
        }
};

int main()
{

    Circle c1;

    if ( c1.setRadius(4.4)) 
    {
        double radius = c1.getRadius();
        cout<<"The radius is : "<<radius<<endl;

        double area = c1.calculateArea();
        cout<<"The area is : "<<area<<endl;

        double circum = c1.calculateCircumference();
        cout<<"The Circumference is : "<<circum<<endl;
    }


    // while ( getchar() != '\n');
    cin.get();
    return 0;
}