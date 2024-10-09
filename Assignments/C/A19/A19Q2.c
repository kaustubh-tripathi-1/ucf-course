#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheckChoice(int *);
void validInputCheckNumbers(double *, double *);

int main()
{
    int choice;
    double num1, num2;

    while(1)
    {
        printf("Enter you choice\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        validInputCheckChoice(&choice);

        switch(choice)
        {
            case 5:
                exit(0);
            case 1:
            {
                printf("Enter 2 numbers to perform Addition :\n");
                validInputCheckNumbers(&num1, &num2);
                printf("The Sum of %.2lf & %.2lf is %.2lf.\n", num1, num2, num1+num2);
                break;
            }
            case 2:
            {
                printf("Enter 2 numbers to perform Subtraction :\n");
                validInputCheckNumbers(&num1, &num2);
                printf("The Difference of %.2lf & %.2lf is %.2lf.\n", num1, num2, num1-num2);
                break;
            }
            case 3:
            {
                printf("Enter 2 numbers to perform Multiplication :\n");
                validInputCheckNumbers(&num1, &num2);
                printf("The Product of %.2lf & %.2lf is %.2lf.\n", num1, num2, num1*num2);
                break;
            }
            case 4:
            {
                printf("Enter 2 numbers to perform Division :\n");
                validInputCheckNumbers(&num1, &num2);
                if(num2!=0)
                    printf("The Quotient of %.2lf & %.2lf is %.2lf.\n", num1, num2, num1/num2);
                else
                    printf("Error: Division by zero is not allowed.\n");
                break;
            }
            default:
                printf("Invalid Choice. Please enter again.\n");
                break;
        }
    }
    
    getch();
    return 0;
}

//@ Valid Input Checking of Choice
void validInputCheckChoice(int *n)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d", n);

        if (validInput == 1 && *n>0)
            break;
        else
        {
            printf("Invalid input! Please enter a valid positive integer.\n");
            while( getchar() != '\n');
        }
    }

}
//@ Valid Input Checking of Numbers
void validInputCheckNumbers(double *n1, double *n2)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%lf%lf", n1, n2);

        if (validInput == 2)
            break;
        else
        {
            printf("Invalid input! Please enter a valid numbers.\n");
            while( getchar() != '\n');
        }
    }

}