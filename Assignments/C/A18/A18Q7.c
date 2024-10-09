#include<stdio.h>
#include<conio.h>

void validInputCheck(int *);

int main()
{
    int i, j, rows, columns, lines, k, l;
    printf("Enter how many lines you want to print -\n");

    validInputCheck(&lines);

    rows = lines;
    columns = 2*lines-1;

    printf("\n\n");

    for ( i = 1; i <= rows; i++)
    {
        l=1;
        for ( j = 1; j <= columns; j++)
        {
            if ( j>= ((lines+1)-i) &&  j<= ((lines-1)+i) && k )
            {
                printf("%d ", l);
                k=0;
                j<lines?l++:l--;
            }
            else
            {
                printf("  ");
                k=1;
                if(j==lines)
                    l--;
            }
        }
        printf("\n");
    }
    

    getch();
    return 0;
}

//@ Valid Input Checking 
void validInputCheck(int *n)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d", n);

        if (validInput == 1 && *n>=0)
            break;
        else
        {
            printf("Invalid input! Please enter a valid positive integer.\n");
            while( getchar() != '\n');
        }
    }

}