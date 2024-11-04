#include <iostream>

class Complex 
{
    private :

        int real, imaginary;

    public:

        Complex(int real, int imaginary) : real(real), imaginary(imaginary) {}

        // Overloading the '+' operator
        Complex operator+(const Complex &c) const 
        {
            return Complex(real + c.real, imaginary + c.imaginary);
        }

        void display() const 
        {
            std::cout << real <<( imaginary >= 0 ? " + " : "" )<< imaginary << "i" << std::endl;
        }
};

int main() 
{
    Complex c1(3, 4), c2(1, 2);
    Complex result = c1 + c2; // Using overloaded '+' operator
    result.display(); // Output: 4 + 6i
    return 0;
}