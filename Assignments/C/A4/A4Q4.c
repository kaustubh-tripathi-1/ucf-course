#include<stdio.h>
#include<conio.h>

int main()
{
    int a,b, temp;
    printf("Enter values of a & b :\n");
    if(scanf("%d%d", &a, &b)!=2)
    {
        printf("Enter valid integer numbers next time!!");
        return 1;
    }
    printf("Before swapping, Value of a = %d & value of b = %d.\n", a, b);
    temp = a;
    a=b;
    b=temp;
    printf("After swapping, Value of a = %d & value of b = %d.\n", a, b);
    getch();
    return 0;
}