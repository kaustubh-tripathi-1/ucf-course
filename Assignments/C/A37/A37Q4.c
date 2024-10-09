#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
int removeNewLine(char [], int );
char* swapCharacters(char [], int, int, int);

int main()
{
    int length, index1, index2;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length], ch;
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    printf("Enter the first index to swap -\n");
    validInputCheck(&index1, 0);

    printf("Enter the second index to swap -\n");
    validInputCheck(&index2, 0);

    length = strlen(str);

    length = removeNewLine(str, length);

    if( length > 0)
        swapCharacters( str, index1, index2 , length);
    else
    {
        printf("The string is empty.");
        return 1;
    }

    printf("The string after swapping characters is -\n");
    printf("%s", str);

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

//@ Swapping 2 characters in a string between specified indices
char* swapCharacters(char str[], int index1, int index2, int length)
{
    char temp;
    
    if ( index1 < length && index2 < length )
    {
        temp = str[index1];
        str[index1] = str[index2];
        str[index2] = temp;
    }
    return str;
}