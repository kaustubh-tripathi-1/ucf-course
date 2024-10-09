#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct Marks {
    
    int rollNo;
    char name[25];
    int chemMarks;
    int phyMarks;
    int mathsMarks;

}Marks;

void validInputCheck(int *, int );
void studentsDataInput(Marks *, int );
void studentsDataDisplayWithPercentage(Marks *, int );
void removeNewLine(char *, int* );

int main()
{
    int numberOfStudents;
    printf("Enter the number of students in you class -\n");
    validInputCheck(&numberOfStudents, 0);
    Marks students[numberOfStudents];


    studentsDataInput(students, numberOfStudents);

    studentsDataDisplayWithPercentage(students, numberOfStudents);

    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n > 0 )))
            break;
        else
        {
            printf("Enter valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Taking Input of Marks and Checking if it's valid
void validInputCheckMarks(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n >= 0 && *n <=100 )))
            break;
        else
        {
            printf("Enter valid marks between 0 and 100!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Removing New Line at the end of a String
void removeNewLine(char *pstr, int* len)
{
    if( *len > 0 && pstr[*len-1] == '\n')
    {
        pstr[*len-1] = '\0';
        (*len)--;
    }
}

//@ Taking Input of Student Data
void studentsDataInput(Marks *ptrStudents, int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        printf("Enter data for student %d -\n", i+1);
        printf("Enter Roll No -\n");
        validInputCheck(&ptrStudents[i].rollNo, 0);

        while ( getchar() != '\n');

        printf("Enter Name -\n");
        fgets( ptrStudents[i].name, sizeof(ptrStudents[i].name), stdin);
        int length = strlen(ptrStudents[i].name);
        removeNewLine(ptrStudents[i].name, &length);

        printf("Enter Marks scored in Chemistry -\n");
        validInputCheckMarks(&ptrStudents[i].chemMarks, 0);

        printf("Enter Marks scored in Physics -\n");
        validInputCheckMarks(&ptrStudents[i].phyMarks, 0);

        printf("Enter Marks scored in Maths -\n");
        validInputCheckMarks(&ptrStudents[i].mathsMarks, 0);
        
    }
}

//@ Displaying Student Data
void studentsDataDisplayWithPercentage(Marks *ptrStudents, int size)
{
    printf("Here's the student Data -\n");
    for ( int i = 0 ; i < size ; i++)
    {
        printf("\nStudent %d ", i+1);

        printf("Roll No. - %d\n", ptrStudents[i].rollNo);
        printf("Name - %s\n", ptrStudents[i].name);
        printf("Chemistry Marks - %d\n", ptrStudents[i].chemMarks);
        printf("Physics Marks- %d\n", ptrStudents[i].phyMarks);
        printf("Maths Marks - %d\n", ptrStudents[i].mathsMarks);

        float percentage = ((ptrStudents[i].chemMarks + ptrStudents[i].phyMarks + ptrStudents[i].mathsMarks) / 300.0) * 100.0;

        printf("Student %d's percentage is %.2f.\n", i+1, percentage);
        
        printf("\n");
    }
}