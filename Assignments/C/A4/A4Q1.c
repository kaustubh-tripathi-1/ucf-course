#include<stdio.h>
#include<conio.h>

int main()
{
    /* char a;
    printf("Enter a character to know it's size :\n");
    if(scanf("%c", &a)!=1)
    {
        printf("Enter valid input.");
        return 1;
    } */
    printf("The size is %zu\n", sizeof('A'));
    getch();
    return 0;
}