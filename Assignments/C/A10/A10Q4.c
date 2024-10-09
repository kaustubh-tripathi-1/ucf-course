#include<stdio.h>
#include<conio.h>

int main()
{
    int month, validInput;
    printf("Enter month number to display number of days : \n");

    while(1)
    {
        validInput = scanf("%d", &month);

        if(validInput == 1 && ( month>=1 && month<=12 ))
            break;
        else
        {
            printf("Enter valid month number\n");
            while( getchar() != '\n');
        }
    }

    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        printf("This month has 31 days.");
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        printf("This month has 30 days.");
    else
        printf("This month has 29 days.");

    getch();
    return 0;
}