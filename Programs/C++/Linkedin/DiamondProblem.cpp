#include <iostream>
#include <string>

class Person  
{
protected:
    std::string name;

public:
    Person(std::string n) : name(n) {}

    void displayName() const
    {
        std::cout << "Name: " << name << "\n";
    }
};

class Employee : virtual public Person  
{
protected:
    int employeeID;

public:
    Employee(std::string n, int id) : Person(n), employeeID(id) {}

    void displayEmployeeInfo() const
    {
        std::cout << "Employee ID: " << employeeID << "\n";
    }
};

class Student : virtual public Person  
{
protected:
    int studentID;

public:
    Student(std::string n, int sid) : Person(n), studentID(sid) {}

    void displayStudentInfo() const
    {
        std::cout << "Student ID: " << studentID << "\n";
    }
};

class Intern : public Employee, public Student  
{
private:
    std::string internshipRole;

public:
    Intern(std::string n, int eid, int sid, std::string role)
        : Person(n), Employee(n, eid), Student(n, sid), internshipRole(role) {}

    void displayInternInfo() const
    {
        displayName(); // No ambiguity due to virtual inheritance
        displayEmployeeInfo();
        displayStudentInfo();
        std::cout << "Internship Role: " << internshipRole << "\n";
    }
};

int main()
{
    // Create an Intern object
    Intern intern("Alex", 101, 202, "Software Developer");

    // Display Intern's details
    intern.displayInternInfo();

    return 0;
}
