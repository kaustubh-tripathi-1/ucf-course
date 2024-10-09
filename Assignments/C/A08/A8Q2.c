#include<stdio.h>
#include<conio.h>

int main()
{
    int i, num1, num2;
    printf("Enter 2 numbers to check which is greater -\n");
    while( scanf("%d%d", &num1, &num2) != 2)
    {
        while(getchar() != '\n');
        printf("Enter a valid number!!\n");
    }
    if(num1>num2)
        printf("%d is greater.", num1);
    else if(num2>num1)
        printf("%d is greater.", num2);
    else
        printf("Both are same. %d", num1);
    getch();
    return 0;
}