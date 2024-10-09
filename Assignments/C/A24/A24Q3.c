#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
unsigned long long int combinations(int , int);
unsigned long long int factorial(int);
void printPascal(int);

int main()
{
    int lines;
    printf("Enter how many lines you want to print -\n");
    validInputCheck(&lines, 0);
    
    printPascal(lines);

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
    /* //& Less iterations Logic
    int i;
    unsigned long long int result=1;
    if( r > n-r )
        r = n-r;

    for( i = 0 ; i < r ; i++)
    {
        result *= n-i;
        result /= i+1;
    }

    return result; */

    //& Simple Logic but more iterations
    return factorial(n) / (factorial(n-r) * factorial(r));
}

//@ Printing Pascal Triangle
void printPascal(int lines)
{
    int i, j, rows, columns, k, n, r;

    printf("\n\n");

    rows = lines;
    columns = 2*lines-1;

    printf("\n\n");

    for ( i = 1; i <= rows; i++)
    {
        n = i-1;
        r = 0;
        for ( j = 1; j <= columns; j++)
        {
            if ( j>= ((lines+1)-i) &&  j<= ((lines-1)+i) && k )
            {
                printf("%3d ", combinations(n, r));
                r++;
                k=0;
            }
            else
            {
                printf("    ");
                k=1;
            }
        }
        printf("\n");
    }
}

