#include<iostream>
#include<string>

//@ Exception classes

//$ Priority Queue Exceptions Base Class
class PriorityQueueExceptions : public std::exception
{
    private:
        std::string message;

    public:

        PriorityQueueExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

//@ Priority Queue Specific Exception Child Classes

class EmptyQueueException : public PriorityQueueExceptions
{
    public:
        EmptyQueueException() : PriorityQueueExceptions("Error : Queue is Empty.") {}

};

class QueueUnderflowException : public PriorityQueueExceptions
{
    public:
        QueueUnderflowException() : PriorityQueueExceptions("Error : Queue Underflow. Can't delete from an Empty Queue.") {}

};

class PriorityQueue;

//@ Node class
class Node
{
    private:

        int data, priorityNo;
        Node *next;

        friend class PriorityQueue;

    public :

        //$ Default Param. Constructor
        Node(int data, int priorityNo) : data(data), priorityNo(priorityNo), next(nullptr) {}

};

//@ Priority Queue with Singly Linked List
class PriorityQueue
{
    private :

        Node *start;

    public :

        //$ Default Constructor
        PriorityQueue() : start(nullptr) {}

        //$ Copy Constructor
        PriorityQueue(const PriorityQueue &pq);

        //$ Copy Assignment Op.
        PriorityQueue& operator=(const PriorityQueue &pq);

        //$ Destructor
        ~PriorityQueue();

        //$ Inserts the element according to Priority
        PriorityQueue& enqueue(int data, int priorityNo);

        //$ Deletes the highest Priority
        PriorityQueue& dequeue();

        //$ Returns the highest priority element
        int getHighestPriorityElement() const;

        //$ Returns the highest priority number
        int getHighestPriorityNumber() const;

        //$ Checks if the queue is empty
        bool isEmpty() const;

};

//$ Copy Constructor
PriorityQueue::PriorityQueue(const PriorityQueue &pq) : start(nullptr)
{
    if ( pq.isEmpty() )
    {
        this->start = nullptr;
        return;
    }

    Node *sourcePQ = pq.start;
    Node *thisPQ = nullptr;

    //& For 1st Node
    this->start = new Node(sourcePQ->data, sourcePQ->priorityNo);
    thisPQ = this->start;
    sourcePQ = sourcePQ->next;

    while ( sourcePQ != nullptr )
    {
        thisPQ->next = new Node(sourcePQ->data, sourcePQ->priorityNo);
        thisPQ = thisPQ->next;
        sourcePQ = sourcePQ->next;
    }
}

//$ Copy Assignment Op.
PriorityQueue& PriorityQueue::operator=(const PriorityQueue &pq)
{
    //& Self-Assignment Check
    if ( this == &pq )
        return *this;

    //& Clean-up existing queue
    while ( start != nullptr )
    {
        Node *temp = start;

        start = start->next;

        delete temp;
    }

    if ( pq.isEmpty() )
    {
        this->start = nullptr;
        return *this;
    }

    Node *sourcePQ = pq.start;
    Node *thisPQ = nullptr;

    //& For 1st Node
    this->start = new Node(sourcePQ->data, sourcePQ->priorityNo);
    thisPQ = this->start;
    sourcePQ = sourcePQ->next;

    while ( sourcePQ != nullptr )
    {
        thisPQ->next = new Node(sourcePQ->data, sourcePQ->priorityNo);
        thisPQ = thisPQ->next;
        sourcePQ = sourcePQ->next;
    }

    return *this;
}

//$ Destructor
PriorityQueue::~PriorityQueue()
{
    while ( start != nullptr )
    {
        Node *temp = start;

        start = start->next;

        delete temp;
    }
}

//$ Inserts the element according to Priority
PriorityQueue& PriorityQueue::enqueue(int data, int priorityNo)
{
    Node *newNode = new Node(data, priorityNo);
    
    //& Insert at the start if the queue is empty or newNode has the highest priority
    if ( isEmpty() || priorityNo > start->priorityNo )
    {
        newNode->next = start;
        start = newNode;
        return *this;
    }

    Node *traverse = start;

    //& Traverse to find the correct position to insert
    while ( traverse->next != nullptr && priorityNo <= traverse->next->priorityNo)
    {
        traverse = traverse->next;
    }

    //& Insert the new node at the correct position
    newNode->next = traverse->next;
    traverse->next = newNode;
   

    return *this;
}

//$ Deletes the highest Priority
PriorityQueue& PriorityQueue::dequeue()
{
    if ( isEmpty() )
        throw QueueUnderflowException();

    Node *temp = start;

    start = start->next;
    delete temp;

    return *this;
}

//$ Returns the highest priority element
int PriorityQueue::getHighestPriorityElement() const
{
    if ( isEmpty() )
        throw EmptyQueueException();

    return start->data;
}

//$ Returns the highest priority number
int PriorityQueue::getHighestPriorityNumber() const
{
    if ( isEmpty() )
        throw EmptyQueueException();

    return start->priorityNo;
}

//$ Checks if the queue is empty
bool PriorityQueue::isEmpty() const
{
    return start == nullptr;
}

int main()
{
    try
    {
        std::cout << "Starting Priority Queue operations testing...\n";

        //$ Test 1: Create a Priority Queue
        std::cout << "\nTest 1: Creating a Priority Queue...\n";
        PriorityQueue pq;
        std::cout << "Priority Queue created successfully.\n";

        //$ Test 2: Insert elements with different priorities
        std::cout << "\nTest 2: Enqueue elements into the Priority Queue...\n";
        pq.enqueue(10, 2)
            .enqueue(20, 1)
            .enqueue(30, 3)
            .enqueue(40, 2)
            .enqueue(50, 5)
            .enqueue(600, 7)
            .enqueue(341, 0)
            .enqueue(-213, 3)
            .enqueue(89, -3)
            .enqueue(9321, 4);
        std::cout << "Inserted 10 (P2), 20 (P1), 30 (P3), 40 (P2), 50 (P5), 600 (P7), 341 (P0), -213 (P3), 89 (P-3), 9321 (P4).\n";
        std::cout << "Highest priority element: " << pq.getHighestPriorityElement() << " (Priority: " << pq.getHighestPriorityNumber() << ")\n";

        //$ Test 3: Dequeue elements based on priority
        std::cout << "\nTest 3: Dequeue elements from the Priority Queue...\n";
        pq.dequeue();
        std::cout << "Dequeued highest priority element. New highest: " << pq.getHighestPriorityElement() << " (Priority: " << pq.getHighestPriorityNumber() << ")\n";

        pq.dequeue();
        std::cout << "Dequeued highest priority element. New highest: " << pq.getHighestPriorityElement() << " (Priority: " << pq.getHighestPriorityNumber() << ")\n";

        //$ Test 4: Insert more elements and check priority order
        std::cout << "\nTest 4: Enqueue more elements into the Priority Queue...\n";
        pq.enqueue(60, 4).enqueue(70, 3).enqueue(4832, -9);
        std::cout << "Inserted 60 (P4), 70 (P3), 4832 (P-9).\n";
        std::cout << "Highest priority element: " << pq.getHighestPriorityElement() << " (Priority: " << pq.getHighestPriorityNumber() << ")\n";

        //$ Test 5: Check if the queue is empty
        std::cout << "\nTest 5: Checking if the Priority Queue is empty...\n";
        std::cout << (pq.isEmpty() ? "Priority Queue is empty.\n" : "Priority Queue is not empty.\n");

        //$ Test 6: Empty the Priority Queue completely
        std::cout << "\nTest 6: Emptying the Priority Queue completely...\n";
        while (!pq.isEmpty())
        {
            std::cout << "Deleting element: " << pq.getHighestPriorityElement() << " (Priority: " << pq.getHighestPriorityNumber() << ")\n";
            pq.dequeue();
        }
        std::cout << "Priority Queue is now empty.\n";

        //$ Test 7: Attempt to dequeue from an empty Priority Queue (Underflow)
        std::cout << "\nTest 7: Attempting to dequeue from an empty Priority Queue (should throw an exception)...\n";
        try
        {
            pq.dequeue(); // Should throw an exception
        }
        catch (const QueueUnderflowException &e)
        {
            std::cerr << e.what() << "\n";
        }

        //$ Test 8: Testing copy constructor and assignment operator
        std::cout << "\nTest 8: Testing copy constructor and assignment operator...\n";
        PriorityQueue pq2;
        pq2.enqueue(100, 1)
            .enqueue(200, 2)
            .enqueue(300, 3)
            .enqueue(239, 1)
            .enqueue(-321, 2);
        std::cout << "Created a new Priority Queue pq2 and inserted 100 (P1), 200 (P2), 300 (P3), 239 (P1), -321 (P2).\n";

        PriorityQueue pq3(pq2); // Copy constructor
        std::cout << "Copied pq2 to pq3 using copy constructor.\n";
        std::cout << "Highest priority in pq3: " << pq3.getHighestPriorityElement() << " (Priority: " << pq3.getHighestPriorityNumber() << ")\n";

        PriorityQueue pq4;
        pq4 = pq2; // Copy assignment operator
        std::cout << "Assigned pq2 to pq4 using copy assignment operator.\n";
        std::cout << "Highest priority in pq4: " << pq4.getHighestPriorityElement() << " (Priority: " << pq4.getHighestPriorityNumber() << ")\n";
    }
    catch (const EmptyQueueException &e)
    {
        std::cerr << "Caught Empty Queue Exception: " << e.what() << "\n";
    }
    catch (const QueueUnderflowException &e)
    {
        std::cerr << "Caught Queue Underflow Exception: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cout << "\nEnd of testing Priority Queue operations.\n";

    std::cin.get();
    return 0;
}