#include <iostream>

class Student {
    std::string name;
    int age;
    
public:
    Student(std::string n, int a) : name(n), age(a) {}

    // Member function using the 'this' pointer
    void display() {
        std::cout << "Name: " << this->name << ", Age: " << this->age << std::endl;
    }

    // Function using an object pointer
    void changeName(Student* s, std::string newName) {
        s->name = newName;  // Accessing 'name' via object pointer
    }
};

int main() {
    // Creating an object of the Student class
    Student student1("John", 20);
    
    // Using object pointer to call changeName function
    Student* ptr = &student1;
    ptr->changeName(ptr, "Alice");

    // Using 'this' pointer to display details
    student1.display();

    return 0;
}