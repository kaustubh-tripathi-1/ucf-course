#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int sumOfSquaresFirstNN(int );

int main()
{
    int n, sum;
    printf("Enter the number up to which you want to calculate the sum of Squares First Natural Numbers :\n");
    validInputCheck(&n, 0);

    if(n==0)
        sum = 0;
    else
        sum = sumOfSquaresFirstNN(n);

    printf("The sum of Squares of First %d Even Natural Numbers is %d.", n, sum);
    
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

//@ Recursive Fn. to calculate Sum of Squares First N Odd Natural Numbers
int sumOfSquaresFirstNN(int n)
{
    if(n==1)
        return n*n;

    return n*n + sumOfSquaresFirstNN(n-1);
}