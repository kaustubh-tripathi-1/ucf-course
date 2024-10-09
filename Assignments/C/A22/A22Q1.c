#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
unsigned long long int factorial(int);

int main()
{
    int n;
    unsigned long long int fact;
    printf("Enter the number to calculate factorial :\n");
    validInputCheck(&n, 0);

    fact = factorial(n);

    printf("The factorial of %d is %llu.", n, fact);
    
    getch();
    return 0;
}

//@ Valid Input Check
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || *n >= 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Factorial of a Number
unsigned long long int factorial(int n)
{
    unsigned long long int fact=1;

    if(n==0)
        return 1;
    
    for( int i=n ; i>=1 ; i--)
    {
        fact *= i;
    }

    return fact;
} 