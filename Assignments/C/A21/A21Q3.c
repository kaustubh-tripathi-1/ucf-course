#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
int checkEven(int);

int main()
{
    int num;
    printf("Enter a number to check for Even or Odd :\n");
    validInputCheck(&num, 1);
    
    if(checkEven(num))
        printf("%d is Even.", num);
    else
        printf("%d is Odd.", num);
    
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

        if(validInput == 1 && (allowNegative || *n >= 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Check for Even Number
int checkEven(int n)
{
    return n % 2 == 0;
}