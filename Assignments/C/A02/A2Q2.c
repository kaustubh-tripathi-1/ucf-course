#include<stdio.h>
#include<conio.h>
#define PI 3.1428

int main()
{
    double r;
    printf("Enter radius of circle to calculate the circumference :\n");
    scanf("%lf", &r);
    while(r<0)
    {
        printf("Radius of circle can't be negative!! Enter again :\n");
        scanf("%lf", &r);
    }
    printf("The circumference of circle with radius %lf is %lf", r, 2*PI*r);
    getch();
    return 0;
}

