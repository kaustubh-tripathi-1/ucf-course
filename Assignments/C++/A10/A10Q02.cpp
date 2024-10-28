#include<iostream>
#include <limits>
#include <string>
using namespace std;

//@ Class for a Customer
class Customer
{
    private :

        unsigned long long int customerId, mobile;
        string name, email;

    public :

        //& Constructors
        
        //$ Default Non-parameterised Constructor
        Customer()
        {
            customerId = 0;
            mobile = 1234567890;
            name = "Default Name";
            email = "defaultemail@abc.com";
        }

        //$ Default Parameterised Constructor with customer id
        Customer(unsigned long long int customerId)
        {
            this->customerId = customerId;
            mobile = 1234567890;
            name = "Default Name";
            email = "defaultemail@abc.com";
        }
        
        //$ Default Parameterised Constructor with customer id, mobile
        Customer(unsigned long long int customerId, unsigned long long int mobile)
        {
            this->customerId = customerId;
            this->mobile = mobile;
            name = "Default Name";
            email = "defaultemail@abc.com";
        }

        //$ Default Parameterised Constructor with customer id, mobile, name
        Customer(unsigned long long int customerId, unsigned long long int mobile, string name)
        {
            this->customerId = customerId;
            this->mobile = mobile;
            this->name = name;
            email = "defaultemail@abc.com";
        }

        //$ Default Parameterised Constructor with customer id, mobile, name, email
        Customer(unsigned long long int customerId, unsigned long long int mobile, string name, string email )
        {
            this->customerId = customerId;
            this->mobile = mobile;
            this->name = name;
            this->email = email;
        }

        //$ Copy Constructor
        Customer(const Customer &cust)
        {
            this->customerId = cust.customerId;
            this->mobile = cust.mobile;
            this->name = cust.name;
            this->email = cust.email;
        }

        //& Initialiser List
        /* Customer(unsigned long long int customerId = 0, unsigned long long int mobile = 1234567890, string name = "Default Name", string email = "defaultemail@abc.com")
            : customerId(customerId), mobile(mobile), name(name), email(email) {}

        Customer(const Customer &cust) 
            : customerId(cust.customerId), mobile(cust.mobile), name(cust.name), email(cust.email) {} */

        //$ Function to display customer details
        void displayCustomer()
        {
            cout << "Customer ID: " << customerId << endl;
            cout << "Mobile: " << mobile << endl;
            cout << "Name: " << name << endl;
            cout << "Email: " << email << endl;
        }
};

/* //@ Class for a Customer
class Customer
{
    private :

        unsigned long long int customerId, mobile;
        string name, email;

    public :

        //& Constructors
        
        //$ Default Parameterised Constructor with customer id, mobile, name, email and will also act as a non-Parameterised Constructor
        Customer(unsigned long long int customerId = 0, unsigned long long int mobile = 1234567890, string name = "Default Name", string email = "defaultemail@abc.com")
        {
            this->customerId = customerId;
            this->mobile = mobile;
            this->name = name;
            this->email = email;
        }

        //$ Copy Constructor
        Customer(const Customer &cust)
        {
            this->customerId = cust.customerId;
            this->mobile = cust.mobile;
            this->name = cust.name;
            this->email = cust.email;
        }

        //& Initialiser List
        Customer(unsigned long long int customerId = 0, unsigned long long int mobile = 1234567890, string name = "Default Name", string email = "defaultemail@abc.com")
            : customerId(customerId), mobile(mobile), name(name), email(email) {}

        Customer(const Customer &cust) 
            : customerId(cust.customerId), mobile(cust.mobile), name(cust.name), email(cust.email) {}
        
}; */

int main()
{
    //? Using the non-parameterized constructor
    Customer defaultCustomer;
    defaultCustomer.displayCustomer();

    cout<<endl;
    //? Using the parameterized constructor
    Customer customCustomer(1, 9876543210, "Alice", "alice@example.com");
    customCustomer.displayCustomer();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}