#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void trimString( char [], int*);
int countWords( char [], int);

int main()
{
    int length, words;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string to count words -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length = strlen(str);

    removeNewLine(str, &length);

    if(length > 0)
    {
        trimString(str, &length);
        words = countWords(str, length);
        printf("There are %d words in the string - \"%s\".", words, str);
    }
    else
        printf("The string is empty.");

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
void removeNewLine(char str[], int* len)
{
    if( *len > 0 && str[*len-1] == '\n')
    {
        str[*len-1] = '\0';
        (*len)--;
    }

}

//@ Trimming a String
void trimString(char str[], int* len)
{
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

//@ Counting Words in a String
int countWords(char str[], int len)
{
    int words=0, i=0;

    while( i < len )
    {
        //$ Skip Spaces
        while ( str[i] == 32 && str[i] != '\0' )
            i++;
        
        //$ Increment words if a non-space character is found
        if( str[i] != ' ' && str[i] != '\0' )
        {
            words++;
            
            //$ Moving to the next space
            while( str[i] != ' ' && str[i] != '\0' )
                i++;
        }
    }

    return words;
}