#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void countFrequency(char [], int);

int main()
{
    int length, words;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string to count the frequency of characters -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length = strlen(str);

    removeNewLine(str, &length);

    if( length > 0)
        countFrequency(str, length);
    else
        printf("The string is Empty.");

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

//@ Counting Each Character Frequency
void countFrequency(char str[], int len)
{
    int i, j, count, processed[len];

    for( i = 0 ; i < len ; i++)
        processed[i] = 0;

    for ( i = 0; i < len; i++)
    {
        if ( processed[i] == 1 || str[i] == ' ')
            continue;
        
        count = 0;

        for ( j = 0 ; j < len; j++)
        {
            if( str[i] == str[j] )
            {
                count++;
                processed[j] = 1;
            }
        }

        printf("%c - %d\n", str[i], count);
        
    }
    
}