#include<iostream>

class Shape
{
    private :

        std::string shapeName;

    public :

        Shape(std::string shapeName = "")
        :   
            shapeName(shapeName) {}

        Shape(const Shape &s)
        :
            shapeName(s.shapeName) {}


        void setShape(std::string shapeName)
        {
            if ( !shapeName.empty() )
                this->shapeName = shapeName;
            else
                std::cout<<"Shape name can't be empty!\n";
        }

        void displayShape() const
        {
            std::cout<<"Shape Name : "<<shapeName;
        }

        virtual double area() const = 0;

        virtual ~Shape() {}
};

class Rectangle : public Shape
{
    private :

        double length, breadth;

    public :

        Rectangle(double length = 0, double breadth = 0)
        :
            Shape("Rectangle"), length(length), breadth(breadth)
        {
            if ( length < 0 )
            {
                std::cout<<"Length can't be -ve, Setting it to 0!\n";
                this->length = 0;
            }
            if ( breadth < 0 )
            {
                std::cout<<"Breadth can't be -ve, Setting it to 0!\n";
                this->breadth = 0;
            }
        }

        Rectangle(const Rectangle &rec)
        :
            Shape(rec), length(rec.length), breadth(rec.breadth) {}

        void setRectangle(double length, double breadth)
        {
            if ( length < 0 )
            {
                std::cout<<"Length can't be -ve, Setting it to 0!\n";
                this->length = 0;
            }
            else
            {
                this->length = length;
            }
            if ( breadth < 0 )
            {
                std::cout<<"Breadth can't be -ve, Setting it to 0!\n";
                this->breadth = 0;
            }
            else
            {
                this->breadth = breadth;
            }
        }

        double getLength() const
        {
            return length;
        }

        double getBreadth() const
        {
            return breadth;
        }

        double area() const override
        {
            return length * breadth;
        }

};

class Square : public Shape
{
    private :

        double side;

    public :

        Square(double side = 0)
        :
            Shape("Square"), side(side)
        {
            if( side < 0 )
            {
                std::cout<<"Side can't be -ve, Setting it to 0!\n";
                this->side = 0;
            }
        }

        Square(const Square &s)
        :
            Shape(s), side(s.side) {}

        void setSquare(double side)
        {
            if( side < 0 )
            {
                std::cout<<"Side can't be -ve, Setting it to 0!\n";
                this->side = 0;
            }
            else
                this->side = side;
        }

        double getSide() const
        {
            return side;
        }

        double area() const override
        {
            return side*side;
        }

};

int main()
{
    Rectangle rec1(4.5, 5);
    std::cout<<"Area of Rectangle is : "<<rec1.area()<<"\n";

    Square s1(4.5);
    std::cout<<"Area of Sqaure is : "<<s1.area()<<"\n";


    std::cin.get();
    return 0;
}