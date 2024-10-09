#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
void printUnique(int [], int);

int main()
{
    int unique, numbers[] = {1, 2, 1, 1, 2, 5, 4, 3, 3, 45, 1, 3, 45, 7, 8, 7};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("The array is -\n");

    for( int i=0 ; i < size ; i++)
        printf("%d ", numbers[i]);

    printf("Unique Elements in the array are -\n");
    printUnique( numbers, size );

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

//@ Counting Unique Array Elements

void printUnique(int a[], int size)
{
    int i, j, uniqueCount=0, unique[size];

    for( i=0 ; i < size ; i++)
    {
        for( j=0 ; j < uniqueCount ; j++)
        {
            if( a[i] == unique[j])
                break;
        }

        if( j == uniqueCount )
        {
            unique[uniqueCount] = a[i];
            uniqueCount++;
            printf("%d ", a[i]);
        }
    }
}