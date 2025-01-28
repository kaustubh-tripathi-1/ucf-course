//@ Using vector instead of raw pointers
/* #include<iostream>
#include<string>
#include<stdlib.h>
#include<stdexcept>

class Employee
{
    private:

        int empID;
        std::string empName;
        double empSalary;

    public:

        Employee(int empID = 0, const std::string &name = "New Joinee", double empSalary = 0)
        {
            setEmployee(empID, name, empSalary);
        }

        Employee(const Employee &emp)
        {
            this->empID = emp.empID;
            this->empName = emp.empName;
            this->empSalary = emp.empSalary;
        }

        Employee& setEmployee(int empID = 0, const std::string &name = "New Joinee", double empSalary = 0)
        {
            if ( empID < 0  )
                throw std::invalid_argument("Employee ID can't be negative!\n");
            if ( name.empty() )
                throw std::invalid_argument("Invalid Employee name!\n");
            if ( empSalary < 0 )
                throw std::invalid_argument("Employee salary can't be negative!\n");

            this->empID = empID;
            this->empName = name;
            this->empSalary = empSalary;

            return *this;
        }

        double getSalary() const 
        { 
            return empSalary; 
        }

        std::string getName() const
        {
            return empName;
        }

        void printEmployee() const
        {
            std::cout<<"E ID : "<<empID<<"\n"
                        <<"E Name : "<<empName<<"\n"
                        <<"E Salary : "<<empSalary<<"\n\n";
        }

        Employee& operator=(const Employee &emp)
        {
            if ( this == &emp )
                return *this;

            this->empID = emp.empID;
            this->empName = emp.empName;
            this->empSalary = emp.empSalary;

            return *this;
        }

};

void merge(Employee *eArray, int leftStart, int leftEnd, int rightStart, int rightEnd )
{
    int leftIndex = leftStart, rightIndex = rightStart;
    int sizeOfFirstArray = leftEnd - leftStart + 1;
    int sizeOfSecondArray = rightEnd - rightStart + 1;
    int mergedSize = sizeOfFirstArray + sizeOfSecondArray;

    Employee *mergedArray = new Employee[mergedSize];
    int mergedIndex = 0;

    while ( leftIndex <= leftEnd && rightIndex <= rightEnd )
    {
        if ( eArray[leftIndex].getSalary() < eArray[rightIndex].getSalary() )
            mergedArray[mergedIndex++] = eArray[leftIndex++];
        else
            mergedArray[mergedIndex++] = eArray[rightIndex++];
    }

    while ( leftIndex <= leftEnd )
    {
        mergedArray[mergedIndex++] = eArray[leftIndex++];
    }

    while ( rightIndex <= rightEnd )
    {
        mergedArray[mergedIndex++] = eArray[rightIndex++];
    }

    int left = leftStart;

    for ( mergedIndex = 0 ; mergedIndex < mergedSize && left <= rightEnd ; left++, mergedIndex++)
    {
        eArray[left] = mergedArray[mergedIndex];
    }

    delete[] mergedArray;
}

void mergeSort(Employee *eArray, int left, int right)
{
    if ( left >= right )
        return;

    int middle = left + (right - left ) / 2;

    mergeSort(eArray, left, middle);
    mergeSort(eArray, middle + 1, right);

    merge(eArray, left, middle, middle + 1, right);
}

int main()
{
    try
    {
        Employee *employees = new Employee[10];
        std::string names[] = {
                                "Kaustubh Tripathi",                    
                                "Shyam Tripathi",                    
                                "Rashmi Tripathi",                    
                                "Nakshatra Gupta",                    
                                "Thiya Sahu",                    
                                "Kushagra Sahu",                    
                                "Nidhi Sahu",                    
                                "Amit Sahu",                    
                                "Sanyam Panwar",                    
                                "Abhijeet Malik"                    
                            };

        srand(time(0));
        int i, eID;
        for ( i = 0, eID = 1 ; i < 10 ; i++, eID++ )
        {
            employees[i].setEmployee(eID, names[i], rand() % 100001);
        }

        std::cout<<"Employees before sorting (merge sort) based on salaries :\n\n";
        for ( int i = 0 ; i < 10 ; i++)
        {
            employees[i].printEmployee();
        }

        mergeSort(employees, 0, 9);
        
        std::cout<<"Employees after sorting (merge sort) based on salaries :\n\n";
        for ( int i = 0 ; i < 10 ; i++)
        {
            employees[i].printEmployee();
        }

        delete[] employees;
    }
    catch(std::exception &e)
    {
        std::cout<<"Caught Exception :"<<e.what()<<"\n";
    }

    std::cin.get();
    return 0;
} */

//@ Using vector instead of raw pointers
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>

class Employee
{
    private:
        int empID;
        std::string empName;
        double empSalary;

    public:
        Employee(int empID = 0, const std::string &name = "New Joinee", double empSalary = 0)
        {
            setEmployee(empID, name, empSalary);
        }

        Employee& setEmployee(int empID, const std::string &name, double empSalary)
        {
            if (empID < 0) throw std::invalid_argument("Employee ID can't be negative!");
            if (name.empty()) throw std::invalid_argument("Invalid Employee name!");
            if (empSalary < 0) throw std::invalid_argument("Employee salary can't be negative!");

            this->empID = empID;
            this->empName = name;
            this->empSalary = empSalary;
            return *this;
        }

        double getSalary() const { return empSalary; }
        std::string getName() const { return empName; }

        void printEmployee() const
        {
            std::cout << "E ID: " << empID << "\n"
                      << "E Name: " << empName << "\n"
                      << "E Salary: " << empSalary << "\n\n";
        }
};

// Merge function
void merge(std::vector<Employee> &eArray, int leftStart, int leftEnd, int rightStart, int rightEnd)
{
    std::vector<Employee> mergedArray;
    int leftIndex = leftStart, rightIndex = rightStart;

    while (leftIndex <= leftEnd && rightIndex <= rightEnd)
    {
        if (eArray[leftIndex].getSalary() < eArray[rightIndex].getSalary())
            mergedArray.push_back(eArray[leftIndex++]);
        else
            mergedArray.push_back(eArray[rightIndex++]);
    }

    while (leftIndex <= leftEnd) mergedArray.push_back(eArray[leftIndex++]);
    while (rightIndex <= rightEnd) mergedArray.push_back(eArray[rightIndex++]);

    for (int i = 0; i < mergedArray.size(); i++)
        eArray[leftStart + i] = mergedArray[i];
}

// Merge Sort Function
void mergeSort(std::vector<Employee> &eArray, int left, int right)
{
    if (left >= right) return;

    int middle = left + (right - left) / 2;
    mergeSort(eArray, left, middle);
    mergeSort(eArray, middle + 1, right);
    merge(eArray, left, middle, middle + 1, right);
}

// Main Function
int main()
{
    try
    {
        std::vector<Employee> employees;
        std::string names[] = {
            "Kaustubh Tripathi", "Shyam Tripathi", "Rashmi Tripathi",
            "Nakshatra Gupta", "Thiya Sahu", "Kushagra Sahu",
            "Nidhi Sahu", "Amit Sahu", "Sanyam Panwar", "Abhijeet Malik"
        };

        srand(time(0));
        for (int i = 0; i < 10; i++)
            employees.emplace_back(i + 1, names[i], rand() % 100001);

        std::cout << "Employees before sorting (merge sort) based on salary:\n\n";
        for (const auto &e : employees) e.printEmployee();

        mergeSort(employees, 0, employees.size() - 1);

        std::cout << "Employees after sorting (merge sort) based on salary:\n\n";
        for (const auto &e : employees) e.printEmployee();
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught Exception: " << e.what() << "\n";
    }

    std::cin.get();
    return 0;
}
