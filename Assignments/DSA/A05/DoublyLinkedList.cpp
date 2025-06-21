#include<iostream>
#include<string>

//@ Exception classes

//$ Doubly Linked List Exception Base Class
class DoublyLinkedListExceptions : public std::exception
{
    private:

        std::string message;

    public:

        DoublyLinkedListExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
};

//@ Doubly Linked List Specific Exception Child Classes

class NodeNotFoundException : public DoublyLinkedListExceptions
{
    public:
        NodeNotFoundException() : DoublyLinkedListExceptions("Error : The specified node was not found.") {}
};

class EmptyLinkedListException : public DoublyLinkedListExceptions
{
    public:
        EmptyLinkedListException() : DoublyLinkedListExceptions("Error : The linked list is empty. Cannot perform some operations like delete, search etc.") {}
};

class NullNodeException : public DoublyLinkedListExceptions
{
    public:
        NullNodeException() : DoublyLinkedListExceptions("Error : Node Address cannot be null.") {}
};

class DoublyLinkedList;

class Node
{
    private:

        Node *previous;
        int data;
        Node *next;

        friend class DoublyLinkedList;

    public:

        //$ Default Non-Param. Constructor
        Node() : previous(nullptr), data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(int data) : previous(nullptr), data(data), next(nullptr) {}
    
};

class DoublyLinkedList
{
    private:

        Node *start;

    public:

        //$ Default Non-Param. Constructor
        DoublyLinkedList() : start(nullptr) {}

        //$ Default Param. Constructor
        DoublyLinkedList(int data) : start(new Node(data)) {}

        //$ Copy Constructor
        DoublyLinkedList(const DoublyLinkedList &dll);

        //$ Overloaded Copy Assignment= Op.
        DoublyLinkedList& operator=(const DoublyLinkedList &dll);

        //$ Destructor
        ~DoublyLinkedList();

        //$ Inserts data at beginning
        DoublyLinkedList& insertAtBeginning(int data);

        //$ Inserts data at end
        DoublyLinkedList& insertAtEnd(int data);

        //$ Searches a node with a specified data
        const Node* searchNode(int data) const;

        //$ Inserts data after specified node with Node address
        DoublyLinkedList& insertAfterNode(Node *nodeAddress, int data);

        //$ Inserts data after specified node with data
        DoublyLinkedList& insertAfterNode(int dataToSearch, int newData);

        //$ Deletes first Node
        DoublyLinkedList& deleteFirstNode();

        //$ Deletes first Node
        DoublyLinkedList& deleteLastNode();

        //$ Deletes specified Node with Node address
        DoublyLinkedList& deleteSpecifiedNode(Node *nodeAddress);

        //$ Deletes specified Node with data
        DoublyLinkedList& deleteSpecifiedNode(int data);

        //$ Displays the list
        DoublyLinkedList& display();

};

//$ Copy Constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList &dll)
{
    if ( dll.start == nullptr )
    {
        this->start = nullptr;
    }
    else
    {
        Node *traverseOtherDLL = dll.start;
        Node *thisDLL = nullptr;
        
        while ( traverseOtherDLL != nullptr )
        {
            Node *temp = new Node(traverseOtherDLL->data);

            if ( traverseOtherDLL->previous == nullptr )
            {
                this->start = temp;
            }
            else
            {
                thisDLL->next = temp;
                temp->previous = thisDLL;
            }
            
            thisDLL = temp;
            traverseOtherDLL = traverseOtherDLL->next;
        }
    }
}

//$ Overloaded Copy Assignment= Op.
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList &dll)
{
    if ( this == &dll )
        return *this;

    //& Delete existing list
    while ( this->start != nullptr)
    {
        Node *temp = start;
        start = start->next;
        start->previous = nullptr;
        delete temp;
    }

    if ( dll.start == nullptr )
    {
        this->start = nullptr;
    }
    else
    {
        Node *traverseOtherDLL = dll.start;
        Node *thisDLL = nullptr;
        
        while ( traverseOtherDLL != nullptr )
        {
            Node *temp = new Node(traverseOtherDLL->data);

            if ( traverseOtherDLL->previous == nullptr )
            {
                this->start = temp;
            }
            else
            {
                thisDLL->next = temp;
                temp->previous = thisDLL;
            }
            
            thisDLL = temp;
            traverseOtherDLL = traverseOtherDLL->next;
        }
    }

    return *this;
}

//$ Destructor
DoublyLinkedList::~DoublyLinkedList()
{
    while ( start != nullptr )
    {
        if ( start->next != nullptr )
        {
            start = start->next;
            delete start->previous;
            start->previous = nullptr;
        }
        else
        {
            delete start;
            start = nullptr;
        }
    }

    //& Another simplified logic
    /* while (start != nullptr)
    {
        Node *temp = start;
        start = start->next;
        start->previous = nullptr;
        delete temp;
    } */
}

//$ Inserts data at the beginning
DoublyLinkedList& DoublyLinkedList::insertAtBeginning(int data)
{
    Node *temp = new Node(data);
    
    //& If the list is not empty
    if ( start != nullptr )
    {
        temp->next = start;
        start->previous = temp;
    }
    
    start = temp;

    return *this;

}

//$ Inserts data at the end
DoublyLinkedList& DoublyLinkedList::insertAtEnd(int data)
{
    if ( start == nullptr )
    {
        start = new Node(data);
    }
    else
    {
        Node *traverse = start;

        while ( traverse->next != nullptr )
        {
            traverse = traverse->next;
        }

        Node *temp = new Node(data);

        traverse->next = temp;

        temp->previous = traverse;
    }
    
    return *this;

}

//$ Searches a node with a specified data
const Node* DoublyLinkedList::searchNode(int data) const
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }

    Node *traverse = start;

    while ( traverse != nullptr )
    {
        if ( traverse->data == data )
        {
            return traverse;
        }
        
        traverse = traverse->next;
    }

    //& Can throw an exception or return nullptr offer flexibility for cases where exceptions aren't desirable.
    // throw NodeNotFoundException();

    return nullptr;
}

//$ Inserts data after specified node with data
DoublyLinkedList& DoublyLinkedList::insertAfterNode(int dataToSearch, int newData)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *traverse = start;

    while ( traverse != nullptr && traverse->data != dataToSearch )
    {
        traverse = traverse->next;
    }

    if ( traverse != nullptr )
    {
        Node *newNode = new Node(newData);

        newNode->previous = traverse;
        newNode->next = traverse->next;
        if ( traverse->next != nullptr )
            traverse->next->previous = newNode;
        traverse->next = newNode;
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;

}

//$ Inserts data after specified node traversing the list if the user provides incorrect Node Address
/* DoublyLinkedList& DoublyLinkedList::insertAfterNode(Node *nodeAddress, int newData)
{
    if ( nodeAddress == nullptr)
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    Node *traverse = start;

    while ( traverse != nullptr && traverse != nodeAddress )
    {
        traverse = traverse->next;
    }

    if ( traverse == nodeAddress )
    {
        Node *newNode = new Node(newData);

        newNode->previous = traverse;
        newNode->next = traverse->next;
        if ( traverse->next != nullptr )
        {
            traverse->next->previous = newNode;
        }
        traverse->next = newNode;
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;

} */

//$ Inserts data after specified node trusting that the user provides the correct node Address
DoublyLinkedList& DoublyLinkedList::insertAfterNode(Node *nodeAddress, int newData)
{
    if ( nodeAddress == nullptr)
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    
    Node *newNode = new Node(newData);

    newNode->previous = nodeAddress;
    newNode->next = nodeAddress->next;

    if ( nodeAddress->next != nullptr )
    {
        nodeAddress->next->previous = newNode;
    }

    nodeAddress->next = newNode;

    return *this;
} 

//$ Deletes first Node
DoublyLinkedList& DoublyLinkedList::deleteFirstNode()
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }

    if ( start->next != nullptr )
    {
        start = start->next;
        delete start->previous;
        start->previous = nullptr;
    }
    else
    {
        delete start;
        start = nullptr;
    }

    return *this;
}

//$ Deletes last Node
DoublyLinkedList& DoublyLinkedList::deleteLastNode()
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }

    Node *traverse = start;

    if ( traverse->next == nullptr )
    {
        delete traverse;
        start = nullptr;
    }
    else
    {
        while ( traverse->next != nullptr )
        {
            traverse = traverse->next;
        }

        traverse->previous->next = nullptr;
        
        delete traverse;
    }

    return *this;

}

//$ Deletes specified Node with data
DoublyLinkedList& DoublyLinkedList::deleteSpecifiedNode(int data)
{
    if ( start == nullptr)
        throw EmptyLinkedListException();

    // Single node in Doubly Linked List
    if(start->data == data && !start->next)
    {
        delete start;
        start = nullptr;
        return *this;
    }

    Node *traverse = start;

    while ( traverse != nullptr && traverse->data != data )
    {
        traverse = traverse->next;
    }

    if ( traverse != nullptr )
    {
        if ( traverse->previous != nullptr )
            traverse->previous->next = traverse->next;
        
        if ( traverse->next != nullptr )
            traverse->next->previous = traverse->previous;

        delete traverse;
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;
}

//$ Deletes specified Node traversing the list if the user provides incorrect Node Address
/* DoublyLinkedList& DoublyLinkedList::deleteSpecifiedNode(Node *nodeAddress)
{
    if ( nodeAddress == nullptr )
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();

    // Single node in Doubly Linked List
    if(start == nodeAddress && !start->next)
    {
        delete start;
        start = nullptr;
        return *this;
    }
        
    Node *traverse = start;

    while ( traverse && traverse != nodeAddress )
    {
        traverse = traverse->next;
    }

    if ( traverse == nodeAddress )
    {
        Node *previousNode = traverse->previous;
        Node *nextNode = traverse->next;
        if(previousNode)
            previousNode->next = nextNode;
        nextNode->previous = previousNode;

        delete traverse;
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;

}*/

//$ Deletes specified Node trusting that the user provides the correct node Address
DoublyLinkedList& DoublyLinkedList::deleteSpecifiedNode(Node *nodeAddress)
{
    if ( nodeAddress == nullptr )
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();

    if ( start == nodeAddress )
    {
        if ( nodeAddress->next != nullptr )
            nodeAddress->next->previous = nullptr;

        start = nodeAddress->next;
        delete nodeAddress;
    }
    else
    {
        if ( nodeAddress->previous != nullptr )
            nodeAddress->previous->next = nodeAddress->next;
        
        if ( nodeAddress->next != nullptr )
            nodeAddress->next->previous = nodeAddress->previous;

        delete nodeAddress;
    }
    
    return *this;
}

//$ Displays the list
DoublyLinkedList& DoublyLinkedList::display()
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *traverse = start;

    std::cout<<"List items are -\n";
    while ( traverse != nullptr )
    {
        std::cout<<traverse->data<<" ";

        traverse = traverse->next;
    }
    std::cout<<"\n";

    return *this;
}

int main()
{
    try
    {
        DoublyLinkedList list1;

        std::cout<<"Using insertAtBeginning() -\n";
        for ( int i = 80 ; i > 0 ; i-= 10)
        {
            // Insert elements at the Beginning
            list1.insertAtBeginning(i);
        }
        list1.display();

        // Insert elements at the end
        std::cout<<"Using insertAtEnd() -\n";
        list1.insertAtEnd(90);
        list1.insertAtEnd(100);
        list1.display();

        std::cout<<"Copy constructor -\n";
        DoublyLinkedList list2 = list1;
        list1.display();

        std::cout<<"Copy assignment op. -\n";
        DoublyLinkedList list3;
        list3 = list1;
        list1.display();

        // Insert after a specific node
        std::cout<<"Using searchNode() and insertAfterNode() -\n";

        Node *thirdNode = const_cast<Node*>(list1.searchNode(30));
        list1.insertAfterNode(thirdNode, 35);
        list1.display();

        // Delete the first node
        std::cout<<"Using deleteFirstNode() -\n";
        list1.deleteFirstNode();
        list1.display();

        // Delete the last node
        std::cout<<"Using deleteLastNode() -\n";
        list1.deleteLastNode();
        list1.display();

        // Search for a specific node by data
        std::cout<<"Using searchNode() -\n";
        const Node *foundNode = list1.searchNode(85);
        if (foundNode)
        {
            std::cout << "Node with data 35 found at address: " << foundNode << std::endl;
        }
        else
        {
            std::cout << "Node with data 35 not found." << std::endl;
        }

        // Delete a specific node by address
        std::cout<<"Using deleteSpecifiedNode() -\n";
        list1.deleteSpecifiedNode(thirdNode);

        // Display remaining element
        list1.display();

    }
    catch (const NodeNotFoundException &e)
    {
        std::cout <<"Node Not Found Exception: " << e.what() << std::endl;
    }
    catch (const EmptyLinkedListException &e)
    {
        std::cout <<"Empty Linked List Exception: " << e.what() << std::endl;
    }
    catch (const NullNodeException &e)
    {
        std::cout <<"Null Node Exception " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Standard Exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout <<"An unknown exception occured."<< std::endl;
    }

    std::cin.get();
    return 0;
}