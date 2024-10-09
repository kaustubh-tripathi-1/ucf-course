#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int );
int firstOccurence(int [] , int, int *);

int main()
{
    int size;
    printf("Enter the size of the array :\n");
    validInputCheck(&size, 0);

    int numbers[size];
    int duplicateElement, present=0;

    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter %d values to find the largest:\n", size);

    arrayInput(numbers, size);

    duplicateElement = firstOccurence( numbers, size , &present);

    if( present != 0 )
        printf("The first adjacent duplicate element in the array is %d.", duplicateElement);
    else
        printf("There are no adjacent duplicate elements in the array.");
    
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

//@ Array Input
void arrayInput(int a[] , int size)
{
    for( int i = 0; i < size ; i++)
    {
        printf("\nEnter %d value :  ", i+1);
        validInputCheck(&a[i], 1);
    }
}

//@ First Occurence of Duplicate Values in Array 
int firstOccurence(int a[], int size, int *present)
{
    int i;
    for( i = 0 ; i < size-1 ; i++)
    {
        if( a[i] == a[i+1] )
        {
            *present = 1;
            return a[i];
        }
    }
    return -1;
}



