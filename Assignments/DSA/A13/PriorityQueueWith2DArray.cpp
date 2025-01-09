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

class NegativeSizeException : public PriorityQueueExceptions
{
    public :

        NegativeSizeException() : PriorityQueueExceptions("Error : Queue Size should be greater than 0!") {}
};

class NegativeMaxPriorityNumberException : public PriorityQueueExceptions
{
    public :

        NegativeMaxPriorityNumberException() : PriorityQueueExceptions("Error : Priority Queue's Max Priority number should be greater than 0!") {}
};

class QueueOverflowException : public PriorityQueueExceptions
{
    public:
        QueueOverflowException() : PriorityQueueExceptions("Error : Queue Overflow.") {}

};

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

class QueueNotCreatedException : public PriorityQueueExceptions
{
    public:
        QueueNotCreatedException(const std::string &operation) : PriorityQueueExceptions("Error : Queue wasn't created properly. Can't perform " + operation + ".") {}

};

class AssignerQueueNotCreatedException : public PriorityQueueExceptions
{
    public:
        AssignerQueueNotCreatedException() : PriorityQueueExceptions("Error : The assigner Queue is not created.") {}

};

class InvalidPriorityNumberException : public PriorityQueueExceptions
{
    public:
        InvalidPriorityNumberException() : PriorityQueueExceptions("Error : The provided priority number should be greater than 0 and less than max priority number for the priority queue.") {}

};


class PriorityQueue
{
    private:

        size_t capacity, *front, *rear;
        int maxPriorityNo, currentMaxPriority;
        int **ptr;

    public :

        //$ Default Constructor
        PriorityQueue(size_t capacity, int maxPriorityNo);

        //$ Copy Constructor
        PriorityQueue(const PriorityQueue &pq);

        //$ Copy Assignment Op.
        PriorityQueue& operator=(const PriorityQueue &pq);

        //$ Destructor
        ~PriorityQueue();

        //$ Inserts the element according to Priority
        PriorityQueue& enqueue(int data, int priorityNo);

        //$ Deletes the highest Priority element
        PriorityQueue& dequeue();

        //$ Returns the highest priority element
        int getHighestPriorityFrontElement() const;

        //$ Returns the highest priority rear element
        int getHighestPriorityRearElement() const;

        //$ Returns the highest priority number
        int getHighestPriorityNumber() const;

        //$ Checks for queue overflow
        bool isOverflow(int priorityNo) const;

        //$ Checks for queue underflow
        bool isUnderflow(int priorityNo) const;

};

//$ Default Constructor
PriorityQueue::PriorityQueue(size_t capacity, int maxPriorityNo)
: ptr(nullptr), front(nullptr), rear(nullptr), maxPriorityNo(maxPriorityNo), currentMaxPriority(maxPriorityNo)
{
    if ( (int)capacity <= 0)
        throw NegativeSizeException();

    if ( maxPriorityNo < 0 )
        throw NegativeMaxPriorityNumberException();

    this->capacity = capacity;

    ptr = new int*[this->maxPriorityNo];
    front = new size_t[this->maxPriorityNo];
    rear = new size_t[this->maxPriorityNo];

    for ( int i = 0 ; i < this->maxPriorityNo ; i++)
    {
        ptr[i] = new int[this->capacity];
        front[i] = SIZE_MAX;
        rear[i] = SIZE_MAX;
    }

}

//$ Copy Constructor
PriorityQueue::PriorityQueue(const PriorityQueue &pq)
: capacity(pq.capacity), maxPriorityNo(pq.maxPriorityNo)
{
    ptr = new int*[maxPriorityNo];
    front = new size_t[maxPriorityNo];
    rear = new size_t[maxPriorityNo];

    for ( int i = 0 ; i < maxPriorityNo ; i++)
    {
        ptr[i] = new int[capacity];
        front[i] = pq.front[i];
        rear[i] = pq.rear[i];
    }

    for ( int i = 0 ; i < maxPriorityNo  ; i++ )
        for ( int j = 0 ; j <= rear[i]  ; j++ )
            ptr[i][j] = pq.ptr[i][j];
}

//$ Copy Assignment Op.
PriorityQueue& PriorityQueue::operator=(const PriorityQueue &pq)
{
    if ( this == &pq)
        return *this;

    //& Existing Memory Clean-up
    if ( ptr != nullptr )
    {
        for ( int i = 0 ; i < maxPriorityNo  ; i++ )
        {
            delete []ptr[i];
        }
        delete []ptr;
        ptr = nullptr;
    }

    if ( front != nullptr || rear != nullptr )
    {
        delete []front;
        front = nullptr;
        delete []rear;
        rear = nullptr;
    }

    if ( pq.ptr == nullptr )
    {
        /* this->ptr = nullptr;
        this->front = nullptr;
        this->rear = nullptr;
        capacity = 0;
        maxPriorityNo = 0;
        return *this; */
        //& Or can throw AssignerArrayNotCreated Exception
        throw AssignerQueueNotCreatedException();
    }

    ptr = new int*[maxPriorityNo];
    front = new size_t[maxPriorityNo];
    rear = new size_t[maxPriorityNo];

    for ( int i = 0 ; i < maxPriorityNo ; i++)
    {
        ptr[i] = new int[capacity];
        front[i] = pq.front[i];
        rear[i] = pq.rear[i];
    }

    for ( int i = 0 ; i < maxPriorityNo  ; i++ )
        for ( int j = 0 ; j <= rear[i]  ; j++ )
            ptr[i][j] = pq.ptr[i][j];

    return *this;
}

//$ Destructor
PriorityQueue::~PriorityQueue()
{
    if ( ptr != nullptr )
    {
        for ( int i = 0 ; i < maxPriorityNo  ; i++ )
        {
            delete []ptr[i];
        }
        delete []ptr;
        ptr = nullptr;
    }

    if ( front != nullptr || rear != nullptr )
    {
        delete []front;
        front = nullptr;
        delete []rear;
        rear = nullptr;
    }
}

//$ Inserts the element according to Priority
PriorityQueue& PriorityQueue::enqueue(int data, int priorityNo)
{
    if ( ptr == nullptr )
        throw QueueNotCreatedException("enqueue");

    if ( priorityNo > maxPriorityNo || priorityNo <= 0 )
        throw InvalidPriorityNumberException();

    if ( isOverflow(priorityNo) )
        throw QueueOverflowException();

    int pNo = priorityNo-1;

    if ( front[pNo] == SIZE_MAX )
    {
        front[pNo] = rear[pNo] = 0;
    }
    else
    {
        rear[pNo] = (rear[pNo] + 1) % capacity;
    }

    ptr[pNo][rear[pNo]] = data;

    if ( priorityNo > currentMaxPriority )
        currentMaxPriority = priorityNo;

    return *this;
}

//$ Deletes the highest Priority element
PriorityQueue& PriorityQueue::dequeue()
{
    if ( ptr == nullptr )
        throw QueueNotCreatedException("dequeue");

    int i = maxPriorityNo-1;
    while ( i >= 0 && front[i] == SIZE_MAX)
    {
        i--;
    }

    if (i < 0) // If all queues are empty
        throw QueueUnderflowException();

    if ( front[i] == rear[i] )
    {
        front[i] = rear[i] = SIZE_MAX;
    }
    else
    {
        front[i] = (front[i] + 1) % capacity;
    }

    //& Update currentMaxPriority
    currentMaxPriority = 0; //& Default to no valid priority
    for (int j = maxPriorityNo - 1; j >= 0; --j)
    {
        if (front[j] != SIZE_MAX)
        {
            currentMaxPriority = j + 1;
            break;
        }
    }

    return *this;
}

//$ Returns the highest priority front element
int PriorityQueue::getHighestPriorityFrontElement() const
{
    if (ptr == nullptr)
        throw QueueNotCreatedException("get Highest Priority Front Element operation");

    int i = maxPriorityNo - 1;
    while (i >= 0 && front[i] == SIZE_MAX)
    {
        i--;
    }

    if (i < 0)
        throw EmptyQueueException();

    return ptr[i][front[i]];
}

//$ Returns the highest priority rear element
int PriorityQueue::getHighestPriorityRearElement() const
{
    if ( ptr == nullptr )
        throw QueueNotCreatedException("get Highest Priority Rear Element operation");

    int i = maxPriorityNo-1;
    while ( i >= 0 && rear[i] == SIZE_MAX)
    {
        i--;
    }

    if (i < 0)
        throw EmptyQueueException();

    return ptr[i][rear[i]];
}

//$ Returns the highest priority number
int PriorityQueue::getHighestPriorityNumber() const
{
    return currentMaxPriority;
}

//$ Checks for queue overflow 
bool PriorityQueue::isOverflow(int priorityNo) const
{
    if ( ptr == nullptr )
        throw QueueNotCreatedException("check for overflow");

    return (rear[priorityNo]+1 == front[priorityNo]) || (rear[priorityNo] + 1 == capacity && front[priorityNo] == 0 );
}

//$ Checks for queue underflow
bool PriorityQueue::isUnderflow(int priorityNo) const
{
    if ( ptr == nullptr )
        throw QueueNotCreatedException("check for underflow");

    return front[priorityNo] == SIZE_MAX;
}

int main()
{
    try
    {
        std::cout << "Starting Priority Queue operations testing...\n";

        //$ Test 1: Create a Priority Queue
        std::cout << "\nTest 1: Creating a Priority Queue...\n";
        PriorityQueue pq(7, 6); // Create a Priority Queue with capacity 5 and max priority 3
        std::cout << "Priority Queue created successfully.\n";

        //$ Test 2: Insert elements with different priorities
        std::cout << "\nTest 2: Enqueue elements into the Priority Queue...\n";
        pq.enqueue(321, 1)
          .enqueue(543, 2)
          .enqueue(6, 3)
          .enqueue(75, 1)
          .enqueue(432, 2)
          .enqueue(5, 2)
          .enqueue(12, 6)
          .enqueue(-214, 3)
          .enqueue(-8123, 1)
          .enqueue(6542, 2);
        std::cout << "Inserted 321 (P1), 543 (P2), 6 (P3), 75 (P1), 432 (P2), 5 (P2), 12 (P6), -214 (P3), -8123 (P1), 6542 (P2).\n";

        std::cout << "Highest priority front element: " 
                  << pq.getHighestPriorityFrontElement() 
                  << " (Priority: " 
                  << pq.getHighestPriorityNumber() 
                  << ")\n";

        //$ Test 3: Dequeue elements based on priority
        std::cout << "\nTest 3: Dequeue elements from the Priority Queue...\n";
        pq.dequeue();
        std::cout << "Dequeued highest priority element. New highest priority front element: " 
                  << pq.getHighestPriorityFrontElement() 
                  << " (Priority: " 
                  << pq.getHighestPriorityNumber() 
                  << ")\n";

        //$ Test 4: Insert more elements and check priority order
        std::cout << "\nTest 4: Enqueue more elements into the Priority Queue...\n";
        pq.enqueue(60, 3).enqueue(70, 2).enqueue(80, 1);
        std::cout << "Inserted 60 (P3), 70 (P2), 80 (P1).\n";
        std::cout << "Highest priority front element: " 
                  << pq.getHighestPriorityFrontElement() 
                  << " (Priority: " 
                  << pq.getHighestPriorityNumber() 
                  << ")\n";

        //$ Test 5: Attempt to dequeue from an empty Priority Queue (Underflow)
        std::cout << "\nTest 5: Attempting to dequeue from an empty Priority Queue (should throw an exception)...\n";
        try
        {
            for (int i = 0; i < 15; ++i)
            {
                pq.dequeue();
                std::cout << "Highest priority front element: " 
                  << pq.getHighestPriorityFrontElement() 
                  << " (Priority: " 
                  << pq.getHighestPriorityNumber() 
                  << ")\n";
            }

            
        }
        catch (const QueueUnderflowException &e)
        {
            std::cerr <<"Caught Queue Underflow Exception"<<e.what() << "\n";
        }
        catch (const EmptyQueueException &e)
        {
            std::cerr <<"Caught Empty Queue Exception"<< e.what() << "\n";
        }

        //$ Test 6: Testing copy constructor and assignment operator
        std::cout << "\nTest 6: Testing copy constructor and assignment operator...\n";
        PriorityQueue pq2(5, 3);
        pq2.enqueue(100, 1)
            .enqueue(200, 2)
            .enqueue(300, 3)
            .enqueue(239, 1)
            .enqueue(-321, 2);
        std::cout << "Created a new Priority Queue pq2 and inserted 100 (P1), 200 (P2), 300 (P3), 239 (P1), -321 (P2).\n";

        PriorityQueue pq3(pq2); // Copy constructor
        std::cout << "Copied pq2 to pq3 using copy constructor.\n";
        std::cout << "Highest priority in pq3: " 
                  << pq3.getHighestPriorityFrontElement() 
                  << " (Priority: " 
                  << pq3.getHighestPriorityNumber() 
                  << ")\n";

        PriorityQueue pq4(5, 3);
        pq4 = pq2; // Copy assignment operator
        std::cout << "Assigned pq2 to pq4 using copy assignment operator.\n";
        std::cout << "Highest priority in pq4: " 
                  << pq4.getHighestPriorityFrontElement() 
                  << " (Priority: " 
                  << pq4.getHighestPriorityNumber() 
                  << ")\n";
    }
    catch (const NegativeSizeException &e)
    {
        std::cerr << "Caught Negative Size Exception: " << e.what() << "\n";
    }
    catch (const NegativeMaxPriorityNumberException &e)
    {
        std::cerr << "Caught Negative Max Priority Number Exception: " << e.what() << "\n";
    }
    catch (const QueueOverflowException &e)
    {
        std::cerr << "Caught Queue Overflow Exception: " << e.what() << "\n";
    }
    catch (const QueueUnderflowException &e)
    {
        std::cerr << "Caught Queue Underflow Exception: " << e.what() << "\n";
    }
    catch (const EmptyQueueException &e)
    {
        std::cerr << "Caught Empty Queue Exception: " << e.what() << "\n";
    }
    catch (const QueueNotCreatedException &e)
    {
        std::cerr << "Caught Queue Not Created Exception: " << e.what() << "\n";
    }
    catch (const AssignerQueueNotCreatedException &e)
    {
        std::cerr << "Caught Assigne rQueue Not Created Exception: " << e.what() << "\n";
    }
    catch (const InvalidPriorityNumberException &e)
    {
        std::cerr << "Caught Invalid Priority Number Exception: " << e.what() << "\n";
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