#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
void printFirstNN(int);

int main()
{
    int n;
    printf("Enter the no. of first Natural Numbers you want to print :\n");
    validInputCheck(&n, 0);

    printf("\n");
    printFirstNN(n);
    
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

//@ Print First N Natural Numbers
void printFirstNN(int n)
{
    for( int i=1 ; i<=n ; i++)
    {
        printf("%d  ", i);
    }
} 