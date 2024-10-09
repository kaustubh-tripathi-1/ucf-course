#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void reverseNumber(int );

int main()
{
    int n;
    printf("Enter a decimal number to reverse it  :\n");
    validInputCheck(&n, 0);

    printf("Reverse of %d is -\n", n);
    if(n==0)
        printf("0");
    else
        reverseNumber(n);
    
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

//@ Recursive Fn. to reverse a number
void reverseNumber(int n)
{
    if(n>0)
    {
        printf("%d", n%10);
        reverseNumber(n/10);
    }
}