#include<stdio.h>
#include<conio.h>

int calculateLength(char []);
int removeNewLine(char [], int);

int main()
{
    char str[100];
    int len;

    printf("Enter a string to calculate it's length -\n");
    fgets(str, sizeof(str), stdin);

    len = calculateLength(str);

    len = removeNewLine(str, len);

    printf("The length of the string \"%s\" is %d.", str, len);

    getch();
    return 0;
}

//@ Calculating the length of a String
int calculateLength(char str[])
{
    int i;
    for( i = 0; str[i] ; i++);

    return i;
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