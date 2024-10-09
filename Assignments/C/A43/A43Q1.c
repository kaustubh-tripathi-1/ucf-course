#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int*);
void swapStrings(char **, char **, int* , int* );

int main()
{
    int length1, length2, i;
    printf("Enter the max length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length1, 0);
    printf("Enter the max length/memory that you want to reserve for 2nd string -\n");
    validInputCheck(&length2, 0);

    char str1[length1], str2[length2];

    while ( getchar() != '\n' );

    printf("Enter 1st string to swap them -\n");
    fgets(str1, sizeof(str1), stdin);

    length1 = strlen(str1);
    removeNewLine(str1, &length1);

    printf("Enter 2nd string to swap them -\n");
    fgets(str2, sizeof(str2), stdin);

    length2 = strlen(str2);
    removeNewLine(str2, &length2);

    char *s1 = str1, *s2 = str2;

    printf("\n********Before Swapping********\n");
    printf("String 1 - \n\"%s\"\nString 2 -\n\"%s\"\n\n", str1, str2);

    swapStrings(&s1, &s2, &length1, &length2);

    printf("********After Swapping********\n");
    printf("String 1 - \n\"%s\"\nString 2 -\n\"%s\"\n", str1, str2);

    printf("L1- %d\nL2 - %d", length1, length2);

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
void removeNewLine(char *str, int* len)
{
    if( *len > 0 && str[*len-1] == '\n')
    {
        str[*len-1] = '\0';
        (*len)--;
    }
}

//@ Swapping 2 strings using Pointers
void swapStrings(char **pstr1, char **pstr2, int *length1, int *length2)
{

    /* //$ Only swapping addresses in pointers, not the actual strings
    char *temp ;
    
    temp = *pstr1;
    *pstr1 = *pstr2;
    *pstr2 = temp; */

    //$ Swapping entire strings char by char using pointers until reaching the shorter length
    int i, minLength = *length1 < *length2 ? *length1 : *length2;
    for (  i = 0 ; i < minLength ; i++ )
    {
        char temp = (*pstr1)[i];
        (*pstr1)[i] = (*pstr2)[i];
        (*pstr2)[i] = temp;
    }
    
    //$ If length1 > length2, transferring the rest of string1 to string 2
    if ( *length1 > *length2 )
    {
        int k = i;
        for ( ; i < *length1 ; i++)
        {
            (*pstr2)[i] = (*pstr1)[i];
        }
        (*pstr2)[i] = '\0';
        (*pstr1)[k] = '\0';
        *length2 = i;
        *length1 = k;
    }
    //$ If length2 > length1, transferring the rest of string2 to string 1
    else if ( *length2 > *length1 )
    {
        int k = i;
        for ( ; i < *length2 ; i++)
        {
            (*pstr1)[i] = (*pstr2)[i];
        }
        (*pstr1)[i] = '\0';
        (*pstr2)[k] = '\0';
        *length1 = i;
        *length2 = k;
    }
   
}