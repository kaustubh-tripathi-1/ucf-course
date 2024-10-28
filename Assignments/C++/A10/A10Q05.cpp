#include<iostream>
#include <limits>
#include <string>
using namespace std;

class Complex
{
    private :

        double real, imaginary;

    public :

        //& Initializer List 
        
        Complex(double real, double imaginary) : real(real), imaginary(imaginary) {}
        Complex(Complex &c) : real(c.real), imaginary(c.imaginary) {}

        void showData()
        {
            cout<<endl<<"The Complex no. is : ";
            cout<<real<<" "<<(imaginary<0 ? "" : "+")<<" "<<imaginary<<"i"<<endl;
        }

};

int main()
{
    Complex complexNumbers[5] = {
        Complex{1.0, 2.0}, 
        Complex{3.0, 4.0}, 
        Complex{5.0, 6.0}, 
        Complex{7.0, 8.0}, 
        Complex{9.0, 10.0}
    };


    for ( int i = 0 ; i < 5 ;  i++)
        complexNumbers[i].showData();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}