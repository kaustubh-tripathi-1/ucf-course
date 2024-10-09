#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int);
int arrayOddSum(int [], int);
int arrayEvenSum(int [], int);

int main()
{
    int numbers[10], size, sumOdd, sumEven;
    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter 10 values to calculate sum of even and odd numbers :\n");

    arrayInput(numbers, size);

    sumOdd = arrayOddSum( numbers, size);
    sumEven = arrayEvenSum( numbers, size);

    printf("The sum of Odd array elements is %d.\n", sumOdd);
    printf("The sum of Even array elements is %d.\n", sumEven);
    
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
        validInputCheck(&a[i], 1);
    }
}

//@ Sum of Odd of Array Elements
int arrayOddSum(int a[], int size)
{
    int sumOdd=0;
    for(int i=0 ; i < size ; i++ )
    {
        if( a[i] % 2 != 0 )
            sumOdd += a[i];
    }
    
    return sumOdd;
}

//@ Sum of Even of Array Elements
int arrayEvenSum(int a[], int size)
{
    int sumEven=0;
    for(int i=0 ; i < size ; i++ )
    {
        if( a[i] % 2 == 0 )
            sumEven += a[i];
    }
    
    return sumEven;
}

