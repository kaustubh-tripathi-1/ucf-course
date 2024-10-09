#include<stdio.h>
#include<conio.h>
#include<string.h>

int calculateLength(char []);
int removeNewLine(char [], int);
void reverseString( char [], int);

int main()
{
    char str[100];
    int len;

    printf("Enter a string to reverse it -\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    len = removeNewLine(str, len);

    if(len>1)
        reverseString( str, len);

    printf("Reversed String is -\n\"%s\".", str);

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

//@ Reversing String
void reverseString(char str[], int len)
{
    int start, end;
    for(  start = 0, end = len-1 ; start < end ; start++, end--)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}