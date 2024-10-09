#include<stdio.h>
#include<conio.h>

int main()
{
    int a, b, c, discriminant;
    printf("Enter the value of a, b & c in a quadratic eq. to know the nature of its roots :\n");
    while( scanf("%d%d%d", &a, &b, &c) !=3 )
    {
        while(getchar() != '\n');
        printf("Enter valid numbers!!\n");
    } 
    
    discriminant = (b*b) - (4*a*c);

    /* if(discriminant>0)
        printf("Roots of the quadratic equation are Real and Distinct.");
    else if(discriminant<0)
        printf("Roots of the quadratic equation are Imaginary/Complex.");
    else
        printf("Roots of the quadratic equation are Real and Equal."); */

    discriminant>0 ? ({ printf("Roots of the quadratic equation are Real and Distinct.");
    printf("Roots ");}):({printf("Roots of the quadratic equation are Imaginary/Complex.");});
    
    getch();
    return 0;
}