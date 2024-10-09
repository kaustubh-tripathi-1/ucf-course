#include<stdio.h>
#include<conio.h>

int main()
{
    char a;
    // char temp_a;
    a='A';
    /* temp_a = a+1;
    printf("The next character after %c is %c.\n", a, temp_a); //Don't rely on order of Function Arguments evaluation, store the value in a variable first. */
    printf("The next character is %c after %c\n",++a, a); //Don't rely on order of Function Arguments evaluation, store the value in a variable first.
    getch();
    return 0;
}