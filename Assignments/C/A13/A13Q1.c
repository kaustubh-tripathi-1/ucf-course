#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1, n, sum=0, validInput;
    printf("Enter the natural number upto which you want to calculate the sum of first NN : \n");
    
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

    while(i<=n)
    {
        sum += i;
        i++; 
    }
    
    printf("The sum of First %d NN is %d.", n, sum);
    
    getch();
    return 0;
}