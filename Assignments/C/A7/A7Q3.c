#include<stdio.h>
#include<conio.h>

int main()
{
    int num;
    printf("Enter a number to check if it's even or odd :\n");
    while(scanf("%d", &num) != 1)
    {
        while ( getchar() != '\n');
        printf("Enter a valid number!!\n");
    }
    if(num%2==0)
        printf("%d is Even.", num);
    else
        printf("%d is Odd.", num); 

    getch();
    return 0;
}