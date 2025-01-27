#include<iostream>
#include<string>

class Employee
{
    private:

        int empID;
        std::string empName;
        double empSalary;

    public:

        Employee(int empID = 0, const std::string &name = "New Joinee", double empSalary = 0)
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

        friend int hoarePartition(Employee *eArray, int left, int right);

};

int nameCompare(const std::string &name1, const std::string &name2) 
{
    size_t minLength = std::min(name1.length(), name2.length());

    for (size_t i = 0; i < minLength; i++) 
    {
        if (name1[i] < name2[i]) return -1;  // name1 comes first
        if (name1[i] > name2[i]) return 1;   // name2 comes first
    }

    // If common part is same, shorter name comes first
    if (name1.length() < name2.length()) return -1;
    if (name1.length() > name2.length()) return 1;
    
    return 0; // Both are the same
}

int hoarePartition(Employee *eArray, int left, int right)
{
    std::string &pivot = eArray[left].empName;
    int leftPtr = left-1, rightPtr = right+1;

    //& Using Pre-defined overloaded operator < and > to compare names
    /* while ( true )
    {
        do
        {
            leftPtr++;
        } while ( pivot > eArray[leftPtr].empName );

        do
        {
            rightPtr--;
        } while ( pivot < eArray[rightPtr].empName );

        if ( leftPtr >= rightPtr)
            return rightPtr;

        std::swap(eArray[leftPtr], eArray[rightPtr]);
    } */

    //& Using a separate method to compare names
    while ( true )
    {
        do
        {
            leftPtr++;
        } while ( nameCompare(eArray[leftPtr].empName, pivot) == -1 );

        do
        {
            rightPtr--;
        } while ( nameCompare(eArray[rightPtr].empName, pivot) == 1 );

        if ( leftPtr >= rightPtr)
            return rightPtr;

        std::swap(eArray[leftPtr], eArray[rightPtr]);
    }

}

void quickSort(Employee *eArray, int left, int right)
{
    if ( left >= right )
        return;

    int pivotIndex = hoarePartition(eArray, left, right);

    quickSort(eArray, left, pivotIndex);
    quickSort(eArray, pivotIndex+1, right);
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

        double eSalary;
        int i, eID;
        for ( i = 0, eID = 1, eSalary = 100000 ; i < 10 ; i++, eID++, eSalary-=1000 )
        {
            employees[i].setEmployee(eID, names[i], eSalary);
        }

        std::cout<<"Employees before sorting (quick sort) based on names :\n\n";
        for ( int i = 0 ; i < 10 ; i++)
        {
            employees[i].printEmployee();
        }

        quickSort(employees, 0, 9);
        
        std::cout<<"Employees before sorting (quick sort) based on names :\n\n";
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
}