#include<stdio.h>
#include<conio.h>

int main()
{
    char c;
    printf("Enter a character to know it's ASCII Code :\n");
    scanf("%c", &c);
    printf("The ASCII Code of %c is %d", c, c);
    getch();
    return 0;
}