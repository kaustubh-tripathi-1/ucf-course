#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int sumOfDigits(int );

int main()
{
    int n, sum;
    printf("Enter the number to calculate the sum of its digits :\n");
    validInputCheck(&n, 0);

    if(n==0)
        sum = 0;
    else
        sum = sumOfDigits(n);

    printf("The sum of Digits in %d is %d.", n, sum);
    
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

//@ Recursive Fn. to calculate Sum of Digits in a Number
int sumOfDigits(int n)
{
    if(n==0)
        return 0;

    return n%10 + sumOfDigits(n/10);
}