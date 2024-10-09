#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheckDay(int *);

int main()
{
    int dayNumber;

    printf("Enter the day number of the week to display a unique message :\n");
    validInputCheckDay(&dayNumber);

    switch(dayNumber)
    {
        case 1:
            printf("Motivational Monday! Start your week strong! Let us conquer Monday with a fresh mindset and unstoppable energy.\n");
            break;
        case 2:
            printf("Terrific Tuesday! It is Tuesday! Keep the momentum going—small steps today lead to big successes tomorrow.\n");
            break;
        case 3:
            printf("Winning Wednesday! Welcome to Wednesday! You are halfway there—stay focused and let the midweek magic happen.\n");
            break;
        case 4:
            printf("Thrilling Thursday! Happy Thursday! The weekend is just around the corner. Keep pushing forward and finish the week strong.\n");
            break;
        case 5:
            printf("Fantastic Friday! It is finally Friday! Celebrate the end of the week with positivity and enthusiasm for what is ahead.\n");
            break;
        case 6:
            printf("Sunny Saturday! Saturday vibes are here! Relax, recharge, and enjoy the freedom of the weekend.\n");
            break;
        case 7:
            printf("Serene Sunday! Sunday is a day of rest and reflection. Take time for yourself, and prepare for a great week ahead.\n");
            break;
        default:
            printf("Invalid Day Number in a Week. Please run the program again.\n");
    }
    
    getch();
    return 0;
}

//@ Valid Input Checking of Day Number
void validInputCheckDay(int *n)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d", n);

        if (validInput == 1 )
            break;
        else
        {
            printf("Invalid input! Please enter a valid number.\n");
            while( getchar() != '\n');
        }
    }

}
