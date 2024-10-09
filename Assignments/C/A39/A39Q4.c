#include<stdio.h>
#include<conio.h>
#include<string.h>


void validInputCheck(int *, int );
void removeNewLine(char [], int* );
int countWords( char [], int);
void makeAcronym(char [], int*);

int main()
{
    int length;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length, 0);
    char str[length];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter your name to convert it to an acronym -\n");
    fgets(str, sizeof(str), stdin);       //$ String Input

    length  = strlen(str);

    removeNewLine(str, &length);

    if( length > 0)
    {
        makeAcronym( str, &length);
        printf("The Acronym for your name is -\n\"%s\".", str);
        printf("\nLength - %d", length);
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

//@ Counting Words in a String
int countWords(char str[], int len)
{
    int words=0, i=0;

    while( i < len )
    {
        //$ Skip Spaces
        while ( str[i] == 32 && str[i] != '\0' )
            i++;
        
        //$ Increment words if a non-space character is found
        if( str[i] != ' ' && str[i] != '\0' )
        {
            words++;
            
            //$ Moving to the next space
            while( str[i] != ' ' && str[i] != '\0' )
                i++;
        }
    }

    return words;
}

//@ Function to create the acronym while preserving the surname
void makeAcronym(char str[], int* len)
{
    int i, j;

    //$ True Acronym with only Initials
    /* for ( i = 0, j = 0 ; str[i] != '\0' ; i++)
    {
        if ( str[i] != ' ' && str[i] != '\0')
        {
            
            str[j] = str[i];
            j++; 
        }

        while ( str[i] != ' ' && str[i] != '\0' )
            i++;
        
        str[j] = str[i];
        j++;
    }

    str[j] = '\0';

    *len = j; */

   //$ Custom Acronym with Complete Surname

    int end = *len-1;

    while ( str[end] == ' ')
        end--;


    while( str[end] != ' ' && str[end] != '\0' )
        end--;
   
    for ( i = 0, j = 0 ; i < end ; i++)
    {
        if ( str[i] != ' ' && str[i] != '\0')
        {
            str[j] = str[i];
            j++; 
        }

        while ( str[i] != ' ' && str[i] != '\0' )
            i++;

        str[j] = str[i];
        j++;
    }

    while ( i < *len )
    {
        str[j] = str[i];
        i++;
        j++;
    }

    str[j] = '\0';
    *len = j;    
}