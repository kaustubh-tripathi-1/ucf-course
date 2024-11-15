#include<iostream>
#include<cmath>

class Coordinate
{
    private :

        double x, y;

    public :

        Coordinate(double x = 0, double y = 0)
        :   x(x), y(y){}

        Coordinate(const Coordinate &c)
        :
            x(c.x), y(c.y) {}

        void setCoordinate(double x = 0, double y = 0)
        {
            this->x = x;
            this->y = y;
        }

        double getDistance() const
        {
            double distance = 0;

            distance = sqrt(((x-0)*(x-0)) + ((y-0) * (y-0)));

            return distance;            
        }
        double getDistance(const Coordinate &secondCoordinate) const
        {
            double distance = 0;

            distance = sqrt(((x-secondCoordinate.x) * (x-secondCoordinate.x))
                        + ((y-secondCoordinate.y) * (y-secondCoordinate.y)));

            return distance;            
        }

        void showCoordinate() const
        {
            std::cout<<"Coordinate values :\nX : "<<x<<", "<<"Y :"<<y<<std::endl;
        }
};

class Shape
{
    private :

        std::string shapeName;

    public :

        //$ Default Param Constructor
        Shape(std::string shapeName)
        :
            shapeName(shapeName){}

        //$ Copy Constructor
        Shape(const Shape &shape2)
        : shapeName(shape2.shapeName) {}

        void setShape(std::string shapeName)
        {
            if ( !shapeName.empty())
            {
                this->shapeName = shapeName;
            }
        }

        std::string getShape() const
        {
            return shapeName;
        }

};

class StraightLine : public Shape
{
    private :

        Coordinate c1, c2;

    public :

        //$ Default Param Constructor
        StraightLine(std::string shapeName, double x1 = 0, double y1 = 0, double x2 = 0, double y2 = 0)
        :
            Shape(shapeName.empty() ? "Default Shape" : shapeName),
            c1(x1, y1) , c2(x2, y2) {}

        //$ Copy Constructor
        StraightLine(const StraightLine &sl)
        :
            Shape(sl), c1(sl.c1), c2(sl.c2) {}


        void setLine(std::string shapeName, double x1, double y1, double x2, double y2)
        {
            setShape(shapeName);
            c1.setCoordinate(x1, y1);
            c2.setCoordinate(x2, y2);
        }

        double getDistance() const
        {
            return c1.getDistance(c2);
        }

        void showLine()
        {
            std::cout<<"Shape Name - "<<getShape()<<"\nCoordinate 1 : \n";
            c1.showCoordinate();
            std::cout<<"Coordinate 2 :\n";
            c2.showCoordinate();
            std::cout<<std::endl;
        }

};

int main()
{
    Coordinate c1(3, 3);
    std::cout<<"C1 :\n";
    c1.showCoordinate();
    Coordinate c2(4,4);
    std::cout<<"C2 :\n";
    c2.showCoordinate();

    std::cout<<"C1 distance from origin :\n";
    double d1 = c1.getDistance();
    std::cout<<"D1 : "<<d1<<"\n";
    
    std::cout<<"C1 distance from C2 :\n";
    double d2 =c1.getDistance(c2);
    std::cout<<"D2 : "<<d2<<"\n";


    StraightLine line1("Straight Line", 3, 3, 4, 4);
    line1.showLine();
    double d3 =  line1.getDistance();
    std::cout<<"Distance b/w 2 coordinates of the line is : "<<d3<<"\n";


    std::cin.get();
    return 0;
}