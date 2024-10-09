#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned long long int a, b;
    printf("Enter 2 numbers to calculate their sum :\n");
    scanf("%llu%llu", &a, &b);
    printf("The sum of %llu and %llu is %llu", a, b, a+b);
    getch();
    return 0;
}

