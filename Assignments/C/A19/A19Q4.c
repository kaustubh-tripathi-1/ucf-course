#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheckChoice(int *);
void validInputCheckSides(double *, double *, double *);
void checkIsosceles(double, double, double);
void checkRightAngled(double, double, double);
void checkEquilateral(double, double, double);
int isValidTriangle(double , double , double );

// @ Main Driver Code
int main()
{
    int choice;
    double side1, side2, side3;


    while(1)
    {
        printf("Enter your choice:\n");
        printf("1. Check for Isosceles Triangle\n");
        printf("2. Check for Right Angled Triangle\n");
        printf("3. Check for Equilateral Triangle\n");
        printf("4. Exit\n");
        validInputCheckChoice(&choice);
        
        switch(choice)
        {
            case 1:
            {
                printf("Enter 3 sides of a triangle to check for Isosceles :\n");
                validInputCheckSides(&side1, &side2, &side3);

                if(isValidTriangle(side1, side2, side3))
                    checkIsosceles(side1, side2, side3);
                else
                    printf("The sides do not form a valid triangle.\n");

                break;
            }
            case 2:
            {
                printf("Enter 3 sides of a triangle to check for Right Angled :\n");
                validInputCheckSides(&side1, &side2, &side3);

                if(isValidTriangle(side1, side2, side3))
                    checkRightAngled(side1, side2, side3);
                else
                    printf("The sides do not form a valid triangle.\n");
                
                break;
            }
            case 3:
            {
                printf("Enter 3 sides of a triangle to check for Equilateral :\n");
                validInputCheckSides(&side1, &side2, &side3);

                if(isValidTriangle(side1, side2, side3))
                    checkEquilateral(side1, side2, side3);
                else
                    printf("The sides do not form a valid triangle.\n");

                break;
            }
            case 4:
                exit(0);
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

//@ Valid Input Checking of Sides
void validInputCheckSides(double *s1,double *s2, double *s3)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%lf%lf%lf", s1, s2, s3);

        if (validInput == 3 && *s1 > 0 && *s2 > 0 && *s3 > 0)
            break;
        else
        {
            printf("Invalid input! Please enter a valid number for sides.\n");
            while( getchar() != '\n');
        }
    }
}

//@ Checking of Valid Triangle
int isValidTriangle(double s1, double s2, double s3)
{
    return (s1 + s2 > s3) && (s2 + s3 > s1) && (s1 + s3 > s2);
}

//@ Checking of Isosceles
void checkIsosceles(double side1, double side2, double side3)
{
    if( (side1==side2 && side1!=side3) || ( side2==side3 && side3!=side1 ) || ( side1==side3 && side1!=side2 ))
        printf("The triangle is Isosceles.\n");
    else
        printf("The triangle is not Isosceles.\n");
}

//@ Checking of Right Angled
void checkRightAngled(double side1, double side2, double side3)
{
    if( (side1*side1 == (side2*side2) + (side3*side3)) || (side2*side2 == (side1*side1) + (side3*side3)) || (side3*side3 == (side1*side1) + (side2*side2)) )
        printf("The triangle is Right Angled.\n");
    else
        printf("The triangle is not Right Angled.\n");
}

//@ Checking of Equilateral
void checkEquilateral(double side1, double side2, double side3)
{
    if( side1==side2 && side2==side3 )
        printf("The triangle is Equilateral.\n");
    else
        printf("The triangle is not Equilateral.\n");
}