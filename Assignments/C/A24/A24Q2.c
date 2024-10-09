#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void printFibonacciFirstN(int );

int main()
{
    int terms;;
    printf("Enter the no. of terms of Fibonacci series that you want to print :\n");
    validInputCheck(&terms, 0);

    printFibonacciFirstN(terms);

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

//@ Printing First N terms of Fibonacci

void printFibonacciFirstN(int n)
{
    unsigned long long int a, b, term;
    int i;

    a=-1;
    b=1;

    for ( i = 1; i <= n; i++)
    {
        term = a+b;
        printf("%llu ", term);
        a=b;
        b=term;
    }
}