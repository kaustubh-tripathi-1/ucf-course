#include<stdio.h>
#include<conio.h>

int main()
{
    int num, num_copy, validInput, count=0;
    printf("Enter a number to count the digits - \n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d", &num);

        if ( validInput==1 )
            break;
        else
        {
            printf("Enter valid numbers only!!\n");
            while( getchar() != '\n');
        }
    }

    num_copy = num; //$ Using num_copy as the original number has to be preserved
    
    if(num_copy > 0)     //$ If number is +ve
    {
        while(num_copy > 0)
        {
            num_copy /= 10;
            count++;
        }
    }

    else if( num_copy < 0 ) //$ If number is -ve
    {
        while( num_copy < 0)
        {
            num_copy /= 10;
            count++;
        }
    }

    else        //$ If number is 0
    {
        count=1;
    }
    
    printf("%d is a %d digit number.", num, count);
    
    getch();
    return 0;
}