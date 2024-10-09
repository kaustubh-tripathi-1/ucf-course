#include<stdio.h>
#include<conio.h>
#include<string.h>


void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void capitalizeFirstLetter(char [], int);

int main()
{
    int length;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length  = strlen(str);

    removeNewLine(str, &length);

    if( length > 0)
    {
        capitalizeFirstLetter( str, length );
        printf("The Updated String is -\n\"%s\".", str);
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

//@ Making the first letter of every word in the string Capital
void capitalizeFirstLetter(char str[], int len)
{
    int i;

    //$ My logic
    for ( i = 0 ; i < len ; i++)
    {
        //$ First letter of a word found, capitalize it
        if( str[i] >= 'a' && str[i] <= 'z' && str[i] != ' ' && str[i] != '\0' )
            str[i] -= 32;
        
        //$ Skip to next word's first letter
        while( str[i] != ' ' && str[i] != '\0' )
            i++;
    }

   //$ Another logic
   /* if( str[0] >= 'a' && str[0] <= 'z' && str[0] != ' ' && str[0] != '\0' )
        str[0] -= 32;

    for ( i = 1 ; i < len ; i++)
    {
        if( str[i] >= 'a' && str[i] <= 'z' && str[i-1] == ' ' )
            str[i] -= 32;

        while( str[i] != ' ' && str[i] != '\0' )
            i++;
    } */
}