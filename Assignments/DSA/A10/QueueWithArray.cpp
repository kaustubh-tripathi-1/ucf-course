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

class NegativeSizeException : public QueueExceptions
{
    public :

        NegativeSizeException() : QueueExceptions("Error : Queue Size should be greater than 0!") {}
};

class QueueOverflowException : public QueueExceptions
{
    public:
        QueueOverflowException() : QueueExceptions("Error : Queue Overflow.") {}

};

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

class QueueNotCreatedException : public QueueExceptions
{
    public:
        QueueNotCreatedException(const std::string &operation) : QueueExceptions("Error : Queue wasn't created properly. Can't perform " + operation + ".") {}

};

class AssignerQueueNotCreatedException : public QueueExceptions
{
    public:
        AssignerQueueNotCreatedException() : QueueExceptions("Error : The assigner Queue is not created.") {}

};

//@ Queue class
class Queue
{
    private :

        size_t capacity, front, rear;
        int *queuePtr;

    public :

        //$ Default Param. Constructor
        Queue(size_t capacity)
            : front(SIZE_MAX), rear(SIZE_MAX), queuePtr(nullptr)
        {
            if ( (int)capacity <= 0 )
                throw NegativeSizeException();

            this->capacity = capacity;
            this->queuePtr = new int[capacity];
        }

        //$ Copy constructor
        Queue(const Queue &q);

        //$ Copy Assignment Op.
        Queue& operator=(const Queue &q);

        //$ Destructor
        ~Queue();

        //# Efficient as no shifting is involved, we treat the Queue as circular, Time Comp. is O(1)
        //$ Inserts an element at the rear in queue
        Queue& enqueue(int data);

        //$ Returns the rear element in queue
        int getRear() const;

        //$ Returns the front element in queue
        int getFront() const;

        //$ Delete the front element from the queue
        Queue& dequeue();

        //$ Checks queue Overflow
        bool isQueueOverflow() const;

        //$ Checks queue Underflow
        bool isQueueUnderflow() const;

        //$ Returns the element count in Queue
        int countElementsInQueue();
};

//$ Copy constructor
Queue::Queue(const Queue &q)
    :  capacity(q.capacity), front(q.front), rear(q.rear), queuePtr(nullptr)
{
    if ( q.queuePtr == nullptr )
    {
        return;
    }

    this->queuePtr = new int[capacity];

    if ( front <= rear )    //& Elements are in a linear range
    {
        for ( int i = front ; i <= rear ; i++ )
        {
            this->queuePtr[i] = q.queuePtr[i];
        }
    }
    else    //& Elements are wrapped around
    {
        for ( int i = front ; i < capacity ; i++ )  //& Copy first part
        {
            this->queuePtr[i] = q.queuePtr[i];
        }

        for ( int i = 0 ; i <= rear ; i++ )     //& Copy second part
        {
            this->queuePtr[i] = q.queuePtr[i];
        }
    }
    
}

//$ Copy Assignment Op.
Queue& Queue::operator=(const Queue &q)
{
    if ( this == &q )
        return *this;

    if ( q.queuePtr == nullptr )
    {
        throw AssignerQueueNotCreatedException();
    }

    if ( this->queuePtr != nullptr )
    {
        delete []queuePtr;
    }

    this->capacity = q.capacity;
    this->front = q.front;
    this->rear = q.rear;
    
    this->queuePtr = new int[capacity];

    if ( front <= rear )    //& Elements are in a linear range
    {
        for ( int i = front ; i <= rear ; i++ )
        {
            this->queuePtr[i] = q.queuePtr[i];
        }
    }
    else    //& Elements are wrapped around
    {
        for ( int i = front ; i < capacity ; i++ )  //& Copy first part
        {
            this->queuePtr[i] = q.queuePtr[i];
        }

        for ( int i = 0 ; i <= rear ; i++ )     //& Copy second part
        {
            this->queuePtr[i] = q.queuePtr[i];
        }
    }

    return *this;
}

//$ Destructor
Queue::~Queue()
{
    if ( queuePtr != nullptr )
        delete []queuePtr;
}

//$ Inserts an element at the rear in queue
Queue& Queue::enqueue(int data)
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("insertion at rear");
    
    if ( isQueueOverflow() )
        throw QueueOverflowException();

    //& Complex multiple if-else checks
    /* if ( rear == SIZE_MAX ) //& Empty Queue
    {
        rear++;
        front++;
    }
    else if ( rear+1 == capacity )  //& Only 1st Index is empty
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queuePtr[rear] = data;
    */

    //& Simple Modulo operation
    if ( rear == SIZE_MAX ) //& Empty Queue
    {
        front = rear = 0;
    }
    else 
    {
        rear = (rear + 1) % capacity;
    }

    queuePtr[rear] = data;

    return *this;
}

//$ Returns the rear element in queue
int Queue::getRear() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("view rear element");

    if ( rear == SIZE_MAX )
        throw EmptyQueueException();

    return queuePtr[rear];
}

//$ Returns the front element in queue
int Queue::getFront() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("view front element");

    if ( rear == SIZE_MAX )
        throw EmptyQueueException();

    return queuePtr[front];
}

//$ Delete the front element from the queue
Queue& Queue::dequeue()
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("deletion at front");

    if ( isQueueUnderflow() )
        throw QueueUnderflowException();

    //& Complex multiple if-else checks
    /* if ( front == rear )   //& Only 1 element
    {
        front = rear = SIZE_MAX;
    }
    else if ( front+1 == capacity )
    {
        front = 0;
    }
    else
    {
        front++;
    } */

    //& Simple Modulo operation
    if ( front == rear )    //& Only 1 element
    {
        front = rear = SIZE_MAX;
    }
    else
    {
        front = (front + 1) % capacity ;
    }


    return *this;
}

//$ Checks queue Overflow
bool Queue::isQueueOverflow() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("the check for Queue overflow");

    return rear+1 == front || (rear+1 == capacity && front == 0);
}

//$ Checks queue Underflow
bool Queue::isQueueUnderflow() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("the check for Queue underflow");

    return rear == SIZE_MAX;
}

//$ Returns the element count in Queue
int Queue::countElementsInQueue()
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("counting of elements in the queue");
    
    if ( isQueueUnderflow() )
        return 0;
    
    if ( front <= rear )
    {
        return rear - front + 1;
    }
    else
    {
        return capacity - ( front - rear ) + 1;
    }
}

int main()
{
    try
    {
        std::cout << "Starting Circular Queue operations testing...\n";

        //$ Test 1: Create a queue with positive capacity
        std::cout << "\nTest 1: Creating a queue with capacity 5...\n";
        Queue q(5);
        std::cout << "Queue created successfully.\n";

        //$ Test 2: Insert elements into the queue
        std::cout << "\nTest 2: Inserting elements into the queue...\n";
        q.enqueue(10).enqueue(20).enqueue(30).enqueue(40);
        std::cout << "Inserted 10, 20, 30, and 40 into the queue.\n";
        std::cout << "Front element: " << q.getFront() << "\n";
        std::cout << "Rear element: " << q.getRear() << "\n";

        //$ Test 3: Test circular behavior by inserting at wrap-around
        std::cout << "\nTest 3: Testing circular behavior...\n";
        q.enqueue(50); // Queue is now full
        std::cout << "Inserted 50 at the rear. Queue is now full.\n";
        std::cout << "Front element: " << q.getFront() << "\n";
        std::cout << "Rear element: " << q.getRear() << "\n";

        //$ Test 4: Attempt to insert into a full queue (Overflow)
        // std::cout << "\nTest 4: Attempting to insert into a full queue (should throw an exception)...\n";
        // q.enqueue(60);

        //$ Test 5: Delete elements and observe circular movement
        std::cout << "\nTest 5: Deleting elements to test circular behavior...\n";
        q.dequeue();
        std::cout << "Deleted one element. New front: " << q.getFront() << "\n";

        q.enqueue(60);
        std::cout << "Inserted 60 at rear after deletion.\n";
        std::cout << "Front element: " << q.getFront() << "\n";
        std::cout << "Rear element: " << q.getRear() << "\n";

        //$ Test 6: Count elements in the queue
        std::cout << "\nTest 6: Counting elements in the queue...\n";
        std::cout << "Number of elements in the queue: " << q.countElementsInQueue() << "\n";

        //$ Test 7: Empty the queue completely
        std::cout << "\nTest 7: Emptying the queue completely...\n";
        while (!q.isQueueUnderflow())
        {
            std::cout << "Deleting front element: " << q.getFront() << "\n";
            q.dequeue();
        }
        std::cout << "Queue is now empty.\n";

        //$ Test 8: Attempt to delete from an empty queue (Underflow)
        // std::cout << "\nTest 8: Attempting to delete from an empty queue (should throw an exception)...\n";
        // q.dequeue();

        //$ Test 9: Copy constructor and assignment operator
        std::cout << "\nTest 9: Testing copy constructor and assignment operator...\n";
        Queue q2(3);
        q2.enqueue(100).enqueue(200).enqueue(300);
        std::cout << "Created a new queue q2 and inserted 100, 200, 300.\n";

        Queue q3(q2); // Copy constructor
        std::cout << "Copied q2 to q3 using copy constructor.\n";
        std::cout << "Front element of q3: " << q3.getFront() << "\n";
        std::cout << "Rear element of q3: " << q3.getRear() << "\n";

        Queue q4(2);
        q4 = q2; // Copy assignment
        std::cout << "Assigned q2 to q4 using copy assignment operator.\n";
        std::cout << "Front element of q4: " << q4.getFront() << "\n";
        std::cout << "Rear element of q4: " << q4.getRear() << "\n";

        //$ Test 10: Attempt to create a queue with negative size
        // std::cout << "\nTest 10: Attempting to create a queue with negative size (should throw an exception)...\n";
        // Queue invalidQueue(-5);
    }
    catch (const NegativeSizeException &e)
    {
        std::cerr << "Caught NegativeSizeException: " << e.what() << "\n";
    }
    catch (const QueueOverflowException &e)
    {
        std::cerr << "Caught QueueOverflowException: " << e.what() << "\n";
    }
    catch (const QueueUnderflowException &e)
    {
        std::cerr << "Caught QueueUnderflowException: " << e.what() << "\n";
    }
    catch (const EmptyQueueException &e)
    {
        std::cerr << "Caught EmptyQueueException: " << e.what() << "\n";
    }
    catch (const QueueNotCreatedException &e)
    {
        std::cerr << "Caught QueueNotCreatedException: " << e.what() << "\n";
    }
    catch (const AssignerQueueNotCreatedException &e)
    {
        std::cerr << "Caught AssignerQueueNotCreatedException: " << e.what() << "\n";
    }
    catch (const QueueExceptions &e)
    {
        std::cerr << "Caught QueueExceptions: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught std::exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cout << "\nEnd of testing Circular Queue operations.\n";
    
    std::cin.get();
    return 0;
}