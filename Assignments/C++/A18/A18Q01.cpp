#include<iostream>

class Person
{
    private :

        std::string name;
        int age;

    protected :

        bool isValid;

    public :

        //$ Setters
        void setNameAndAge(std::string name, int age)
        {
            if (!name.empty() && age >= 0)
            {
                this->name = name;
                this->age = age;
                isValid = true;
            }
            else
            {
                std::cout<<"Invalid Values for a Person!\n";
                isValid = false;
            }
        }
        void setName(std::string name)
        {
            if (!name.empty())
            {
                this->name = name;
                isValid = true;
            }
            else
            {
                std::cout<<"Invalid Name for a Person!\n";
                isValid = false;
            }
        }
        void setAge( int age)
        {
            if ( age >= 0)
            {
                this->age = age;
                isValid = true;
            }
            else
            {
                std::cout<<"Invalid Age for a Person!\n";
                isValid = false;
            }
        }

        //$ Getters
        std::string getName() const
        {
            return this->name;
        }

        int getAge() const
        {
            return this->age;
        }


        //$ Default Param Constructor
        Person(std::string name, int age)
        :
            name(name), age(age), isValid(true)
        {
            if ( this->name.empty() || this->age < 0)
            {
                isValid = false;
                this->name = "Default Name";
                this->age = 0;
                std::cout<<"Invalid Values for a Person!\n";
            }
        }

        Person( const Person &p)
        :
            name(p.name), age(p.age), isValid(p.isValid) {}

};

class Employee : public Person
{
    private :

        double empSalary;

    public :

        Employee(std::string name, int age, double empSalary)
        :
            Person(name, age), empSalary(empSalary)
        {
            if( empSalary < 0)
            {
                isValid = false;
                this->empSalary = 0;
                std::cout<<"Invalid Employee Salary! Set to 0.\n";
            }
        }

        Employee(const Employee &e)
        :
            Person(e), empSalary(e.empSalary) {}

        void setEmployee(std::string name, int age, double empSalary)
        {
            setNameAndAge(name, age);
            if ( empSalary < 0)
            {
                isValid = false;
                std::cout<<"Invalid Salary for an Employee!\n";
            }
            else if (isValid)
            {
                this->empSalary = empSalary;
            }

        }

        void showEmployee() const
        {
            if( isValid )
            {
                std::cout<<"Employee Details -\n";
                std::cout<<"Name - "<<getName()<<"\n"
                        <<"Age - "<<getAge()<<"\n"
                        <<"Salary - "<<empSalary<<"\n";
            }
            else
            {
                std::cout<<"Cannot display employee, details are invalid!\n";
            }

        }
};

int main()
{
    Employee e1("Kaustubh Tripathi", 25, 120000);
    std::cout<<"Valid Employee -\n";
    e1.showEmployee();

    Employee e2(e1);
    std::cout<<"Employee 2 with Copy Constructor -\n";
    e2.showEmployee();

    Employee e3 = {"", -4, -213};
    std::cout<<"Employee 3 with all Invalid Values -\n";
    e3.showEmployee();

    Employee e4("Nakshatra", 25, -324);
    std::cout<<"Employee 4 with Invalid Salary -\n";
    e4.showEmployee();


    std::cin.get();
    return 0;
}