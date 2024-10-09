#include<stdio.h>
#include<conio.h>

int main()
{
    char c;
    printf("ENter a character to check if it's an uppercase, lowercase or a special character :\n");
    scanf("%c", &c);

    if( c>='A' && c<='Z')
        printf("%c is an Uppercase character.", c);
    else if( c>='a' && c<= 'z')
        printf("%c is an Lowercase character.", c);
    else if(c>='0' && c<= '9')
        printf("%c is a Digit.", c);
    else
        printf("%c is an special character.", c);
    
    getch();
    return 0;
}