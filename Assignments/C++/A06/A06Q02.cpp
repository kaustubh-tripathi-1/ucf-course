#include<iostream>
#include <limits>
#include <stdio.h>
#include <string.h>
using namespace std;

void validInputCheck( int &, int );
void removeNewLine(char *str, int* len);
void stringsInput(int strings, char str[6][200], int *plengthOfStrings);
void stringsPrint(int strings, char str[6][200], int *plengthOfStrings);
void sortStrings(char str[6][200], int strings, int *plengthOfStrings, bool = true);

int main()
{
    int i;
    char str[6][200] = {
        "my name is kaustubh",
        "his name is tripathi",
        "rashmi tripathi",
        "shyam nandan tripathi",
        "her name is thiya sahu",
        "kaustubh tripathi"
    };
    int lengthOfStrings[6];

    for ( i = 0 ; i < 6 ; i++)
    {
        lengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &lengthOfStrings[i]);
    }


    // stringsInput(6, str, lengthOfStrings);

    cout<<"Here are the strings before sorting -"<<endl;   
    stringsPrint(6, str, lengthOfStrings);

    sortStrings(str, 6, lengthOfStrings, true);
    cout<<"Sorted Strings in ascending order -"<<endl;
    stringsPrint(6, str, lengthOfStrings);


    sortStrings(str, 6, lengthOfStrings, false);
    cout<<"Sorted Strings in descending order -"<<endl;
    stringsPrint(6, str, lengthOfStrings);


    // while ( getchar() != '\n');
    cin.get();
    return 0;
}

//@ Validate User Input of 1 int type value
void validInputCheck( int &n, int allowNegative)
{
    while ( 1 )
    {
        cin>>n;

        if( cin && (allowNegative || ( n >= 0  ) ))   //& Good State, Input Successful
            break;
        else
        {
            //& Invalid Input, Failure/Bad State
            cout<<"Invalid Input! Enter Again -"<<endl;

            //& Clear the fail/bad state
            cin.clear();

            //& Ignore invalid input until the '\n' char ( end of current line )
            cin.ignore( numeric_limits<streamsize>::max(), '\n');
            
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

//@ Strings Input
void stringsInput(int strings, char str[6][200], int *plengthOfStrings)
{
    cout<<"Enter strings -"<<endl;
    for ( int i = 0 ; i < strings ; i++)
    {
        cout<<"Enter string "<<i+1<<endl;
        fgets(str[i], 200, stdin);
        plengthOfStrings[i] = strlen(str[i]);
        removeNewLine(str[i], &plengthOfStrings[i]);
    }
}

//@ Strings Print
void stringsPrint(int strings, char str[6][200], int *plengthOfStrings)
{
    for ( int i = 0 ; i < strings ; i++)
        cout<<"\""<<str[i]<<"\""<<endl;

}

//@ Sorting Strings in ascending or descending order
void sortStrings(char str[6][200], int strings, int *plengthOfStrings, bool order)
{
    int i, j;

    if ( order )
    {
        for ( i = 0 ; i < strings - 1 ; i++)
        {
            for ( j = 0 ; j < strings-i-1 ; j++)
            {
                if ( strcmp(str[j], str[j+1]) == 1 )
                {
                    char temp[200];
                    strcpy(temp, str[j]);
                    strcpy(str[j], str[j+1]);
                    strcpy(str[j+1], temp);

                    int temp1 = plengthOfStrings[j];
                    plengthOfStrings[j] = plengthOfStrings[j+1];
                    plengthOfStrings[j+1] = temp1;
                }
            }
        }
    }
    else
    {
        for ( i = 0 ; i < strings - 1 ; i++)
        {
            for ( j = 0 ; j < strings-i-1 ; j++)
            {
                if ( strcmp(str[j], str[j+1]) == -1 )
                {
                    char temp[200];
                    strcpy(temp, str[j]);
                    strcpy(str[j], str[j+1]);
                    strcpy(str[j+1], temp);

                    int temp1 = plengthOfStrings[j];
                    plengthOfStrings[j] = plengthOfStrings[j+1];
                    plengthOfStrings[j+1] = temp1;
                }
            }
        }
    }
}