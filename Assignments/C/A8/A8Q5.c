#include<stdio.h>
#include<conio.h>

int main()
{
    int i, num1, num2, num3;
    printf("Enter 2 numbers to check which is greater -\n");
    while( scanf("%d%d%d", &num1, &num2, &num3) != 3)
    {
        while(getchar() != '\n');
        printf("Enter a valid number!!\n");
    }
    if(num1 > num2 && num1 > num3)
        printf("%d is greatest.", num1);
    else if(num2 > num3)
        printf("%d is greatest.", num2);
    else
        printf("%d is greatest.", num3);
    getch();
    return 0;
}