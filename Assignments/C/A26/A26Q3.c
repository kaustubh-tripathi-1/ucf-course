#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void binaryRecursion(int );

int main()
{
    int n;
    printf("Enter a decimal number to print its binary  :\n");
    validInputCheck(&n, 0);

    printf("Binary of %d is -\n", n);
    if(n==0)
        printf("0");
    else
        binaryRecursion(n);
    
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

//@ Recursive Fn. to print Binary
void binaryRecursion(int n)
{
    if(n>0)
    {
        binaryRecursion(n/2);
        printf("%d ", n%2);
    }
}