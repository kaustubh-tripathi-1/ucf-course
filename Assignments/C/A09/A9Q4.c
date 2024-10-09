#include<stdio.h>
#include<conio.h>

int main()
{
    int num;
    printf("Enter a number to check for divisibility by 3 AND 2 :\n");
    while( scanf("%d", &num) != 1)
    {
        while( getchar() != '\n');
        printf("Enter only valid numbers!!\n");
    }

    if( (num%2==0) && (num%3==0) )
        printf("%d is divisible by both 3 and 2.", num);
    else
        printf("%d is not divisible by both 3 and 2.", num);
    
    getch();
    return 0;
}