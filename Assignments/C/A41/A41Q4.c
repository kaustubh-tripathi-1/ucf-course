#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
void printStrings(int words, int length, char (*str)[length]);
void trimString(char *, int* len);
int countWords( char *, int);
void storeIn2DArray(char *str, int length, int *words, char (*words2DArray)[length]);

int main()
{
    int length, words, i;
    printf("Enter the max length/memory that you want to reserve for each word -\n");
    validInputCheck(&length, 0);

    char str[length];

    while ( getchar() != '\n' );

    printf("Enter a string to find words starting with 'a' -\n");
    fgets(str, sizeof(str), stdin);

    length = strlen(str);
    removeNewLine(str, &length);

    

    if ( length > 0)
    {
        trimString(str, &length);
        words = countWords(str, length);
        
        char words2DArray[words][length];

        storeIn2DArray(str, length, &words, words2DArray);

        printf("The words starting with a are - \n");
        printStrings(words, length, words2DArray);
    }

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
void removeNewLine(char *str, int* len)
{
    if( *len > 0 && str[*len-1] == '\n')
    {
        str[*len-1] = '\0';
        (*len)--;
    }
}

//@ Multiple Strings Print
void printStrings(int words, int length, char (*str)[length])
{
    for ( int i = 0; i < words; i++)
        printf("%s\n", str[i]);         //$ Printing Strings
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

//@ Counting Words in a String
int countWords(char *str, int len)
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

//@ Finding Words starting with 'a' and storing them in a 2D Char Array
void storeIn2DArray(char *str, int length, int *words, char (*words2DArray)[length])
{
    int i, j, k, l;

    for ( i = 0, k = 0 ; str[i] != '\0' ; i++)
    {

        if (str[i] == 'a' || str[i] == 'A')    //$ Checking for 's' char if word ends
        {
            for( l = 0 ;  str[i] != ' ' ; l++, i++ )
            {
                words2DArray[k][l] = str[i]; //$ Storing words ending with 's' in 2D array
            }
            words2DArray[k][l] = '\0';
            k++;
        }
        //$ i is for traversing original string, k for 1st dimension and l is for 2nd dimension of 2D array
        
        while ( str[i] != ' ' && str[i] != '\0' )  //$ Finding Next Space char
            i++;
    }
    
    
    int wordsBefore = *words;
    *words = k; //$ Update the count of words stored in the 2D Array

    for (j = k; j < wordsBefore ; j++)
    {
        words2DArray[j][0] = '\0';  //$ Placing null char at the start of rest of the 2D Array
    }
}
