#include<iostream>
#include<string>

//@ Node class
class Node
{
    private:

        int data;
        Node *next;
};

//@ Singly Linked List class
class SinglyLinkedList
{
    private :

        Node *start;

    public :

        //$ Default Constructor
        SinglyLinkedList()
        :   start(nullptr) {}

        //$ Copy Constructor
        /* SinglyLinkedList(const SinglyLinkedList &sll)
        :
            {} */

        

};

int main()
{
    

    std::cin.get();
    return 0;
}