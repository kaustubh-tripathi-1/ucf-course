#include<stdio.h>
#include<conio.h>

int main()
{
    double l, b;
    printf("Enter length and breadth of a rectangle to calculate its area :\n");
    scanf("%lf%lf", &l, &b);
    while(l<0 || b<0)
    {
        printf("Length and Breadth of a rectangle can't be negative, enter positive values only :\n");
        scanf("%lf%lf", &l, &b);
    }
    printf("The area of rectangle is %lf\n", l*b);
    getch();
    return 0;
}

