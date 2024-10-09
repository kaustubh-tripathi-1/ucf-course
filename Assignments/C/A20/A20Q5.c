#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int);
void validInputCheck2Numbers(int *, int*, int);
void validInputCheck3Double(double *, double *, double *);
int LCM(int, int);
int sumOfDigits(int);
double cuboidVolume(double, double, double);
int prime(int );

// @ Main Driver Code
int main()
{
    int choice, num1, num2, num, sum, lcm;
    double l, b, h;
    double volume;



    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Calculate LCM of 2 Numbers\n");
        printf("2. Calculate Sum of digits in number\n");
        printf("3. Volume of Cuboid\n");
        printf("4. Check a number for Prime\n");
        printf("5. Exit\n");
        validInputCheck(&choice, 0);
        
        switch(choice)
        {
            case 1:
            {
                printf("Enter 2 numbers to calculate LCM :\n");
                validInputCheck2Numbers(&num1, &num2, 0);

                lcm = LCM(num1, num2);
                printf("The LCM of %d and %d is %d.\n", num1, num2, lcm);
                break;
            }
            case 2:
            {
                printf("Enter a number calcualte sum of its digits :\n");
                validInputCheck(&num, 1);

                sum = sumOfDigits(num);

                printf("Sum of digits of %d is %d.\n", num, sum);
                break;
            }
            case 3:
            {
                printf("Enter length, breadth and height of a cuboid :\n");
                validInputCheck3Double(&l, &b, &h);

                volume = cuboidVolume(l, b, h);

                printf("The Volume of the cuboid is %.2lf.\n", volume);

                break;
            }
            case 4:
            {
                printf("Enter a number to check for prime :\n");
                validInputCheck(&num, 0);

                if(prime(num))
                    printf("%d is Prime.\n", num);
                else
                    printf("%d is not Prime.\n", num);
                break;
            }
            case 5:
                exit(0);
            default:
                printf("Invalid Choice. Please enter again.\n");
                break;
        }
    }

    getch();
    return 0;
}

//@ Valid Input Checking of Integers
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d", n);

        if (validInput == 1 && ( allowNegative || *n>=0) )
            break;
        else
        {
            printf("Invalid input! Please enter a valid positive integer.\n");
            while( getchar() != '\n');
        }
    }

}

//@ Valid Input Checking of 2 Integers
void validInputCheck2Numbers(int *n1, int *n2, int allowNegative)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d%d", n1, n2);

        if (validInput == 2 && ( allowNegative || *n1>=0 || *n2>=0) )
            break;
        else
        {
            printf("Invalid input! Please enter a valid positive integer.\n");
            while( getchar() != '\n');
        }
    }

}

//@ Valid Input Checking of 3 Double
void validInputCheck3Double(double *n1, double *n2, double *n3)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%lf%lf%lf", n1, n2, n3);

        if (validInput == 3 && *n1>=0 && *n2>=0 && *n3>=0)
            break;
        else
        {
            printf("Invalid input! Please enter a valid positive integer.\n");
            while( getchar() != '\n');
        }
    }
}

//@ LCM
int LCM(int n1, int n2)
{
    int num1_copy=n1, num2_copy=n2, hcf, lcm, remainder;
    //$ Most Efficient, Using Euclidean method for HCF and HCF, LCM Relatioship
    while(num2_copy)
    {
        remainder = num1_copy % num2_copy;
        num1_copy = num2_copy;
        num2_copy = remainder;
    }

    hcf = num1_copy;

    lcm = (n1 * n2) / hcf;

    return lcm;
}

//@ Sum Of Digits of Number
int sumOfDigits(int n)
{
    int sum=0, remainder;
    while(n)
    {
        remainder = n % 10;
        sum += remainder;
        n /= 10;
    }

    return sum;

}

//@ Volume of Cuboid
double cuboidVolume(double l, double b, double h)
{
    return l * b * h;
}

//@ Sum of N Natural Numbers
int prime(int n)
{
    int j, isPrime=1;

    if(n==1 || n==0)
    {
        isPrime = 0;
        return isPrime;
    }

    for( j=2 ; j*j <= n ; j++)    //$ Checking till square root of the number
    {
        if (n%j==0)
        {
            isPrime=0;  //$ Found a divisor, break the loop.
            break;
        }
    }
    
    return isPrime;
        
}