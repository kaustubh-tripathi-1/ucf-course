#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int );
void copyArray(int [] , int [], int, int);

int main()
{
    int size1, size2, numbers[10], num_copy[10];
    size1 = sizeof(numbers)/sizeof(numbers[0]);
    size2 = sizeof(num_copy)/sizeof(num_copy[0]);
    
    printf("Enter 10 values to copy them:\n");

    arrayInput( numbers, size1 );

    printf("This is the Original array -\n");
    for (int i = 0; i < size1; i++)
    {
        printf("%d ", numbers[i]);
    }

    copyArray( numbers, num_copy, size1, size2 );

    printf("\nHere's copied array -\n");
    for (int i = 0; i < size2; i++)
    {
        printf("%d ", num_copy[i]);
    }
    
    
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

//@ Copying the Array 
void copyArray(int a[], int b[], int size1, int size2)
{
    int i;

    for( i = 0 ; i < size1 && i < size2 ; i++ )
    {
        b[i] = a[i];
    }   
}