#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void stringsInput( int words, int length, char str[words][length], int []);
void printStrings(int words, int length, char str[words][length]);
void storeIn2DArray(char str[], int length, int words, char words2DArray[words][length]);
void trimString(char str[], int* len);
int countWords( char [], int);

int main()
{
    int length, words, i;
    printf("Enter the max length/memory that you want to reserve for a string -\n");
    validInputCheck(&length, 0);

    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer
    
    printf("Enter string -\n");
    fgets(str, sizeof(str), stdin); //$ String Input
    length = strlen(str);
    removeNewLine(str, &length);      

    //$ Trimming and Counting words & storing words of the string in a 2D array
    if(length > 0)
    {
        trimString(str, &length);
        words = countWords(str, length);
        printf("There are %d words in the string - \"%s\".", words, str);
    

        char words2DArray[words][length];   //$ 2D Array for storing each word

        storeIn2DArray(str, length, words, words2DArray);

        int lengthOfStrings[words];

        for ( i = 0 ; i < words ; i++)
            lengthOfStrings[i] = strlen(words2DArray[i]);
        
        printf("\nThe 2D array of each word -\n");
        printStrings( words,  length,  words2DArray);
    
    }
    else
        printf("The string is empty.\n");
    

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


//@ Multiple Strings Print
void printStrings(int words, int length, char str[words][length])
{
    for ( int i = 0; i < words; i++)
        printf("%s\n", str[i]);         //$ Printing Strings
}

//@ Trimming a String
void trimString(char str[], int* len)
{
    int start = 0, end = *len - 1, i, j;

    //$ Remove leading spaces
    while ( str[start] == ' ' && str[start] != '\0' )
        start++;

    //$ Remove trailing spaces
    while ( end >= start && str[end] == ' ' && str[start] != '\0' )
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
        while ( str[i] == ' ' && str[i] != '\0' )
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

void storeIn2DArray(char str[], int length, int words, char words2DArray[words][length])
{
    int i, j, k;

    for ( i = 0, j = 0 ; str[i] != '\0' ; j++)
    {
        for ( k = 0 ; str[i] != ' ' && str[i] != '\0'; k++, i++)
            words2DArray[j][k] = str[i];
        
        words2DArray[j][k] = '\0';  //$ Null terminating the word

        //$ Skipping Multiple Spaces between words
        while ( str[i] == ' ')
            i++;

    }
}