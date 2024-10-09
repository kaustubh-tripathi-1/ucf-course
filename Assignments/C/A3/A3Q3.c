#include<stdio.h>
#include<conio.h>

int main()
{
    char a, b, c;
    printf("Enter 3 characters to know their ASCII Codes :\n");
    scanf("%c\n%c\n%c", &a, &b, &c);
    printf("The ASCII Codes are\n%c = %d\n%c = %d\n%c = %d\n",a, a, b, b, c, c);
    getch();
    return 0;
}