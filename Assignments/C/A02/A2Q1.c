#include<stdio.h>
#include<conio.h>

int main()
{
    int a, b, c;
    printf("Enter 3 integers to calculate their average :\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("The average of the integers entered by you is %lf", (a+b+c)/3.0);
    getch();
    return 0;
}

