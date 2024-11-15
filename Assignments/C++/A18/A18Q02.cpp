#include<iostream>

class Circle
{
    private :

        double radius;

    protected:
        static constexpr double PI = 3.141592;

    public :

        Circle(double radius = 0) : radius(radius)
        {
            if (radius >= 0)
                this->radius = radius; 
            else
            {
                std::cout<<"Invalid Radius Value! Set to 0.\n";
                this->radius = 0; 
            }
        }

        Circle(const Circle &c)
        :
            radius(c.radius) {}


        //$ Setter
        void setRadius(double radius)
        {
            if( radius >= 0 )
                this->radius = radius;
            else
                std::cout<<"Invalid Radius! Can't be set...\n";
        }

        //$ Getter
        double getRadius() const
        {
            return radius;
        }

        double getArea() const
        {
            return PI * radius * radius;
        }

};

class ThickCircle : public Circle
{
    private :

        double thickness;

    public :

        ThickCircle(double radius = 0, double thickness = 0)
        : Circle(radius), thickness(thickness)
        {
            if ( this->thickness < 0)
            {
                std::cout<<"Thickness can't be -ve! Setting to 0.";
                this->thickness = 0;
            }
        }

        ThickCircle( const ThickCircle &tc)
        :
            Circle(tc), thickness(tc.thickness) {}

        void setThickness(double thickness)
        {
            if ( thickness >= 0)
                this->thickness = thickness;
            else
            {
                this->thickness = 0;
                std::cout<<"Thickness can't be -ve! Setting to 0.\n";
            }
        }
    
        double getThickness() const
        {
            return thickness;
        }

        double getArea() const
        {
            double areaOfPortion = 0;
            double smallRadius = getRadius();
            double bigRadius = getRadius() + thickness;

            areaOfPortion =  (PI * bigRadius * bigRadius) - (PI * smallRadius * smallRadius);
            
            return areaOfPortion;
        }

};

int main()
{
    ThickCircle c1(30, 30);

    std::cout<<"Area of Portion is : "<<c1.getArea()<<"\n";


    std::cin.get();
    return 0;
}