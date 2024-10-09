#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void octalRecursion(int );

int main()
{
    int n;
    printf("Enter a decimal number to print its Octal  :\n");
    validInputCheck(&n, 0);

    printf("Octal of %d is -\n", n);
    if(n==0)
        printf("0");
    else
        octalRecursion(n);
    
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

//@ Recursive Fn. to print Octal
void octalRecursion(int n)
{
    if(n>0)
    {
        octalRecursion(n/8);
        printf("%d", n%8);
    }
}