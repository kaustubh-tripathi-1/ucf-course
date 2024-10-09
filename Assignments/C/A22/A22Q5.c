#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
void primeFactors(int);

int main()
{
    int num;
    printf("Enter a number to know it's prime factors :\n");
    validInputCheck(&num, 0);

    primeFactors(num);

    getch();
    return 0;
}

//@ Valid Input Check of 1 number
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

//@ Checking for Prime

int Prime(int n)
{
    int j;

    if( n<2 )
        return 0;

    for( j=2 ; j*j <= n ; j++)    //$ Checking till square root of the number
        if ( n % j == 0 )
            return 0;             //$ Found a divisor, end function

    return 1;
}

//@ Finding next Prime
int nextPrime(int n)
{
    int i ;
    for( i = n+1 ; Prime(i) != 1 ; i++ );

    return i;
    
}

//@ Printing Prime Factors
void primeFactors(int n)
{
    int i=2;

    while( n > 1 )
    {
        if( n % i == 0 )
        {
            printf("%d ", i);
            n/=i;
        }
        else
            i = nextPrime(i);
    }
}