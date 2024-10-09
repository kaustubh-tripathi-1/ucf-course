#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int );
void sortArray(int [] , int);

int main()
{
    int size;
    printf("Enter the size of the array :\n");
    validInputCheck(&size, 0);

    int numbers[size];

    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter %d values to sort them :\n", size);

    arrayInput( numbers, size );

    printf("This is the Original array -\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }

    sortArray( numbers, size );

    printf("\nHere's the sorted array -\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
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

//@ Sorting the Array 
void sortArray(int a[], int size)
{
    int i, temp, j;

    for( i = 0 ; i < size ; i++ )
    {
        for( j=0 ; j < size-i-1 ; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }   
}