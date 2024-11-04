#include<iostream>
#include <string>
// using namespace std;

class Distance
{
    private :

        int km, m, cm;
        bool isValidDistance;

    public :

        //$ Default Constructor
        Distance(int km = 0, int m = 0, int cm = 0)
        :
            km(km), m(m), cm(cm)
        {
            if ( km < 0 || m < 0 || cm < 0 )
            {
                isValidDistance = false;
                std::cout<<"Distance can't be negative!"<<std::endl;
            }
            else
            {
                normalize();
                isValidDistance = true;
            }
        }

        //$ Copy Constructor
        Distance ( const Distance &d)
        :
            km(d.km), m(d.m), cm(d.cm), isValidDistance(d.isValidDistance) {}

        //$ Show Distance Method
        void showDistance() const
        {
            if ( isValidDistance )
                std::cout<<"Distance is : "<<km<<" km, "<<m<<" m, "<<cm<<" cm"<<std::endl;
            else
                std::cout<<"Valid Distance was not set!!"<<std::endl;
        }

        void normalize()
        {
            //& For Increment
            if ( cm > 99 )
            {
                m += cm / 100;
                cm %= 100;
            }
            if ( m > 999 )
            {
                km += m / 1000;
                m %= 1000;
            }

            //& For Decrement
            if ( cm < 0)
            {
                m--;
                cm = 100 + cm;
            }
            if ( m < 0 )
            {
                km--;
                m = 1000 + m;
            }
        }

        //$ Set Distance Method
        void setDistance(int km, int m, int cm)
        {
            this->km = km;
            this->m = m;
            this->cm = cm;

            normalize();
        }

        //$ Overloaded +, Adds 2 distance objects
        Distance operator+(const Distance& d) const
        {
            Distance temp;

            temp.km = this->km + d.km;
            temp.m = this->m + d.m;
            temp.cm = this->cm + d.cm;

            temp.normalize();

            return temp;
        }

        //$ Overloaded pre - ++, Increments second by 1 then returns
        Distance& operator++()
        {
            ++cm;

            normalize();

            return *this;
        }

        //$ Overloaded post - ++, Returns then Increments second by 1
        Distance operator++(int)
        {
            Distance temp(*this);
            
            cm++;

            normalize();

            return temp;
        }

        //$ Overloaded pre - decrement, Decrements second by 1 then returns
        Distance& operator--()
        {
            --cm;

            normalize();

            return *this;
        }

        //$ Overloaded post - decrement, Returns then Decrements second by 1
        Distance operator--(int)
        {
            Distance temp(*this);
            
            cm--;

            normalize();

            return temp;
        }
        
};

int main()
{
    Distance d1 = {12, 980, 76};
    Distance d2(12, 0, 0);

    std::cout<<"Distance values :\n";
    d1.showDistance();
    d2.showDistance();

    Distance d3 = d1 + ++d2;
    std::cout<<"Added Distance :\n";
    d3.showDistance();
    d2.showDistance();

    std::cout<<"Pre - Decremented Distance :\n";
    Distance d4 =  --d2;
    d4.showDistance();

    Distance d5(10, 0, 0);
    std::cout<<"Post - Decremented Distance :\n";
    Distance d6 = d5--;
    d6.showDistance();
    d5.showDistance();
    
    // while ( getchar() != '\n');
    std::cin.get();
    return 0;
}