#include<stdio.h>
#include<conio.h>

int main()
{
    int i, n, validInput;
    printf("Enter the natural number from which you want to print the natural numbers in reverse order:\n");

    while (1)
    {
        validInput = scanf("%d", &n);
        if(validInput==1)
            break;
        else
        {
            printf("Enter valid numbers!!\n");
            while( getchar() != '\n');
        }
    }
    
    printf("The natural numbers from %d to 1 in reverse order are - \n", n);

    i=n;
    while (i>=1)
    {
        printf("%d\n", i);
        i--;
    }
    
    
    getch();
    return 0;
}