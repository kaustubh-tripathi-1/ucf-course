#include<iostream>
#include <limits>
#include <string>
using namespace std;

class Student
{
    private :

        int rollNo, age;
        long long int mobileNumber;
        string name, email;
        bool isValid;

    public :

        //& Initializer Lists

        //$ Param. Constructor, no non-param. Constructor as student details cannot be default, making student object w/o all details is not allowed
        Student(int rollNo, 
                int age, 
                long long int mobileNumber, 
                string name, 
                string email ) 
            : 
                rollNo(rollNo>0 ? rollNo : -1), 
                age(age>0 ? age : -1), 
                mobileNumber(mobileNumber>999999999 ? mobileNumber : -1), 
                name(name), 
                email(email), 
                isValid(true)
        {
            if( rollNo <= 0 || 
                age <= 0 || 
                mobileNumber <= 0 || 
                name.empty() || 
                email.empty())
            {
                isValid = false;
                cout<<"Invalid Data provided for Student!\n";
            }
        }

        //$ Copy Constructor
        Student(const Student &s ) 
        :
            rollNo(s.rollNo), 
            age(s.age), 
            mobileNumber(s.mobileNumber), 
            name(s.name), 
            email(s.email),
            isValid(isValid) 
        {}

        void displayStudent() const
        {
            if(isValid)
            {
                cout<<"Student details    :"<<endl;
                cout<<"Student Roll No.   : "<<rollNo<<endl;
                cout<<"Student Name       : "<<name<<endl;
                cout<<"Student Age        : "<<age<<endl;
                cout<<"Student Mobile no. : "<<mobileNumber<<endl;
                cout<<"Student Email      : "<<email<<endl;
                cout<<endl;
            }
            else
            {
                cout<<"Student data is invalid and cannot be displayed"<<endl;
            }
        }
    
};

int main()
{
    Student s1 = {16, 25, 9811656514, "Kaustubh Tripathi", "kt40060@gmail.com"};
    s1.displayStudent();

    Student s2(0, 25, 9811656514, "", "");  //! Invalid Student
    s2.displayStudent();

    cin.get();
    return 0;
}