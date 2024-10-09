#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
int removeNewLine(char [], int );
int checkAlphaNumeric(char [], int);

int main()
{
    int length;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length = strlen(str);

    length = removeNewLine(str, length);

    if(length > 0)
    {
        if( checkAlphaNumeric( str, length ) )
            printf("The string \"%s\" is Alpha-Numeric.", str);
        else
            printf("The string \"%s\" is not Alpha-Numeric.", str);
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

//@ Checking a String  if it's alphanumeric
int checkAlphaNumeric(char str[], int len)
{
    int i, hasAlpha=0, hasDigit=0;
    for( i=0 ; str[i] != '\0' ; i++)
    {
        if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') )
            hasAlpha=1;
        else if( str[i] >= '0' && str[i] <= '9' )
            hasDigit=1;
        
        if(hasAlpha && hasDigit)
            return 1;
    }
    
    return 0;
}