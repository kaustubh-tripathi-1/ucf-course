#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int* , int );
void validInputCheckCharacter(char *);
void removeNewLine(char *, int* );
void searchOccurences(char *, char, int *);

int main()
{
    int length;
    printf("Enter the max memory/length you want to reserve for the string - \n");
    validInputCheck(&length, 0);

    char str[length], character;
    
    printf("Enter the string to find all occurences of a given char - \n");
    while( getchar() != '\n');
    fgets( str, sizeof(str), stdin );
    length = strlen(str);
    removeNewLine(str, &length);

    printf("Enter the character to find in the string -\n");
    validInputCheckCharacter(&character);

    int i, indices[length];

    for ( i = 0; i < length; i++)
        indices[i] = -1;
    
    searchOccurences(str, character, indices);
    
    if (indices[0] == -1)
        printf("Character not found.\n");
    else
    {
        printf("The indices at which the character was found are -\n");
        for ( i = 0; i < length && indices[i] != -1 ; i++)
            printf("%d ", indices[i]);
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

        if(validInput == 1 && (allowNegative || (*n > 0 )))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Taking Input of a character and Checking if it's valid
void validInputCheckCharacter(char *n)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%c", n);

        if(validInput == 1 && *n > 0 && *n <= 127 )
            break;
        else
        {
            printf("Enter valid numbers!\n");
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

//@ Searchinf for All Occurences and storing them in an Array
void searchOccurences(char *str, char character, int *indices)
{
    int i, j;
    for ( i = 0, j = 0 ; str[i] != '\0' ; i++)
    {
        if( str[i] == character )
        {
            indices[j] = i;
            j++; 
        }
    }
}