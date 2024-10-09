#include<stdio.h>
#include<conio.h>

int main()
{
    /* double a;
    printf("Enter a real constant to know it's size :\n");
    if(scanf("%lf", &a)!=1)
    {
        printf("Enter valid input.");
        return 1;
    } */
    printf("The size is %zu\n", sizeof(3.8));
    getch();
    return 0;
}