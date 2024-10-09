#include<stdio.h>
#include<conio.h>

int main()
{
    int year;
    printf("Enter a year to check if it's Leap or not :\n");
    while( scanf("%d", &year) != 1 || year<0 )
    {
        while( getchar() != '\n' );
        printf("Enter a valid year!!");
    }

    if(year%100 == 0)
    {
        if (year%400 == 0)
        {
            printf("%d year is Leap.", year);
        }
        else
            printf("%d year is not Leap.", year);
    }    
    else
    {   
        if( year%4 == 0 )
            printf("%d year is Leap.", year);
        else
            printf("%d year is not Leap.", year);
    }
    getch();
    return 0;
}