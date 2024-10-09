#include<stdio.h>
#include<conio.h>
#include<string.h>

int calculateLength(char []);
int removeNewLine(char [], int);
int firstOccurrence( char [], int, char);

int main()
{
    char character, str[100];
    int len, index;

    printf("Enter a string to check the occurence of a character -\n");
    fgets(str, sizeof(str), stdin);

    getchar(); //$ To remove the new line char from the input buffer for scanf
    
    printf("Enter a character to check the occurence in a string -\n");
    scanf("%c", &character);

    len = strlen(str);
    len = removeNewLine(str, len);

    index = firstOccurrence( str, len, character);

    if(index!=-1)
        printf("The occurence of %c in the string \"%s\" is at index %d.", character, str, index);
    else
        printf("The character %c was not found in the string \"%s\".", character, str);

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

//@ Checking First Occurence of a character in a String
int firstOccurrence(char str[], int len, char character)
{
    int i;
    for( i = 0; str[i] ; i++)
    {
        if( str[i] == character)
           return i;
    }

    return -1;
}