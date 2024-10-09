#include<stdio.h>
#include<conio.h>

int main()
{
    double l, b, h;
    printf("Enter the side of a cuboid to calculate the volume :\n");
    scanf("%lf%lf%lf", &l, &b, &h);

    while(l<0 || b<0 || h<0 )
    {
        if(l<0)
        {
            printf("Length of a cuboid can't be -ve. Enter +ve value only :\n");
            scanf("%lf", &l);
        }
        if(b<0)
        {
            printf("Breadth of a cuboid can't be -ve. Enter +ve value only :\n");
            scanf("%lf", &b);
        }
        if(h<0)
        {
            printf("Height of a cuboid can't be -ve. Enter +ve value only :\n");
            scanf("%lf", &h);
        }
    }

    printf("The volume of cuboid is %lf", l*b*h);
    getch();
    return 0;
}