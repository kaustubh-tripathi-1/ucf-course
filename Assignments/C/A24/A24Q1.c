#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int*, int );
int Prime(int );
void printPrimeBetween(int , int);

int main()
{
    int rangeStart, rangeEnd;
    printf("Enter 2 numbers for which you want to print prime numbers between them :\n");
    validInputCheck(&rangeStart, &rangeEnd, 0);

    printPrimeBetween(rangeStart, rangeEnd);

    getch();
    return 0;
}

//@ Valid Input Check of 2 numbers
void validInputCheck(int *n1, int *n2, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n1, n2);

        if(validInput == 2 && (allowNegative || ( *n1 >= 0 && *n2>=0)))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Checking for Prime

int Prime(int n)
{
    int j;

    if( n<2 )
        return 0;               //$ Numbers less than 2 are not prime

    for( j=2 ; j*j <= n ; j++)    //$ Checking till square root of the number
        if ( n % j == 0 )
            return 0;             //$ Found a divisor, end function

    return 1;                  //$ No divisors found, number is prime
}

//@ Print Prime Numbers between 2 numbers
void printPrimeBetween(int rangeStart, int rangeEnd)
{
    int i, foundPrime = 0;

    if (rangeStart >= rangeEnd) {
        printf("Invalid range: start should be less than end.\n");
        return;
    }
    
    for ( i = rangeStart+1; i < rangeEnd; i++)
    {
        if (Prime(i))
        {
            printf("%d ", i);   
            foundPrime = 1;
        }
    }

    if(foundPrime == 0 )
        printf("No prime numbers found in the given range.\n");

}