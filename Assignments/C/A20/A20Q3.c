#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
    char c;

    printf("Enter a character to know if know the category (Uppercase, Lowercase or a special character) :\n");
    scanf("%c", &c);

    switch(c)
    {
        case 'A' ... 'Z':
            printf("%c is a Upper Case Character.\n", c);
            break;
        case 'a' ... 'z':
            printf("%c is an Lower Case Character\n", c);
            break;
        default:
            printf("%c is a Special Character.\n", c);
            break;
    }
    
    getch();
    return 0;
}
