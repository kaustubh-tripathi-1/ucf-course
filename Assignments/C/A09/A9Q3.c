#include<stdio.h>
#include<conio.h>

int main()
{
    char a;
    printf("Enter an alphabet to check its Case -\n");

    while(1)
    {
        scanf("%c", &a);

        // Check if the character is a valid alphabet
        if( (a>=65 && a<=90) || (a>=97 && a<=122) )
            break;      // Exit the loop if a valid alphabet is entered
            
        else if(a!='\n') // Discard invalid input
        {
            printf("Enter only alphabets!!\n");
            // Clear the input buffer
            while( getchar() != '\n'); // Discard the rest of the line
        }
    }

    if(a>=65 && a<=90 )
        printf("%c is an Uppercase Alphabet.\n", a);
    else if(a>=97 && a<=122)
        printf("%c is an Lowercase Alphabet.\n", a);

    getch();
    return 0;
}