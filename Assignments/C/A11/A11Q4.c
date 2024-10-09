#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1;
    while( i<=10 )
    {
        printf("%d\n", (2*i)-1);
        i++;
    }
    getch();
    return 0;
}