#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *);

int main()
{
    int month;

    while(1)
    {
        printf("Enter the month number to know the number of days in it or Enter 0 to exit the program :\n");
        validInputCheck(&month);

        switch(month)
        {
            case 0:
                exit(0);
            case 1:
                printf("January has 31 days.\n");
                break;
            case 2:
                printf("February has 28/29 days.\n");
                break;
            case 3:
                printf("March has 31 days.\n");
                break;
            case 4:
                printf("April has 30 days.\n");
                break;
            case 5:
                printf("May has 31 days.\n");
                break;
            case 6:
                printf("June has 30 days.\n");
                break;
            case 7:
                printf("July has 31 days.\n");
                break;
            case 8:
                printf("August has 31 days.\n");
                break;
            case 9:
                printf("September has 30 days.\n");
                break;
            case 10:
                printf("October has 31 days.\n");
                break;
            case 11:
                printf("November has 30 days.\n");
                break;
            case 12:
                printf("December has 31 days.\n");
                break;
            default:
                printf("Invalid Choice. Please enter again.\n");
        }
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