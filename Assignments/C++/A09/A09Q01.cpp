#include<iostream>
#include <limits>
using namespace std;

//@ Class for a complex number
class Complex
{
    private :

        int real, imaginary;
    
    public :

        //$ Sets a Complex Number at Compile-time
        void setData(int real=0, int imaginary=0)
        {
            this->real = real;
            this->imaginary = imaginary;
        }

        //$ Sets a Complex Number at Run-time
        void setData()
        {
            cout<<"Enter Real part of Complex number - "<<endl;
            cin>>real;
            cout<<"Enter Imaginary part of Complex number - "<<endl;
            cin>>imaginary;
        }

        //$ Displays the Complex number
        void showData()
        {
            cout<<"The complex number is : "<<real<<(imaginary >= 0 ? "+" : "")<<imaginary<<"i"<<endl;
        }
        
        //$ Adds 2 complex numbers and returns the complex number
        Complex add(Complex x)
        {
            Complex temp;
            
            temp.real = this->real + x.real;
            temp.imaginary = this->imaginary + x.imaginary;

            return temp;
        }

        //$ Subtracts 2 complex numbers and returns the complex number
        Complex subtract(Complex x)
        {
            Complex temp;
            
            temp.real = this->real - x.real;
            temp.imaginary = this->imaginary - x.imaginary;

            return temp;
        }

        //$ Multiplies 2 complex numbers and returns the complex number
        Complex multiply(Complex x)
        {
            Complex temp;
            
            temp.real = ( (this->real * x.real) - (this->imaginary * x.imaginary) );
            temp.imaginary = ( (this->real * x.imaginary) + (x.real * this->imaginary) );
            
            return temp;
        }
};

int main()
{
    Complex c1, c2;

    c1.setData(4,5);
    c2.setData(11,8);
    /* c1.setData();
    c2.setData(); */

    c1.showData();
    c2.showData();

    cout<<"Addition -"<<endl;
    Complex c3 = c1.add(c2);
    c3.showData();
    cout<<"Subtraction -"<<endl;
    Complex c4 = c1.subtract(c2);
    c4.showData();
    cout<<"Multiplication -"<<endl;
    Complex c5 = c1.multiply(c2);
    c5.showData();


    // while ( getchar() != '\n');
    cin.get();
    return 0;
}