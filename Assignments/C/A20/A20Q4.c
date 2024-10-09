#include<stdio.h>
#include<conio.h>

int main()
{
    char c;

    printf("Enter a character to know if know the category (Vowel, Consonant or a special character) :\n");
    scanf("%c", &c);

    switch(c)
    {
        //* Vowels 
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a':case 'e': case 'i': case 'o': case 'u':
            printf("%c is a Vowel.\n", c);
            break;
        //* Consonants
        case 'B' ... 'D': case 'F' ... 'H': case 'J' ... 'N': 
        case 'P' ... 'T': case 'V' ... 'Z': case 'b' ... 'd':
        case 'f' ... 'h':  case 'j' ... 'n': case 'p' ... 't':
        case 'v' ... 'z':
            printf("%c is a Consonant.\n", c);
            break;
        //* Special Characters
        default:
            printf("%c is a Special Character.\n", c);
            break;
    }
    
    getch();
    return 0;
}
