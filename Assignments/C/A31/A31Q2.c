#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int );
int findSmallest(int [] , int);

int main()
{
    int size;
    printf("Enter the size of the array :\n");
    validInputCheck(&size, 0);

    int numbers[size];
    int smallestElement;

    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter %d values to find the smallest:\n", size);

    arrayInput(numbers, size);

    smallestElement = findSmallest( numbers, size );

    printf("The smallest element in the array is %d.", smallestElement);
    
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

//@ Find Smallest Element in Array 
int findSmallest(int a[], int size)
{

    int smallest = a[0];
    for(int i=1 ; i < size ; i++ )
        if( smallest > a[i] )
            smallest = a[i];
    
    return smallest;
}

