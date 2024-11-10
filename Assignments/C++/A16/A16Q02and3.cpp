#include<iostream>
// using namespace std;

class Complex
{
    private :

        int real, imaginary;

    public :

        Complex( int real = 0, int imaginary = 0 )
        :
            real(real), imaginary(imaginary) {}

        Complex(const Complex&c )
        :
            real(c.real), imaginary(c.imaginary) {}

        Complex& setComplex(int real, int imaginary )
        {
            this->real = real;
            this->imaginary = imaginary;

            return *this;
        }

        Complex& displayComplex()
        {
            std::cout<<"Complex number is : "
                    <<real
                    <<(imaginary >= 0 ? "+" : "")
                    <<imaginary<<"i"
                    <<std::endl;

            return *this;
        }
        
};

Complex* createComplexDynamically( int real, int imaginary)
{
    /* Complex *c = new Complex(real, imaginary);    //$ Calls constructor

    //$ Explicitly setting real and imaginary
    // c = new Complex;

    // c->real = real;
    // c->imaginary = imaginary;

    return c; */

    return new Complex(real, imaginary);    //$ Direct Address Return
}

int main()
{
    Complex c1 = {23, 67};
    Complex c2;

    c1.displayComplex();
    c2.displayComplex();

    c2.setComplex(3, 4);
    c2.displayComplex();

    Complex *ptrComplex = createComplexDynamically(5, 6);
    ptrComplex->displayComplex();

    delete ptrComplex;

    std::cin.get();
    return 0;
}