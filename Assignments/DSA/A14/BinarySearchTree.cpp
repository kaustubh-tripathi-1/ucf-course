#include<iostream>
#include<string>
#include<stack>

//@ Exception classes

//$ Binary Search Tree Exceptions Base Class
class BinarySearchTreeExceptions : public std::exception
{
    private:
        std::string message;

    public:

        BinarySearchTreeExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

class EmptyBSTException : public BinarySearchTreeExceptions
{
    public :

        EmptyBSTException() : BinarySearchTreeExceptions("Error : The Binary Search Tree is empty!.") {}
};

class DuplicateValueException : public BinarySearchTreeExceptions
{
    public :

        DuplicateValueException() : BinarySearchTreeExceptions("Error : Duplicate values are not allowed in a Binary Search Tree.") {}
};

class BSTUnderflowException : public BinarySearchTreeExceptions
{
    public :

        BSTUnderflowException() : BinarySearchTreeExceptions("Error : Can't delete from an empty Binary Search Tree.") {}
};

class DataNotFoundException : public BinarySearchTreeExceptions
{
    public :

        DataNotFoundException() : BinarySearchTreeExceptions("Error : The data that you want to delete/search was not found in the Binary Search Tree.") {}
};

class BinarySearchTree;

//@ Node class
class Node
{
    private:

        int data;
        Node *left, *right;

        friend class BinarySearchTree;

    public :

        //$ Default Param. Constructor
        Node(int data) : data(data), left(nullptr), right(nullptr) {}

};

//@ Binary Search Tree Data Structure
class BinarySearchTree
{
    private :

        Node *root;

        //$ Helper method to delete a node recursively
        Node* deleteNode(Node *traverse, int dataToDelete);

        //$ Delete/Free the whole BST
        Node* deleteBST(Node *traverse);

        //$ Copy all nodes of a BST
        Node* copyBST(const Node* sourceBST);

    public:

        //$ Default Constructor
        BinarySearchTree() : root(nullptr) {}
        
        //$ Copy Constructor
        BinarySearchTree(const BinarySearchTree &bst);

        //$ Copy Assignment Operator
        BinarySearchTree& operator=(const BinarySearchTree &bst);

        //$ Destructor
        ~BinarySearchTree();

        //$ Check if the BST is empty
        bool isBSTEmpty() const;

        //$ Inserts data in BST
        BinarySearchTree& insertData(int data);

        //$ Pre-Order traversing of BST
        void preOrderTraverse() const;

        //$ Pre-Order traversing of BST Recursive Method
        void preOrderTraverseRecursion(Node *traverse) const;

        //$ In-Order traversing of BST
        void inOrderTraverse() const;

        //$ In-Order traversing of BST Recursive Method
        void inOrderTraverseRecursion(Node *traverse) const;

        //$ Post-Order traversing of BST
        void postOrderTraverse() const;

        //$ Post-Order traversing of BST Recursive Method
        void postOrderTraverseRecursion(Node *traverse) const;

        //$ Deletes data from BST
        BinarySearchTree& deleteData(int dataToDelete);

        //$ Searches for data in the BST and returns the node address
        Node* searchData(int dataToSearch) const;

        //$ Explicitly clear the BST
        void clear();

};

//$ Helper method to delete a node recursively
Node* BinarySearchTree::deleteNode(Node *traverse, int dataToDelete)
{
    if ( !traverse )
        throw DataNotFoundException();
    
    if ( dataToDelete < traverse->data )
    {
        traverse->left = deleteNode(traverse->left, dataToDelete);  //& Move to Left Subtree
    }
    else if ( dataToDelete > traverse->data )
    {
        traverse->right = deleteNode(traverse->right, dataToDelete);    //& Move to Right Subtree
    }
    else    //& Found the node to delete
    {
        if ( !traverse->left && !traverse->right )
        {
            //% Case 1: Leaf node
            delete traverse;
            return nullptr;
        }
        else if ( !traverse->left )
        {
            //% Case 2: Node has only right child
            Node *rightNode = traverse->right;
            delete traverse;
            return rightNode;   //% Return the right child to link with the parent
        }
        else if ( !traverse->right )
        {
            //% Case 4: Node has only left child
            Node *leftNode = traverse->left;
            delete traverse;
            return leftNode;    //% Return the left child to link with the parent
        }
        else
        {
            //% Case 4: Node has two children
            //% Find the in-order successor (smallest in the right subtree)
            Node *successor = traverse->right;

            while ( successor && successor->left )
            {
                successor = successor->left;  //% Move to the leftmost node in the right subtree
            }

            //% Replace the value of the node to be deleted with the successor's value
            traverse->data = successor->data;

            //% Delete the successor node recursively
            traverse->right = deleteNode(traverse->right, successor->data);

        }

    }
    
    return traverse;    //& Return the modified root
}

//$ Delete/Free the whole BST
Node* BinarySearchTree::deleteBST(Node *traverse)
{
    if (!traverse)
    {
        return nullptr;
    }
    
    traverse->left = deleteBST(traverse->left);
    traverse->right = deleteBST(traverse->right);

    delete traverse;

    return nullptr;
}

//$ Copy all nodes of a BST
Node* BinarySearchTree::copyBST(const Node* sourceBST)
{
    if ( !sourceBST )
        return nullptr;
    
    Node *newNode = new Node(sourceBST->data);

    newNode->left = copyBST(sourceBST->left);
    
    newNode->right = copyBST(sourceBST->right);

    return newNode;
}

//$ Copy Constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &bst)
: root(nullptr)
{
    this->root = copyBST(bst.root);
}

//$ Copy Assignment Operator
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &bst)
{
    //& Self-Assignment Check
    if ( this == &bst )
        return *this;

    //& Clean-up existing tree
    this->root = deleteBST(this->root);

    this->root = copyBST(bst.root);

    return *this;
}

//$ Destructor
BinarySearchTree::~BinarySearchTree()
{
    root = deleteBST(root);
}

//$ Check if the BST is empty
bool BinarySearchTree::isBSTEmpty() const
{
    return root == nullptr;
}

//$ Inserts data in BST
BinarySearchTree& BinarySearchTree::insertData(int data)
{
    //& Inserting into an empty tree
    if ( isBSTEmpty() )
    {
        root = new Node(data);
        return *this;
    }

    Node *traverse = root;
    Node *parent = nullptr;

    while ( traverse ) 
    {
        parent = traverse;
        
        if ( data == traverse->data )   //& Will not insert the same data that is already in the BST
        {
            throw DuplicateValueException(); //% Can throw exception
            // return *this;   //% Can simply return w/o inserting
        }
        else if ( data < traverse->data )
        {
            traverse = traverse->left;
        }
        else
        {
            traverse = traverse->right;
        }
    }

    if ( data < parent->data )
        parent->left = new Node(data);
    else
        parent->right = new Node(data);

    return *this;
}

//$ Pre-Order traversing of BST
void BinarySearchTree::preOrderTraverse() const
{
    //& Recursive approach
    // preOrderTraverseRecursion(root);

    //& Iterative approach with Stack

    if ( !root )
        return;

    std::stack<Node *> stack;
    stack.push(root);

    while (!stack.empty())
    {
        Node *current = stack.top();
        stack.pop();

        std::cout<<current->data<<" ";

        if ( current->right )
        {
            stack.push(current->right);
        }
        if ( current->left )
        {
            stack.push(current->left);
        }
    }
}

//$ Pre-Order traversing of BST Recursive Method
void BinarySearchTree::preOrderTraverseRecursion(Node *traverse) const
{
    /**
     * & Can Throw exception for strict exception handling  
        if ( isBSTEmpty() )
            throw EmptyBSTException(); 
    */

    /**
     * & Logic 1, but this has additional checks for every node which increases the time
     *  std::cout<<traverse->data<<" ";

    if ( !traverse->left && !traverse->right )
        return;

    preOrderTraverse(traverse->left);

    preOrderTraverse(traverse->right); */

    //& Logic 2
    if ( !traverse )
        return;

    std::cout<<traverse->data<<" ";

    preOrderTraverseRecursion(traverse->left);

    preOrderTraverseRecursion(traverse->right);
}

//$ In-Order traversing of BST
void BinarySearchTree::inOrderTraverse() const
{
    //& Recursive approach
    // inOrderTraverseRecursion(root);


    //& Iterative approach with Stack

    if ( !root )
        return;

    std::stack<Node *> stack;
    Node *traverse = root;

    while ( traverse || !stack.empty())
    {
        while ( traverse )
        {
            stack.push(traverse);
            traverse = traverse->left;
        }

        traverse = stack.top();
        stack.pop();

        std::cout<<traverse->data<<" ";
        traverse = traverse->right;
    }
}

//$ In-Order traversing of BST Recursive Method
void BinarySearchTree::inOrderTraverseRecursion(Node *traverse) const
{
    /**
     * & Can Throw exception for strict exception handling  
        if ( isBSTEmpty() )
            throw EmptyBSTException(); 
    */

    if ( !traverse )
        return;

    inOrderTraverseRecursion(traverse->left);

    std::cout<<traverse->data<<" ";

    inOrderTraverseRecursion(traverse->right);
}

//$ Post-Order traversing of BST
void BinarySearchTree::postOrderTraverse() const
{
    //& Recursive approach
    // postOrderTraverseRecursion(root);


    //& Iterative approach with Stack

    if ( !root )
        return;

    std::stack <Node*> stack1, stack2;
    stack1.push(root);

     // Process nodes in reverse post-order using two stacks
    while (!stack1.empty())
    {
        Node *current = stack1.top();
        stack1.pop();

        stack2.push(current);

        if (current->left) 
        {
            stack1.push(current->left);
        }
        if (current->right) 
        {
            stack1.push(current->right);
        }
    }

    // Pop all nodes from the second stack (this gives post-order traversal)
    while (!stack2.empty())
    {
        std::cout << stack2.top()->data << " ";
        stack2.pop();
    }

}

//$ Post-Order traversing of BST Recursive Method
void BinarySearchTree::postOrderTraverseRecursion(Node *traverse) const
{
    /**
     * & Can Throw exception for strict exception handling  
        if ( isBSTEmpty() )
            throw EmptyBSTException(); 
    */

    if ( !traverse  )
        return;

    postOrderTraverseRecursion(traverse->left);

    postOrderTraverseRecursion(traverse->right);

    std::cout<<traverse->data<<" ";
}

//$ Deletes data from BST
BinarySearchTree& BinarySearchTree::deleteData(int dataToDelete)
{
    if ( isBSTEmpty() )
        throw BSTUnderflowException();

    root = deleteNode(root, dataToDelete);

    return *this;

}

//$ Searches for data in the BST and returns the node address
Node* BinarySearchTree::searchData(int dataToSearch) const
{

    if ( !root )
        throw EmptyBSTException();

    Node *traverse = root;

    while ( traverse )
    {
        if ( dataToSearch == traverse->data )
        {
            return traverse;
        }
        else if ( dataToSearch < traverse->data )
        {
            traverse = traverse->left;
        }
        else
        {
            traverse = traverse->right;
        }
    }

    return nullptr;
}

//$ Explicitly clear the BST
void BinarySearchTree::clear()
{
    root = deleteBST(root);
}

int main()
{
    try
    {
        std::cout << "Starting Binary Search Tree operations testing...\n";

        //$ Test 1: Create a Binary Search Tree
        std::cout << "\nTest 1: Creating a Binary Search Tree...\n";
        BinarySearchTree bst;
        std::cout << "Binary Search Tree created successfully.\n";

        //$ Test 2: Insert elements into the Binary Search Tree
        std::cout << "\nTest 2: Inserting elements into the Binary Search Tree...\n";
        bst.insertData(60)
           .insertData(20)
           .insertData(71)
           .insertData(11)
           .insertData(33)
           .insertData(65)
           .insertData(82)
           .insertData(7)
           .insertData(15)
           .insertData(26)
           .insertData(47)
           .insertData(64)
           .insertData(68)
           .insertData(76)
           .insertData(2)
           .insertData(17)
           .insertData(18)
           .insertData(50)
           .insertData(51)
           .insertData(83)
           .insertData(85)
           .insertData(101)
           .insertData(90);
        std::cout << "Inserted elements successfully.\n";

        //$ Test 3: Perform Pre-order Traversal
        std::cout << "\nTest 3: Performing Pre-order Traversal...\n";
        std::cout << "Pre-order Traversal: ";
        bst.preOrderTraverse();
        std::cout << "\n";

        //$ Test 4: Perform In-order Traversal
        std::cout << "\nTest 4: Performing In-order Traversal...\n";
        std::cout << "In-order Traversal: ";
        bst.inOrderTraverse();
        std::cout << "\n";

        //$ Test 5: Perform Post-order Traversal
        std::cout << "\nTest 5: Performing Post-order Traversal...\n";
        std::cout << "Post-order Traversal: ";
        bst.postOrderTraverse();
        std::cout << "\n";

        //$ Test 6: Find an element in the tree
        std::cout << "\nTest 6: Searching for elements in the Binary Search Tree...\n";
        int searchKey = 50;
        std::cout << "Searching for " << searchKey << ": " 
                  << (bst.searchData(searchKey) ? "Found" : "Not Found") << "\n";

        searchKey = 1000;
        std::cout << "Searching for " << searchKey << ": " 
                  << (bst.searchData(searchKey) ? "Found" : "Not Found") << "\n";

        //$ Test 7: Remove an element from the tree
        std::cout << "\nTest 7: Removing elements from the Binary Search Tree...\n";
        int removeKey = 20;
        std::cout << "Removing " << removeKey << "...\n";
        bst.deleteData(removeKey);
        std::cout << "In-order Traversal after removal: ";
        bst.inOrderTraverse();
        std::cout << "\n";

        //$ Test 8: Check if the tree is empty
        std::cout << "\nTest 8: Checking if the Binary Search Tree is empty...\n";
        std::cout << (bst.isBSTEmpty() ? "The tree is empty.\n" : "The tree is not empty.\n");

        //$ Test 9: Attempt to insert a duplicate value
        std::cout << "\nTest 9: Attempting to insert a duplicate value...\n";
        try
        {
            bst.insertData(60); // Duplicate
        }
        catch (const DuplicateValueException &e)
        {
            std::cerr << "Expected exception for duplicate: " << e.what() << "\n";
        }

        //$ Test 10: Attempt to remove a non-existent value
        std::cout << "\nTest 10: Attempting to remove a non-existent value...\n";
        try
        {
            bst.deleteData(999); // Not in tree
        }
        catch (const DataNotFoundException &e)
        {
            std::cerr << "Expected exception for non-existent data: " << e.what() << "\n";
        }

        //$ Test 11: Removing the root node
        std::cout << "\nTest 11: Removing the root node...\n";
        bst.deleteData(60); // Root node
        std::cout << "Pre-order Traversal after root deletion: ";
        bst.preOrderTraverse();
        std::cout << "\n";

        //$ Test 12: Clear the Binary Search Tree
        std::cout << "\nTest 12: Clearing the Binary Search Tree...\n";
        bst.clear();
        std::cout << "Binary Search Tree cleared.\n";
        std::cout << (bst.isBSTEmpty() ? "The tree is now empty.\n" : "The tree is not empty.\n");

        //$ Test 13: Traversals on an empty tree
        std::cout << "\nTest 13: Traversals on an empty tree...\n";
        bst.clear();
        std::cout << "Pre-order Traversal: ";
        bst.preOrderTraverse();
        std::cout << "\n";

    }
    catch (const EmptyBSTException &e)
    {
        std::cerr << "Caught Empty BST Exception: " << e.what() << "\n";
    }
    catch (const DuplicateValueException &e)
    {
        std::cerr << "Caught Duplicate Value Exception: " << e.what() << "\n";
    }
    catch (const DataNotFoundException &e)
    {
        std::cerr << "Caught Data NotFound Exception: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught an exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cout << "\nEnd of testing Binary Search Tree operations.\n";

    std::cin.get();
    return 0;
}