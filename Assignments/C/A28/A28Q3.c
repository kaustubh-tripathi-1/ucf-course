#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void printFibonacci(int, int, int);

int main()
{
    int terms, term;
    printf("Enter the number of terms of Fibonacci Series that you want to print :\n");

    validInputCheck(&terms, 0);

    printFibonacci(terms, 0, 1);

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

        if(validInput == 1 && (allowNegative || *n > 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Printing N terms of Fibonacci Series
void printFibonacci(int terms, int a, int b)
{
    if( terms == 0 )
        return;
    
    printf("%d ", a);
    
    printFibonacci( terms-1, b, a + b );
}