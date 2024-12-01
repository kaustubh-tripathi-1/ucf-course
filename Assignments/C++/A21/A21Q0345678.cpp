#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

class Employee
{
    private :

        int empID;
        std::string name;
        double empSalary;
        bool isValid;

    public:

        Employee(int empID, std::string name, double empSalary)
        :
            empID(empID), name(name), empSalary(empSalary)
        {
            if (name.empty() || empID < 0 || empSalary < 0)
            {
                isValid = false;
                std::cout<<"Invalid Values for an Employee!\n";
            }
            else
            {
                isValid = true;
            }
        }

        Employee(const Employee &emp)
        :
            empID(emp.empID), name(emp.name), empSalary(emp.empSalary), isValid(emp.isValid) {}

        
        void setEmployee(int empID, std::string name, double empSalary)
        {
            if (name.empty() || empID < 0 || empSalary < 0)
            {
                isValid = false;
                std::cout<<"Invalid Values for an Employee!\n";
            }
            else
            {
                isValid = true;
                this->name = name;
                this->empID = empID;
                this->empSalary = empSalary;
            }
        }

        void showEmployee() const
        {
            if( isValid )
            {
                std::cout<<"Employee Details -\n";
                std::cout<<"Name - "<<name<<"\n"
                        <<"Employee ID - "<<empID<<"\n"
                        <<"Salary - "<<empSalary<<"\n";
            }
            else
            {
                std::cout<<"Cannot display employee, details are invalid! Set Employee values again with setEmployee()\n";
            }

        }

        void saveToFile(std::string &fileName)
        {
            std::ofstream empFile(fileName, std::ios::app);

            if ( empFile.is_open() )
            {
                empFile<<empID<<","<<name<<","<<empSalary<<"\n";

                empFile.close();
            }
            else
            {
                std::cout<<"Unable to open file for writing.\n";
            }
        }

        static void viewAllEmployees(std::string &fileName)
        {
            std::ifstream empFile(fileName, std::ios::in);

            if ( empFile.is_open() )
            {
                std::string line;
                bool isEmpty = true;

                while(std::getline(empFile, line))
                {
                    isEmpty = false;
                    std::stringstream ss(line);
                    std::string empID, empName, empSalary;

                    std::getline(ss, empID, ',');
                    std::getline(ss, empName, ',');
                    std::getline(ss, empSalary, ',');

                    std::cout << "Employee Details -\n";
                    std::cout << "Name - " << empName << "\n"
                            << "Employee ID - " << empID << "\n"
                            << "Salary - " << empSalary << "\n\n";
                    
                }
                if ( isEmpty )
                {
                    std::cout<<"File is empty!\n";
                }
                empFile.close();
            }
            else
            {
                std::cout<<"Unable to open file for reading..\n";
            }
        }

        static void searchEmployee(std::string &fileName, int employeeID)
        {
            std::ifstream empFile(fileName, std::ios::in);

            if ( empFile.is_open() )
            {
                std::string line;
                bool isEmpty = true;
                bool found = false;

                while(std::getline(empFile, line))
                {
                    isEmpty = false;
                    std::stringstream ss(line);
                    std::string empID, empName, empSalary;

                    std::getline(ss, empID, ',');
                    std::getline(ss, empName, ',');
                    std::getline(ss, empSalary, ',');

                    int empIDAsInt  = std::stoi(empID);

                    if ( employeeID == empIDAsInt )
                    {
                        std::cout << "Found!!\nEmployee Details -\n";
                        std::cout << "Name - " << empName << "\n"
                                << "Employee ID - " << empID << "\n"
                                << "Salary - " << empSalary << "\n\n";

                        found = true;
                        break;
                    }
                }
                if ( !found )
                {
                    std::cout<<"Employee with "<<employeeID<<" not found.\n";
                }
                if ( isEmpty )
                {
                    std::cout<<"File is empty!\n";
                }
                empFile.close();
            }
            else
            {
                std::cout<<"Unable to open file for reading..\n";
            }
        }

        //$ Modify Employee Using Temporary File
        static void modifyEmployee(const std::string &fileName, int employeeID)
        {
            std::ifstream empFile(fileName, std::ios::in);
            std::ofstream tempFile("temp.txt", std::ios::out | std::ios::trunc);

            if (empFile.is_open() && tempFile.is_open())
            {
                std::string line;
                bool found = false;

                while (std::getline(empFile, line))
                {
                    std::stringstream ss(line);
                    std::string empID, empName, empSalary;
                    std::getline(ss, empID, ',');
                    std::getline(ss, empName, ',');
                    std::getline(ss, empSalary, ',');

                    int empIDAsInt = std::stoi(empID);

                    if (empIDAsInt == employeeID)
                    {
                        found = true;

                        // Prompt user for new data
                        std::cout << "Enter new name: ";
                        std::string newName;
                        std::getline(std::cin >> std::ws, newName);

                        std::cout << "Enter new salary: ";
                        double newSalary;
                        std::cin >> newSalary;

                        // Write updated record to the temp file
                        tempFile << employeeID << "," << newName << "," << newSalary << "\n";
                    }
                    else
                    {
                        // Write original record to the temp file
                        tempFile << line << "\n";
                    }
                }

                empFile.close();
                tempFile.close();

                if (!found)
                {
                    std::cout << "Employee with ID " << employeeID << " not found.\n";
                }
                else
                {
                    // Replace original file with temp file
                    std::remove(fileName.c_str());
                    std::rename("temp.txt", fileName.c_str());
                    std::cout << "Employee with ID " << employeeID << " has been updated.\n";
                }
            }
            else
            {
                std::cout << "Unable to open file.\n";
            }
        }

        //$ Delete Employee Using Temporary File
        static void deleteEmployee(const std::string &fileName, int employeeID)
        {
            std::ifstream empFile(fileName, std::ios::in);
            std::ofstream tempFile("temp.txt", std::ios::out | std::ios::trunc);

            if (empFile.is_open() && tempFile.is_open())
            {
                std::string line;
                bool found = false;

                while (std::getline(empFile, line))
                {
                    std::stringstream ss(line);
                    std::string empID, empName, empSalary;
                    std::getline(ss, empID, ',');
                    std::getline(ss, empName, ',');
                    std::getline(ss, empSalary, ',');

                    int empIDAsInt = std::stoi(empID);

                    if (empIDAsInt == employeeID)
                    {
                        found = true; // Skip this record
                    }
                    else
                    {
                        // Write original record to the temp file
                        tempFile << line << "\n";
                    }
                }

                empFile.close();
                tempFile.close();

                if (!found)
                {
                    std::cout << "Employee with ID " << employeeID << " not found.\n";
                }
                else
                {
                    // Replace original file with temp file
                    std::remove(fileName.c_str());
                    std::rename("temp.txt", fileName.c_str());
                    std::cout << "Employee with ID " << employeeID << " has been deleted.\n";
                }
            }
            else
            {
                std::cout << "Unable to open file.\n";
            }
        }


};

int main()
{
    std::string fileName = "employeeFile.txt";

    // Add employees
    Employee e1(1, "Kaustubh Tripathi", 120000);
    e1.saveToFile(fileName);
    Employee e2(2, "Nakshatra Gupta", 100000);
    e2.saveToFile(fileName);

    // View all employees
    std::cout << "Displaying all employees from file:\n";
    Employee::viewAllEmployees(fileName);

    // Modify an employee's details
    std::cout << "Modifying employee with ID 2:\n";
    Employee::modifyEmployee(fileName, 2);

    // View all employees after modification
    std::cout << "Displaying all employees after modification:\n";
    Employee::viewAllEmployees(fileName);

    // Delete an employee
    std::cout << "Deleting employee with ID 1:\n";
    Employee::deleteEmployee(fileName, 1);

    // View all employees after deletion
    std::cout << "Displaying all employees after deletion:\n";
    Employee::viewAllEmployees(fileName);

    std::cin.get();
    return 0;
}
