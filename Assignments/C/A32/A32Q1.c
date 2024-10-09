#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
void arrayInput(int [] , int );
void swapElements(int [], int, int,int);

int main()
{
    int size;
    printf("Enter the size of the array -\n");
    validInputCheck(&size, 0);

    int index1, index2, numbers[size];

    arrayInput(numbers, size);
    
    size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Enter the index 1 and index 2 for which you want to swap the values in array :\n");
    validInputCheck(&index1, 0);
    validInputCheck(&index2, 0);
    
    if( index1 >=0 && index1<size && index2>=0 && index2<size )
        swapElements( numbers, size, index1, index2 );
    else
    {
        printf("You entered a wrong index.");
        return 1;
    }
    
    printf("The array with swapped values is -\n");

    for( int i=0 ; i < size ; i++)
        printf("%d ", numbers[i]);

    getch();
    return 0;
}

//@ Valid Input & Check
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if( validInput == 1 && ( allowNegative || *n > 0))
            break;

        else
        {
            printf("Enter valid index!\n");
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

//@ Swapping Array Elements

void swapElements(int a[], int size, int index1, int index2)
{
    int temp;

    temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}