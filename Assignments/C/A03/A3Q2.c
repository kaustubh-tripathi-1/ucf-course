#include<stdio.h>
#include<conio.h>

int main()
{
    int c;
    printf("Enter the ASCII Code of a character to print the character :\n");
    if(scanf("%d", &c)!=1 || c<0 || c>255)
    {
        printf("Enter a valid numeric input between 0 to 255.");
        return 1;
    }
    printf("The character with ASCII Code %d is %c.", c, c);
    getch();
    return 0;
}