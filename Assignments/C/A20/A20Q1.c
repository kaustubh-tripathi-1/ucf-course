#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputMarks(int *);

int main()
{
    int marks;

    printf("Enter your marks to display the corresponding grade :\n");
    validInputMarks(&marks);

    switch(marks)
    {
        case 0 ... 49:
            printf("Your Grade is F.\n");
            break;
        case 50 ... 59:
            printf("Your Grade is E.\n");
            break;
        case 60 ... 69:
            printf("Your Grade is D.\n");
            break;
        case 70 ... 79:
            printf("Your Grade is C.\n");
            break;
        case 80 ... 89:
            printf("Your Grade is B.\n");
            break;
        case 90 ... 100:
            printf("Your Grade is A.\n");
            break;
        
        default:
            printf("Invalid Marks.\n");
    }
    
    getch();
    return 0;
}

//@ Valid Input Checking of Marks
void validInputMarks(int *n)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d", n);

        if (validInput == 1 )
            break;
        else
        {
            printf("Invalid input! Please enter marks between 0 and 100.\n");
            while( getchar() != '\n');
        }
    }

}
