#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int prime(int );

int main()
{
    int num;
    printf("Enter a number to check for prime :\n");
    validInputCheck(&num, 1);
    
    if(prime(num))
        printf("%d is prime.\n", num);
    else
        printf("%d is not prime.\n", num);
    
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
int prime(int n)
{
    int j;

    if( n<2 )
        return 0;

    for( j=2 ; j*j <= n ; j++)    //$ Checking till square root of the number
        if ( n % j == 0 )
            return 0;  //$ Found a divisor, end function

    return 1;
}