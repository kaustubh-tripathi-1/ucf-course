#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1, n, validInput;
    printf("Enter the natural number upto which you want to print the natural numbers :\n");

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

    printf("The natural numbers upto %d are - \n", n);
    while (i<=n)
    {
        printf("%d\n", i);
        i++;
    }
    
    
    getch();
    return 0;
}