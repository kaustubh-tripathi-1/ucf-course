#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct Employee
{
    int id;
    char name[20];
    float salary;
}Employee;

void structureInput(Employee *);
void displayStructure(Employee );

int main()
{
    Employee e1;

    structureInput(&e1);

    displayStructure(e1);
    
    getch();
    return 0;
}

void structureInput(Employee *e1)
{
    printf("Enter Employee ID -\n");
    scanf("%d", &e1->id);

    while ( getchar() != '\n');

    printf("Enter Name -\n");
    fgets(e1->name, sizeof(e1->name), stdin);
    
    printf("Enter Employee salary -\n");
    scanf("%f", &e1->salary);

}

void displayStructure(Employee e1)
{
    printf("Employee ID - %d\nEmployee Name - %s\nEmployee Salary - %f.", e1.id, e1.name, e1.salary);
}
