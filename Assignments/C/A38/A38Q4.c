#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void reverseStringWords( int words, int length, char str[words][length] );

int main()
{
    int length, words;
    printf("Enter the max length/memory that you want to reserve for each word -\n");
    validInputCheck(&length, 0);
    printf("Enter the number of words in a string -\n");
    validInputCheck(&words, 0);
    char str[words][length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter words to form a string and then to reverse it word wise -\n");
    for( int i = 0 ; i < words ; i++)
        fgets(str[i], sizeof(str[i]), stdin);       //$ String Input

    int lengthOfStrings[words], i;
    
    for ( i = 0 ; i < words ; i++)
        lengthOfStrings[i] = 0;

    for ( i = 0 ; i < words ; i++)
    {
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }   

    if(words > 0)
    {
        printf("Original entered String is - \n");
        for ( i = 0 ; i < words ; i++)
        {
            printf("%s ", str[i]);
        }
        
        reverseStringWords( words, length, str );

        printf("\nReversed String word wise is - \n");
        for ( i = 0 ; i < words ; i++)
        {
            printf("%s ", str[i]);
        }
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

//@ Reversing String Word Wise
void reverseStringWords( int words, int length, char str[words][length] )
{

    //$ 2D Array Approach
    
    int start = 0, end = words-1;
    while ( start < end )
    {
        char temp[length];

        strcpy(temp, str[start]);
        strcpy(str[start], str[end]);
        strcpy(str[end], temp);
        
        start++;
        end--;
    }
}