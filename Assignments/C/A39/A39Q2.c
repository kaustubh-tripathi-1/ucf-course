#include<stdio.h>
#include<conio.h>
#include<string.h>


void validInputCheck(int *, int );
void removeNewLine(char [], int* );
int findWord(char [], int, char [], int);

int main()
{
    int length1, length2, words;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length1, 0);
    printf("Enter the length/memory that you want to reserve for the word that you want to find -\n");
    validInputCheck(&length2, 0);
    char str[length1], word[length2];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    printf("Enter a word to find in the string -\n");
    fgets(word, sizeof(word), stdin);       //$ Word Input

    length1 = strlen(str);

    removeNewLine(str, &length1);

    length2 = strlen(word);

    removeNewLine(word, &length2);

    if( length1 > 0 && length2 > 0)
    {
        
        int found = findWord(str, length1, word, length2);
        if(found)
            printf("Yes, the word \"%s\" is present in the string \"%s\".", word, str);
        else
            printf("No, the word \"%s\" is not present in the string \"%s\".", word, str);


    }
    else
        printf("The string or the word you entered is Empty.");

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

//@ Finding a word in the string
int findWord(char str[], int len1, char word[], int len2)
{
    int i, j;

    //$ My Logic
    /* for ( i = 0 ; i <= len1 - len2 ; i++)
    {
        for ( j = 0 ; j < len2 ; j++)
        {
            if( word[j] != str[i] )
                break;

            while ( word[j] == str[i] )
            {
                if( j == len2-1)
                {
                    return 1;
                }
                i++;
                j++;

            }
        }
    } */

   //$ Better Logic
    for ( i = 0 ; i <= len1 - len2 ; i++)
    {
        if ( i != 0 && (str[i-1] != ' ' || str[i+len2] != ' ') && str[i+len2] != '\0' )
            continue;

        for ( j = 0 ; j < len2 ; j++)
        {
            if( word[j] != str[i+j] )
                break;            
        }

        if ( j == len2 )
            return 1;
        
    }
    
    return 0;
}