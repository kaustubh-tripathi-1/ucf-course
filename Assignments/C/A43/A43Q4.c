#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput( int *, int );
void arrayDisplay(int *, int );
void partitionFirstValue(int *, int *, int );

int main()
{
    int size, i;
    printf("Enter the size for the array -\n");
    validInputCheck(&size, 0);

    int numbers1[size], numbers2[size];

    arrayInput(numbers1, size);

    for ( i = 0 ; i < size ; i++)
        numbers2[i] = 0;

    printf("The entered array is -\n");
    arrayDisplay(numbers1, size);

    partitionFirstValue(numbers1, numbers2, size);

    printf("\nThe modified array is -\n");
    arrayDisplay(numbers2, size);

    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n >= 0 )))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Function for Array Input
void arrayInput( int *pArr, int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        printf("Enter %d value -\n", i+1);
        validInputCheck(&pArr[i], 1);
    }
}

void arrayDisplay(int * pArr, int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        printf("%d ", pArr[i]);
    }
}

//@ Function to move first value to its right position
//$ My logic with Extra Space and O(n^2)
void partitionFirstValue(int *pnumbers1, int *pnumbers2, int size)
{
    int i, j;
    int firstValue = pnumbers1[0];
    pnumbers2[0] = firstValue;

    for ( i = 1, j = 1 ; i < size ; i++)
    {
        if ( (pnumbers1[i] > firstValue || pnumbers1[i] == firstValue))
        {
            pnumbers2[j] = pnumbers1[i];
            j++;
        }
        else if ( pnumbers1[i] < firstValue )
        {
            int k = j;
            while ( k > 0 )
            {
                pnumbers2[k] = pnumbers2[k - 1];
                k--;
            }
            pnumbers2[k] = pnumbers1[i];
            j++;
        }
    }
    
}

