#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void reverseString( char [], int, int);
void reverseStringWords( char [], int );

int main()
{
    int length, i;
    printf("Enter the max length/memory that you want to reserve for the string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter  a string to reverse it word wise -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input


    length = strlen(str);
    removeNewLine(str, &length);

    if(length > 0)
    {
        printf("Original entered String is - \n");
        printf("\"%s\"", str);
        
        reverseStringWords( str, length );

        printf("\nReversed String word wise is - \n");
        printf("\"%s\"", str);
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

//@ Reversing Part/Whole String
void reverseString( char str[], int start, int end )
{

    while ( start < end)
    {
        char temp;

        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        
        start++;
        end--;
    }
}

//@ Reversing String Word Wise
void reverseStringWords( char str[], int length )
{

    //$ 1D Array Approach, Reversing The whole string and then reversing each word
    
    int start = 0, end = length-1;

    reverseString(str, start, end);

    int i;
    start = 0;
    for ( i = 0 ; i <= length ; i++ )
    {
        if ( str[i] == ' ' || str[i] == '\0')
        {
            reverseString(str, start, i-1);
            start = i+1;
        }
    }
}