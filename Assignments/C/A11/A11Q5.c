#include<stdio.h>
#include<conio.h>

int main()
{
    int i=10;
    while( i>=1 )
    {
        printf("%d\n", (2*i)-1);
        i--;
    }
    getch();
    return 0;
}