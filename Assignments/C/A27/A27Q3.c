#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int sumOfFirstEvenNN(int );

int main()
{
    int n, sum;
    printf("Enter the number up to which you want to calculate the sum of First Odd Natural Numbers :\n");
    validInputCheck(&n, 0);

    if(n==0)
        sum = 0;
    else
        sum = sumOfFirstEvenNN(n);

    printf("The sum of First %d Even Natural Numbers is %d.", n, sum);
    
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

//@ Recursive Fn. to calculate Sum of First N Even Natural Numbers
int sumOfFirstEvenNN(int n)
{
    if(n==1)
        return 2*n;

    return (2*n) + sumOfFirstEvenNN(n-1);
}