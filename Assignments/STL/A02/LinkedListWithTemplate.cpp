#include<iostream>
#include<string>

//@ Exception classes

//$ Singly Linked List Exception Base Class
class SinglyLinkedListExceptions : public std::exception
{
    protected :

        std::string message;

    public:

        SinglyLinkedListExceptions(const std::string &msg)
        :   message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

//@ Singly Linked List Specific Exception Child Classes

class NodeNotFoundException : public SinglyLinkedListExceptions
{
    public:
        NodeNotFoundException() : SinglyLinkedListExceptions("Error : The specified node was not found.") {}
};

class EmptyLinkedListException : public SinglyLinkedListExceptions
{
    public:
        EmptyLinkedListException() : SinglyLinkedListExceptions("Error : The linked list is empty. Cannot perform some operations like delete, search etc.") {}
};

class NullNodeException : public SinglyLinkedListExceptions
{
    public:
        NullNodeException() : SinglyLinkedListExceptions("Error : Node Address cannot be null.") {}
};

template <typename DT>
class SinglyLinkedList;

//@ Node class
template <typename DT>
class Node
{
    private:

        DT data;
        Node *next;

        friend class SinglyLinkedList<DT>;

    public :

        //$ Default Non-Param. Constructor
        Node() : data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(DT data) : data(data), next(nullptr) {}

};


//@ Singly Linked List class
template <typename DT>
class SinglyLinkedList
{
    private :

        Node<int> *start;

    public :

        //$ Default Non-Param. Constructor
        SinglyLinkedList() : start(nullptr) {}

        //$ Copy Constructor
        SinglyLinkedList(const SinglyLinkedList &sll);

        //$ Overloaded Copy Assignment Op.
        SinglyLinkedList<DT>& operator=(const SinglyLinkedList &sll);

        //$ Destructor
        ~SinglyLinkedList();

        //$ Inserts data at beginning
        SinglyLinkedList<DT>& insertAtBeginning(DT data);

        //$ Inserts data at end
        SinglyLinkedList<DT>& insertAtEnd(DT data);

        //$ Searches the List with a specified data
        const Node<DT>* searchNode(DT data) const;

        //$ Inserts data after a specified node with Node address
        SinglyLinkedList<DT>& insertAfterNode(Node<DT> *node, DT data);

        //$ Inserts data after a specified node with data
        SinglyLinkedList<DT>& insertAfterNode(DT dataToSearch, DT data);

        //$ Deletes First Node
        SinglyLinkedList<DT>& deleteFirstNode();

        //$ Deletes last Node
        SinglyLinkedList<DT>& deleteLastNode();

        //$ Deletes a specified node with node address
        SinglyLinkedList<DT>& deleteSpecifiedNode(Node<DT> *nodeAddress);

        //$ Deletes a specified node with data value
        SinglyLinkedList<DT>& deleteSpecifiedNode(DT data);

        //$ Displays the list
        SinglyLinkedList<DT>& display();

};

//$ Copy Constructor
template <typename DT>
SinglyLinkedList<DT>::SinglyLinkedList(const SinglyLinkedList &sll)
{
    //& My logic
    /* if ( sll.start == nullptr )
    {
        this->start = nullptr;
    }
    else
    {
        Node<DT> *traverseOtherSLL = sll.start;
        Node<DT> *thisSLL = nullptr;
        
        while ( traverseOtherSLL != nullptr )
        {
            Node<DT> *temp = new Node(traverseOtherSLL->data);

            if ( traverseOtherSLL == sll.start)
            {
                this->start = temp;
            }
            else
            {
                thisSLL->next = temp;
            }

            thisSLL = temp;
            traverseOtherSLL = traverseOtherSLL->next;
        }
    } */

    //& More optimized logic
    if (sll.start == nullptr)
    {
        this->start = nullptr;
        return;
    }

    // Initialize the first node
    Node<DT> *traverseOtherSLL = sll.start;
    this->start = new Node<DT>(traverseOtherSLL->data);

    // Traverse and copy remaining nodes
    Node<DT> *traverseThisSLL = this->start; // Current node in the new list
    traverseOtherSLL = traverseOtherSLL->next;

    while (traverseOtherSLL != nullptr)
    {
        traverseThisSLL->next = new Node<DT>(traverseOtherSLL->data);
        traverseThisSLL = traverseThisSLL->next;
        traverseOtherSLL = traverseOtherSLL->next;
    }
}

//$ Overloaded Copy Assignment Op.
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::operator=(const SinglyLinkedList &sll)
{
    if ( this == &sll)
        return *this;

    //& Delete existing list
    while( this->start != nullptr )
    {
        Node<DT> *temp = start->next;
        delete start;
        start = temp;
    }

    //& My logic
    /* if ( sll.start == nullptr )
    {
        this->start = nullptr;
    }
    else
    {
        Node<DT> *traverseOtherSLL = sll.start;
        
        this->start = new Node<DT>(traverseOtherSLL->data);

        Node<DT> *thisSLL = this->start;
        
        while ( traverseOtherSLL->next != nullptr )
        {
            thisSLL->next = new Node<DT>(traverseOtherSLL->next->data);

            traverseOtherSLL = traverseOtherSLL->next;

            thisSLL = thisSLL->next;
        }
    } */

    //& More optimized logic
    if (sll.start == nullptr)
    {
        this->start = nullptr;
        return *this;
    }

    // Initialize the first node
    Node<DT> *traverseOtherSLL = sll.start;
    this->start = new Node<DT>(traverseOtherSLL->data);

    // Traverse and copy remaining nodes
    Node<DT> *traverseThisSLL = this->start; // Current node in the new list
    traverseOtherSLL = traverseOtherSLL->next;

    while (traverseOtherSLL != nullptr)
    {
        traverseThisSLL->next = new Node<DT>(traverseOtherSLL->data);
        traverseThisSLL = traverseThisSLL->next;
        traverseOtherSLL = traverseOtherSLL->next;
    }

    return *this;
}

//$ Destructor
template <typename DT>
SinglyLinkedList<DT>::~SinglyLinkedList()
{
    while( start != nullptr )
    {
        Node<DT> *temp = start->next;

        delete start;

        start = temp;
    }
}

//$ Inserts data at beginning
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::insertAtBeginning(DT data)
{
    //& If list is not empty
    if ( this->start != nullptr)
    {
        Node<DT> *temp = this->start;

        start = new Node<DT>(data);

        start->next = temp;
    }
    else
    {
        //& If list is empty
        start = new Node<DT>(data);
    }

    return *this;

}

//$ Inserts data at end
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::insertAtEnd(DT data)
{
    if ( this->start != nullptr)
    {
        Node<DT> *temp = this->start;
        
        while ( temp->next != nullptr )
        {
            temp = temp->next;
        }

        temp->next = new Node<DT>(data);
    }
    else
    {
        start = new Node<DT>(data);
    }

    return *this;

}

//$ Searches the List with a specified data
template <typename DT>
const Node<DT>* SinglyLinkedList<DT>::searchNode(DT data) const
{
    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    Node<DT> *temp = this->start;

    while( temp != nullptr )
    {
        if ( temp->data == data )
            return temp;
        
        temp = temp->next;
        
    } 

    return nullptr;
}

//$ Inserts data after a specified node with Node address
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::insertAfterNode(Node<DT> *nodeAddress, DT data)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    //& Handle null nodeAddress
    if ( nodeAddress == nullptr )
    {
        throw NullNodeException();
    }
    
    Node<DT> *traverse = this->start;
    
    //& Traverse the list to find the specified node
    while ( traverse != nullptr && traverse != nodeAddress )
    {
        traverse = traverse->next;
    }
    
    //& If the node is found
    if ( traverse == nodeAddress )
    {
        Node<DT> *newNode = new Node<DT>(data);     //& Create new node
        newNode->next = nodeAddress->next;  //& Link new node to the next node
        nodeAddress->next = newNode;        //& Link current node to the new node
    }
    else
    {
        //& Throw an exception if the node is not found
        throw NodeNotFoundException();
    }

    return *this;
}

//$ Inserts data after a specified node with data
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::insertAfterNode(DT dataToSearch, DT newNodeData)
{
    if ( start == nullptr )
        throw EmptyLinkedListException();
    
    Node<DT> *traverse = this->start;
    
    //& Traverse the list to find the specified node
    while ( traverse != nullptr && traverse->data != dataToSearch )
    {
        traverse = traverse->next;
    }
    
    //& If the node is found
    if ( traverse->data == dataToSearch )
    {
        Node<DT> *newNode = new Node<DT>(newNodeData);     //& Create new node
        newNode->next = traverse->next;  //& Link new node to the next node
        traverse->next = newNode;        //& Link current node to the new node
    }
    else
    {
        //& Throw an exception if the node is not found
        throw NodeNotFoundException();
    }

    return *this;
}

//$ Deletes First Node
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::deleteFirstNode()
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }
    
    Node<DT> *temp = start->next;

    delete start;

    start = temp;

    return *this;

}

//$ Deletes last Node
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::deleteLastNode()
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

    while ( traverse->next->next != nullptr )
    {
        traverse = traverse->next;
    }

    delete traverse->next;
    traverse->next = nullptr;

    return *this;
}

//$ Overloaded : Deletes a specified node providing the Node Address
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::deleteSpecifiedNode(Node<DT> *nodeAddress)
{
    //& Handle null nodeAddress
    if ( nodeAddress == nullptr )
    {
        throw NullNodeException();
    }

    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }
    
    Node<DT> *traverse = this->start;
    Node<DT> *nodeBoforeSpecifiedNode = nullptr;
    
    //& Traverse the list to find the specified node
    while ( traverse != nullptr && traverse != nodeAddress )
    {
        if ( traverse->next == nodeAddress )
        {
            nodeBoforeSpecifiedNode = traverse;
        }

        traverse = traverse->next;
    }
    
    //& If the node is found
    if ( traverse == nodeAddress )
    {
        Node<DT> *temp = traverse->next;
        delete traverse;
         
        if ( nodeBoforeSpecifiedNode != nullptr )
            nodeBoforeSpecifiedNode->next = temp;
        else
        {   
            //& If the deleted node was the first Node
            start = temp;
        }
        
    }
    else
    {
        //& Throw an exception if the node is not found
        throw NodeNotFoundException();
    }

    return *this;
}

//$ Overloaded : Deletes a specified node providing the data
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::deleteSpecifiedNode(DT data)
{
    if ( start == nullptr )
    {
        throw EmptyLinkedListException();
    }
    
    Node<DT> *traverse = this->start;
    Node<DT> *nodeBoforeSpecifiedNode = nullptr;

    while( traverse!= nullptr && traverse->data != data )
    {
        if ( traverse->next->data == data )
        {
            nodeBoforeSpecifiedNode = traverse;
        }

        traverse = traverse->next;
    }

    if ( traverse != nullptr && traverse->data == data )
    {
        Node<DT> *temp = traverse->next;
        delete traverse;

        if ( nodeBoforeSpecifiedNode != nullptr )
            nodeBoforeSpecifiedNode->next = temp;
        else
            start = temp;
    }
    else
    {
        throw NodeNotFoundException();
    }

    return *this;

}

//$ Displays the list
template <typename DT>
SinglyLinkedList<DT>& SinglyLinkedList<DT>::display()
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
        SinglyLinkedList<int> list1;

        std::cout << "Using insertAtBeginning() -\n";
        for (int i = 80; i > 0; i -= 10)
        {
            // Insert elements at the beginning
            list1.insertAtBeginning(i);
        }
        list1.display();

        // Insert elements at the end
        std::cout << "Using insertAtEnd() -\n";
        list1.insertAtEnd(90);
        list1.insertAtEnd(100);
        list1.display();

        // Copy constructor
        std::cout << "Copy constructor -\n";
        SinglyLinkedList list2 = list1;
        list2.display();

        // Copy assignment operator
        std::cout << "Copy assignment op. -\n";
        SinglyLinkedList<int> list3;
        list3 = list1;
        list3.display();

        // Insert after a specific node
        std::cout << "Using searchNode() and insertAfterNode() -\n";
        Node<int> *thirdNode = const_cast<Node<int> *>(list1.searchNode(30));
        list1.insertAfterNode(thirdNode, 35);
        list1.display();

        // Delete the first node
        std::cout << "Using deleteFirstNode() -\n";
        list1.deleteFirstNode();
        list1.display();

        // Delete the last node
        std::cout << "Using deleteLastNode() -\n";
        list1.deleteLastNode();
        list1.display();

        // Search for a specific node by data
        std::cout << "Using searchNode() -\n";
        const Node<int> *foundNode = list1.searchNode(35);
        if (foundNode)
        {
            std::cout << "Node with data 35 found at address: " << foundNode << std::endl;
        }
        else
        {
            std::cout << "Node with data 35 not found." << std::endl;
        }

        // Delete a specific node by address
        std::cout << "Using deleteSpecifiedNode() -\n";
        list1.deleteSpecifiedNode(thirdNode);
        list1.display();

        // Delete a specific node by data
        std::cout << "Using deleteSpecifiedNode(int data) -\n";
        list1.deleteSpecifiedNode(35);
        list1.display();

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