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

class GraphListNotCreatedException : public GraphListExceptions
{
    public :

        GraphListNotCreatedException() : GraphListExceptions("Error : The adjacency list is not created!.") {}
};

class InvalidEdgeCountException : public GraphListExceptions
{
    public :

        InvalidEdgeCountException() : GraphListExceptions("Error : Edge count in a Graph must be positive!.") {}
};

class InvalidVertexIndexException : public GraphListExceptions
{
    public :

        InvalidVertexIndexException() : GraphListExceptions("Error : Invalid vertex index! The range is 0 to current vertex/node count.") {}
};

class InvalidEdgesDataException : public GraphListExceptions
{
    public :

        InvalidEdgesDataException() : GraphListExceptions("Error : Invalid edges data provided! The data should be an array of pairs.") {}
};

class EdgeAlreadyAddedException : public GraphListExceptions
{
    public :

        EdgeAlreadyAddedException() : GraphListExceptions("Error : Edge is already present between the pair of nodes/vertices.") {}
};

class EdgeToSelfNodeException : public GraphListExceptions
{
    public :

        EdgeToSelfNodeException() : GraphListExceptions("Error : Edge to the same node is not allowed / Self Loops not allowed.") {}
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
        AdjacencyList& deleteLast();

        //$ Delete specific Node
        AdjacencyList& deleteSpecifiedNode(int nodeToDelete);

        //$ Searches if the node exists, returns true if it exists and false otherwise
        bool searchNode(int vertenNo) const;

        //$ Displays all the values in the list
        void displayList() const;
};

//$ Copy Constructor
AdjacencyList::AdjacencyList(const AdjacencyList &adjl)
{
    if (adjl.start == nullptr)
    {
        this->start = nullptr;
        return;
    }

    // Initialize the first node
    Node *sourceSLL = adjl.start;
    this->start = new Node(sourceSLL->vertexNo);

    // Traverse and copy remaining nodes
    Node *thisSLL = this->start; // Current node in the new list
    sourceSLL = sourceSLL->next;

    while (sourceSLL != nullptr)
    {
        thisSLL->next = new Node(sourceSLL->vertexNo);
        thisSLL = thisSLL->next;
        sourceSLL = sourceSLL->next;
    }
}

//$ Copy Assignment Op.
AdjacencyList& AdjacencyList::operator=(const AdjacencyList &adjl)
{
    if ( this == &adjl)
        return *this;

    //& Delete existing list
    while( this->start != nullptr )
    {
        Node *temp = start->next;
        delete start;
        start = temp;
    }

    if (adjl.start == nullptr)
    {
        this->start = nullptr;
        return *this;
    }

    // Initialize the first node
    Node *sourceSLL = adjl.start;
    this->start = new Node(sourceSLL->vertexNo);

    // Traverse and copy remaining nodes
    Node *thisSLL = this->start; // Current node in the new list
    sourceSLL = sourceSLL->next;

    while (sourceSLL != nullptr)
    {
        thisSLL->next = new Node(sourceSLL->vertexNo);
        thisSLL = thisSLL->next;
        sourceSLL = sourceSLL->next;
    }

    return *this;
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
AdjacencyList& AdjacencyList::deleteLast()
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

    while ( traverse->next && traverse->next->next )
    {
        traverse = traverse->next;
    }

    delete traverse->next;
    traverse->next = nullptr;

    return *this;
}

//$ Delete specific Node
AdjacencyList& AdjacencyList::deleteSpecifiedNode(int vertexNo)
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

    return *this;
    
}

//$ Searches if the node exists, returns true if it exists and false otherwise
bool AdjacencyList::searchNode(int vertexNo) const
{
    if ( !start )
        return false;

    Node *traverse = start;

    while ( traverse )
    {
        if ( traverse->vertexNo == vertexNo )
            return true;
        
        traverse = traverse->next;
    }

    return false;
}

//$ Displays all the values in the list
void AdjacencyList::displayList() const
{
    if ( !start )
    {
        std::cout<<"\n";
        return;
    }

    Node *traverse = start;

    while ( traverse )
    {
        std::cout<<traverse->vertexNo<<" ";
        traverse = traverse->next;
    }

    std::cout<<"\n";
}

class GraphList
{
    private :
        int vertexCount, edgeCount;
        AdjacencyList *graphListArr;

    public :
    
        //$ Constructor
        GraphList(int vertexCount);

        //$ Copy Constructor
        GraphList(const GraphList &gl);

        //$ Copy Assignment Op.
        GraphList& operator=(const GraphList &gl);

        //$ Destructor
        ~GraphList();

        //$ Creates a graph with appropriate List Representation
        void createGraphList(int (*edges)[2], int edgeCount);

        //$ Adds an edge in the graph
        GraphList& addEdge(int u, int v);

        //$ Prints the values in the adjacency list in the whole graph
        void printGraph() const;

        //$ Returns the total number of edges
        int getEdgeCount() const;

        //$ Returns the total number of vertices
        int getVertexCount() const;

};

//$ Constructor
GraphList::GraphList(int vertexCount)
{
    if ( vertexCount <= 0)
        throw NegativeVertexCountException();

    this->vertexCount = vertexCount;
    edgeCount = 0;

    graphListArr = new AdjacencyList[vertexCount]();

}

//$ Copy Constructor
GraphList::GraphList(const GraphList &gl)
{
    if ( !gl.graphListArr )
    {
        this->vertexCount = gl.vertexCount;
        this->edgeCount = gl.edgeCount;
        this->graphListArr = nullptr;
        return;
    }

    this->vertexCount = gl.vertexCount;
    this->edgeCount = gl.edgeCount;

    this->graphListArr = new AdjacencyList[vertexCount]();

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        this->graphListArr[i] = gl.graphListArr[i];
    }

}

//$ Copy Assignment Op.
GraphList& GraphList::operator=(const GraphList &gl)
{
    if ( this == &gl )
        return *this;

    //& Existing Linked List Array Clean-up
    if ( this->graphListArr )
    {
        delete[] graphListArr;
    }

    if ( !gl.graphListArr )
    {
        this->vertexCount = gl.vertexCount;
        this->edgeCount = gl.edgeCount;
        this->graphListArr = nullptr;
        return *this;
    }

    this->vertexCount = gl.vertexCount;
    this->edgeCount = gl.edgeCount;

    this->graphListArr = new AdjacencyList[vertexCount]();

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        this->graphListArr[i] = gl.graphListArr[i];
    }

    return *this;
}

//$ Destructor
GraphList::~GraphList()
{
    if ( graphListArr )
        delete[] graphListArr;
}

//$ Creates a graph with appropriate List Representation
void GraphList::createGraphList(int (*edges)[2], int edgeCount)
{
    if ( !graphListArr )
        throw GraphListNotCreatedException();
    
    if ( !edges )
        throw InvalidEdgesDataException();

    if ( edgeCount < 0 )
        throw InvalidEdgeCountException();

    this->edgeCount = edgeCount;

    if ( !edgeCount )
    {
        std::cout<<"Please provide correct edge count and edge data!\n";
        return;
    }

    for ( int i = 0 ; i < edgeCount ; i++ )
    {
        int node1 = edges[i][0];
        int node2= edges[i][1];

        if ( node1 == node2 )
        throw EdgeToSelfNodeException();

        if ( node1 < 0 || node1 >= vertexCount || node2 < 0 || node2 >= vertexCount )
            throw InvalidVertexIndexException();

        graphListArr[node1].insertFirst(node2);
        graphListArr[node2].insertFirst(node1);
    }

}

//$ Adds an edge in the graph
GraphList& GraphList::addEdge(int node1, int node2)
{
    if ( !graphListArr )
        throw GraphListNotCreatedException();
    
    if ( node1 == node2 )
        throw EdgeToSelfNodeException();
    
    if ( node1 < 0 || node1 >= vertexCount || node2 < 0 || node2 >= vertexCount )
            throw InvalidVertexIndexException();

    if ( graphListArr[node1].searchNode(node2) || graphListArr[node2].searchNode(node1) )
    {
        throw EdgeAlreadyAddedException();
    }

    graphListArr[node1].insertFirst(node2);
    graphListArr[node2].insertFirst(node1);

    edgeCount++;

    return *this;
}

//$ Prints the values in the adjacency list in the whole graph
void GraphList::printGraph() const
{
    if ( !graphListArr )
        throw GraphListNotCreatedException();

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        std::cout<<i<<" : ";
        graphListArr[i].displayList();
    }
}

//$ Returns the total number of edges
int GraphList::getEdgeCount() const
{
    if ( !graphListArr )
        throw GraphListNotCreatedException();

    return edgeCount;
}

//$ Returns the total number of vertices
int GraphList::getVertexCount() const
{
    if ( !graphListArr )
        throw GraphListNotCreatedException();
    
    return vertexCount;
}

int main()
{
    try
    {
        std::cout << "Starting GraphList operations testing...\n";

        //$ Test 1: Create a GraphList
        std::cout << "\nTest 1: Creating a GraphList...\n";
        GraphList gl(5); // Creating a graph with 5 vertices
        std::cout << "GraphList created successfully with 5 vertices.\n";

        //$ Test 2: Populate the GraphList using createGraph()
        std::cout << "\nTest 2: Creating the GraphList using edges array...\n";
        int edges[][2] = {
            {0, 1},
            {0, 2},
            {1, 3},
            {3, 4},
            {2, 4}
        };
        gl.createGraphList(edges, 5);
        std::cout << "GraphList populated successfully using createGraphList().\n";

        //$ Test 3: Print the GraphList
        std::cout << "\nTest 3: Printing the GraphList...\n";
        gl.printGraph();

        //$ Test 4: Get edge and vertex counts
        std::cout << "\nTest 4: Retrieving edge and vertex counts...\n";
        std::cout << "Total vertices: " << gl.getVertexCount() << "\n";
        std::cout << "Total edges: " << gl.getEdgeCount() << "\n";

        //$ Test 4.1: Adding mores edges
        std::cout << "\nTest 5: Adding mores edges...\n";
        gl.addEdge(2, 1).addEdge(3, 2).addEdge(1, 4).addEdge(3, 0).addEdge(4, 0);
        std::cout << "\nTest 3: Printing the GraphList...\n";
        gl.printGraph();

        //$ Test 5: Attempt to add an invalid edge
        std::cout << "\nTest 5: Attempting to add an invalid edge...\n";
        try
        {
            gl.addEdge(0, 0); // Self-loop
        }
        catch (const std::exception &ex)
        {
            std::cout << "Caught exception: " << ex.what() << "\n";
        }

        //$ Test 6: Checking copy assignment and copy constructor using edges array
        std::cout << "\nTest 6: Checking copy assignment and copy constructor...\n";
        int edges1[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
        GraphList gl2(5);
        gl2.createGraphList(edges1, 5);
        std::cout << "Another Test Graph:\n";
        gl2.printGraph();

        GraphList gl3(gl2);
        std::cout << "Copy Constructor Graph:\n";
        gl3.printGraph();
        
        GraphList gl4(5);
        gl4 = gl3;
        std::cout << "Copy Assignment Graph:\n";
        gl4.printGraph();

        std::cout << "\nAll tests completed successfully.\n";
    }
    catch (const std::exception &ex)
    {
        std::cerr << "An exception occurred: " << ex.what() << "\n";
    }

    std::cin.get();
    return 0;
}