#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int *, int );
void swap(int*, int* );

int main()
{
    unsigned long long int factorial;
    int num1, num2;
    printf("Enter 2 numbers to swap them -\n");
    validInputCheck(&num1, &num2, 1);

    printf("Values before swap -\nnum1 - %d, num2 - %d\n", num1, num2);    

    swap(&num1, &num2);
    
    printf("Values after swap -\nnum1 - %d, num2 - %d\n", num1, num2);    


    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck( int *n1, int *n2, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n1, n2);

        if(validInput == 2 && (allowNegative || (*n1 > 0 && *n2 > 0)))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

void swap(int *pnum1, int *pnum2)
{
    int temp;

    temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
    
}