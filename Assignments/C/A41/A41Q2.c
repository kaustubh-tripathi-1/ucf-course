#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
void stringsInput(int strings, int length, char (*str)[length], int *ptrlengthOfStrings);
void printStrings(int strings, int length, char (*pstr)[length]);
void lowerCase(int length, char (*pstr)[length], int strings);
int findMax(int *, int );
char countCharacterOccurence(int length, char (*pstr)[length], int strings, char *pAllCharacters, int *pCharacterCount);

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

    char allCharacters[strings * length];

    for ( int i = 0 ; i < strings * length ; i++)
        allCharacters[i] = 0;
    
    int characterCount[strings * length];
    
    for ( int i = 0 ; i < strings * length ; i++)
        characterCount[i] = 0;
        
    if (strings > 0)
    {
        lowerCase( length, str, strings );
        char mostRepeatedchar = countCharacterOccurence( length, str, strings, allCharacters, characterCount);

        if ( mostRepeatedchar != '\0')
            printf("The most repeated char is - %c.\n", mostRepeatedchar);
        else
            printf("No character is repeated");

        //$ Check the arrays
        /* printf("all char array - \n");
        for (int i = 0; allCharacters[i] != '\0'; i++)
        {
            printf("%c ", allCharacters[i]);
        }
        printf("Char COunt array - \n");
        for (int i = 0; characterCount[i] != 0; i++)
        {
            printf("%d ", characterCount[i]);
        } */
        
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

//@ Finding largest element in an array through pointer
int findMax(int *arr, int size)
{

    if ( size == 0)
        return -1;
    
    int max = arr[0];
    int index=0;

    for ( int i = 1 ; i < size && arr[i] != 0; i++)
    {
        if ( max < arr[i])
        {
            max = arr[i];
            index = i;
        }
        
    }

    return index;
    
}

//@ Counting the most repeating character in list of strings
char countCharacterOccurence(int length, char (*pstr)[length], int strings, char *pAllCharacters, int *pCharacterCount)
{
    int i, j, k, l, m = 0, count;
    int processed[strings][length];
    char ch;

    //$ Initializing the processed array with 0
    for ( i = 0 ; i < strings ; i++)
    {
        for ( j = 0 ; j < length ; j++)
        {
            processed[i][j] = 0;
        }
    }

    //$ Counting character occurence, 1st 2 loops for keeping character ( i and j ), rest 2 loops for traversing the 2D array ( k and l )
    for ( i = 0 ; i < strings ; i++)
    {
        for ( j = 0 ; pstr[i][j] != '\0' ; j++)
        {
            if ( processed[i][j] == 1 || pstr[i][j] == ' ' )     //$ Character already processed, skip to next iteration 
                continue;

            count = 0;
            
            ch = pstr[i][j];

            pAllCharacters[m] = ch;
            
            for ( k = 0 ; k < strings ; k++)
            {
                for ( l = 0 ; pstr[k][l] != '\0' ; l++)
                {
                    if ( pstr[k][l] == ch )
                    {
                        count++;
                        processed[k][l] = 1;
                    }
                }
            }
            
            pCharacterCount[m] = count;
            m++;    //$ m are for keeping index track of allCharacters and characterCount arrays
        }
    }
    
    int index = findMax(pCharacterCount, m);

    if ( index == -1)
        return '\0';
    else
        return pAllCharacters[index];
    
}