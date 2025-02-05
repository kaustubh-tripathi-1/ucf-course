#include<iostream>
#include<array>

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
            /* Complex temp;

            temp.real = this->real + c.real;
            temp.imaginary = this->imaginary + c.imaginary;

            return temp; */

            return Complex((this->real + c.real), (this->imaginary + c.imaginary));

        }
        //$ Operator Overloading to Subtract 2 Complex objects
        Complex operator-(const Complex &c) const
        {
            /* Complex temp;

            temp.real = this->real - c.real;
            temp.imaginary = this->imaginary - c.imaginary;

            return temp; */

            return Complex((this->real - c.real), (this->imaginary - c.imaginary));
            
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
            return (this->real == c.real && this->imaginary == c.imaginary);
        }

        /** @brief Set Complex Number */
        void setComplex(int real, int imaginary=0)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        int getReal() const
        {
            return real;
        }

        int getImaginary() const
        {
            return imaginary;
        }

        /** @brief Display Complex Number */
        void showComplex() const
        {
            std::cout<<"The complex no. is : "<<real<<(imaginary >= 0 ? "+" : "")<<imaginary<<"i"<<std::endl;
        }

        //$ Overloaded -, negates the real and imaginary part
        friend Complex& operator-(Complex &C);

        void inputComplex()
        {
            std::cout<<"Enter the real and iamginary part of complex number respectively :\n";
            std::cin>>real>>imaginary;
        }

};

Complex& operator-(Complex &C)
{
    C.real = -(C.real);
    C.imaginary = -(C.imaginary);

    return C;
}

void inputComplexNumbers(std::array<Complex, 5> &complexNums)
{
    for ( int i = 0 ; i < complexNums.size() ; i++ )
    {
        complexNums.at(i).inputComplex();
    }
}

void displayComplexNumbers(std::array<Complex, 5> &complexNums)
{
    for ( int i = 0 ; i < complexNums.size() ; i++ )
    {
        complexNums.at(i).showComplex();
    }
}

Complex calculateSumOfComplexNumbers(std::array<Complex, 5> &complexNums)
{
    Complex temp;

    for ( int i = 0 ; i < complexNums.size() ; i++ )
    {
        temp = temp + complexNums.at(i); 
    }

    return temp;
}

int main()
{
    std::array<Complex, 5> complexNums;

    std::cout<<"Input "<<complexNums.size()<<" complex numbers:\n";
    inputComplexNumbers(complexNums);

    std::cout<<"The complex numbers in the array are :\n";
    displayComplexNumbers(complexNums);

    Complex sum = calculateSumOfComplexNumbers(complexNums);

    std::cout<<"The sum of all complex numbers in the array is :\n";
    sum.showComplex();

    std::cin.get();
    return 0;
}