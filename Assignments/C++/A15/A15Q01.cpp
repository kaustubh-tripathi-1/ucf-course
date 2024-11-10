#include<iostream>
// using namespace std;

class Complex
{
    private :

        int real, imaginary;
    
    public :

        //$ Necessary Constructors
        Complex(int real = 0, int imaginary = 0) : real(real), imaginary(imaginary) {}

        Complex(const Complex &com) : real(com.real), imaginary(com.imaginary) {}

        //$ Operator Overloading to Add 2 Complex objects
        Complex operator+(const Complex &c) const
        {
            Complex temp;

            temp.real = this->real + c.real;
            temp.imaginary = this->imaginary + c.imaginary;

            return temp;
        }
        //$ Operator Overloading to Subtract 2 Complex objects
        Complex operator-(const Complex &c) const
        {
            Complex temp;

            temp.real = this->real - c.real;
            temp.imaginary = this->imaginary - c.imaginary;

            return temp;
        }

        //$ Operator Overloading to Add 2 Complex objects
        Complex operator*(const Complex &c) const
        {
            Complex temp;

            temp.real = (this->real * c.real) - (this->imaginary * c.imaginary);
            temp.imaginary = (this->real * c.imaginary) + (this->imaginary * c.real);

            return temp;
        }

        //$ Operator Overloading to compare equality of 2 Complex objects
        bool operator==(const Complex &c) const
        {
            if( this->real == c.real && this->imaginary == c.imaginary)
                return true;
            
            return false;
        }

        /** @brief Set Complex Number */
        void setComplex(int real, int imaginary=0)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        /** @brief Display Complex Number */
        void showComplex() const
        {
            std::cout<<"The complex no. is : "<<real<<(imaginary >= 0 ? "+" : "")<<imaginary<<"i"<<std::endl;
        }

        //$ Overloaded -, negates the real and imaginary part
        friend Complex& operator-(Complex &C);

};

Complex& operator-(Complex &C)
{
    C.real = -(C.real);
    C.imaginary = -(C.imaginary);

    return C;
}

int main()
{

    Complex c1(3, 4);
    Complex c2(5, 6);
    Complex c3 = c1;


    Complex c4;
    c4 = c1 + c2;
    std::cout<<"Addition :\n";
    c4.showComplex();

    Complex c5 = (c2 - c1);
    std::cout<<"Subtraction -:\n";
    c5.showComplex();

    Complex c6 = (c1 * c2);
    std::cout<<"Multiplication -:\n";
    c6.showComplex();

    if ( c1 == c2 )
        std::cout<<"Complex numbers are equal.\n";
    else
        std::cout<<"Complex numbers are not equal.\n";

    if ( c1 == c3 )
        std::cout<<"Complex numbers are equal.\n";
    else
        std::cout<<"Complex numbers are not equal.\n";

    std::cout<<"Negation Operator :\n";
    c6 = -(-c6);
    c6.showComplex();

    std::cin.get();
    return 0;
}