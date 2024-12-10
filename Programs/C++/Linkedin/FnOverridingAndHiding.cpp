#include <iostream>
#include <string>

class Account  
{
public:
    virtual void displayDetails() const // Virtual for overriding
    {
        std::cout << "Account: General account details\n";
    }

    void calculateInterest() const // Non-virtual function
    {
        std::cout << "Interest: 4%% per annum (Base interest rate)\n";
    }
};

class SavingsAccount : public Account  
{
public:
    void displayDetails() const override // Overriding the base class function
    {
        std::cout << "Savings Account: Includes minimum balance and interest rate details\n";
    }

    void calculateInterest() const // Hiding the base class function
    {
        std::cout << "Interest: 5%% per annum (Special rate for savings account)\n";
    }
};

class FixedDepositAccount : public Account  
{
public:
    void displayDetails() const override // Overriding
    {
        std::cout << "Fixed Deposit Account: Includes lock-in period and higher interest rate\n";
    }

    void calculateInterest() const // Hiding
    {
        std::cout << "Interest: 7%% per annum (Fixed deposit rate)\n";
    }
};

int main()  
{
    Account generalAccount;
    SavingsAccount savings;
    FixedDepositAccount fd;

    Account* accPtr = &savings; // Base pointer to SavingsAccount

    // Function overriding
    accPtr->displayDetails(); // Calls SavingsAccount's displayDetails() due to virtual

    // Function hiding
    accPtr->calculateInterest(); // Calls Account's calculateInterest() (non-virtual)

    // Direct access
    fd.calculateInterest(); // Calls FixedDepositAccount's calculateInterest() (hides base)
    savings.calculateInterest(); // Calls SavingsAccount's calculateInterest() (hides base)

    return 0;
}