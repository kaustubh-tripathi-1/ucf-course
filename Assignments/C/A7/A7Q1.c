#include<stdio.h>
#include<conio.h>

int main()
{
    int num, result;
    printf("Enter a number to check for positive or non - positive :\n");
    while(scanf("%d", &num) != 1)
    {
        while(getchar() != '\n');
        printf("Enter a valid number!!\n");
    }
    if(num<=0)
        printf("%d is non-positive", num);
    else
        printf("%d is positive", num); 

    getch();
    return 0;
}