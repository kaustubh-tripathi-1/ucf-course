#include<stdio.h>
#include<conio.h>

int main()
{
    int i, n, validInput;
    printf("Enter the number of even natural numbers you want to print in reverse order:\n");

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

    printf("The First %d even natural numbers in reverse order are - \n", n);

    i=n;
    while (i>=1)
    {
        printf("%d\n", (2*i));
        i--;
    }
        
    getch();
    return 0;
}