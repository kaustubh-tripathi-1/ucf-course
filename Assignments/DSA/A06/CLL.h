#include<iostream>
#include<string>

//@ Exception classes

//$ Circular Linked List Exception Base Class
class CircularLinkedListExceptions : public std::exception
{
    private:

        std::string message;

    public:

        CircularLinkedListExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
};

//@ Circular Linked List Specific Exception Child Classes

class NodeNotFoundException : public CircularLinkedListExceptions
{
    public:
        NodeNotFoundException() : CircularLinkedListExceptions("Error : The specified node was not found.") {}
};

class EmptyLinkedListException : public CircularLinkedListExceptions
{
    public:
        EmptyLinkedListException() : CircularLinkedListExceptions("Error : The linked list is empty. Cannot perform some operations like delete, search etc.") {}
};

class NullNodeException : public CircularLinkedListExceptions
{
    public:
        NullNodeException() : CircularLinkedListExceptions("Error : Node Address cannot be null.") {}
};

class CircularLinkedList;

class Node
{
    private:

        int data;
        Node *next;

        friend class CircularLinkedList;

    public:

        //$ Default Non-Param. Constructor
        Node() : data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(int data) : data(data), next(nullptr) {}
    
};

class CircularLinkedList
{
    private:

        Node *end;

    public:

        //$ Default Non-Param. Constructor
        CircularLinkedList() : end(nullptr) {}

        //$ Default Param. Constructor
        CircularLinkedList(int data) : end(new Node(data)) {}

        //$ Copy Constructor
        CircularLinkedList(const CircularLinkedList &cll);

        //$ Overloaded Copy Assignment= Op.
        CircularLinkedList& operator=(const CircularLinkedList &cll);

        //$ Destructor
        ~CircularLinkedList();

        //$ Inserts data at beginning
        CircularLinkedList& insertAtBeginning(int data);

        //$ Inserts data at end
        CircularLinkedList& insertAtEnd(int data);

        //$ Searches a node with a specified data
        const Node* searchNode(int data) const;

        //$ Inserts data after specified node with Node address
        CircularLinkedList& insertAfterNode(Node *nodeAddress, int data);

        //$ Inserts data after specified node with data
        CircularLinkedList& insertAfterNode(int dataToSearch, int newData);

        //$ Deletes first Node
        CircularLinkedList& deleteFirstNode();

        //$ Deletes first Node
        CircularLinkedList& deleteLastNode();

        //$ Deletes specified Node with Node address
        CircularLinkedList& deleteSpecifiedNode(Node *nodeAddress);

        //$ Deletes specified Node with data
        CircularLinkedList& deleteSpecifiedNode(int data);

        //$ Displays the list
        CircularLinkedList& display();

};

//$ Copy Constructor
CircularLinkedList::CircularLinkedList(const CircularLinkedList &cll)
{
    if ( cll.end == nullptr )
    {
        this->end = nullptr;
        return ;
    }
    
    //& Complex and forced logic
    /* Node *sourceCLL = cll.end;
    Node *destinationCLL = nullptr;

    while ( sourceCLL->next != cll.end )
    {
        Node *newNode = new Node(sourceCLL->data);

        if ( sourceCLL == cll.end )
        {
            this->end = newNode;
            this->end->next = newNode;
        }
        else
        {
            newNode->next = destinationCLL->next;
            destinationCLL->next = newNode;
        }

        destinationCLL = newNode;
        sourceCLL = sourceCLL->next;
    }

    if ( sourceCLL->next == cll.end )
    {
        Node *newNode = new Node(sourceCLL->data);

        newNode->next = destinationCLL->next;

        destinationCLL->next = newNode;
    } */
    
    //& Simple and Better logic
    Node *sourceCLL = cll.end->next;
    Node *newNode = new Node(sourceCLL->data);
    newNode->next = newNode;
    this->end = newNode;    //& Temporarily set `end` to the first node
    Node *previousNode = newNode;

    //& Copy the rest of the nodes
    sourceCLL = sourceCLL->next;
    while ( sourceCLL != cll.end->next )    //& Stop when we loop back to the first node
    {
        Node *newNode = new Node(sourceCLL->data);
        previousNode->next = newNode;
        previousNode = newNode;
        sourceCLL = sourceCLL->next;
    }

    //& Complete the circular link
    previousNode->next = this->end;
    this->end = previousNode;   //& Set `end` to the last node
}

//$ Overloaded Copy Assignment= Op.
CircularLinkedList& CircularLinkedList::operator=(const CircularLinkedList &cll)
{
    if ( this == &cll )
        return *this;

    if ( cll.end == nullptr )
    {
        this->end = nullptr;
        return *this;
    }
    
    //& Clean-up existing the list
    while ( this->end != nullptr )
    {
        deleteLastNode();
    }

    //& Simple and Better logic
    Node *sourceCLL = cll.end->next;
    Node *newNode = new Node(sourceCLL->data);
    newNode->next = newNode;
    this->end = newNode;    //& Temporarily set `end` to the first node
    Node *previousNode = newNode;

    //& Copy the rest of the nodes
    sourceCLL = sourceCLL->next;
    while ( sourceCLL != cll.end->next )    //& Stop when we loop back to the first node
    {
        Node *newNode = new Node(sourceCLL->data);
        previousNode->next = newNode;
        previousNode = newNode;
        sourceCLL = sourceCLL->next;
    }

    //& Complete the circular link
    previousNode->next = this->end;
    this->end = previousNode;   //& Set `end` to the last node

    return *this;
}

//$ Destructor
CircularLinkedList::~CircularLinkedList()
{
    while ( end != nullptr )
    {
        deleteLastNode();
    }
}

//$ Inserts data at beginning
CircularLinkedList& CircularLinkedList::insertAtBeginning(int data)
{
    Node *newNode = new Node(data);
    
    if ( end == nullptr )
    {
        //& Single node pointing to itself, List is empty, so the new node becomes both the first and last node
        end = newNode;
        end->next = newNode;
    }
    else
    {
        //& Insert at the beginning
        newNode->next = end->next;
        end->next = newNode;
    }

    return *this;
}

//$ Inserts data at end
CircularLinkedList& CircularLinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    
    if ( end == nullptr )
    {
        //& Single node pointing to itself, List is empty, so the new node becomes both the first and last node
        end = newNode;
        end->next = newNode;
    }
    else
    {
        //& Insert at the end
        newNode->next = end->next;
        end->next = newNode;
        end = newNode;
    }

    return *this;
}

//$ Searches a node with a specified data
const Node* CircularLinkedList::searchNode(int data) const
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    //& If the searched node is the last node
    if ( end->data == data )
        return end;

    Node *traverse = end->next;     //& Start with 1st node

    while ( traverse != end )
    {
        if ( traverse->data == data )
        {
            return traverse;    //& Node found, return the address
        }
        traverse = traverse->next;  //& Move to the next node
    }

    return nullptr;     //& Node not found
}

//$ Inserts data after specified node with Node address traversing if the node is still present or not
/* CircularLinkedList& CircularLinkedList::insertAfterNode(Node *nodeAddress, int data)
{
    if ( nodeAddress == nullptr )
        throw NullNodeException();

    if ( end == nullptr )
        throw EmptyLinkedListException();

    Node *newNode = new Node(data);

    //& Check if the node is the last node
    if ( nodeAddress == end )
    {
        newNode->next = nodeAddress->next;
        nodeAddress->next = newNode;
        end = newNode;

        return *this;
    }

    Node *traverse = end->next;

    while ( traverse != end )
    {
        if ( traverse == nodeAddress )  //& Validate nodeAddress by traversal
        {
            newNode->next = traverse->next;
            traverse->next = newNode;
            return *this;
        }
        
        traverse = traverse->next;
    }

    throw NodeNotFoundException();  //& nodeAddress not found in the list
    
} */

//$ Inserts data after specified node with Node address trusting that the node Address provided is right
CircularLinkedList& CircularLinkedList::insertAfterNode(Node *nodeAddress, int data)
{
    if ( nodeAddress == nullptr )
        throw NullNodeException();

    if ( end == nullptr )
        throw EmptyLinkedListException();

    Node *newNode = new Node(data);

    //& Check if the node is the last node
    if ( nodeAddress == end )
    {
        newNode->next = nodeAddress->next;
        nodeAddress->next = newNode;
        end = newNode;

        return *this;
    }
    
    newNode->next = nodeAddress->next;
    nodeAddress->next = newNode;
    
    return *this;
}

//$ Inserts data after specified node with data
CircularLinkedList& CircularLinkedList::insertAfterNode(int dataToSearch, int newData)
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    Node *newNode = new Node(newData);
    
    Node *foundNode = const_cast<Node*>(searchNode(dataToSearch));

    if ( foundNode != nullptr )
    {
        newNode->next = foundNode->next;
        foundNode->next = newNode;

        //& Update end if the new node is inserted after the last node
        if ( foundNode == end )
        {
            end = newNode;
        }
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;
}

//$ Deletes first Node
CircularLinkedList& CircularLinkedList::deleteFirstNode()
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( end->next == end )
    {
        delete end;     //& Free the single node
        end = nullptr;

        return *this;
    }

    Node *temp = end->next; //& First node (head of the list)

    end->next = temp->next; //& Point end to the second node
    delete temp;            //& Delete the first node

    return *this;
}

//$ Deletes first Node
CircularLinkedList& CircularLinkedList::deleteLastNode()
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( end->next == end )
    {
        delete end;     //& Free the single node
        end = nullptr;

        return *this;
    }

    Node *traverse = end->next;

    while ( traverse->next != end )
    {
        traverse = traverse->next;
    }

    Node *temp = end;
    
    traverse->next = end->next;
    end = traverse;
    delete temp;

    return *this; 
}

//$ Deletes specified Node with Node address w/o using already defined methods
/* CircularLinkedList& CircularLinkedList::deleteSpecifiedNode(Node *nodeAddress)
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( end->next == end && end == nodeAddress )
    {
        delete end;     //& Free the single node
        end = nullptr;

        return *this;
    }

    Node *traverse = end->next;

    //& If the node to delete is the first node
    if ( traverse == nodeAddress )
    {
        end->next = traverse->next;
        delete traverse;

        return *this;
    }

    //& Traverse to find the node to delete
    while ( traverse->next != end->next )
    {
        if ( traverse->next == nodeAddress )
        {
            traverse->next = nodeAddress->next;
            if ( traverse->next == end )
            {
                end = traverse;
            }
            delete nodeAddress;

            return *this;
        }
        
        traverse = traverse->next;
    }

    throw NodeNotFoundException();
} */

//$ Deletes specified Node with Node address with using already defined methods
CircularLinkedList& CircularLinkedList::deleteSpecifiedNode(Node *nodeAddress)
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( end->next == end && end == nodeAddress )
    {
        return deleteLastNode();
    }

    Node *traverse = end->next;

    //& If the node to delete is the first node
    if ( traverse == nodeAddress )
    {
        return deleteFirstNode();
    }

    //& Traverse to find the node to delete
    while ( traverse->next != end->next )
    {
        if ( traverse->next == nodeAddress )
        {
            traverse->next = nodeAddress->next;
            if ( traverse->next == end )
            {
                end = traverse;
            }
            delete nodeAddress;

            return *this;
        }
        
        traverse = traverse->next;
    }

    throw NodeNotFoundException();
}

//$ Deletes specified Node with data w/o using already defined methods
/* CircularLinkedList& CircularLinkedList::deleteSpecifiedNode(int data)
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    //& Only 1 node is present
    if ( end->data == data && end->next == end )
    {
        delete end;     //& Free the single node
        end = nullptr;

        return *this;
    }

    Node *traverse = end->next;

    //& Deletes the first node if 2 or more nodes are present
    if ( traverse->data == data )
    {
        //& Exactly 2 nodes
        if ( traverse->next == end )
        {
            end->next = end;
            delete traverse;
        }
        else
        {
            end->next = traverse->next;
            delete traverse;
        }

        return *this;
    }

    //& Traverse and find the node
    while ( traverse->next != end->next )
    {
        if ( traverse->next->data == data )
        {
            traverse->next = traverse->next->next;

            if ( traverse->next == end )
            {
                end = traverse;
            }

            delete traverse->next;

            return *this;
        }
        
        traverse = traverse->next;
    }

    throw NodeNotFoundException();

} */

//$ Deletes specified Node with data with using already defined methods
CircularLinkedList& CircularLinkedList::deleteSpecifiedNode(int data)
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    Node *nodeToDelete = const_cast<Node*>(searchNode(data));

    if ( nodeToDelete != nullptr )
    {
        //& Only 1 node is present
        if ( nodeToDelete == end )
        {
            return deleteLastNode();
        }

        if ( nodeToDelete == end->next)
        {
            return deleteFirstNode();
        }

        Node *traverse = end->next;

        //& Traverse and find the node
        while ( traverse->next != nodeToDelete )
        {
            traverse = traverse->next;
        }

        traverse->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;
}

//$ Displays the list
CircularLinkedList& CircularLinkedList::display()
{
    if ( end == nullptr )
        throw EmptyLinkedListException();

    Node *traverse = end->next;

    std::cout<<"The list items are -\n";
    do
    {
        std::cout<<traverse->data<<" ";

        traverse = traverse->next;
    }
    while ( traverse != end->next );

    std::cout<<"\n";

    return *this;
}