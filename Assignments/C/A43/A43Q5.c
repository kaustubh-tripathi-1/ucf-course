#include<stdio.h>
#include<conio.h>

int findHighestMarks(int **, int *, int);

int main()
{
    int class1Marks[12] = {98, 79, 84, 76, 92, 99, 65, 85, 87, 81, 59, 83} ;
    int class2Marks[10] = {96, 68, 59, 94, 84, 97, 78, 74, 69, 62} ;
    int class3Marks[8] = {93, 65, 76, 49, 80, 91, 72, 54} ;
    int class4Marks[9] = {65, 92, 64, 71, 45, 54, 98, 73, 58} ;
    int class5Marks[7] = {94, 92, 61, 77, 44, 99, 66} ;

    int sizeOfClasses[5] = {
        sizeof(class1Marks) / sizeof(class1Marks[0]),
        sizeof(class2Marks) / sizeof(class2Marks[0]),
        sizeof(class3Marks) / sizeof(class3Marks[0]),
        sizeof(class4Marks) / sizeof(class4Marks[0]),
        sizeof(class5Marks) / sizeof(class5Marks[0])
    };

    
    int *class[5] = {
        class1Marks,
        class2Marks,
        class3Marks,
        class4Marks,
        class5Marks
    };
    int sizeOfPtrArray = sizeof(class) / sizeof(class[0]); 
    
    int highestmarks = findHighestMarks(class, sizeOfClasses, sizeOfPtrArray);

    printf("The highest marks in all the classes is - %d.\n", highestmarks);

    getch();
    return 0;
}

//@ Function to find highest marsk in all classes
int findHighestMarks(int **ptrArrayClass, int *ptrSizeOfClasses, int sizeOfPtrArray)
{
    int highestmarks = ptrArrayClass[0][0];

    for ( int i = 0 ; i < sizeOfPtrArray ; i++)
    {
        for ( int j = 0 ; j < ptrSizeOfClasses[i] ; j++)
        {
            if ( highestmarks < ptrArrayClass[i][j])
            {
                highestmarks = ptrArrayClass[i][j];
            }
        }
    }

    return highestmarks;
    
}