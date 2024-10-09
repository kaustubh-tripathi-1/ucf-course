#include<stdio.h>
#include<conio.h>
#include<string.h>

int removeNewLine(char [], int);
void convertToUpperCase( char [], int);

int main()
{
    char str[100];
    int len;

    printf("Enter a string to convert it to Uppercase -\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    len = removeNewLine(str, len);

    convertToUpperCase( str, len);

    printf("String converted to uppercase is -\n\"%s\".", str);

    getch();
    return 0;
}

//@ Removing New Line at the end of a String
int removeNewLine(char str[], int len)
{
    if( len > 0 && str[len-1] == '\n')
    {
        str[len-1] = '\0';
        len--;
    }

    return len;
}

//@ Converting String to Uppercase
void convertToUpperCase(char str[], int len)
{
    int i;
    for( i = 0; i < len ; i++)
    {
        if( str[i] >= 'a' && str[i] <= 'z' )
            str[i] -= 32;
    }
}