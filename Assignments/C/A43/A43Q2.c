#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void sortArray(int *, int);

int main()
{
    int size, i;
    printf("Enter the max size that you want to reserve for the array -\n");
    validInputCheck(&size, 0);

    int numbers[size];

    size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Enter %d values for the array to sort them -\n", size);
    for ( i = 0; i < size; i++)
        validInputCheck(&numbers[i], 1);

    printf("Here's the original array -\n");
    for ( i = 0; i < size; i++)
        printf("%d ", numbers[i]);

    sortArray(numbers, size);
    
    printf("\nHere's the sorted array -\n");
    for ( i = 0; i < size; i++)
        printf("%d ", numbers[i]);

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

//@ Sorting an Array
void sortArray(int *ptrnumbers, int size)
{
    int i, j, temp;

    for ( i = 0 ; i < size - 1 ; i++)
    {
        for ( j = 0 ; j < size-i-1 ; j++)
        {
            if ( ptrnumbers[j] > ptrnumbers[j+1] )
            {
                temp = ptrnumbers[j];
                ptrnumbers[j] = ptrnumbers[j+1];
                ptrnumbers[j+1] = temp;
            }
        }
    }
}