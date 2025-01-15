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

//$ Graph using List Exceptions Base Class
class GraphListExceptions : public std::exception
{
    private:
        std::string message;

    public:

        GraphListExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

class NegativeVertexCountException : public GraphListExceptions
{
    public :

        NegativeVertexCountException() : GraphListExceptions("Error : Vertex/Node count in a Graph must be positive!.") {}
};

class AdjacencyList;
class GraphList;

class Node
{
    private :
        int vertexNo;
        Node *next;

    public :
        Node(int vertexNo) : vertexNo(vertexNo), next(nullptr) {}
        friend class AdjacencyList;
        friend class GraphList;
};

class AdjacencyList
{
    private :
        Node *start;

    public :
    
        //$ Constructor
        AdjacencyList() : start(nullptr) {}

        //$ Copy Constructor
        AdjacencyList(const AdjacencyList &adjl);

        //$ Copy Assignment Op.
        AdjacencyList& operator=(const AdjacencyList &adjl);

        //$ Destructor
        ~AdjacencyList();
    
        //$ Inserts at first
        AdjacencyList& insertFirst(int vertexNo);

        //$ Inserts at last
        AdjacencyList& insertLast(int vertexNo);

        //$ Delete first
        AdjacencyList& deleteFirst();

        //$ Delete last
        AdjacencyList& deleteFirst();

        //$ Delete specific Node
        AdjacencyList& deleteSpecifedNode(int nodeToDelete);
};

//$ Copy Constructor
AdjacencyList::AdjacencyList(const AdjacencyList &adjl)
{
    
}

//$ Copy Assignment Op.
AdjacencyList& AdjacencyList::operator=(const AdjacencyList &adjl)
{

}

//$ Destructor
AdjacencyList::~AdjacencyList()
{
    while ( start != nullptr )
    {
        Node *temp = start->next;
        delete start;
        start = temp;
    }
}

//$ Inserts at first
AdjacencyList& AdjacencyList::insertFirst(int vertexNo)
{
    Node *newNode = new Node(vertexNo);
    
    if ( !start )   //& Empty List 
    {
        start = newNode;
        return *this;
    }

    newNode->next = start;
    start = newNode;

    return *this;

}

//$ Inserts at last
AdjacencyList& AdjacencyList::insertLast(int vertexNo)
{
    Node *newNode = new Node(vertexNo);
    
    if ( !start )   //& Empty List 
    {
        start = newNode;
        return *this;
    }

    Node *traverse = start;

    while ( traverse->next )
    {
        traverse = traverse->next;
    }

    traverse->next = newNode;

    return *this;
}

//$ Delete first
AdjacencyList& AdjacencyList::deleteFirst()
{
    if ( !start )
        throw EmptyLinkedListException();

    Node *temp = start->next;
    delete start;

    start = temp;

    return *this;
}

//$ Delete last
AdjacencyList& AdjacencyList::deleteFirst()
{
    if ( !start )
        throw EmptyLinkedListException();

    if ( !start->next ) //& Only 1 node present
    {
        delete start;
        start = nullptr;
        return *this;
    }

    Node *traverse = start;

    while ( traverse->next->next )
    {
        traverse = traverse->next;
    }

    delete traverse->next;
    traverse->next = nullptr;

    return *this;
}

//$ Delete specific Node
AdjacencyList& AdjacencyList::deleteSpecifedNode(int vertexNo)
{
    if ( !start )
        throw EmptyLinkedListException();
    
    if ( vertexNo == start->vertexNo )
    {
        deleteFirst();
        return *this;
    }
    
    Node *traverse = start;

    while ( traverse->next && traverse->next->vertexNo != vertexNo )
    {
        traverse = traverse->next;
    }

    if ( traverse->next && traverse->next->vertexNo == vertexNo )
    {
        Node *temp = nullptr;
        if ( traverse->next->next )
        {
            temp = traverse->next->next;
            delete traverse->next;
            traverse->next = temp;
        }
        else
        {
            //& For Last node
            delete traverse->next;
            traverse->next = nullptr;
        }
    }
    else
        throw NodeNotFoundException();  //& Node not found
    
}

class GraphList
{
    private :
        int vertexCount;
        AdjacencyList *arr;

    public :
    
        //$ Constructor
        GraphList(int vertexCount);

};

//$ Constructor
GraphList::GraphList(int vertexCount)
{
    if ( vertexCount <= 0)
        throw NegativeVertexCountException();

    this->vertexCount = vertexCount;

    arr = new AdjacencyList[vertexCount]();

}