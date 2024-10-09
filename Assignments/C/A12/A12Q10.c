#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1, n, validInput;
    printf("Enter a number for which you want to print the table of - \n");
    
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
    
    printf("The table of %d is -\n");
    
    while(i<=10)
    {
        printf("%d x %d = %d\n", n, i, n*i);
        i++;
    }
    
    getch();
    return 0;
}