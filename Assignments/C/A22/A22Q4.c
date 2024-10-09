#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int checkForDigit(int, int);
void validInputCheck(int *, int *, int);

int main()
{
    int num, digit;
    printf("Enter a digit to check for in a number :\n");
    validInputCheck(&num, &digit, 1);

    if(checkForDigit(num, digit))
        printf("%d contains %d.", num, digit);
    else
        printf("%d doesn't contain %d.", num, digit);

    getch();
    return 0;
}

//@ Valid Input Check of 2 numbers
void validInputCheck(int *n, int *d, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n, d);

        if(validInput == 2 && (allowNegative || (*n >= 0 && *d >=0)))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}


//@ Checking for occurrence of a digit in a Number
int checkForDigit(int n, int d)
{
    n = abs(n);

    while(n>0)
    {        
        if(n%10 == d)
            return 1;

        n/=10;
    }

    return 0;
    
}