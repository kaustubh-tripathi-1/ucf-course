#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void printNN(int );

int main()
{
    int n;
    printf("Enter the number upto which you want to print Natural Numbers in reverse Order :\n");
    validInputCheck(&n, 0);
    printf("\n");

    printNN(n);
    
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

        if(validInput == 1 && (allowNegative || *n > 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Recursive Fn. to print Natural numbers in reverse Order
void printNN(int n)
{
    if(n>=1)
    {    
        printf("%d  ", n);
        printNN(n-1);
    }
    
}