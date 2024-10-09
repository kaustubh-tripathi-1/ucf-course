#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
void stringsInput(int words, int length, char (*str)[length], int *lengthOfStrings);
void printStrings(int words, int length, char (*str)[length]);
void sortStrings(int words, int length, char (*str)[length], int *lengthOfStrings);
void removeDuplicateNames(int* words, int length, char (*str)[length], int *lengthOfStrings);

int main()
{
    int length, words, i;
    printf("Enter the max length/memory that you want to reserve for each word -\n");
    validInputCheck(&length, 0);
    printf("Enter the number of words in a string -\n");
    validInputCheck(&words, 0);
    char str[words][length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    int lengthOfStrings[words];

    for ( i = 0 ; i < words ; i++)
        lengthOfStrings[i] = 0;
    
    stringsInput( words, length, str, lengthOfStrings);


    
    printf("The entered City Names are -\n");
    printStrings( words,  length,  str);

    printf("\n");
    
    if (words > 0 && length > 0)
    {
        sortStrings(words, length, str, lengthOfStrings);

        printf("Sorted Strings are - .\n");
        printStrings(words, length, str);

        removeDuplicateNames(&words, length, str, lengthOfStrings);

        printf("Names w/o duplicacy are - .\n");
        printStrings(words, length, str);        
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
void removeNewLine(char *str, int* len)
{
    if( *len > 0 && str[*len-1] == '\n')
    {
        str[*len-1] = '\0';
        (*len)--;
    }
}

//@ Multiple Strings Input
void stringsInput(int words, int length, char (*str)[length], int *lengthOfStrings)
{
    int i;
    printf("Enter strings -\n");
    for( i = 0 ; i < words ; i++)
    {
        printf("Enter String %d -\n", i+1);
        fgets(str[i], sizeof(str[i]), stdin);       //$ String Input
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }
}

//@ Multiple Strings Print
void printStrings(int words, int length, char (*str)[length])
{
    for ( int i = 0; i < words; i++)
        printf("%s\n", str[i]);         //$ Printing Strings
}

//@ Sorting Multiple Strings
void sortStrings(int words, int length, char (*str)[length], int *lengthOfStrings)
{
    int i, j, order;

    for( i = 0 ; i < words-1 ; i++)
    {
        for( j = 0 ; j < words-i-1 ; j++)
        {
            order = strcmp(str[j], str[j+1]);
            if (order == 1)
            {
                char temp[length];
                strcpy(temp, str[j]); 
                strcpy(str[j], str[j+1]); 
                strcpy(str[j+1], temp);

                int temp1 = lengthOfStrings[j];
                lengthOfStrings[j] = lengthOfStrings[j+1];
                lengthOfStrings[j+1] = temp1;
            }
        }
    }
}

void removeDuplicateNames(int *words, int length, char (*str)[length], int *lengthOfStrings)
{
    int i, j;
    
    for( i = 1, j = 0 ; i < *words ; i++ )
    {
        if ( strcmp(str[j], str[i]) != 0 )
        {
            j++;
            strcpy(str[j], str[i]);
            lengthOfStrings[j] = lengthOfStrings[i];
        }
    }

    for ( i = j+1 ; i < *words ; i++)
    {
        for ( int k = 0 ; k < lengthOfStrings[i] ; k++)
            str[i][k] = '\0';

        lengthOfStrings[i] = 0;
    }


    *words = j+1;
}
