#include<iostream>
#include<string>
// using namespace std;

class Person
{
    private :

        std::string name;
        int age;
        bool isValid;

    public :

        Person( std::string name = "Default Name", int age = 0 )
        :
            name(name), age(age), isValid(true)
        {
            if ( name.empty() || age <= 0 )
            {
                std::cout<<"Invalid Person Properties\n";
                this->name = "Default Name";
                this->age = 0;
                isValid = false;
            }
        }

        //$ Getters
        std::string getName() const { return name; }

        int getAge() const { return age; }

        bool isValidPerson() const { return isValid; }
};

int main()
{


    std::cin.get();
    return 0;
}