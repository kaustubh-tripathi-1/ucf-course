#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int );

int main()
{
    int *numPtr = NULL;

    numPtr = (int *)malloc(sizeof(int));

    if (numPtr == NULL)
    {
        printf("Memory Allocation Failed!");
        return 1;
    }

    printf("Enter a number to check for even or odd -\n");
    validInputCheck(numPtr, 1);

    if ( *numPtr % 2 == 0)
        printf("%d is Even.", *numPtr);
    else
        printf("%d is Odd.", *numPtr);

    free(numPtr);
    numPtr = NULL;

    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
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