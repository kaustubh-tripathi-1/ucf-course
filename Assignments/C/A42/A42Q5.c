#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int* , int );
void validInputCheckCharacter(char *);
void removeNewLine(char *, int* );
void extractSubstring(char *, int, int, char *);

int main()
{
    int length;
    printf("Enter the max memory/length you want to reserve for the string - \n");
    validInputCheck(&length, 0);

    char str[length];
    
    printf("Enter a string - \n");
    while( getchar() != '\n');
    fgets( str, sizeof(str), stdin );

    length = strlen(str);
    removeNewLine(str, &length);

    int indexStart, indexEnd;

    printf("Enter the starting index to extract Substring - \n");
    validInputCheck(&indexStart, 0);
    printf("Enter the ending index to extract Substring - \n");
    validInputCheck(&indexEnd, 0);

    while ( indexStart > length || indexEnd <= indexStart || indexEnd > length-1 )
    {
        printf("Invalid indices! Ensure 0 <= start < end <= length of string.\n");
        printf("Enter the starting index to extract Substring - \n");
        validInputCheck(&indexStart, 0);
        printf("Enter the ending index to extract Substring - \n");
        validInputCheck(&indexEnd, 0);
    }
    

    char extractedString[indexEnd-indexStart+1];
    
    extractSubstring(str, indexStart, indexEnd, extractedString);
    
    int lengthOfSubstring = strlen(extractedString);
    
    if ( length > 0 && lengthOfSubstring > 0)
    {
        printf("The extracted Sub string is -\n\"%s\".\n", extractedString);
        printf("Length of - %d", lengthOfSubstring);
    }
    else
        printf("The original string is empty.");

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

        if(validInput == 1 && (allowNegative || (*n >= 0 )))
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

//@ Extracting a substring from the original string with start and end index
void extractSubstring(char *str, int indexStart, int indexEnd, char *extractedString)
{
    int i, j;
    for ( i = indexStart, j = 0 ; i < indexEnd ; i++, j++)
    {
        extractedString[j] = str[i];
    }
    extractedString[j] = '\0';
}