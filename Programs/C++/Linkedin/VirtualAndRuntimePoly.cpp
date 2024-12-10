#include <iostream>
#include <string>

class Employee  
{
protected:
    std::string name;

public:
    Employee(const std::string &empName) : name(empName) {}

    virtual void work() const // Virtual function for runtime polymorphism
    {
        std::cout << name << " is doing general tasks.\n";
    }

    virtual ~Employee() {} // Virtual destructor for proper cleanup
};

class Developer : public Employee  
{
public:
    Developer(const std::string &empName) : Employee(empName) {}

    void work() const override // Overriding base class function
    {
        std::cout << name << " is writing and debugging code.\n";
    }
};

class Manager : public Employee  
{
public:
    Manager(const std::string &empName) : Employee(empName) {}

    void work() const override // Overriding base class function
    {
        std::cout << name << " is planning and managing projects.\n";
    }
};

void assignWork(const Employee &emp)  
{
    emp.work(); // Calls the appropriate function at runtime
}

int main()  
{
    Developer dev("Alice");
    Manager mgr("Bob");
    Employee gen("Charlie");

    assignWork(dev); // Calls Developer's work()
    assignWork(mgr); // Calls Manager's work()
    assignWork(gen); // Calls Employee's work()

    return 0;
}