#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int Prime(int );
void printPrime(int );

int main()
{
    int num;
    printf("Enter how many First Prime Numbers you want to print :\n");
    validInputCheck(&num, 0);
    
    printPrime(num);
    
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
    int i, nPrime ;
    for( i = n+1 ; Prime(i) != 1 ; i++ );

    return i;
    
}

//@ Printing First N Prime
void printPrime(int n)
{
    int count=0, i=2;

    while(count!=n)
    {
        printf("%d ", i);
        count++;
        
        i = nextPrime(i);
    }
    
}