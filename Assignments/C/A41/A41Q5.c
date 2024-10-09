#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
void stringsInput(int strings, int length, char (*str)[length], int *ptrlengthOfStrings);
void printStrings(int strings, int length, char (*pstr)[length]);
void lowerCase(int length, char (*pstr)[length], int strings);
void trimString(char *, int* len);
int checkGmail( int length, int strings, char (*pstr)[length], int *plengthOfStrings);

int main()
{
    int length, strings, i;
    printf("Enter the max length/memory that you want to reserve for each string -\n");
    validInputCheck(&length, 0);
    printf("Enter the number strings -\n");
    validInputCheck(&strings, 0);
    char str[strings][length];
 
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    int lengthOfStrings[strings];

    for ( i = 0 ; i < strings ; i++)
        lengthOfStrings[i] = 0;
    
    stringsInput( strings, length, str, lengthOfStrings);

    for( i = 0 ; i < strings ; i++)
    {
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }
        
    printf("The entered strings are -\n");
    printStrings( strings,  length,  str);
        
    if (strings > 0)
    {
        for ( i = 0 ; i < strings ; i++ )
        {
            trimString(str[i], &lengthOfStrings[i]);
        }

        lowerCase( length, str, strings );
    
        int stringsWithGmail = checkGmail(length, strings, str, lengthOfStrings);

        printf("%d emails belong to Gmail.\n", stringsWithGmail);
        
        
    }
    else
        printf("The strings are empty.\n");

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
void removeNewLine(char *pstr, int* len)
{
    if( *len > 0 && pstr[*len-1] == '\n')
    {
        pstr[*len-1] = '\0';
        (*len)--;
    }
}

//@ Multiple Strings Input
void stringsInput(int strings, int length, char (*pstr)[length], int *ptrlengthOfStrings)
{
    int i;
    printf("Enter strings -\n");
    for( i = 0 ; i < strings ; i++)
    {
        printf("Enter String %d -\n", i+1);
        fgets(pstr[i], sizeof(pstr[i]), stdin);       //$ String Input
        ptrlengthOfStrings[i] = strlen(pstr[i]);
        removeNewLine(pstr[i], &ptrlengthOfStrings[i]);
    }
}

//@ Multiple Strings Print
void printStrings(int strings, int length, char (*pstr)[length])
{
    for ( int i = 0; i < strings; i++)
        printf("%s\n", pstr[i]);         //$ Printing Strings
}

//@ Converting the string to lower case
void lowerCase(int length, char (*pstr)[length], int strings)
{
    for ( int i = 0 ; i < strings; i++)
    {
        for ( int j = 0 ; pstr[i][j] != '\0' ; j++)
        {
            if ( pstr[i][j] >= 'A' && pstr[i][j] <= 'Z' )
            {
                pstr[i][j] += 32;
            }
        }
    }
}

//@ Trimming a String
void trimString(char *str, int* len)
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

//@ Checking how many emails belong to Gmail
//$ My Logic, char by char check
int checkGmail( int length, int strings, char (*pstr)[length], int *plengthOfStrings)
{
    int i, j, k, countGmail = 0, end;
    char gmail[9] = "gmail.com";
    int lenOfGmail = strlen(gmail);

    for ( i = 0 ; i < strings ; i++)
    {
        if ( plengthOfStrings[i] > lenOfGmail)
        {
        
            end = plengthOfStrings[i] - 1;


            while( pstr[i][end] != '@' && end > 0 )
                end--;
            
            for ( j = ++end, k = 0 ; pstr[i][j] != '\0' ; j++, k++)
            {
                if ( gmail[k] != pstr[i][j] )
                    break;
            }

            if ( j == plengthOfStrings[i] )
                countGmail++;
        
        }
    }

    return countGmail;
}

//$ Checking directly using strcmp after @ symbol
/* int checkGmail( int length, int strings, char (*pstr)[length], int *plengthOfStrings)
{
    int i, countGmail = 0;
    char *gmailDomain = "@gmail.com";
    int domainLength = strlen(gmailDomain);

    for ( i = 0 ; i < strings ; i++)
    {
        int strlength = plengthOfStrings[i];

        if ( strlength > domainLength)
        {
            char *atPosition = strchr(pstr[i], '@');

            if ( atPosition != NULL && strcmp(atPosition, gmailDomain) == 0)
            {
                countGmail++;
            }
        }
        
    }

    return countGmail;
    
} */