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
        NodeNotFoundException(const std::string &operation) : CircularDoublyLinkedListExceptions("Error : The specified node was not found during " + operation +".") {}
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

        Node *start;

        //$ Deleting the whole list
        void clear();

        //$ Copies all nodes from source list to destination
        Node* copyNodes(const CircularDoublyLinkedList &cdll);

    public:

        //$ Default Non-Param. Constructor
        CircularDoublyLinkedList() : start(nullptr) {}

        //$ Default Param. Constructor
        CircularDoublyLinkedList(int data) : start(new Node(data)) {}

        //$ Copy Constructor
        CircularDoublyLinkedList(const CircularDoublyLinkedList &cdll);

        //$ Overloaded Copy Assignment= Op.
        CircularDoublyLinkedList& operator=(const CircularDoublyLinkedList &cdll);

        //$ Destructor
        ~CircularDoublyLinkedList();

        //$ Inserts data at beginning
        CircularDoublyLinkedList& insertAtBeginning(int data);

        //$ Inserts data at end
        CircularDoublyLinkedList& insertAtEnd(int data);

        //$ Searches a node with a specified data
        const Node* searchNode(int data) const;

        //$ Inserts data after specified node with Node address
        CircularDoublyLinkedList& insertAfterNode(Node *nodeAddress, int data);

        //$ Inserts data after specified node with data
        CircularDoublyLinkedList& insertAfterNode(int dataToSearch, int newData);

        //$ Deletes first Node
        CircularDoublyLinkedList& deleteFirstNode();

        //$ Deletes last Node
        CircularDoublyLinkedList& deleteLastNode();

        //$ Deletes specified Node with Node address
        CircularDoublyLinkedList& deleteSpecifiedNode(Node *nodeAddress);

        //$ Deletes specified Node with data
        CircularDoublyLinkedList& deleteSpecifiedNode(int data);

        //$ Displays the list
        CircularDoublyLinkedList& display();

};

//$ Deleting the whole list
void CircularDoublyLinkedList::clear() 
{
    if (!start) return;

    Node *current = start;
    Node *last = start->previous;

    while (current != last) 
    {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    delete current;

    start = nullptr;
}

//$ Copies all nodes from source list to destination
Node* CircularDoublyLinkedList::copyNodes(const CircularDoublyLinkedList &cdll) 
{
    if (cdll.start == nullptr)
        return nullptr;

    Node *source = cdll.start;
    Node *copiedStart = new Node(source->data);
    Node *prevCopied = copiedStart;

    source = source->next;

    while (source != cdll.start) 
    {
        Node *newNode = new Node(source->data);
        prevCopied->next = newNode;
        newNode->previous = prevCopied;

        prevCopied = newNode;
        source = source->next;
    }

    // Complete circular connection
    prevCopied->next = copiedStart;
    copiedStart->previous = prevCopied;

    return copiedStart;
}

//$ Copy Constructor
CircularDoublyLinkedList::CircularDoublyLinkedList(const CircularDoublyLinkedList &cdll)
{

    start = copyNodes(cdll);

    //& W/O Helper function
    /* if ( cdll.start == nullptr )
    {
        this->start = nullptr;
        return;
    }

    Node *sourceCDLL = cdll.start;
    Node *thisCDLL = nullptr;

    do
    {
        Node *newNode = new Node(sourceCDLL->data);
        thisCDLL = newNode;

        //& Only for 1st node
        if ( sourceCDLL == cdll.start)
        {
            this->start = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
        }

        newNode->previous = thisCDLL;
        thisCDLL->next = newNode;

        //& For the last node to make the list circular
        if ( sourceCDLL == cdll.start->previous )
        {
            start->previous = newNode;
            newNode->next = start;
        }

        sourceCDLL = sourceCDLL->next;
        
    } while ( sourceCDLL != cdll.start ); */
    
}

//$ Overloaded Copy Assignment= Op.
CircularDoublyLinkedList& CircularDoublyLinkedList::operator=(const CircularDoublyLinkedList &cdll)
{
    if (this != &cdll) 
    {
        clear(); // Helper function to delete all nodes
        start = copyNodes(cdll);
    }

    return *this;

    //& W/O Helper method
    /* if ( this == &cdll )
        return *this;
    
    //& Existing list clean up using predefined method
    // while ( this->start != nullptr )
    // {
    //     deleteFirstNode();
    // }

    //& Existing list clean up explicitly
    if ( this->start != nullptr )
    {
        Node *traverse = this->start;
        Node *lastNode = this->start->previous;
        do
        {
            if ( traverse == lastNode )
            {
                delete traverse;
                this->start = nullptr;
                break;
            }
            Node *temp = traverse->next;

            delete traverse;

            traverse = temp;
            
        } while ( true );
    }


    if ( cdll.start == nullptr )
    {
        this->start = nullptr;
        return *this;
    }

    Node *sourceCDLL = cdll.start;
    Node *thisCDLL = nullptr;

    do
    {
        Node *newNode = new Node(sourceCDLL->data);
        thisCDLL = newNode;

        //& Only for 1st node
        if ( sourceCDLL == cdll.start)
        {
            this->start = newNode;
            newNode->next = newNode;
            newNode->previous = newNode;
        }

        newNode->previous = thisCDLL;
        thisCDLL->next = newNode;

        //& For the last node to make the list circular
        if ( sourceCDLL == cdll.start->previous )
        {
            start->previous = newNode;
            newNode->next = start;
        }

        sourceCDLL = sourceCDLL->next;
        
    } while ( sourceCDLL != cdll.start );

    return *this; */
}

//$ Destructor
CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
    clear();

    //& W/O Helper method
    /* if ( this->start != nullptr )
    {
        Node *traverse = this->start;
        Node *lastNode = this->start->previous;
        do
        {
            if ( traverse == lastNode )
            {
                delete traverse;
                this->start = nullptr;
                break;
            }
            Node *temp = traverse->next;

            delete traverse;

            traverse = temp;
            
        } while ( true );
    } */

}

//$ Inserts data at beginning
CircularDoublyLinkedList& CircularDoublyLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);

    if ( start == nullptr ) //& Handles empty list
    {
        start = newNode;

        //& Update pointers for circularity
        newNode->previous = newNode;
        newNode->next = newNode;

        return *this;
    }
    
    //& Non - empty list
    newNode->previous = start->previous;
    newNode->next = start;
    start->previous->next = newNode;
    start->previous = newNode;
    start = newNode;

    return *this;
}

//$ Inserts data at end
CircularDoublyLinkedList& CircularDoublyLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);

    if ( start == nullptr )     //& Handles empty list
    {
        start = newNode;

        //& Update pointers for circularity
        newNode->previous = newNode;
        newNode->next = newNode;

        return *this;
    }

    //& Non - empty list
    newNode->previous = start->previous;
    newNode->next = start;
    start->previous->next = newNode;
    start->previous = newNode;

    return *this;
}

//$ Searches a node with a specified data
const Node* CircularDoublyLinkedList::searchNode(int data) const
{
    if ( start == nullptr )     //& Empty List
        throw EmptyLinkedListException();

    Node *traverse = start;

    //& Traverse the list to find data
    do
    {
        if ( traverse->data == data )
            return traverse;    //& Node found, return address

        traverse = traverse->next;

    } while ( traverse != start );

    return nullptr;     //& Node not found
}

//$ Inserts data after specified node with Node address traversing if the node is still present or not
CircularDoublyLinkedList& CircularDoublyLinkedList::insertAfterNode(Node *nodeAddress, int data)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *newNode = new Node(data);
    Node *traverse = start;

    do
    {
        if ( traverse == nodeAddress )
        {
            newNode->previous = nodeAddress;
            newNode->next = nodeAddress->next;
            nodeAddress->next->previous = newNode;
            nodeAddress->next = newNode;
            break;
        }
        traverse = traverse->next;

    } while ( traverse != start );

    if ( traverse == start )
        throw NodeNotFoundException("insertion after node");

    return *this;

}

//$ Inserts data after specified node with Node address trusting that the node Address provided is right
/* CircularDoublyLinkedList& CircularDoublyLinkedList::insertAfterNode(Node *nodeAddress, int data)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *newNode = new Node(data);

    newNode->previous = nodeAddress;
    newNode->next = nodeAddress->next;
    nodeAddress->next->previous = newNode;
    nodeAddress->next = newNode;

    return *this;
} */

//$ Inserts data after specified node with data
CircularDoublyLinkedList& CircularDoublyLinkedList::insertAfterNode(int dataToSearch, int newData)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *newNode = new Node(newData);

    Node *foundNode = const_cast<Node*>(searchNode(dataToSearch));

    if ( foundNode != nullptr )
    {
        newNode->previous = foundNode;
        newNode->next = foundNode->next;
        foundNode->next->previous = newNode;
        foundNode->next = newNode;
    }
    else
    {
        throw NodeNotFoundException("insertion after node");
    }

    return *this;
}

//$ Deletes first Node
CircularDoublyLinkedList& CircularDoublyLinkedList::deleteFirstNode()
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( start->next == start )
    {
        delete start;
        start = nullptr;
        return *this;
    }


    Node *lastNode = start->previous;
    Node *firstNode = start;
    lastNode->next = start->next;
    start->next->previous = lastNode;
    start = start->next;

    delete firstNode;

    return *this;

}

//$ Deletes last Node
CircularDoublyLinkedList& CircularDoublyLinkedList::deleteLastNode()
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( start->next == start )
    {
        delete start;
        start = nullptr;
        return *this;
    }

    Node *lastNode = start->previous;

    lastNode->previous->next = start;
    start->previous = lastNode->previous;

    delete lastNode;

    return *this;
}

//$ Deletes specified Node with Node address with using already defined methods
CircularDoublyLinkedList& CircularDoublyLinkedList::deleteSpecifiedNode(Node *nodeAddress)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    if ( nodeAddress == start )
        return deleteFirstNode();

    if ( nodeAddress == start->previous )
        return deleteLastNode();

    nodeAddress->previous->next = nodeAddress->next;
    nodeAddress->next->previous = nodeAddress->previous;

    delete nodeAddress;

    return *this;
}

//$ Deletes specified Node with data with using already defined methods
CircularDoublyLinkedList& CircularDoublyLinkedList::deleteSpecifiedNode(int data)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *foundNode = const_cast<Node*>(searchNode(data));

    if ( foundNode != nullptr )
    {
        if ( foundNode == start )
            return deleteFirstNode();

        if ( foundNode == start->previous )
            return deleteLastNode();

        foundNode->previous->next = foundNode->next;
        foundNode->next->previous = foundNode->previous;

        delete foundNode;
    }
    else
    {
        throw NodeNotFoundException("deletion of specified node");
    }

    return *this;
}

//$ Displays the list
CircularDoublyLinkedList& CircularDoublyLinkedList::display()
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node *traverse = start;

    std::cout<<"List Items are - \n";

    do
    {
        std::cout<<traverse->data<<" ";
        traverse = traverse->next;

    } while ( traverse != start );

    std::cout<<"\n";

    return *this;
}

int main()
{
    try
    {
        CircularDoublyLinkedList list1;

        //% Insert elements at the beginning
        std::cout << "Using insertAtBeginning() -\n";
        for (int i = 80; i > 0; i -= 10)
        {
            list1.insertAtBeginning(i);
        }
        list1.display();

        //% Insert elements at the end
        std::cout << "Using insertAtEnd() -\n";
        list1.insertAtEnd(90);
        list1.insertAtEnd(100);
        list1.display();

        //% Test the copy constructor
        std::cout << "Copy constructor -\n";
        CircularDoublyLinkedList list2 = list1;
        list2.display();

        //% Test the copy assignment operator
        std::cout << "Copy assignment operator -\n";
        CircularDoublyLinkedList list3;
        list3 = list1;
        list3.display();

        //% Test inserting after a specific node
        std::cout << "Using searchNode() and insertAfterNode() -\n";
        Node *thirdNode = const_cast<Node*>(list1.searchNode(30)); //% Find a node with data 30
        list1.insertAfterNode(thirdNode, 35);
        list1.display();

        //% Test deleting the first node
        std::cout << "Using deleteFirstNode() -\n";
        list1.deleteFirstNode();
        list1.display();

        //% Test deleting the last node
        std::cout << "Using deleteLastNode() -\n";
        list1.deleteLastNode();
        list1.display();

        //% Test searching for a node by data
        std::cout << "Using searchNode() -\n";
        const Node *foundNode = list1.searchNode(35);
        if (foundNode)
        {
            std::cout << "Node with data 35 found at address: " << foundNode << std::endl;
        }
        else
        {
            std::cout << "Node with data 35 not found." << std::endl;
        }

        //% Test deleting a specific node by address
        std::cout << "Using deleteSpecifiedNode(Node *nodeAddress) -\n";
        list1.deleteSpecifiedNode(thirdNode);
        list1.display();

        //% Test deleting a specific node by data
        std::cout << "Using deleteSpecifiedNode(int data) -\n";
        list1.deleteSpecifiedNode(35);
        list1.display();
        
        std::cout << "All tests completed successfully.\n";
    }
    catch (const NodeNotFoundException &e)
    {
        std::cout << "Node Not Found Exception: " << e.what() << std::endl;
    }
    catch (const EmptyLinkedListException &e)
    {
        std::cout << "Empty Linked List Exception: " << e.what() << std::endl;
    }
    catch (const NullNodeException &e)
    {
        std::cout << "Null Node Exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Standard Exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred." << std::endl;
    }

    std::cin.get();
    return 0;
}