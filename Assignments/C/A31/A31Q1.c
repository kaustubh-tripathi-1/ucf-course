#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int );
int findLargest(int [] , int);

int main()
{
    int size;
    printf("Enter the size of the array :\n");
    validInputCheck(&size, 0);

    int numbers[size];
    int largestElement;

    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter %d values to find the largest:\n", size);

    arrayInput(numbers, size);

    largestElement = findLargest( numbers, size );

    printf("The largest element in the array is %d.", largestElement);
    
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

//@ Find Largest Element in Array 
int findLargest(int a[], int size)
{

    int largest = a[0];
    for(int i=1 ; i < size ; i++ )
        if( largest < a[i] )
            largest = a[i];
    
    return largest;
}

