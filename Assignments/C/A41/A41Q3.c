#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );

int main()
{
    int length;
    printf("Enter the max length/memory you want to reserve for a string -\n");
    validInputCheck(&length, 0);

    char str[2][length];

    int i;
    int lengthOfStrings[2] = {0};
    
    while ( getchar() != '\n' );

    for ( i = 0 ; i < 2 ; i++)
    {
        fgets( str[i], sizeof(str[i]), stdin);
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }

    if ( (lengthOfStrings[0] != lengthOfStrings[1]) || lengthOfStrings[0] < 1 || lengthOfStrings[1] < 1 )
        printf("The strings are not anagrams or The strings ar empty.");
    else
    {

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


