#include<iostream>
#include<string>

//@ Exception classes

//$ Queue Exceptions Base Class
class QueueExceptions : public std::exception
{
    private:
        std::string message;

    public:

        QueueExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

//@ Queue Specific Exception Child Classes

class EmptyQueueException : public QueueExceptions
{
    public:
        EmptyQueueException() : QueueExceptions("Error : Queue is Empty.") {}

};

class QueueUnderflowException : public QueueExceptions
{
    public:
        QueueUnderflowException() : QueueExceptions("Error : Queue Underflow. Can't delete from an Empty Queue.") {}

};

class QueueLL;

//@ Node class
class Node
{
    private:

        int data;
        Node *next;

        friend class QueueLL;

    public :

        //$ Default Non-Param. Constructor
        Node() : data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(int data) : data(data), next(nullptr) {}

};

//@ Queue with Singly Linked List
class QueueLL
{
    private :

        Node *front, *rear;

    public :
        
        //$ Default Constructor
        QueueLL() : front(nullptr), rear(nullptr) {}

        //$ Copy Constructor
        QueueLL( const QueueLL &q);

        //$ Copy Assignment Op.
        QueueLL& operator=( const QueueLL &q);

        //$ Destructor
        ~QueueLL();

        //$ Inserts an element at the rear in the queue
        QueueLL& insertAtRear(int data);

        //$ Returns the rear element
        int getRear();

        //$ Returns the front element
        int getFront();

        //$ Deletes an element from the front in the queue
        QueueLL& deleteFromFront();

        //$ Returns the element count in the queue
        int getElementCount();

};

//$ Copy Constructor
QueueLL::QueueLL( const QueueLL &q )
{
    if (q.front == nullptr && q.rear == nullptr )
    {
        this->front = nullptr;
        this->rear = nullptr;
        return;
    }

    // Initialize the first node
    Node *traverseOtherQueue = q.front;
    this->front = new Node(traverseOtherQueue->data);

    // Traverse and copy remaining nodes
    Node *traverseThisQueue = this->front; // Current node in the new list
    traverseOtherQueue = traverseOtherQueue->next;

    while ( traverseOtherQueue != nullptr )
    {
        traverseThisQueue->next = new Node(traverseOtherQueue->data);
        traverseThisQueue = traverseThisQueue->next;
        traverseOtherQueue = traverseOtherQueue->next;
    }

    this->rear = traverseThisQueue;
}

//$ Copy Assignment Op.
QueueLL& QueueLL::operator=( const QueueLL &q )
{
    //& Self-Assignment Check
    if ( this == &q )
        return *this;

    //& Delete existing list
    while( this->front != nullptr )
    {
        Node *temp = front->next;
        front = front->next;
        delete temp;
    }
    this->rear = nullptr;

    if (q.front == nullptr && q.rear == nullptr )
    {
        this->front = nullptr;
        this->rear = nullptr;
        return *this;
    }

    //& Initialize the first node
    Node *traverseOtherQueue = q.front;
    this->front = new Node(traverseOtherQueue->data);

    //& Traverse and copy remaining nodes
    Node *traverseThisQueue = this->front; //& Current node in the new list
    traverseOtherQueue = traverseOtherQueue->next;

    while ( traverseOtherQueue != nullptr )
    {
        traverseThisQueue->next = new Node(traverseOtherQueue->data);
        traverseThisQueue = traverseThisQueue->next;
        traverseOtherQueue = traverseOtherQueue->next;
    }

    this->rear = traverseThisQueue;

    return *this;
}

//$ Destructor
QueueLL::~QueueLL()
{
    while ( front != nullptr )
    {
        deleteFromFront();
    }
}

//$ Inserts an element at the rear in the queue
QueueLL& QueueLL::insertAtRear(int data)
{
    Node *newNode = new Node(data);

    if ( rear == nullptr && front == nullptr )
    {
        front = rear = newNode;
        return *this;
    }

    rear->next = newNode;
    rear = newNode;

    return *this;
}

//$ Returns the rear element
int QueueLL::getRear()
{
    if ( rear == nullptr )
        throw EmptyQueueException();

    return rear->data;
}

//$ Returns the front element
int QueueLL::getFront()
{
    if ( front == nullptr )
        throw EmptyQueueException();

    return front->data;
}

//$ Deletes an element from the front in the queue
QueueLL& QueueLL::deleteFromFront()
{
    if ( front == nullptr && rear == nullptr )
        throw QueueUnderflowException();
    
    if ( front->next == nullptr && rear->next == nullptr )
    {
        delete front;
        front = rear = nullptr;
        return *this;
    }

    Node *temp = front;
    front = front->next;

    delete temp;

    return *this;
}

//$ Returns the element count in the queue
int QueueLL::getElementCount()
{
    if ( front == nullptr && rear == nullptr )
        return 0;

    Node *traverse = front;
    int count = 0;

    while ( traverse != nullptr )
    {
        count++;
        traverse = traverse->next;
    }

    return count;
}

int main()
{
    try
    {
        std::cout << "Starting Linked List Queue operations testing...\n";

        //$ Test 1: Create a queue
        std::cout << "\nTest 1: Creating a Linked List Queue...\n";
        QueueLL q;
        std::cout << "Queue created successfully.\n";

        //$ Test 2: Insert elements into the queue
        std::cout << "\nTest 2: Inserting elements into the queue...\n";
        q.insertAtRear(10).insertAtRear(20).insertAtRear(30).insertAtRear(40);
        std::cout << "Inserted 10, 20, 30, and 40 into the queue.\n";
        std::cout << "Front element: " << q.getFront() << "\n";
        std::cout << "Rear element: " << q.getRear() << "\n";

        //$ Test 3: Delete elements and check front and rear
        std::cout << "\nTest 3: Deleting elements from the queue...\n";
        q.deleteFromFront();
        std::cout << "Deleted one element. New front: " << q.getFront() << "\n";
        q.deleteFromFront();
        std::cout << "Deleted another element. New front: " << q.getFront() << "\n";

        //$ Test 4: Insert more elements
        std::cout << "\nTest 4: Inserting more elements into the queue...\n";
        q.insertAtRear(50).insertAtRear(60);
        std::cout << "Inserted 50 and 60.\n";
        std::cout << "Front element: " << q.getFront() << "\n";
        std::cout << "Rear element: " << q.getRear() << "\n";

        //$ Test 5: Count elements in the queue
        std::cout << "\nTest 5: Counting elements in the queue...\n";
        std::cout << "Number of elements in the queue: " << q.getElementCount() << "\n";

        //$ Test 6: Empty the queue completely
        std::cout << "\nTest 6: Emptying the queue completely...\n";
        while ( q.getElementCount() != 0 )
        {
            std::cout << "Deleting front element: " << q.getFront() << "\n";
            q.deleteFromFront();
        }
        std::cout << "Queue is now empty.\n";

        //$ Test 7: Attempt to delete from an empty queue (Underflow)
        // std::cout << "\nTest 7: Attempting to delete from an empty queue (should throw an exception)...\n";
        // q.deleteFromFront(); // Should throw an exception

        //$ Test 8: Testing copy constructor and assignment operator
        std::cout << "\nTest 8: Testing copy constructor and assignment operator...\n";
        QueueLL q2;
        q2.insertAtRear(100).insertAtRear(200).insertAtRear(300);
        std::cout << "Created a new queue q2 and inserted 100, 200, 300.\n";

        QueueLL q3(q2); // Copy constructor
        std::cout << "Copied q2 to q3 using copy constructor.\n";
        std::cout << "Front element of q3: " << q3.getFront() << "\n";
        std::cout << "Rear element of q3: " << q3.getRear() << "\n";

        QueueLL q4;
        q4 = q2; // Copy assignment operator
        std::cout << "Assigned q2 to q4 using copy assignment operator.\n";
        std::cout << "Front element of q4: " << q4.getFront() << "\n";
        std::cout << "Rear element of q4: " << q4.getRear() << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Caught runtime exception: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cout << "\nEnd of testing Linked List Queue operations.\n";

    std::cin.get();
    return 0;
}