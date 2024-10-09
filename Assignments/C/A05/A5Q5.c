#include<stdio.h>
#include<conio.h>

int main()
{
    int num, digit, result;
    printf("Enter a number :\n");
    if(scanf("%d", &num)!=1)
    {
        printf("You didn't enter a valid number!!");
        return 1;
    }
    printf("Enter a digit to append to the previously entered number :\n");
    if(scanf("%d", &digit)!=1)
    {
        printf("You didn't enter a valid number!!");
        return 1;
    }
    result = num*10 + digit;
    printf("%d with the last digit as 0 is %d.", num , result);
    getch();
    return 0;
}