#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
int countDuplicateElements(int [], int);

int main()
{
    int count, numbers[] = {1, 1, 2, 3, 1, 4, 2, 5, 3, 6, 7, 1, 1, 1, 1};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    count = countDuplicateElements( numbers, size );

    printf("The array is -\n");

    for( int i=0 ; i < size ; i++)
        printf("%d ", numbers[i]);

    printf("\nThe number of duplicate elements that occur more than once in the array are %d.\n", count);

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

//@ Counting No. of Duplicate Array Elements

int countDuplicateElements(int a[], int size)
{
    /* //$ Using Extra Space
    int i, j, count=0, visited[size];

    for( i = 0 ; i < size ; i++ )
        visited[i] = 0;
    
    for( i = 0 ; i < size ; i++)
    {
        if( visited[i] == 1)
            continue;

        for( j = i+1 ; j < size ; j++)
        {
            if ( a[i] == a[j] ) 
            {
                count++;
                visited[j] = 1;
                break;
            }
        }
    } */

   //$ W/O Using Extra Space

   int i, j, count = 0;

    for( i = 0 ; i < size ; i++)
    {
        int isDuplicate = 0, alreadyCounted = 0;

        //$ Check if the current element has appeared before in the array
        for ( j = 0; j < i; j++) 
        {
            if (a[i] == a[j])
            {
                alreadyCounted = 1;  //$ Already counted this element as a duplicate before
                break;
            }
        }

        if (alreadyCounted) 
            continue; //$ Skip if already counted

        //$ Check for any duplicate of the current element ahead in the array
        for ( j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                isDuplicate = 1;  //$ Found a duplicate
                break;
            }
        }

        //$ If it's a distinct duplicate, increase the count
        if (isDuplicate)
            count++;
    }

    return count;
}