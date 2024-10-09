#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int );
int checkPrime(int);

int main()
{
    int num, prime;
    printf("Enter a number to check for Prime -\n");
    validInputCheck(&num, 0);

    prime = checkPrime(num);
    
    if ( prime )
        printf("%d is Prime.", num);    
    else
        printf("%d is not Prime.", num);    



    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck( int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n );

        if(validInput == 1 && (allowNegative || (*n > 0 )))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

int checkPrime(int num)
{
    int divisor;

    if ( num < 2)
        return 0;

    for ( divisor = 2 ; divisor * divisor <= num ; divisor++)
        if ( num % divisor == 0)
            return 0;

    return 1;
    
}