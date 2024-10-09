#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void validInputCheckChar(char *);
void arrayInput(int [] , int );
void rotateArray(int [] , int, int , char);


//@ Driver Main Code
int main()
{
    int size, position;
    char direction;
    printf("Enter the size of the array :\n");
    validInputCheck(&size, 0);

    int numbers[size];

    size = sizeof(numbers)/sizeof(numbers[0]);
    
    printf("Enter %d values to rotate them :\n", size);

    arrayInput( numbers, size );

    printf("This is the Original array -\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }

    printf("\nEnter by how many positions you want to rotate the array :\n");
    validInputCheck(&position, 0);

    position = position%size;
    while( getchar() != '\n');

    printf("Enter the direction in which you want to rotate the array - left(l) or right(r) :\n");
    validInputCheckChar(&direction);

    rotateArray( numbers, size, position, direction );

    printf("\nHere's the rotated array -\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    
    getch();
    return 0;
}

//@ Valid Input Check Integer
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

//@ Valid Input Check Character
void validInputCheckChar(char *n)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%c", n);

        if(validInput == 1 && (*n == 'l' || *n == 'r' || *n == 'L' || *n == 'R'))
            break;
        else
        {
            printf("Enter a valid direction!\n");
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

//@ Rotating the Array 
void rotateArray(int rotated[], int size, int position, char direction)
{
    int i, j, temp;
    if(direction == 'r' || direction == 'R')
    {
        for( i = 0 ; i < position ; i++)
        {
            temp = rotated[size-1];
            for ( j = size-2 ; j >= 0 ; j-- )
            {
                rotated[j+1] = rotated[j];
            }
            rotated[0] = temp;
        }
    }
    else
    {
        for( i = 0 ; i < position ; i++)
        {
            temp = rotated[0];
            for ( j = 0 ; j < size-1 ; j++ )
            {
                rotated[j] = rotated[j+1];
            }
            rotated[size-1] = temp;
        }
    }
}