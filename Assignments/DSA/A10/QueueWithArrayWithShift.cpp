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

        //@ Inefficient as shifting is involved, Time Comp. is O(n)
        //$ Inserts an element at the rear in queue
        Queue& insertAtRear(int data);

        //$ Returns the rear element in queue
        int getRear() const;

        //$ Returns the front element in queue
        int getFront() const;

        //$ Delete the front element from the queue
        Queue& deleteFront();

        //$ Checks queue Overflow
        bool isQueueOverflow() const;

        //$ Checks queue Underflow
        bool isQueueUnderflow() const;
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

    for ( int i = 0 ; i <= front ; i++ )
    {
        this->queuePtr[i] = q.queuePtr[i];
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

    for ( int i = 0 ; i <= front ; i++ )
    {
        this->queuePtr[i] = q.queuePtr[i];
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
Queue& Queue::insertAtRear(int data)
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("insertion at rear");
    
    if ( isQueueOverflow() )
        throw QueueOverflowException();

    rear = 0;

    for ( int i = front ; i >= rear && front != SIZE_MAX ; i-- )
    {
        queuePtr[i+1] = queuePtr[i];
    }

    queuePtr[rear] = data;
    front++;

    return *this;
}

//$ Returns the rear element in queue
int Queue::getRear() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("view rear element");

    if ( rear == SIZE_MAX || front == SIZE_MAX )
        throw EmptyQueueException();

    return queuePtr[rear];
}

//$ Returns the front element in queue
int Queue::getFront() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("view front element");

    if ( rear == SIZE_MAX || front == SIZE_MAX )
        throw EmptyQueueException();

    return queuePtr[front];
}

//$ Delete the front element from the queue
Queue& Queue::deleteFront()
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("view rear element");

    if ( front == SIZE_MAX )
        throw QueueUnderflowException();

    front--;

    if ( front == SIZE_MAX )
        rear = SIZE_MAX;

    return *this;
}

//$ Checks queue Overflow
bool Queue::isQueueOverflow() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("the check for Queue overflow");

    return front+1 == capacity;
}

//$ Checks queue Underflow
bool Queue::isQueueUnderflow() const
{
    if ( queuePtr == nullptr )
        throw QueueNotCreatedException("the check for Queue underflow");

    return rear == SIZE_MAX;
}

//$ Returns the element count in Queue
int countElementsInQueue(const Queue &q)
{
    if ( q.isQueueUnderflow() )
        throw EmptyQueueException();
    
    return q.getFront()+1;
}

int main()
{


    std::cin.get();
    return 0;
}