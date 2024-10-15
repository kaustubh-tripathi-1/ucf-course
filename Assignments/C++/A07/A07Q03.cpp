#include<iostream>
#include <limits>
#include <cstring>
using namespace std;

void validInputCheck( int &n, int allowNegative);
void subString(char *, int, int, int = -1);

int main()
{
    char str[100] = "My name is Kaustubh Tripathi.";

    int length = strlen(str);
    if ( length>0 && str[length-1] == '\n')
    {
        str[length-1] = '\0';
        length--;
    }

    int startIndex, endIndex;
    cout<<"Enter start and end Index to print sub-string -"<<endl;
    validInputCheck(startIndex, 0);
    validInputCheck(endIndex, 0);

    cout<<"With End Index -"<<endl;
    subString(str, length, startIndex, endIndex);

    cout<<endl<<"Without End Index -"<<endl;
    subString(str, length, startIndex);

    while ( getchar() != '\n');
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

void subString(char *pstr, int len, int startIndex, int endIndex)
{

    if ( endIndex == -1)
        endIndex = len;
    
    if ( (startIndex >= endIndex) || (startIndex < 0) || (endIndex > len-1) )
    {
        cout<<"Invalid Indices!"<<endl;
        return;
    }

    for ( int i = startIndex ; i < endIndex; i++)
        cout<<pstr[i];

}