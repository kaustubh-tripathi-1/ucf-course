#include<iostream>
#include<string>

//@ Exception classes

//$ Deque Exception Base Class
class DequeExceptions : public std::exception
{
    private:

        std::string message;

    public:

        DequeExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
};

//@ Deque Specific Exception Child Classes

class EmptyDequeException : public DequeExceptions
{
    public:
        EmptyDequeException() : DequeExceptions("Error : The Deque is empty. Cannot perform some operations like delete, get rear and front elements.") {}
};

class DequeUnderflowException : public DequeExceptions
{
    public:
        DequeUnderflowException() : DequeExceptions("Error : Deque Underflow. Can't delete from an Empty Deque.") {}

};

class Deque;

class Node
{
    private:

        Node *previous;
        int data;
        Node *next;

        friend class Deque;

    public:

        //$ Default Param. Constructor
        Node(int data) : previous(nullptr), data(data), next(nullptr) {}
    
};

//@ Deque using Doubly Linked List
class Deque
{
    private :
        Node *rear, *front;

    public :

        //$ Default Constructor
        Deque() : rear(nullptr), front(nullptr) {}

        //$ Copy Constructor
        Deque(const Deque &d);

        //$ Copy Assignment Op.
        Deque& operator=( const Deque &d);

        //$ Destructor
        ~Deque();

        //$ Inserts an element at the front in the queue
        Deque& enqueueFront(int data);

        //$ Inserts an element at the rear in the queue
        Deque& enqueueRear(int data);

        //$ Returns the rear element
        inline int getRear() const;

        //$ Returns the front element
        inline int getFront() const;

        //$ Deletes an element from the front in the queue
        Deque& dequeueFront();

        //$ Deletes an element from the rear in the queue
        Deque& dequeueRear();

        //$ Check for an empty Deque
        bool isEmptyDeque() const;
    
};

//$ Copy Constructor
Deque::Deque(const Deque &d)
{
    //& Source Deque Empty 
    if ( d.isEmptyDeque() )
    {
        this->front = this->rear = nullptr;
        return;
    }

    Node *sourceDeque = d.front;
    Node *thisDeque = nullptr;

    //& For 1st Node
    this->front = new Node(sourceDeque->data);
    sourceDeque = sourceDeque->next;
    thisDeque = front;

    //& Rest of the nodes
    while ( sourceDeque != nullptr )
    {
        Node *newNode = new Node(sourceDeque->data);

        thisDeque->next = newNode;
        newNode->previous = thisDeque;

        thisDeque = thisDeque->next;
        sourceDeque = sourceDeque->next;
    }

    this->rear = thisDeque; //& Update rear

}

//$ Copy Assignment Op.
Deque& Deque::operator=( const Deque &d)
{
    //& Self-Assignment Check
    if ( this == &d )
        return *this;
    
    //& Clean-up of existing Deque
    while ( this->front != nullptr )
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    this->rear = nullptr;
    
    //& Source Deque Empty 
    if ( d.isEmptyDeque() )
    {
        this->front = this->rear = nullptr;
        return *this;
    }

    Node *sourceDeque = d.front;
    Node *thisDeque = nullptr;

    //& For 1st Node
    this->front = new Node(sourceDeque->data);
    sourceDeque = sourceDeque->next;
    thisDeque = front;

    //& Rest of the nodes
    while ( sourceDeque != nullptr )
    {
        Node *newNode = new Node(sourceDeque->data);

        thisDeque->next = newNode;
        newNode->previous = thisDeque;

        thisDeque = thisDeque->next;
        sourceDeque = sourceDeque->next;
    }

    this->rear = thisDeque; //& Update rear

    return *this;
}

//$ Destructor
Deque::~Deque()
{
    while ( front != nullptr )
    {
        Node *temp = front;
        front = front->next;
        delete temp;
    }

    rear = nullptr;
}

//$ Inserts an element at the front in the queue
Deque& Deque::enqueueFront(int data)
{
    Node *newNode = new Node(data);
    
    //& Inserting in an empty queue
    if ( isEmptyDeque() )
    {
        front = rear = newNode;
        return *this;
    }

    newNode->next = front;
    front->previous = newNode;
    front = newNode;

    return *this;
}

//$ Inserts an element at the rear in the queue
Deque& Deque::enqueueRear(int data)
{
    Node *newNode = new Node(data);

    //& Inserting in an empty queue
    if ( isEmptyDeque() )
    {
        front = rear = newNode;
        return *this;
    }

    rear->next = newNode;
    newNode->previous = rear;
    rear = newNode;

    return *this;
}

//$ Returns the rear element
int Deque::getRear() const
{
    if ( isEmptyDeque() )
        throw EmptyDequeException();

    return rear->data;
}

//$ Returns the front element
int Deque::getFront() const
{
    if ( isEmptyDeque() )
        throw EmptyDequeException();

    return front->data;
}

//$ Deletes an element from the front in the queue
Deque& Deque::dequeueFront()
{
    if ( isEmptyDeque() )
        throw DequeUnderflowException();

    //& Only 1 node present
    if ( front == rear )
    {
        delete front;
        front = rear = nullptr;

        return *this;
    }

    Node *temp = front;

    front = front->next;
    front->previous = nullptr;
    delete temp;

    return *this;
}

//$ Deletes an element from the rear in the queue
Deque& Deque::dequeueRear()
{
    if ( isEmptyDeque() )
        throw DequeUnderflowException();

    //& Only 1 node present
    if ( front == rear )
    {
        delete front;
        front = rear = nullptr;

        return *this;
    }

    Node *temp = rear;

    rear->previous->next = nullptr;
    rear = rear->previous;

    delete temp;

    return *this;
}

//$ Check for an empty Deque
bool Deque::isEmptyDeque() const
{
    return front == nullptr;
}

int main()
{
    try
    {
        std::cout << "Starting Doubly Linked List Deque operations testing...\n";

        //$ Test 1: Create a deque
        std::cout << "\nTest 1: Creating a Doubly Linked List Deque...\n";
        Deque deque;
        std::cout << "Deque created successfully.\n";

        //$ Test 2: Insert elements at the front and rear
        std::cout << "\nTest 2: Inserting elements into the deque...\n";
        deque.enqueueRear(10).enqueueRear(20).enqueueFront(5).enqueueFront(1);
        std::cout << "Inserted 10, 20 at the rear, and 5, 1 at the front.\n";
        std::cout << "Front element: " << deque.getFront() << "\n";
        std::cout << "Rear element: " << deque.getRear() << "\n";

        //$ Test 3: Delete elements from the front and rear
        std::cout << "\nTest 3: Deleting elements from the deque...\n";
        deque.dequeueFront();
        std::cout << "Deleted one element from the front. New front: " << deque.getFront() << "\n";
        deque.dequeueRear();
        std::cout << "Deleted one element from the rear. New rear: " << deque.getRear() << "\n";

        //$ Test 4: Insert more elements at both ends
        std::cout << "\nTest 4: Inserting more elements into the deque...\n";
        deque.enqueueRear(50).enqueueFront(0).enqueueRear(60);
        std::cout << "Inserted 50, 60 at the rear, and 0 at the front.\n";
        std::cout << "Front element: " << deque.getFront() << "\n";
        std::cout << "Rear element: " << deque.getRear() << "\n";

        //$ Test 5: Check if the deque is empty
        std::cout << "\nTest 5: Checking if the deque is empty...\n";
        std::cout << (deque.isEmptyDeque() ? "Deque is empty.\n" : "Deque is not empty.\n");

        //$ Test 6: Empty the deque completely
        std::cout << "\nTest 6: Emptying the deque completely...\n";
        while (!deque.isEmptyDeque())
        {
            std::cout << "Deleting front element: " << deque.getFront() << "\n";
            deque.dequeueFront();
        }
        std::cout << "Deque is now empty.\n";

        //$ Test 7: Attempt to delete from an empty deque (Underflow)
        std::cout << "\nTest 7: Attempting to delete from an empty deque (should throw an exception)...\n";
        try
        {
            deque.dequeueFront(); // Should throw an exception
        }
        catch (const DequeUnderflowException &e)
        {
            std::cerr << e.what() << "\n";
        }

        //$ Test 8: Testing copy constructor and assignment operator
        std::cout << "\nTest 8: Testing copy constructor and assignment operator...\n";
        Deque deque2;
        deque2.enqueueRear(100).enqueueRear(200).enqueueRear(300);
        std::cout << "Created a new deque deque2 and inserted 100, 200, 300.\n";

        Deque deque3(deque2); // Copy constructor
        std::cout << "Copied deque2 to deque3 using copy constructor.\n";
        std::cout << "Front element of deque3: " << deque3.getFront() << "\n";
        std::cout << "Rear element of deque3: " << deque3.getRear() << "\n";

        Deque deque4;
        deque4 = deque2; // Copy assignment operator
        std::cout << "Assigned deque2 to deque4 using copy assignment operator.\n";
        std::cout << "Front element of deque4: " << deque4.getFront() << "\n";
        std::cout << "Rear element of deque4: " << deque4.getRear() << "\n";
    }
    catch (const EmptyDequeException &e)
    {
        std::cerr << "Caught Empty Deque Exception: " << e.what() << "\n";
    }
    catch (const DequeUnderflowException &e)
    {
        std::cerr << "Caught Deque Underflow Exception: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cout << "\nEnd of testing Doubly Linked List Deque operations.\n";

    std::cin.get();
    return 0;
}