#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
unsigned long long int factorial(int);

int main()
{
    unsigned long long int fact;
    int num;
    printf("Enter a number to calculate it's factorial :\n");

    validInputCheck(&num, 0);

    fact = factorial(num);

    printf("The factorial of %d is %llu.", num, fact);

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

//@ Factorial of a Number with Recursion
unsigned long long int factorial(int n)
{
    if( n == 0 || n == 1 )
        return 1;
    
    return n * factorial(n-1);
}