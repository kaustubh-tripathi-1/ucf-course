#include<iostream>
#include <limits>
using namespace std;

class Complex 
{
    private :
        int real, imaginary;
    
    public :
        void printComplex()
        {
            cout<<"The complex number is -"<<endl;
            cout<<real<<"+"<<imaginary<<"i"<<endl;
        }

        void setComplex(int r, int i)
        {
            real = r;
            imaginary = i;
        }
};

int main()
{
    Complex c1;
    c1.setComplex(3, 4);
    c1.printComplex();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}