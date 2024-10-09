#include<stdio.h>
#include<conio.h>

int main()
{
    int var;
    printf("Enter a value :\n");
    scanf("%d", &var);

    switch (var)
    {
    case 1:
        printf("good");
        break;
    case 2:
        printf("better");
        break;
    case 3:
        printf("best");
        break;
    default:
        printf("invalid");
        break;
    }
    
    getch();
    return 0;
}