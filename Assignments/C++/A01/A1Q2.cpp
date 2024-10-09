#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int );
unsigned long long int calculateFactorial(int );

int main()
{
    unsigned long long int factorial;
    int num;
    printf("Enter a number to calculate factorial -\n");
    validInputCheck(&num, 0);

    factorial = calculateFactorial(num);

    printf("The factorial of %d is %llu.\n", num, factorial);

    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck( int *n, int allowNegative)
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

unsigned long long int calculateFactorial(int num)
{
    unsigned long long int fact = 1;

    for (  ; num > 1 ; num-- )
        fact *= num;

    return fact;

}