#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void stringsInput( int words, int length, char str[words][length] );
int countVowels(int words, int length, char str[words][length], int []);

int main()
{
    int length, words, i, vowels;
    printf("Enter the max length/memory that you want to reserve for each word -\n");
    validInputCheck(&length, 0);
    printf("Enter the number of words in a string -\n");
    validInputCheck(&words, 0);
    char str[words][length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    stringsInput( words, length, str);

    int lengthOfStrings[words];
    
    for ( i = 0 ; i < words ; i++)
        lengthOfStrings[i] = 0;

    for ( i = 0 ; i < words ; i++)
    {
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }
    
    printf("The entered strings are -\n");
    for ( i = 0; i < words; i++)
        printf("%s\n", str[i]);

    for ( i = 0 ; i < words ; i++)
    {
        printf("Length of String %d is %d.\n", i+1, lengthOfStrings[i]);
    }

    if (words > 0 && length > 0)
    {
        vowels = countVowels( words, length, str, lengthOfStrings);
        printf("There are total %d vowels in all the strings.\n", vowels);
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
void removeNewLine(char str[], int* len)
{
    if( *len > 0 && str[*len-1] == '\n')
    {
        str[*len-1] = '\0';
        (*len)--;
    }
}

void stringsInput(int words, int length, char str[words][length])
{
    int i;
    printf("Enter words to form a string -\n");
    for( i = 0 ; i < words ; i++)
        fgets(str[i], sizeof(str[i]), stdin);       //$ String Input
}

int countVowels(int words, int length, char str[words][length], int lengthOfStrings[])
{
    int i, j;
    int vowels = 0;

    for( i = 0 ; i < words ; i++)
    {
        for( j = 0, vowels = 0 ; j < lengthOfStrings[i] ; j++)
        {
            if( str[i][j] == 'a' || str[i][j] == 'e' || str[i][j] == 'i' || str[i][j] == 'o' || str[i][j] == 'u' || str[i][j] == 'A' || str[i][j] == 'E' || str[i][j] == 'I' || str[i][j] == 'O' || str[i][j] == 'U')
                vowels++;
        }

        printf("There are %d vowels in String %d", vowels, i+1);
        
    }

    return vowels;
}