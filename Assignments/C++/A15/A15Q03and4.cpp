#include<iostream>
// using namespace std;

class Coordinate
{
    private :

        double x, y;

    public :

        Coordinate(int x = 0, int y = 0) : x(x), y(y) {}

        Coordinate( const Coordinate &c)
        :
            x(c.x), y(c.y) {}

        //$ Overloaded comma op., returns passed object
        Coordinate& operator,(Coordinate &c)
        {
            return c;
        }

        Coordinate& operator++()
        {
            ++this->x;
            ++this->y;

            return *this;
        }

        friend std::ostream& operator<<(std::ostream &out, const Coordinate& c)
        {
            out<<"Coordinates are : \nx = "<<c.x<<" , y = "<<c.y<<std::endl;

            return out;
        }
        friend std::istream& operator>>(std::istream &in, Coordinate &c)
        {
            std::cout<<"Enter x and y coordinates for a Coordinate object :\n";
            in>>c.x>>c.y;

            return in;
        }

};

int main()
{
    Coordinate c1;
    std::cin>>c1;

    Coordinate c2;

    Coordinate c3 = (++c1, c2, c1);

    std::cout<<c3<<c1;

    std::cin.get();
    return 0;
}