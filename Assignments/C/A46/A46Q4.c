#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void validInputCheckInt(int *, int );
int* createArrayDMA(int );
void inputArray(int *, int);
int* mergeArray(int *, int , int *, int );

int main()
{
    int *sizeOfArray1 = NULL;

    sizeOfArray1 = (int *)malloc(sizeof(int));

    if ( sizeOfArray1 == NULL )
    {
        printf("Memory Allocation Failed!!");
        return 1;
    }

    printf("Enter the number of values first array -\n");
    validInputCheckInt(sizeOfArray1, 0);

    int *sizeOfArray2 = NULL;

    sizeOfArray2 = (int *)malloc(sizeof(int));

    if ( sizeOfArray2 == NULL )
    {
        printf("Memory Allocation Failed!!");
        return 1;
    }

    printf("Enter the number of values second array -\n");
    validInputCheckInt(sizeOfArray2, 0);


    int *arrayPointer1 = createArrayDMA(*sizeOfArray1);

    int *arrayPointer2 = createArrayDMA(*sizeOfArray2);

    printf("Enter values for 1st array -\n");
    inputArray(arrayPointer1, *sizeOfArray1);

    printf("Enter values for 2nd array -\n");
    inputArray(arrayPointer2, *sizeOfArray2);

    int *mergedArray = mergeArray(arrayPointer1, *sizeOfArray1, arrayPointer2, *sizeOfArray2);

    printf("The merged array is -\n");

    for ( int i = 0 ; i < *sizeOfArray1 + *sizeOfArray2 ; i++)
    {
        printf("%d ", mergedArray[i]);
    }

    free(sizeOfArray1);
    sizeOfArray1 = NULL;

    free(sizeOfArray2);
    sizeOfArray2 = NULL;

    free(arrayPointer1);
    arrayPointer1 = NULL;

    free(arrayPointer2);
    arrayPointer2 = NULL;

    free(mergedArray);
    mergedArray = NULL;

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

//@ Creating Array using DMA
int* createArrayDMA(int ptrSizeOfArray)
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

//@ Function to input array values
void inputArray(int *arrayPointer, int sizeOfArray)
{
    for ( int i = 0 ; i < sizeOfArray ; i++)
    {
        printf("Enter the %d value -\n", i+1);
        validInputCheckInt(&arrayPointer[i], 1);
    }
}

//@ Merging 2 arrays
int* mergeArray(int *arrayPointer1, int sizeOfArray1, int *arrayPointer2, int sizeOfArray2)
{
    int sizeOfMergedArray = sizeOfArray1 + sizeOfArray2;
    
    int *mergedArrayPtr = createArrayDMA(sizeOfMergedArray);

    int i, j;
    for ( i = 0 ; i < sizeOfArray1 ; i++)
        mergedArrayPtr[i] = arrayPointer1[i];

    for ( j = 0; i < sizeOfMergedArray ; i++, j++)
        mergedArrayPtr[i] = arrayPointer2[j];

    return mergedArrayPtr;
}