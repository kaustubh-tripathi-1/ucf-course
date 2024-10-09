#include<stdio.h>
#include<conio.h>

int main()
{
    int w;
    float x;
    char y;
    double z;
    printf("Size of an int var is %zu.\n", sizeof(w));
    printf("Size of a float var is %zu.\n", sizeof(x));
    printf("Size of a char var is %zu.\n", sizeof(y));
    printf("Size of a double var is %zu.\n", sizeof(z));
    getch();
    return 0;
}