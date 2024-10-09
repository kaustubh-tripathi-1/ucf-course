#include<stdio.h>
#include<conio.h>
#include<string.h>


void validInputCheck(int *, int );
void removeNewLine(char [], int* );
void concat(char [], int*, char [], int);

int main()
{
    int length1, length2;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length1, 0);
    printf("Enter the length/memory that you want to reserve for 2nd string -\n");
    validInputCheck(&length2, 0);
    char str1[length1], str2[length2];
    
    while( getchar() != '\n');      //$ Clearing the input buffer

    printf("Enter a string 1 to concatenate -\n");
    fgets(str1, sizeof(str1), stdin);       //$ String1 Input

    printf("Enter a string 2 to concatenate -\n");
    fgets(str2, sizeof(str2), stdin);       //$ String2 Input

    length1  = strlen(str1);

    removeNewLine(str1, &length1);

    length2  = strlen(str2);

    removeNewLine(str2, &length2);

    if( length1 > 0 && length2 > 0)
    {
        concat( str1, &length1, str2, length2 );
        printf("The concatenated string is -\n\"%s\".", str1);
    }
    else
        printf("One of the strings you entered is Empty.");

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

//@ Making the first letter of every word in the string Capital
void concat(char str1[], int* len1, char str2[], int len2)
{
    //$ My Logic
    /* *len1 += len2 + 1;
    
    int i, j;

    str1[*len1 - len2 - 1] = ' ';

    for ( i = *len1 - len2, j = 0 ; i <= *len1 && j <= len2 ; i++, j++)
        str1[i] = str2[j]; */

    //$ Another logic w/o extra space

    int i, j;

    for ( i = *len1, j = 0 ; j < len2 ; i++, j++)
        str1[i] = str2[j];

    str1[i] = '\0';

    *len1 = i; 

}