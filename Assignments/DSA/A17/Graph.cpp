#include<iostream>
#include<string>

//@ Exception classes

//$ Priority Queue Exceptions Base Class
class BinarySearchTreeExceptions : public std::exception
{
    private:
        std::string message;

    public:

        BinarySearchTreeExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

int main()
{
    

    std::cin.get();
    return 0;
}