#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int sumOfSeries(int);
unsigned long long int factorial(int);


//@ Main Driver Code
int main()
{
    int terms, sum;
    printf("Enter the no. of terms fof which you want to know the sum of the series :\n");
    validInputCheck(&terms, 0);

    sum = sumOfSeries(terms);

    printf("The sum of First %d terms of the series is %d.\n", terms, sum);

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

//@ Sum of Series
int sumOfSeries(int terms)
{
    int i, sum = 0;

    for ( i = 1; i <= terms ; i++)
        sum += factorial(i) / i;
    
    return sum;
}