#include<stdio.h>
#include<conio.h>

int main()
{
    int num, result;
    printf("Enter a number to make the last digit in that number 0 :\n");
    if(scanf("%d", &num)!=1)
    {
        printf("You didn't enter a valid number!!");
        return 1;
    }
    result = num - num%10;
    printf("%d with the last digit as 0 is %d.", num , result);
    getch();
    return 0;
}