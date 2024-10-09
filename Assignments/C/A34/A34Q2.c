#include<stdio.h>
#include<conio.h>
#include<string.h>

int calculateLength(char []);
int removeNewLine(char [], int);
int checkOccurence( char [], int, char);

int main()
{
    char character, str[100];
    int len, count;

    printf("Enter a string to check the occurence of a character -\n");
    fgets(str, sizeof(str), stdin);

    getchar(); //$ To remove the new line char from the input buffer for scanf
    
    printf("Enter a character to check the occurence in a string -\n");
    scanf("%c", &character);

    len = strlen(str);
    len = removeNewLine(str, len);

    count = checkOccurence( str, len, character);

    printf("The occurence of %c in the string \"%s\" is %d.", character, str, count);

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

//@ Checking Occurence of a character in a String
int checkOccurence(char str[], int len, char character)
{
    int i, count=0;
    for( i = 0; i < len ; i++)
    {
        if( str[i] == character)
            count++;
    }

    return count;
}