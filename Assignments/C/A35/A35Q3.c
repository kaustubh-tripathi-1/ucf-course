#include<stdio.h>
#include<conio.h>
#include<string.h>

int calculateLength(char []);
int removeNewLine(char [], int);
int countAllCharacters( char [], int, int *, int *, int *);


int main()
{
    char str[100];
    int len, alphabetsCount=0, digitsCount=0, specialCharacterCount=0;

    printf("Enter a string to count Alphabets, Digits & Special Characters -\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    len = removeNewLine(str, len);

    countAllCharacters( str, len, &alphabetsCount, &digitsCount, &specialCharacterCount);
    

    printf("In string \"%s\" -\nAlphabets - %d\nDigits - %d\nSpecial Character - %d.", str, alphabetsCount, digitsCount, specialCharacterCount );

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

//@ Counting All types of Characters in a String
int countAllCharacters(char str[], int len, int *alphabetsCount, int *digitsCount, int *specialCharacterCount)
{
    int i, alphabetsCount=0;
    for( i = 0; i < len && str[i] >= 0 && str[i]<=127 ; i++)
    {
        if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
            (*alphabetsCount)++;
        else if( str[i] >= '0' && str[i] <= '9' )
            (*digitsCount)++;
        else
            (*specialCharacterCount)++;
    }
}

