#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void sortArray(int *, int);
void merge2Arrays(int *ptrnumbers1, int size1, int *ptrnumbers2, int size2, int *ptrmergedArray, int size3);

int main()
{
    int size1, size2, i;
    printf("Enter the max size that you want to reserve for array1 -\n");
    validInputCheck(&size1, 0);
    printf("Enter the max size that you want to reserve for array2 -\n");
    validInputCheck(&size2, 0);

    int numbers1[size1], numbers2[size2], mergedArray[size1+size2];

    size1 = sizeof(numbers1) / sizeof(numbers1[0]);
    size2 = sizeof(numbers2) / sizeof(numbers2[0]);

    printf("Enter %d values for the array -\n", size1);
    for ( i = 0; i < size1; i++)
        validInputCheck(&numbers1[i], 1);

    printf("Enter %d values for the array -\n", size2);
    for ( i = 0; i < size2; i++)
        validInputCheck(&numbers2[i], 1);

    printf("Here's the first array -\n");
    for ( i = 0; i < size1; i++)
        printf("%d ", numbers1[i]);

    printf("\nHere's the second array -\n");
    for ( i = 0; i < size2; i++)
        printf("%d ", numbers2[i]);
    
    int size3 = size1 + size2;

    merge2Arrays(numbers1, size1, numbers2, size2, mergedArray, size3);

    printf("\n\nHere's the Merged array -\n");
    for ( i = 0; i < size3; i++)
        printf("%d ", mergedArray[i]);

    sortArray(mergedArray, size3);
    
    printf("\n\nHere's the Merged & sorted array -\n");
    for ( i = 0; i < size3; i++)
        printf("%d ", mergedArray[i]);

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

void merge2Arrays(int *ptrnumbers1, int size1, int *ptrnumbers2, int size2, int *ptrmergedArray, int size3)
{
    int i, j;

    for ( i = 0 ; i < size1 ; i++ )
    {
        ptrmergedArray[i] = ptrnumbers1[i];
    }

    for ( j = 0 ; i < size3 ; j++, i++ )
    {
        ptrmergedArray[i] = ptrnumbers2[j];
    }

}