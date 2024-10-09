#include<stdio.h>
#include<conio.h>

int main()
{
    int num, num_copy, rev_num = 0, validInput;
    printf("Enter a number to reverse it - \n");
    
    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d", &num);

        if ( validInput==1 )
            break;
        else
        {
            printf("Enter valid and positive numbers only!!\n");
            while( getchar() != '\n');
        }
    }

    num_copy = num;

    if( num > 0 )
    {
        while (num > 0)
        {
            rev_num = (rev_num*10) + (num%10); 
            num/=10;
        }
    }
    else if( num < 0 )
    {
        while (num < 0)
        {
            rev_num = (rev_num*10) + (num%10); 
            num/=10;
        }
    }
    
    printf("The reverse of %d is %d.\n", num_copy, rev_num);
    
    getch();
    return 0;
}