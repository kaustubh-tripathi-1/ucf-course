#include<stdio.h>
#include<conio.h>

void validInputCheck(int* , int* , int );
void swap( int* , int*);

int main()
{
    int num1, num2;
    printf("Enter 2 numbers to swap them - \n");
    validInputCheck(&num1, &num2, 1);

    printf("The numbers before swapping\nNum 1 - %d\nNum 2 - %d\n", num1, num2);

    swap(&num1, &num2);

    printf("The numbers after swapping\nNum 1 - %d\nNum 2 - %d\n", num1, num2);

    getch();
    return 0;
}

//@ Taking Input for 2 integers and Checking if it's valid
void validInputCheck(int *n1, int *n2, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n1, n2);

        if(validInput == 2 && (allowNegative || (*n1 > 0 && *n2 > 0)))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Swapping 2 Numbers
void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}