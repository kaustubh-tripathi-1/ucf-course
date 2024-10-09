#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
void stringsInput(int strings, int length, char (*str)[length], int *ptrlengthOfStrings);
void printStrings(int strings, int length, char (*pstr)[length]);
void lowerCase(int length, char (*pstr)[length], int strings);
char countCharacterOccurence(int length, char (*pstr)[length], int strings);

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
    
    printf("The entered strings are -\n");
    printStrings( strings,  length,  str);
        
    if (strings > 0)
    {
        lowerCase( length, str, strings );
        char mostRepeatedchar = countCharacterOccurence( length, str, strings);

        if ( mostRepeatedchar != '\0')
            printf("The most repeated char is - %c.\n", mostRepeatedchar);
        else
            printf("No character is repeated");
        
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

//@ Counting the most repeating character in list of strings
char countCharacterOccurence(int length, char (*pstr)[length], int strings)
{
    int i, j;

    //@ Better and readable Logic than mine 
    int freq[128] = {0};     //$ Frequency array for all characters till ASCII Code 128

    for (  i = 0 ; i < strings; i++)
    {
        for ( int j = 0 ; pstr[i][j] != '\0' ; j++)
        {
            freq[pstr[i][j]]++;
        }
    }

    //$ Find the character with the highest frequency
    int maxFreq = 0;
    char mostFreqChar = '\0';

    for ( i = 0 ; i < 128; i++)
    {
        if ( maxFreq < freq[i])
        {
            maxFreq = freq[i];
            mostFreqChar = i;
        }
    }

    if ( maxFreq > 1 )
        return mostFreqChar;
    else
        return '\0';
    
}