#include<stdio.h>
#include<conio.h>
#include<string.h>

int calculateLength(char []);
int removeNewLine(char [], int);
void copyString(char [], int, char []);

int main()
{
    char str1[100], str2[100];
    int len1, alphabetsCount, digitsCount, specialCharacterCount;

    printf("Enter a string to check the occurence of a character -\n");
    fgets(str1, sizeof(str1), stdin);

    len1 = strlen(str1);
    len1 = removeNewLine(str1, len1);

    copyString(str1, len1, str2);

    printf("Copied String -\n");
    printf("%s", str2);

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

//@ Counting Alphabets in a String
void copyString(char str1[], int len, char str2[])
{
    int i;
    for( i = 0; i <= len ; i++)
    {
        str2[i] = str1[i];
    }
}

