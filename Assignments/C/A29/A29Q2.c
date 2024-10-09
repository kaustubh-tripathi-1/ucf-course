#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void arrayInput(int [] , int);
double arrayAverage(int [], int);

int main()
{
    int numbers[10], size;
    double average;
    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter 10 values to calculate their average :\n");

    arrayInput(numbers, size);

    average = arrayAverage( numbers, size);

    printf("The sum of array elements is %.2lf.", average);
    
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

//@ Average of Array Elements
double arrayAverage(int a[], int size)
{
    int sum=0, average;
    for(int i=0 ; i < size ; i++ )
        sum += a[i];

    average = sum/size;
    
    return average;
}

