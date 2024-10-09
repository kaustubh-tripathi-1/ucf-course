#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
int countDuplicateElements(int [], int);

int main()
{
    int count, numbers[] = {1, 2, 1, 1, 2, 5, 4, 3, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    count = countDuplicateElements( numbers, size );

    printf("The array is -\n");

    for( int i=0 ; i < size ; i++)
        printf("%d ", numbers[i]);

    printf("The number of duplicate elements that occur exactly twice in the array are %d.\n", count);

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

//@ Counting No. of Duplicate Array Elements that occur exactly twice

int countDuplicateElements(int a[], int size)
{
    int i, j, count=0, occurence, processed[size];

    for( i=0 ; i<size ; i++)
        processed[i]=0;

    for( i = 0 ; i < size ; i++)
    {
        if( processed[i]==1 )
            continue;
        
        occurence = 0;
        for( j = i+1 ; j < size ; j++)
        {
            if ( a[i] == a[j] )
            {
                occurence++;
                processed[j] = 1;
            }
        }
        if(occurence == 1)
            count++;
    }

    return count;
}