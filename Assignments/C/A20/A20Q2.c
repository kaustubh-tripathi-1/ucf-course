#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int);
void validInputCheckDouble(double *);
unsigned long long int factorial(int);
int checkEvenOdd(int);
double circleArea(double);
int sumOfNaturalNumbers(int );

// @ Main Driver Code
int main()
{
    int choice, num, sum;
    double radius, area;
    unsigned long long int fact;



    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Calculate Factorial of a Number\n");
        printf("2. Check for Even or Odd\n");
        printf("3. Area of Circle\n");
        printf("4. Sum of n Natural Numbers\n");
        printf("5. Exit\n");
        validInputCheck(&choice, 0);
        
        switch(choice)
        {
            case 1:
            {
                printf("Enter a number to Calculate its factorial :\n");
                validInputCheck(&num, 0);

                fact = factorial(num);
                
                printf("Factorial of %d is %llu.\n", num, fact);
                break;
            }
            case 2:
            {
                printf("Enter a number to Check for Even or Odd :\n");
                validInputCheck(&num, 1);

                if(checkEvenOdd(num))
                    printf("%d is Even.\n", num);
                else
                    printf("%d is Odd.\n", num);                
                break;
            }
            case 3:
            {
                printf("Enter radius of a Circle to calculate Area :\n");
                validInputCheckDouble(&radius);

                area = circleArea(radius);

                printf("The Area of the circle with radius %.2lf is %.2lf.\n", radius, area);

                break;
            }
            case 4:
            {
                printf("Enter the number of First Natural numbers of which you want to know the sum of :\n");
                validInputCheck(&num, 0);

                sum = sumOfNaturalNumbers(num);
                printf("The sum of First %d natural numbers is %d\n", num, sum);

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

//@ Valid Input Checking of Numbers 
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
            printf("Invalid input! Please enter a valid integer.\n");
            while( getchar() != '\n');
        }
    }

}


//@ Valid Input Checking of All Double
void validInputCheckDouble(double *n)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%lf", n);

        if (validInput == 1)
            break;
        else
        {
            printf("Invalid input! Please enter a valid number.\n");
            while( getchar() != '\n');
        }
    }

}

//@ Factorial
unsigned long long int factorial(int n)
{
    int i;
    unsigned long long int f=1;
    for( i=n ; i>=2 ; i--)
    {
        f*=i;
    }
    return f;
}

//@ Even or Odd
int checkEvenOdd(int n)
{
    return n%2 == 0;
}

//@ Circle Area
double circleArea(double r)
{
    return 3.1428 * r * r;
}

//@ Sum of N Natural Numbers
int sumOfNaturalNumbers(int n)
{
    return (n*(n+1))/2;
}