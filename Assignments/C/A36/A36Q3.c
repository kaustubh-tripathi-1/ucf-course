#include<stdio.h>
#include<conio.h>
#include<string.h>

void validInputCheck(int *, int );
int removeNewLine(char [], int );
void converToLowerCase(char [], int );
int compareStrings(char [], int, char [], int);

int main()
{
    int length1, length2, order;
    printf("Enter the length/memory that you want to reserve for 1st string -\n");
    validInputCheck(&length1, 0);           //$ Length Input
    printf("Enter the length/memory that you want to reserve for 2nd string -\n");
    validInputCheck(&length2, 0);           //$ Length Input
    char str1[length1], str2[length2];

    while( getchar() != '\n');

    printf("Enter the 1st string for comparison -\n");
    fgets(str1, sizeof(str1), stdin);       //$ String Input

    printf("Enter the 2nd string for comparison -\n");
    fgets(str2, sizeof(str2), stdin);       //$ String Input

    length1 = strlen(str1);     //$ Calculating Length of String
    length2 = strlen(str2);     //$ Calculating Length of String

    length1 = removeNewLine( str1, length1 );    //$ Removing New Line
    length2 = removeNewLine( str2, length2 );    //$ Removing New Line

    converToLowerCase(str1, length1);   //$ Converting String to Lowercase
    converToLowerCase(str2, length2);   //$ Converting String to Lowercase

    order = compareStrings(str1, length1, str2, length2);  //$ Comparing Strings

    if(order == -1)
        printf("The strings are in dictionary order.\n");
    else if(order == 1)
        printf("The strings are not in dictionary order.\n");
    else if( order == 0)
        printf("The strings are same.\n");

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

//@ Converting String to LowerCase
void converToLowerCase(char str[], int len)
{
    int i;
    for( i = 0; i < len ; i++)
    {
        if( str[i] >= 'A' && str[i] <= 'Z' )
            str[i] += 32;
    }
}

//@ Comparing 2 strings
int compareStrings(char str1[], int len1, char str2[], int len2)
{
    int i, j;
    for(i=0 ; i < len1 && i < len2 ; i++)
    {
        if( str1[i] < str2[i] )
            return -1;      //$ In Dictionary Order
        else if( str1[i] > str2[i] )
            return 1;       //$ Not in Dictionary Order
    }

    //$ If the strings are the same up to the shorter length
    if(i == len1 && len1 == len2)
        return 0;           //$ Strings are same
    else if ( i == len1 && i < len2 )
        return -1;          //$ In Dictionary Order
    else if ( i == len2 && i < len1 )
        return 1;           //$ Not in Dictionary Order
}