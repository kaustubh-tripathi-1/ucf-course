#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int *, int );
unsigned long long int factorial(int);
unsigned long long int combinations(int, int);

int main()
{
    int n, r;
    unsigned long long int combination;
    
    printf("Enter value of n and r to calculate combinations :\n");
    validInputCheck(&n, &r, 0);

    combination = combinations(n, r);

    printf("The no. of combinations from %d items, selected %d at a time are %llu", n, r, combination);
    
    getch();
    return 0;
}

//@ Valid Input Check of 2 numbers
void validInputCheck(int *n, int *r, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n, r);

        if(validInput == 2 && (allowNegative || (*n >= 0 && *r >=0 && *n >= *r)))
            break;
        else
        {
            printf("Enter 2 valid numbers and n should be greater than r!\n");
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
        
    for( int i=n ; i>1 ; i--)
    {
        fact *= i;
    }
    return fact;
} 

//@ Calculating No. of Combinations
unsigned long long int combinations(int n, int r)
{
    //& Less iterations Logic
    int i;
    unsigned long long int result=1;
    if( r > n-r )
        r = n-r;

    for( i = 0 ; i < r ; i++)
    {
        result *= n-i;
        result /= i+1;
    }

    return result;

    //& Simple Logic but more iterations
    // return factorial(n) / (factorial(n-r) * factorial(r));
}

