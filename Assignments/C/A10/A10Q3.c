#include<stdio.h>
#include<conio.h>

int main()
{
    double a, b, c;
    int validInput = 0;
    printf("Enter 3 sides of a triangle :\n");

    while( 1 )
    {
        validInput = ("%lf%lf%lf", &a, &b, &c);
        if(validInput == 3)
            break;
        else
        {
            printf("Enter valid numbers!!\n");
            while( getchar() != '\n');
        }
    }

    if((a+b > c) && (b+c > a) && (a+c > b) )
        printf("Triangle is valid.");
    else
        printf("Triangle is not valid.");

    getch();
    return 0;
}