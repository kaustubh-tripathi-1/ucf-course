#include<stdio.h>
#include<conio.h>
#define PI 3.1428

void validInputCheck(double *);
double circleArea(double);

int main()
{
    double r, area;
    printf("Enter the radius of circle to calculate the area - \n");
    validInputCheck(&r);

    area = circleArea(r);

    printf("The area of circle with radius %.2lf is %.2lf.\n", r, area);
    
    getch();
    return 0;
}

//@ Valid Input Check
void validInputCheck(double *r)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%lf", r);

        if(validInput == 1 && *r >= 0)
            break;
        else
        {
            printf("Enter a valid number for radius!\n");
            while( getchar() != '\n');
        }
    }
    
}

//@ Area of Circle
double circleArea(double r)
{
    return PI * r * r;
}