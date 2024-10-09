#include<stdio.h>
#include<conio.h>

int main()
{
    double a;
    printf("Enter a numbers to calculate its square :\n");
    scanf("%lf", &a);
    printf("The square of %.0lf is %.0lf", a, a*a);
    getch();
    return 0;
}

