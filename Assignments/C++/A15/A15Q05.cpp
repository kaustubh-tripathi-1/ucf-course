#include<iostream>
#include<string>
#include<limits>
// using namespace std;

class Student
{
    private :

        int rollNo, age;
        std::string name;

    public :

        Student(int rollNo, int age, std::string name)
        :
            rollNo(rollNo), age(age), name(name) {}

        Student ( const Student &s)
        :
            rollNo(s.rollNo), age(s.age), name(s.name) {}

        bool operator==(const Student &student) const
        {
            //$ Self-equality check
            if ( this == &student)
                return true;
            
            //$ Regular member comparison
            return ( this->rollNo == student.rollNo 
                && this->age == student.age 
                && this->name == student.name);
        }

        void setStudent(int rollNo, int age, std::string name)
        {
            this->rollNo = rollNo;
            this->age = age;
            this->name = name;
        }

        friend std::istream& operator>>( std::istream &in, Student &s) 
        {
            std::cout << "Enter roll number, age, and name: ";
            
            in>>s.rollNo>>s.age;

            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // while ( getchar() != '\n');
            std::getline(in, s.name);

            return in;
            
        }

        friend std::ostream& operator<<( std::ostream &out, const Student &s) 
        {
            out<<"Student info :\n";
            out<<"Roll No. : "<<s.rollNo<<"\nName : "<<s.name<<"\nAge : "<<s.age<<std::endl;

            return out;
        }

};

int main()
{
    Student s1(1, 25, "Kaustubh Tripathi");
    Student s2 = s1;

    Student s3 = {2, 27, "Nakshatra Gupta"};

    std::cout<<"Students :\n";
    std::cout<<s1<<s2<<s3;

    if ( s1 == s2 )
        std::cout<<"Student are same.\n";
    else
        std::cout<<"Student are not same.\n";

    if ( s1 == s3 )
        std::cout<<"Student are same.\n";
    else
        std::cout<<"Student are not same.\n";
    
    if ( s1 == s1 )
        std::cout<<"Student are same.\n";
    else
        std::cout<<"Student are not same.\n";

    
    std::cin>>s3;
    std::cout<<"Modified Student with cin :\n"<<s3;

    

    std::cin.get();
    return 0;
}