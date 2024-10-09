#include<stdio.h>
#include<conio.h>

int main()
{
    /* int a=5,b;
    b= a+++a;
    printf("%d & %d", b, a); */
    int a = 1, b = 2, c = 3;

    // Using prefix and postfix in complex expressions
    // int result = a++ + (++a * ++a) - a++;
    int result = ++a*b+++a+c++;

    printf("Result: %d\n", result);
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("Value of c: %d\n", c);

    getch();
    return 0;
}