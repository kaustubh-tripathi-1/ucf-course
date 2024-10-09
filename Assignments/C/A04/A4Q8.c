#include<stdio.h>
#include<conio.h>

int main()
{
    int a, b;
    printf("Enter values of a & b :\n");
    if(scanf("%d%d", &a, &b)!=2)
    {
        printf("Enter valid integer numbers next time!!");
        return 1;
    }
    printf("Before swapping, Value of a = %d & value of b = %d.\n", a, b);
    b = (a+b) - (a=b);
    /* b = (a*b) / (a=b);   //Using * and /
    b = (a^b) ^ (a=b); //Using XOR */    
    printf("After swapping, Value of a = %d & value of b = %d.\n", a, b);
    getch();
    return 0;
}