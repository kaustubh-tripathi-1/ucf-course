#include<stdio.h>
#include<conio.h>
#define PI 3.14

int main()
{
    double r;
    printf("Enter radius of a circle to calculate its area :\n");
    scanf("%lf", &r);
    while(r<0)
    {
        printf("Radius of a circle can't be negative, enter positive value only :\n");
        scanf("%lf", &r);
    }
    printf("The area of circle is %lf", PI*r*r);
    getch();
    return 0;
}

