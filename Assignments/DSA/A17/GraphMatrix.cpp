#include<iostream>
#include<string>

//@ Exception classes

//$ Graph using Matrix Exceptions Base Class
class GraphMatrixExceptions : public std::exception
{
    private:
        std::string message;

    public:

        GraphMatrixExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

class AdjMatrixNotCreatedException : public GraphMatrixExceptions
{
    public :

        AdjMatrixNotCreatedException() : GraphMatrixExceptions("Error : The adjacency matrix was not created!.") {}
};

class NegativeNodesException : public GraphMatrixExceptions
{
    public :

        NegativeNodesException() : GraphMatrixExceptions("Error : Node count in a Graph must be positive!.") {}
};

class InvalidEdgeCountException : public GraphMatrixExceptions
{
    public :

        InvalidEdgeCountException() : GraphMatrixExceptions("Error : Edge count in a Graph must be positive!.") {}
};

class InvalidVertexIndexException : public GraphMatrixExceptions
{
    public :

        InvalidVertexIndexException() : GraphMatrixExceptions("Error : Invalid vertex index! The range is 0 to current vertex/node count.") {}
};

class InvalidEdgesDataException : public GraphMatrixExceptions
{
    public :

        InvalidEdgesDataException() : GraphMatrixExceptions("Error : Invalid edges data provided! The data should be an array of pairs.") {}
};

class GraphMatrix
{
    private :

        int vertexCount, edgeCount, **adj;

    public:

        //$ Constructor
        GraphMatrix(int vertexCount);

        //$ Copy Constructor
        GraphMatrix(const GraphMatrix& gm);

        //$ Copy Assignment Op.
        GraphMatrix& operator=(const GraphMatrix& gm);

        //$ Destructor
        ~GraphMatrix();

        //$ Creates relationship and stores adjacent node info.
        void createGraph(int edges[][2], int edgeCount, bool isDirected);

        //$ Adds edge info to the adjacency matrix 
        GraphMatrix& addEdge(int u, int v, bool isDirected);

        //$ Removes an edge from the graph
        GraphMatrix& removeEdge(int u, int v, bool isDirected);

        //$ Utility method to get the total number of edges
        int getEdgeCount() const;

        //$ Utility method to get the total number of vertices
        int getVertexCount() const;

        //$ Prints the Graph Adjacency Matrix
        void printAdjMatrix() const;

        //$ Prints Adjacent Nodes in the graph
        void printAdjacentNodes(int node) const;

        //$ Checks if the node is isolated
        bool isIsolatedNode(int nodeToCheck) const; 
    
};

//$ Constructor
GraphMatrix::GraphMatrix(int vertexCount)
: adj(nullptr)
{
    if ( vertexCount <= 0 )
        throw NegativeNodesException();

    this->vertexCount = vertexCount;
    edgeCount = 0;

    adj = new int*[vertexCount];

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        adj[i] = new int[vertexCount]();
    }
}

//$ Copy Constructor
GraphMatrix::GraphMatrix(const GraphMatrix& gm)
: edgeCount(gm.edgeCount), vertexCount(gm.vertexCount)
{
    if ( !gm.adj )
    {
        this->adj = nullptr;
        return;
    }

    this->adj = new int*[vertexCount];

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        adj[i] = new int[vertexCount]();
    }

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        for ( int j = 0 ; j < vertexCount ; j++ )
        {
            this->adj[i][j] = gm.adj[i][j];
        }
    }
}

//$ Copy Assignment Op.
GraphMatrix& GraphMatrix::operator=(const GraphMatrix& gm)
{
    if( this == &gm )
        return *this;

    if ( !gm.adj )
    {
        this->adj = nullptr;
        this->edgeCount = gm.edgeCount;
        this->vertexCount = gm.vertexCount;
        return *this;
    }

    //& Existing clean-up
    if ( this->adj )
    {
        for ( int i = 0 ; i < vertexCount ; i++ )
        {
            delete[] adj[i];
        }

        delete[] adj;
    }

    this->edgeCount = gm.edgeCount;
    this->vertexCount = gm.vertexCount;
    this->adj = new int*[vertexCount];

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        adj[i] = new int[vertexCount]();
    }

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        for ( int j = 0 ; j < vertexCount ; j++ )
        {
            this->adj[i][j] = gm.adj[i][j];
        }
    }

    return *this;
}

//$ Destructor
GraphMatrix::~GraphMatrix()
{
    if ( adj )
    {
        for ( int i = 0 ; i < vertexCount ; i++ )
        {
            delete[] adj[i];
        }

        delete[] adj;
    }
}

//$ Creates relationship and stores adjacent node info. for unweighted graph
void GraphMatrix::createGraph(int edges[][2], int edgeCount, bool isDirected)
{
    if ( !adj )
        throw AdjMatrixNotCreatedException();
    
    if ( !edges )
        throw InvalidEdgesDataException();
    
    if ( edgeCount <= 0 )
        throw InvalidEdgeCountException();

    this->edgeCount = edgeCount;

    for ( int i = 0 ; i < edgeCount ; i++ )
    {
        int u = edges[i][0];    //& Starting vertex/node b/w edge
        int v = edges[i][1];    //& Ending vertex/node b/w edge

        if ( u < 0 || u >= vertexCount || v < 0 || v >= vertexCount )
            throw InvalidVertexIndexException();

        //& Updating the internal adjacency matrix (undirected graph)
        adj[u][v] = 1;
        if ( !isDirected )
            adj[v][u] = 1;
    }
}

//$ Adds edge info to the adjacency matrix 
GraphMatrix& GraphMatrix::addEdge(int u, int v, bool isDirected)
{
    if ( !adj )
        throw AdjMatrixNotCreatedException();
    
    if ( u < 0 || u >= vertexCount || v < 0 || v >= vertexCount )
        throw InvalidVertexIndexException();

    //& Updating the internal adjacency matrix
        adj[u][v] = 1;
        if ( !isDirected )
            adj[v][u] = 1;

        edgeCount++;

    return *this;
}

//$ Removes an edge from the graph
GraphMatrix& GraphMatrix::removeEdge(int u, int v, bool isDirected)
{
    if (!adj)
        throw AdjMatrixNotCreatedException();
    
    if (u < 0 || u >= vertexCount || v < 0 || v >= vertexCount)
        throw InvalidVertexIndexException();

    // Removing the edge
    adj[u][v] = 0;
    if (!isDirected)
        adj[v][u] = 0;

    edgeCount--;

    return *this;
}

//$ Utility method to get the total number of edges
int GraphMatrix::getEdgeCount() const
{
    return edgeCount;
}

//$ Utility method to get the total number of vertices
int GraphMatrix::getVertexCount() const
{
    return vertexCount;
}

//$ Prints the Graph Adjacency Matrix
void GraphMatrix::printAdjMatrix() const
{
    if ( !adj )
        throw AdjMatrixNotCreatedException();

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        for ( int j = 0 ; j < vertexCount ; j++ )
        {
            std::cout<<adj[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

//$ Prints Adjacent Nodes in the undirected graph
void GraphMatrix::printAdjacentNodes(int node) const
{
    if ( !adj )
        throw AdjMatrixNotCreatedException();

    if ( node < 0 || node > vertexCount )
        throw InvalidVertexIndexException();

    /* std::cout<<"Adjacent Nodes in an undirected Graph are :\n";
    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        for ( int j = 0 ; j < vertexCount ; j++ )
        {
            //& For undirected graphs, we only print pairs where i < j to avoid duplicates.
            if ( adj[i][j] && i <= j )
                std::cout<<"["<<i<<","<<j<<"]";
        }
        std::cout<<"\n";
    } */

    bool hasAdjacentNodes = false;
    std::cout<<"Adjacent Nodes of Vertex "<<node<<" in the undirected Graph are :\n";
    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        if ( adj[node][i] )
        {
            std::cout<<i<<" ";
            hasAdjacentNodes = true;
        }
        
    }
    if ( !hasAdjacentNodes )
        std::cout<<"Node "<<node<<" has no adjacent nodes/is isolated.\n";
    std::cout<<"\n";
}

//$ Checks if the node is isolated
bool GraphMatrix::isIsolatedNode(int nodeToCheck) const
{
    if ( !adj )
        throw AdjMatrixNotCreatedException();
    
    if ( nodeToCheck < 0 || nodeToCheck >= vertexCount )
        throw InvalidVertexIndexException();

    for ( int i = 0 ; i < vertexCount ; i++ )
    {
        if ( adj[nodeToCheck][i] ) //& Any non-zero value
            return false;
    }

    return true;
}

int main()
{
    try
    {
        std::cout << "Starting GraphMatrix operations testing...\n";

        //$ Test 1: Create a GraphMatrix
        std::cout << "\nTest 1: Creating a GraphMatrix...\n";
        GraphMatrix gm(5); // Creating a graph with 5 vertices
        std::cout << "GraphMatrix created successfully with 5 vertices.\n";

        //$ Test 2: Add edges to the GraphMatrix
        std::cout << "\nTest 2: Adding edges to the GraphMatrix...\n";
        //$ Initial edges
        int edges[4][2] = { {0, 1}, {1, 2}, {3, 0}, {2, 3} };

        /* //$ Convert to dynamic 2D array for `createGraph`
        int **edges = new int*[3];
        for (int i = 0; i < 3; i++)
        {
            edges[i] = new int[2];
            edges[i][0] = initialEdges[i][0];
            edges[i][1] = initialEdges[i][1];
        } */

        //$ Create graph with initial edges
        gm.createGraph(edges, 4, false);

        //$ Add more edges using `addEdge`
        gm.addEdge(1, 3, false);
        std::cout << "Edges added successfully.\n";

        //$ Print the Graph Adj. Matrix
        gm.printAdjMatrix();

        //$ Test 3: Print adjacent nodes for a vertex
        std::cout << "\nTest 3: Printing adjacent nodes...\n";
        try
        {
            gm.printAdjacentNodes(0);
            gm.printAdjacentNodes(2);
            gm.printAdjacentNodes(1);
            gm.printAdjacentNodes(4);
            gm.printAdjacentNodes(3);
        }
        catch (const InvalidVertexIndexException &e)
        {
            std::cerr << "Caught InvalidVertexIndexException: " << e.what() << "\n";
        }

        //$ Test 4: Check if a node is isolated
        std::cout << "\nTest 4: Checking if a node is isolated...\n";
        try
        {
            std::cout << "Is node 0 isolated? : " << (gm.isIsolatedNode(0) ? "Yes\n" : "No\n") << "\n";
            std::cout << "Is node 2 isolated? : " << (gm.isIsolatedNode(2) ? "Yes\n" : "No\n") << "\n";
            std::cout << "Is node 3 isolated? : " << (gm.isIsolatedNode(3) ? "Yes\n" : "No\n") << "\n";
            std::cout << "Is node 4 isolated? : " << (gm.isIsolatedNode(4) ? "Yes\n" : "No\n") << "\n";
            std::cout << "Is node 1 isolated? : " << (gm.isIsolatedNode(1) ? "Yes\n" : "No\n") << "\n";
            std::cout << "Is node 5 isolated?\n ";
            std::cout << (gm.isIsolatedNode(5) ? "Yes" : "No") << "\n"; // Invalid node
        }
        catch (const InvalidVertexIndexException &e)
        {
            std::cerr << "Caught Invalid Vertex Index Exception: " << e.what() << "\n";
        }

        //$ Test 5: Copy assignment of the GraphMatrix
        std::cout << "\nTest 5: Copy assignment...\n";
        try
        {
            GraphMatrix gmCopy(5);
            gmCopy = gm;
            std::cout << "GraphMatrix copied successfully. Copy contains:\n";
            gmCopy.printAdjMatrix();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception during copy assignment: " << e.what() << "\n";
        }

        //$ Test 6: Remove an edge
        std::cout << "\nTest 6: Removing an edge...\n";
        try
        {
            gm.removeEdge(3, 1, false);
            std::cout << "Edge between nodes 3 and 1 removed successfully.\n";
            std::cout << "Updated adjacency matrix:\n";
            gm.printAdjMatrix();
        }
        catch (const InvalidVertexIndexException &e)
        {
            std::cerr << "Caught exception: " << e.what() << "\n";
        }

        //$ Test 7: Self-assignment
        std::cout << "\nTest 7: Testing self-assignment...\n";
        try
        {
            gm = gm;
            std::cout << "Self-assignment handled successfully.\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << "Caught exception during self-assignment: " << e.what() << "\n";
        }

        //$ Test 8: Access invalid node
        std::cout << "\nTest 8: Accessing invalid node...\n";
        try
        {
            gm.printAdjacentNodes(10); // Invalid node index
        }
        catch (const InvalidVertexIndexException &e)
        {
            std::cerr << "Caught exception: " << e.what() << "\n";
        }

        //$ Test 9: Display the graph
        std::cout << "\nTest 9: Displaying the GraphMatrix...\n";
        gm.printAdjMatrix();

    }
    catch (const AdjMatrixNotCreatedException &e)
    {
        std::cerr << "Caught an Adj Matrix Not Created Exception: " << e.what() << "\n";
    }
    catch (const NegativeNodesException &e)
    {
        std::cerr << "Caught an Negative Nodes Exception: " << e.what() << "\n";
    }
    catch (const InvalidEdgeCountException &e)
    {
        std::cerr << "Caught an Invalid Edge Count Exception: " << e.what() << "\n";
    }
    catch (const InvalidVertexIndexException &e)
    {
        std::cerr << "Caught an Invalid Vertex Index Exception: " << e.what() << "\n";
    }
    catch (const InvalidEdgesDataException &e)
    {
        std::cerr << "Caught an Invalid Edges Data Exception: " << e.what() << "\n";
    }
    catch (const GraphMatrixExceptions &e)
    {
        std::cerr << "Caught an Graph Matrix Exception: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught an exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cout << "\nEnd of testing GraphMatrix operations.\n";

    std::cin.get();
    return 0;
}