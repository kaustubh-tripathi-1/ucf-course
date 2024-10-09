#include<stdio.h>
#include<conio.h>

int main()
{
    int i, num;
    printf("Enter a number to check if it's 3 digit or not -\n");
    while( scanf("%d", &num) != 1)
    {
        while(getchar() != '\n');
        printf("Enter a valid number!!\n");
    }
    if( (num >= 100 && num<=999) || (num <= -100 && num>= -999) )
        printf("%d is a 3 digit number.", num);
    else
        printf("%d is not a 3 digit number.", num);
    getch();
    return 0;
}