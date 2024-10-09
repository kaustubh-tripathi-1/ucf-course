#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1;
    while( i<=10 )
    {
        printf("5 x %d = %d\n", i, (i*5));
        i++;
    }
    getch();
    return 0;
}