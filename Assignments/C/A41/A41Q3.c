#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
void trimString(char *, int* );
void lowerCase(int length, char (*pstr)[length], int strings);
void sortStringCharByChar(char *, int );
int checkAnagram(int strings, int length, char (*pstr)[length], int *ptrLengthOfStrings);

int main()
{
    int length;
    printf("Enter the max length/memory you want to reserve for a string -\n");
    validInputCheck(&length, 0);

    char str[2][length];

    int i;
    int lengthOfStrings[2] = {0};
    
    while ( getchar() != '\n' );

    printf("Enter 2 Strings to check for anagram -\n");
    for ( i = 0 ; i < 2 ; i++)
    {
        printf("Enter String %d -\n", i+1);
        fgets( str[i], sizeof(str[i]), stdin);
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }

    if ( (lengthOfStrings[0] != lengthOfStrings[1]) || lengthOfStrings[0] < 1 || lengthOfStrings[1] < 1 )
        printf("The strings are not anagrams or The strings ar empty.");
    else
    {
        lowerCase(length, str, 2);
        int isAnagram = checkAnagram(2, length, str, lengthOfStrings);

        if ( isAnagram )
            printf("\nThe 2 strings are anagrams of each other.");
        else
            printf("\nThe 2 strings are not anagrams of each other.");
        
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
void removeNewLine(char *pstr, int* len)
{
    if( *len > 0 && pstr[*len-1] == '\n')
    {
        pstr[*len-1] = '\0';
        (*len)--;
    }
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

//@ Function to sort 1 strings char by char 
void sortStringCharByChar(char *str, int length)
{
    int i, j;
    for ( i = 0 ; i < length - 1 ; i++ )
    {
        for ( j = 0 ; j < length - i - 1 ; j++)
        {
            if ( str[j] > str[j+1] )
            {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

//@ Checking if 2 strings are anagram of each other
int checkAnagram(int strings, int length, char (*pstr)[length], int *ptrLengthOfStrings)
{
    /* //$ Logic with Time Complexity of O( n log n)
    int i, j, k;

    for ( i = 0 ; i < strings ; i++ )
    {
        trimString(pstr[i], &ptrLengthOfStrings[i]);
        sortStringCharByChar(pstr[i], ptrLengthOfStrings[i]);
    }

    for ( i = 0, j = 1 ; i < strings ; i++ )
    {
        for ( k = 0 ; pstr[i][k] != '\0' || pstr[j][k] != '\0' ; k++)
        {
            if ( pstr[i][k] != pstr[j][k])
                return 0;   //$ If a char in sorted String 1 != char in sorted String 2, the 2 strings are not anagrams
        }
    }

    return 1;   //$ All characters of both sorted strings were same
     */

    /* //$ Logic with Linear Time Complexity O(n)
    
    int i, j;
    int freq1[256] = {0};
    int freq2[256] = {0};

    for ( i = 0 ; i < strings ; i++ )
        trimString(pstr[i], &ptrLengthOfStrings[i]);
    
    //$ Traversing 1st string for frequency count
    for ( i = 0, j = 0 ; pstr[i][j] != '\0' ; j++ )
    {
        freq1[pstr[i][j]]++;
    }
    //$ Traversing 2nd string for frequency count
    for ( i = 1, j = 0 ; pstr[i][j] != '\0' ; j++ )
    {
        freq2[pstr[i][j]]++;
    }

    //$ Comparing both frequency count arrays
    for ( i = 0 ; i < 255 ; i++)
    {
        if ( freq1[i] != freq2[i] )
            return 0;
    }

    return 1;   //$ Both frequency arrays are same so strings are anagram  */


    //$ Logic with a single frequency array
    int i, j;
    int freq[256] = {0};

    for ( i = 0 ; i < strings ; i++ )
        trimString(pstr[i], &ptrLengthOfStrings[i]);
    
     //$ Traversing 1st string: Increment frequency count
    for ( i = 0, j = 0 ; pstr[i][j] != '\0' ; j++ )
    {
        freq[pstr[i][j]]++;
    }
    //$ Traversing 2nd string - Decrement frequency count
    for ( i = 1, j = 0 ; pstr[i][j] != '\0' ; j++ )
    {
        freq[pstr[i][j]]--;
    }

    //$ Comparing both frequency count arrays
    for ( i = 0 ; i < 255 ; i++)
    {
        if ( freq[i] != 0 )
            return 0;   //$ Strings are not anagrams
    }

    return 1;   //$ Both frequency arrays are same so strings are anagram  */


}
