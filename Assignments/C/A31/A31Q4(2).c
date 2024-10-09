#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void validInputCheckChar(char *);
void arrayInput(int [] , int );
void reverseArray(int [], int, int);
void rotateRight(int [] , int, int);
void rotateLeft(int [] , int, int);


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

    if(direction == 'r' || direction == 'R')
        rotateRight( numbers, size, position);
    else
        rotateLeft(numbers, size, position);

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

//@ Reversing the array
void reverseArray(int reverseArray[], int start, int end)
{
    int temp;
    while(start<end)
    {
        temp = reverseArray[start];
        reverseArray[start] = reverseArray[end];
        reverseArray[end] = temp;
        start++;
        end--;
    }
}

//@ Rotating the Array Right
void rotateRight(int rotated[], int size, int position)
{
    reverseArray(rotated, 0, size-1);  //$ Reversing the whole Array
    reverseArray(rotated, 0, size-position-1);  //$ Reversing the first k(positions) elements of the array
    reverseArray(rotated, size-position-1, size-1);  //$ Reversing the rest of the array
}

//@ Rotating the Array Left
void rotateLeft(int rotated[], int size, int position)
{
    reverseArray(rotated, 0, size-1);  //$ Reversing the whole Array
    reverseArray(rotated, 0, position-1);  //$ Reversing the first k(positions) elements of the array
    reverseArray(rotated, position, size-1);  //$ Reversing the rest of the array
}