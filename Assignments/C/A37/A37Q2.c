#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
int removeNewLine(char [], int );
int findCharacter(char [], int, char);

int main()
{
    int length, index;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length], ch;
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    while( getchar() != '\n');

    printf("Enter a character to find in the string -\n");
    scanf(" %c", &ch);

    length = strlen(str);

    length = removeNewLine(str, length);

    if( length > 0)
        index = findCharacter( str, length, ch );
    else
    {
        printf("The string is empty.");
        return 1;
    }

    if( index != -1)
        printf("The index of the character \"%c\" in the string \"%s\" is %d.", ch, str, index);
    else
        printf("The character \"%c\" was not found in the string \"%s\".", ch, str);

    getch();
    return 0;
}

//@ Valid Input Check
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
int removeNewLine(char str[], int len)
{
    if( len > 0 && str[len-1] == '\n')
    {
        str[len-1] = '\0';
        len--;
    }

    return len;
}

//@ Finding a character in a string
int findCharacter(char str[], int len, char ch)
{
    int i;
    for( i=0 ; str[i] != '\0' ; i++)
    {
        if( str[i] == ch)
            return i;
    }

    return -1;
}