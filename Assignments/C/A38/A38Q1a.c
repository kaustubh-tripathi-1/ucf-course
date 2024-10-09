#include<stdio.h>
#include<conio.h>
#include<string.h>



void validInputCheck(int *, int );
int removeNewLine(char [], int );
int checkPalindrome( char [], int);

//$ Checking for palindrome W/O Using extra space
int main()
{
    int length;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string to check for palindorme -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length = strlen(str);

    length = removeNewLine(str, length);

    

    if(length > 0)
    {
        if( checkPalindrome(str, length) )
            printf("The string \"%s\" is Palindrome.", str);
        else
            printf("The string \"%s\" is not Palindrome.", str);
    }
    else
        printf("The string is empty.");


    getch();
    return 0;
}

//@ Valid Input Check
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || *n > 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
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
int checkPalindrome(char str[], int len)
{
    int start, end;
    for(  start = 0, end = len-1 ; start < end ; start++, end--)
    {
        if( str[start] != str[end] )
            return 0;
    }

    return 1;
}