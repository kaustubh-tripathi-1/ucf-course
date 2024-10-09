#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
int removeNewLine(char [], int );
void trimString( char [], int*);

int main()
{
    int length;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string to trim it -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length = strlen(str);

    length = removeNewLine(str, length);

    if(length > 0)
    {
        trimString(str, &length);
        printf("The trimmed string is - \n\"%s\"\nLength - %d.", str, length);
    }
    else
        printf("The string is empty.");

    length = strlen(str);


    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
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

//@ Trimming a String
void trimString(char str[], int* len)
{
    //$ My Logic
    /* int start = 0, end = *len-1, i = 0, spaces = 0, j;

     while( str[i] == 32 )
    {
        spaces++;
        i++;
    }
    
    for ( i = start; i < spaces ; i++)
    {
        for ( j = start+1 ; j < *len ; j++)
        {
            str[j-1] = str[j];
        }
    }

    i=end;
    spaces = 0;
    while( str[i] == 32 )
    {
        spaces++;
        i--;
    }
    
    str[end - (spaces-1)] = '\0'; */

    //$ Better Logic

    int start = 0, end = *len - 1, i, j;

    //$ Remove leading spaces
    while ( str[start] == ' ' )
        start++;

    //$ Remove trailing spaces
    while ( end >= start && str[end] == ' ' )
        end--;

    //$ Shifting Trimmed string to the front
    for ( i = start, j = 0 ; i <= end ; i++, j++ )
        str[j] = str[i];

    str[j] = '\0';  //$ Place Null at the end
    
    *len = j;       //$ Updating Length

}