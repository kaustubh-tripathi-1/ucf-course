#include<iostream>
#include <string>
using namespace std;

class Fraction
{
    private :

        long numerator;
        long denominator;

        long HCF(long a, long b) const
        {
            if( b == 0)
                return a;
            
            return HCF(b, a%b);
        }

        long calculateLCM(long a, long b) const
        {
            long lcm = ( a * b ) / HCF(a, b);

            return lcm;
        }

    public :

        //$ Default Constructor
        Fraction(long numerator = 0, long denominator = 1)
        :
            numerator(numerator), denominator(denominator)
        {
            //& Adjust denominator if it's zero after initialization
            if( this->denominator == 0 )
            {
                cout << "Warning: Denominator cannot be zero. Setting it to 1." << endl;
                this->denominator = 1;
            }

            this->reduceFraction();

        }

        //$ Copy Constructor
        Fraction(const Fraction &f)
        :
            numerator(f.numerator), denominator(f.denominator) {}


        void reduceFraction()
        {   
            long hcf = HCF(numerator, denominator);
            
            if ( hcf == 1)
                return;
            
            if ( (numerator % hcf == 0) && (denominator % hcf == 0) )
            {
                numerator /= hcf;
                denominator /= hcf;
                cout<<"Fraction Reduced\n";
            }

        }

        //$ Overloaded +, Adds 2 Fraction values
        Fraction operator+(const Fraction &f) const
        {
            Fraction result;
            
            result.denominator = calculateLCM(this->denominator, f.denominator);

            result.numerator = ( this->numerator * ( result.denominator / this->denominator ) ) + ( f.numerator * ( result.denominator / f.denominator ) ); 

            result.reduceFraction();
            
            return result;
        }

        //$ Overloaded <, Compare 2 Fraction values
        bool operator<(const Fraction &f) const
        {
            double fractionValue1, fractionValue2;

            fractionValue1 = (double)this->numerator / this->denominator;
            
            fractionValue2 = (double)f.numerator / f.denominator;
            
            return fractionValue1 < fractionValue2;
            
        }

        //$ Display Fraction
        void displayFraction() const
        {
            cout<<"Fraction :"<<numerator<<"/"<<denominator<<endl;
        }

};

int main()
{
    Fraction f1(1, 8);
    Fraction f2(4, 6);

    Fraction f3 = f1 + f2;
    f3.displayFraction();

    if ( f1 < f2 )
        cout<<"Caller Object Fraction is less than passed object fraction.\n";
    else
        cout<<"Passed Object Fraction is less than Caller object fraction.\n";


    // while ( getchar() != '\n');
    cin.get();
    return 0;
}