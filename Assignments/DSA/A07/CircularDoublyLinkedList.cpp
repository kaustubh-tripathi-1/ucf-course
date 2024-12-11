#include<iostream>
#include<string>

//@ Exception classes

//$ Circular Doubly Linked List Exception Base Class
class CircularDoublyLinkedListExceptions : public std::exception
{
    private:

        std::string message;

    public:

        CircularDoublyLinkedListExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
};

//@ Circular Doubly Linked List Specific Exception Child Classes

class NodeNotFoundException : public CircularDoublyLinkedListExceptions
{
    public:
        NodeNotFoundException() : CircularDoublyLinkedListExceptions("Error : The specified node was not found.") {}
};

class EmptyLinkedListException : public CircularDoublyLinkedListExceptions
{
    public:
        EmptyLinkedListException() : CircularDoublyLinkedListExceptions("Error : The linked list is empty. Cannot perform some operations like delete, search etc.") {}
};

class NullNodeException : public CircularDoublyLinkedListExceptions
{
    public:
        NullNodeException() : CircularDoublyLinkedListExceptions("Error : Node Address cannot be null.") {}
};

class CircularDoublyLinkedList;

class Node
{
    private:

        Node *previous;
        int data;
        Node *next;

        friend class CircularDoublyLinkedList;

    public:

        //$ Default Non-Param. Constructor
        Node() : previous(nullptr), data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(int data) : previous(nullptr), data(data), next(nullptr) {}
    
};

class CircularDoublyLinkedList
{

    private:

        

};

int main()
{
    

    std::cin.get();
    return 0;
}