#include<stdio.h>
#include<conio.h>

int main()
{
    int a;
    printf("Enter a number to remove it's last digit :\n");
    if(scanf("%d", &a)!=1)
    {
        printf("Enter valid input.");
        return 1;
    }
    printf("%d without the last digit is %d\n",a, a/10);
    getch();
    return 0;
}