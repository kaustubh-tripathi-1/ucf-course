#include <iostream>
#include <stdexcept>

class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) 
        : balance(initialBalance) 
    { 
        if (initialBalance < 0)
        {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    void deposit(double amount) 
    {
        if (amount <= 0) 
        {
            throw std::invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
    }

    void withdraw(double amount) 
    {
        if (amount > balance) 
        {
            throw std::runtime_error("Insufficient balance for withdrawal.");
        }
        else if (amount <= 0) 
        {
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }
        balance -= amount;
    }

    double getBalance() const 
    {
        return balance;
    }
};

int main() 
{
    try 
    {
        BankAccount myAccount(1000.0);
        std::cout << "Initial balance: ₹" << myAccount.getBalance() << std::endl;

        myAccount.deposit(500.0);
        std::cout << "Balance after deposit: ₹" << myAccount.getBalance() << std::endl;

        myAccount.withdraw(2000.0); // Will throw an exception
    } 
    catch (const std::invalid_argument &e) 
    {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
    } 
    catch (const std::runtime_error &e) 
    {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    } 
    catch (...) 
    {
        std::cerr << "An unknown error occurred." << std::endl;
    }

    return 0;
}
