#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void validInputCheckInt(int *, int );
int* createArrayDMA(int );
void inputArray(int *, int);

int main()
{
    int *sizeOfArray = NULL;

    sizeOfArray = (int *)malloc(sizeof(int));

    if ( sizeOfArray == NULL )
    {
        printf("Memory Allocation Failed!!");
        return 1;
    }

    printf("Enter the number of values to calculate sum -\n");
    validInputCheckInt(sizeOfArray, 0);


    int *arrayPointer = createArrayDMA(*sizeOfArray);

    inputArray(arrayPointer, *sizeOfArray);

    int sum = 0;
    for ( int i = 0 ; i < *sizeOfArray ; i++)
        sum += arrayPointer[i];

    printf("The sum of all elements is %d", sum);

    free(sizeOfArray);
    sizeOfArray = NULL;

    free(arrayPointer);
    arrayPointer = NULL;

    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheckInt(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n > 0 )))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Creating String using DMA
int * createArrayDMA(int ptrSizeOfArray)
{
    int *array = NULL;

    array = (int *)malloc(ptrSizeOfArray * sizeof(int));

    if( array == NULL )
    {
        printf("Memory allocation for string failed!!");
        exit(1);
    }
    
    return array;

}

void inputArray(int *arrayPointer, int sizeOfArray)
{
    for ( int i = 0 ; i < sizeOfArray ; i++)
    {
        printf("Enter the %d value -\n", i+1);
        validInputCheckInt(&arrayPointer[i], 1);
    }
}