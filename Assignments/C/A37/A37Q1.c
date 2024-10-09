#include<stdio.h>
#include<conio.h>
#include<string.h>

int removeNewLine(char [], int);
int countVowel( char [], int);
int isVowel(char );

int main()
{
    char str[100];
    int len, count;

    printf("Enter a string to count vowels -\n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    len = removeNewLine(str, len);

    count = countVowel( str, len);

    printf("There are %d vowel/s in string \"%s\".", count, str);

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

//@ Counting Vowels in a String
int countVowel(char str[], int len)
{
    int i, vowelCount=0;
    for( i = 0; i < len ; i++)
    {
        if(isVowel(str[i]))
            vowelCount++;
    }

    return vowelCount;
}

int isVowel(char ch)
{
    return( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}