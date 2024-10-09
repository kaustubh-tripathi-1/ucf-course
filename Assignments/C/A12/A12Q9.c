#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1, n, validInput;
    printf("Enter the number upto which you want to print the cubes of the natural numbers :\n");
    
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

    printf("The cubes of first %d natural numbers are - \n");
    while(i<=n)
    {
        printf("%d\n", i*i*i);
        i++;
    }
    
    getch();
    return 0;
}