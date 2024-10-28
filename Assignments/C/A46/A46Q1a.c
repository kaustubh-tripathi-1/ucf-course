#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void validInputCheck(int *, int );
void removeNewLine(char *, int* );
char *createStringDMA();

int main()
{
    char *stringPointer = createStringDMA();

    printf("The string you entered is -\n\"%s.\"", stringPointer);

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
char *createStringDMA()
{
    //$ Reading string char by char and increasing the size of array as we go
    char *str1 = NULL, *str2 = NULL, ch;
    int size=1, i;

    while (1)
    {
        ch = getchar();
        if ( ch == '\n')
            break;
        
        str1 = (char *)malloc(size);
        
        if( str2 )
        {
            for ( i = 0 ; i < size ; i++)
                str1[i] = str2[i];

            str1[i-1] = ch;

            free(str2);
        }   
        else
        {
            *str1 = ch;
        }

        str2 = (char *)malloc(size+1);

        for ( i = 0 ; i < size ; i++)
            str2[i] = str1[i];

        str2[i] = '\0';

        free(str1);

        size++;
    }

    return str2;
    
}


