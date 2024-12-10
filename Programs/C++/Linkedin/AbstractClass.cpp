#include <iostream>
#include <string>

// Abstract class
class Employee  
{
protected:
    std::string name;

public:
    Employee(const std::string &empName) : name(empName) {}

    // Pure virtual function
    virtual void work() const = 0;

    // Virtual destructor for proper cleanup
    virtual ~Employee() 
    {
        std::cout << "Employee destructor called for " << name << std::endl;
    }
};

class Developer : public Employee  
{
public:
    Developer(const std::string &empName) : Employee(empName) {}

    void work() const override // Implementation of pure virtual function
    {
        std::cout << name << " is writing code.\n";
    }

    ~Developer() 
    {
        std::cout << "Developer destructor called for " << name << std::endl;
    }
};

class Manager : public Employee  
{
public:
    Manager(const std::string &empName) : Employee(empName) {}

    void work() const override // Implementation of pure virtual function
    {
        std::cout << name << " is managing projects.\n";
    }

    ~Manager() 
    {
        std::cout << "Manager destructor called for " << name << std::endl;
    }
};

int main()  
{
    Employee *e1 = new Developer("Alice");
    Employee *e2 = new Manager("Bob");

    e1->work(); // Calls Developer's work()
    e2->work(); // Calls Manager's work()

    delete e1; // Proper cleanup due to virtual destructor
    delete e2;

    return 0;
}
