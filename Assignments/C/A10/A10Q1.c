#include <stdio.h>
#include <conio.h>

int main()
{
    int num;
    printf("Enter a number to check for +ve, -ve or 0 :\n");
    while (scanf("%d", &num) != 1)
    {
        while (getchar() != '\n');
        printf("Enter a valid number!!\n");
    }

    if (num > 0)
        printf("%d is a positive number.", num);
    else if (num < 0)
        printf("%d is a negative number.", num);
    else
        printf("Number is 0.", num);

    getch();
    return 0;
}