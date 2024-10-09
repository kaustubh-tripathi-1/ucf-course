#include<stdio.h>
#include<conio.h>

int main()
{
    int a;
    printf("Enter a number to print it's last digit :\n");
    if(scanf("%d", &a)!=1)
    {
        printf("Enter valid input.");
        return 1;
    }
    printf("The last digit of %d is %d\n",a, a%10);
    getch();
    return 0;
}