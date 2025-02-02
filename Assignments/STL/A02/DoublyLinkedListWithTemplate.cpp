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

template <typename DT>
class DoublyLinkedList;

template <typename DT>
class Node
{
    private:

        Node *previous;
        int data;
        Node *next;

        friend class DoublyLinkedList<DT>;

    public:

        //$ Default Non-Param. Constructor
        Node() : previous(nullptr), data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(DT data) : previous(nullptr), data(data), next(nullptr) {}
    
};

template <typename DT>
class DoublyLinkedList
{
    private:

        Node<DT> *start;

    public:

        //$ Default Non-Param. Constructor
        DoublyLinkedList() : start(nullptr) {}

        //$ Default Param. Constructor
        DoublyLinkedList(DT data) : start(new Node<DT>(data)) {}

        //$ Copy Constructor
        DoublyLinkedList(const DoublyLinkedList<DT> &dll);

        //$ Overloaded Copy Assignment= Op.
        DoublyLinkedList<DT>& operator=(const DoublyLinkedList<DT> &dll);

        //$ Destructor
        ~DoublyLinkedList();

        //$ Inserts data at beginning
        DoublyLinkedList<DT>& insertAtBeginning(DT data);

        //$ Inserts data at end
        DoublyLinkedList<DT>& insertAtEnd(DT data);

        //$ Searches a node with a specified data
        const Node<DT>* searchNode(DT data) const;

        //$ Inserts data after specified node with Node address
        DoublyLinkedList<DT>& insertAfterNode(Node<DT> *nodeAddress, DT data);

        //$ Inserts data after specified node with data
        DoublyLinkedList<DT>& insertAfterNode(DT dataToSearch, DT newData);

        //$ Deletes first Node
        DoublyLinkedList<DT>& deleteFirstNode();

        //$ Deletes first Node
        DoublyLinkedList<DT>& deleteLastNode();

        //$ Deletes specified Node with Node address
        DoublyLinkedList<DT>& deleteSpecifiedNode(Node<DT> *nodeAddress);

        //$ Deletes specified Node with data
        DoublyLinkedList<DT>& deleteSpecifiedNode(DT data);

        //$ Displays the list
        DoublyLinkedList<DT>& display();

};

//$ Copy Constructor
template <typename DT>
DoublyLinkedList<DT>::DoublyLinkedList(const DoublyLinkedList<DT> &dll)
{
    if ( dll.start == nullptr )
    {
        this->start = nullptr;
    }
    else
    {
        Node<DT> *traverseOtherDLL = dll.start;
        Node<DT> *thisDLL = nullptr;
        
        while ( traverseOtherDLL != nullptr )
        {
            Node<DT> *temp = new Node<DT>(traverseOtherDLL->data);

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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::operator=(const DoublyLinkedList<DT> &dll)
{
    if ( this == &dll )
        return *this;

    //& Delete existing list
    while ( this->start != nullptr)
    {
        Node<DT> *temp = start;
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
        Node<DT> *traverseOtherDLL = dll.start;
        Node<DT> *thisDLL = nullptr;
        
        while ( traverseOtherDLL != nullptr )
        {
            Node<DT> *temp = new Node<DT>(traverseOtherDLL->data);

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
template <typename DT>
DoublyLinkedList<DT>::~DoublyLinkedList()
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
        Node<DT> *temp = start;
        start = start->next;
        start->previous = nullptr;
        delete temp;
    } */
}

//$ Inserts data at the beginning
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::insertAtBeginning(DT data)
{
    Node<DT> *temp = new Node<DT>(data);
    
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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::insertAtEnd(DT data)
{
    if ( start == nullptr )
    {
        start = new Node<DT>(data);
    }
    else
    {
        Node<DT> *traverse = start;

        while ( traverse->next != nullptr )
        {
            traverse = traverse->next;
        }

        Node<DT> *temp = new Node<DT>(data);

        traverse->next = temp;

        temp->previous = traverse;
    }
    
    return *this;

}

//$ Searches a node with a specified data
template <typename DT>
const Node<DT>* DoublyLinkedList<DT>::searchNode(DT data) const
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }

    Node<DT> *traverse = start;

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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::insertAfterNode(DT dataToSearch, DT newData)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node<DT> *traverse = start;

    while ( traverse != nullptr && traverse->data != dataToSearch )
    {
        traverse = traverse->next;
    }

    if ( traverse != nullptr )
    {
        Node<DT> *newNode = new Node<DT>(newData);

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
/* template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::insertAfterNode(Node<DT> *nodeAddress, DT newData)
{
    if ( nodeAddress == nullptr)
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    Node<DT> *traverse = start;

    while ( traverse != nullptr && traverse != nodeAddress )
    {
        traverse = traverse->next;
    }

    if ( traverse == nodeAddress )
    {
        Node<DT> *newNode = new Node(newData);

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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::insertAfterNode(Node<DT> *nodeAddress, DT newData)
{
    if ( nodeAddress == nullptr)
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    
    Node<DT> *newNode = new Node<DT>(newData);

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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::deleteFirstNode()
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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::deleteLastNode()
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }

    Node<DT> *traverse = start;

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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::deleteSpecifiedNode(DT data)
{
    if ( start == nullptr)
        throw EmptyLinkedListException();

    Node<DT> *traverse = start;

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
/* template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::deleteSpecifiedNode(Node<DT> *nodeAddress)
{
    if ( nodeAddress == nullptr )
        throw NullNodeException();

    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node<DT> *traverse = start;

    while ( traverse != nodeAddress )
    {
        traverse = traverse->next;
    }

    if ( traverse == nodeAddress )
    {
        Node<DT> *previousNode = traverse->previous;
        Node<DT> *nextNode = traverse->next;
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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::deleteSpecifiedNode(Node<DT> *nodeAddress)
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
template <typename DT>
DoublyLinkedList<DT>& DoublyLinkedList<DT>::display()
{
    if ( start == nullptr )
        throw EmptyLinkedListException();

    Node<DT> *traverse = start;

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
        DoublyLinkedList<int> list1;

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
        DoublyLinkedList<int> list2 = list1;
        list1.display();

        std::cout<<"Copy assignment op. -\n";
        DoublyLinkedList<int> list3;
        list3 = list1;
        list1.display();

        // Insert after a specific node
        std::cout<<"Using searchNode() and insertAfterNode() -\n";

        Node<int> *thirdNode = const_cast<Node<int>*>(list1.searchNode(30));
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
        const Node<int> *foundNode = list1.searchNode(85);
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