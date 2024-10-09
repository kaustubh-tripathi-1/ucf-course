#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
char * createStringDMA(int ptrSizeOfString);

int main()
{
    int *sizeOfString = NULL;

    sizeOfString = (int *)malloc(sizeof(int));

    if ( sizeOfString == NULL )
    {
        printf("Memory Allocation Failed!!");
        return 1;
    }

    printf("Enter the length of the string that you want to enter -\n");
    validInputCheck(sizeOfString, 0);


    char *stringPointer = createStringDMA(*sizeOfString + 1);

    printf("The string you entered is -\n\"%s.\"", stringPointer);

    free(sizeOfString);
    sizeOfString = NULL;

    free(stringPointer);
    stringPointer = NULL;

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
void removeNewLine(char *pstr, int *len)
{
    if( *len > 0 && pstr[*len-1] == '\n')
    {
        pstr[*len-1] = '\0';
        (*len)--;
    }
}

//@ Creating String using DMA
char * createStringDMA(int ptrSizeOfString)
{
    char *string = NULL;

    string = (char *)calloc(ptrSizeOfString, sizeof(char));

    if( string == NULL )
    {
        printf("Memory allocation for string failed!!");
        exit(1);
    }

    while ( getchar() != '\n');
    printf("Enter a string -\n");
    fgets(string, ptrSizeOfString, stdin);
    int length = strlen(string);
    removeNewLine(string, &length);
    
    return string;

}
