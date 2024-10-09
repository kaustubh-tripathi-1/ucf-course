#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int* , int );
void validInputCheckCharacter(char *);
void removeNewLine(char *, int* );
void convertToUpperCase(char *, int );

int main()
{
    int length;
    printf("Enter the max memory/length you want to reserve for the string - \n");
    validInputCheck(&length, 0);

    char str[length];
    
    printf("Enter the string to convert it to uppercase - \n");
    while( getchar() != '\n');
    fgets( str, sizeof(str), stdin );

    length = strlen(str);
    removeNewLine(str, &length);
    
    if ( length > 0 )
    {
        convertToUpperCase(str, length);
        printf("The string converted to uppercase is -\n\"%s\".", str);
    }
    else
        printf("The string is empty.");

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

//@ Removing New Line at the end of a String
void removeNewLine(char *str, int* len)
{
    if( *len > 0 && str[*len-1] == '\n')
    {
        str[*len-1] = '\0';
        (*len)--;
    }
}

//@ Converting String to Uppercase
void convertToUpperCase(char *str, int len)
{
    int i;
    for( i = 0; i < len ; i++)
    {
        if( str[i] >= 'a' && str[i] <= 'z' )
            str[i] -= 32;
    }
}