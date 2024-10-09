#include<stdio.h>
#include<conio.h>
#include<string.h>

int removeNewLine(char [], int);
int countSpaces( char [], int);

int main()
{
    char str[100];
    int len, count;

    printf("Enter a string to check the occurence of a character -\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    len = removeNewLine(str, len);

    count = countSpaces( str, len);

    printf("There are %d spaces in string \"%s\".", count, str);

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

//@ Counting Spaces in a String
int countSpaces(char str[], int len)
{
    int i, spaceCount=0;
    for( i = 0; i < len ; i++)
    {
        if( str[i] == ' ')
            spaceCount++;
    }

    return spaceCount;
}