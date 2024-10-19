#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput( int *, int );
void arrayDisplay(int *, int );
void partitionFirstValue(int *, int );

int main()
{
    int size, i;
    printf("Enter the size for the array -\n");
    validInputCheck(&size, 0);

    int numbers[size];

    arrayInput(numbers, size);

    printf("The entered array is -\n");
    arrayDisplay(numbers, size);

    partitionFirstValue(numbers, size);

    printf("\nThe modified array is -\n");
    arrayDisplay(numbers, size);

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
//$ Better Partition logic with No Extra Space and O(n)
void partitionFirstValue(int *pnumbers, int size)
{
    int left = 1, right = size - 1;
    int pivot = pnumbers[0];
    
    //$ Partitioning the array using two-pointer technique
    while( left <= right )
    {
        //$ Move the left pointer to the right until a value larger than the pivot is found
        while ( left <= right && pnumbers[left] < pivot )
            left++;

        //$ Move the right pointer to the left until a value smaller than the pivot is found
        while ( left <= right && pnumbers[right] >= pivot)
            right--;

        //$ If the left pointer is still smaller than the right pointer, swap the values
        if ( left < right )
        {
            int temp = pnumbers[left];
            pnumbers[left] = pnumbers[right];
            pnumbers[right] = temp;
            left++;
            right--;
        }
    }

    //$ Finally, place the pivot element in its correct position
    pnumbers[0] = pnumbers[right];
    pnumbers[right] = pivot;
    
}

