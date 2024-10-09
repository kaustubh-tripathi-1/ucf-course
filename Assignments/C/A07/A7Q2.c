#include<stdio.h>
#include<conio.h>

int main()
{
    int num;
    printf("Enter a number to check if it's divisible by 5 :\n");
    while(scanf("%d", &num) != 1)
    {
        while ( getchar() != '\n' );
        printf("Enter a valid number!!\n");
    }
    if(num%5==0) // or if(num%5), remainder will be 1, 2, 3, 4 if not divisible, which is true, 0 (false) else, which is divisible
        printf("%d is divisible by 5", num);
    else
        printf("%d is not divisible by 5", num); 

    getch();
    return 0;
}