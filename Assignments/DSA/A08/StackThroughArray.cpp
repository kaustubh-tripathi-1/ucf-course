#include<iostream>
#include<string>

//@ Exception classes

//$ Stack Exceptions Base Class
class StackExceptions : public std::exception
{
    private:
        std::string message;

    public:

        StackExceptions(const std::string &msg) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

//@ Stack Specific Exception Child Classes

class NegativeSizeException : public StackExceptions
{
    public :

        NegativeSizeException() : StackExceptions("Error : Stack Size should be greater than 0!") {}
};

class StackOverflowException : public StackExceptions
{
    public:
        StackOverflowException() : StackExceptions("Error : Stack Overflow.") {}

};

class EmptyStackException : public StackExceptions
{
    public:
        EmptyStackException() : StackExceptions("Error : Stack is Empty.") {}

};

class StackUnderflowException : public StackExceptions
{
    public:
        StackUnderflowException() : StackExceptions("Error : Stack Underflow. Can't delete from an Empty Stack.") {}

};

class StackNotCreatedException : public StackExceptions
{
    public:
        StackNotCreatedException(const std::string &operation) : StackExceptions("Error : Stack wasn't created properly. Can't perform " + operation + ".") {}

};

class NoElementsInStackException : public StackExceptions
{
    public:
        NoElementsInStackException() : StackExceptions("Error : No elements in stack to reverse.") {}

};

class AssignerStackNotCreatedException : public StackExceptions
{
    public:
        AssignerStackNotCreatedException() : StackExceptions("Error : The assigner stack is not created.") {}

};

class StackWithMin;

class Stack
{
    private:

        size_t capacity, top;
        int *stack;

    public:

        //$ Default Non-param. Constructor
        Stack() : capacity(0), top(SIZE_MAX), stack(nullptr) {}

        //$ Default Param. Constructor
        Stack(size_t capacity);

        //$ Copy Constructor
        Stack(const Stack &s);

        //$ Copy Assignment Op.
        virtual Stack& operator=(const Stack &s);

        //$ Destructor
        virtual ~Stack();

        //$ Pushes an element onto the stack
        virtual Stack& push(int data);

        //$ Pops an element from the stack
        virtual Stack& pop();

        //$ Peek the top element
        virtual int peek() const;

        //$ Check for stack overflow
        virtual bool isStackOverflow() const;

        //$ Check for stack overflow
        virtual bool isStackUnderflow() const;

        //$ Reverses the stack
        virtual Stack& reverseStack();

        //$ Reverses the stack
        friend Stack reverseStack( const Stack &s );

        friend StackWithMin;

};

//$ Default Param. Constructor
Stack::Stack(size_t capacity) : capacity(0), top(SIZE_MAX), stack(nullptr)
{
    if ( (int)capacity <= 0)
        throw NegativeSizeException();
    
    this->capacity = capacity;
    stack = new int[this->capacity];
}

//$ Copy Constructor
Stack::Stack(const Stack &s)
    : capacity(s.capacity), top(s.top)
{
    if ( s.stack == nullptr )
    {
        this->stack = nullptr;
        throw EmptyStackException();
    }

    this->stack = new int[capacity];

    for ( int i = 0 ; i <= s.top ; i++)
    {
        this->stack[i] = s.stack[i];
    }
}

Stack& Stack::operator=(const Stack &s)
{
    if ( s.stack == nullptr )
        throw AssignerStackNotCreatedException();

    if ( this == &s )
        return *this;

    if ( this->stack != nullptr )
    {
        delete []stack;
        stack = nullptr;
    }

    this->capacity = s.capacity;
    this->top = s.top;

    this->stack = new int[capacity];

    for ( int i = 0 ; i <= s.top ; i++)
    {
        this->stack[i] = s.stack[i];
    }

    return *this;
}

//$ Destructor
Stack::~Stack()
{
    if ( stack != nullptr )
        delete []stack;
}

//$ Pushes an element onto the stack
Stack& Stack::push(int data)
{
    if ( stack == nullptr )
        throw StackNotCreatedException("push");
    
    if ( isStackOverflow() )
        throw StackOverflowException();

    stack[++top] = data;

    return *this;
}

//$ Pops an element from the stack
Stack& Stack::pop()
{
    if ( stack == nullptr )
        throw StackNotCreatedException("push");
    
    if ( top == SIZE_MAX )
        throw StackUnderflowException();

    top--;

    return *this;
}

//$ Peek the top element
int Stack::peek() const
{
    if ( stack == nullptr )
        throw StackNotCreatedException("peek");
    
    if ( top == SIZE_MAX )
        throw EmptyStackException();

    return stack[top];
}

//$ Check for stack overflow
bool Stack::isStackOverflow() const
{
    if ( stack == nullptr )
        throw StackNotCreatedException("checking of stack overflow");
    
    return top+1 == capacity;
}

//$ Check for stack overflow
bool Stack::isStackUnderflow() const
{
    if ( stack == nullptr )
        throw StackNotCreatedException("checking of stack underflow");
    
    return top == SIZE_MAX;
}

//$ Member, Reverses the stack with 2 pointers ( invalid operations )
Stack& Stack::reverseStack()
{
    if ( stack == nullptr )
        throw StackNotCreatedException("reverse the stack");

    //& No need to reverse as the stack only has 1 element
    if ( top == 0 )
        return *this;

    for ( int start = 0, end = top ; start < end ; start++, end-- )
    {
        int temp = stack[start];
        stack[start] = stack[end];
        stack[end] = temp;
    }

    return *this;
}

//$ Non - member, Reverses the stack with Valid operations
Stack reverseStack( const Stack &s )
{
    if ( s.stack == nullptr )
        throw StackNotCreatedException("reverse the stack");

    //& No need to reverse as the stack has no element
    if ( s.top == SIZE_MAX )
        throw NoElementsInStackException();

    //& No need to reverse as the stack only has 1 element
    if ( s.top == 0 )
        return s;

    Stack tempStack1 = s, tempStack2(s.capacity);

    while ( tempStack1.top != SIZE_MAX )
    {
        tempStack2.push(tempStack1.peek());
        tempStack1.pop();
    }

    return tempStack2;
}

//@ Specialized Stack with additional Mininmum Value Stack
class StackWithMin : public Stack
{
    private :
        Stack minStack; //$ Auxiliary stack to track minimum values

    public :

        //$ Default Param. Constrctor
        StackWithMin(size_t capacity) : Stack(capacity), minStack(capacity) {}

        //$ Copy Constructor
        StackWithMin(const StackWithMin &minStackObj) : Stack(minStackObj), minStack(minStackObj)
        {
            if (minStackObj.minStack.stack == nullptr)
            {
                throw AssignerStackNotCreatedException();
            }
        }

        //$ Copy Assignment Op.
        StackWithMin& operator=(const StackWithMin &minStack);

        //$ Push operation (Override)
        StackWithMin& push(int data);

        //$ Pop operation (Override)
        StackWithMin& pop();

        //$ Gets the minimun value in the stack
        int getMin() const;
        
};

//$ Copy Assignment Op.
StackWithMin& StackWithMin::operator=(const StackWithMin &minStackObj)
{
    if ( this == &minStackObj )
        return *this;

    if ( minStackObj.stack == nullptr )
        throw AssignerStackNotCreatedException();

    //% Manual Copy
    /* if ( this->stack != nullptr )
    {
        delete []stack;
        delete []minStack.stack;

        stack = nullptr;
        minStack.stack = nullptr;
    }

    
    //& Initialize main stack
    this->capacity = minStackObj.capacity;
    this->top = minStackObj.top;

    //& Initialize min stack
    minStack.capacity = this->capacity;
    minStack.top = this->top;

    for ( int i = 0 ; i <= top ; i++)
    {
        this->stack[i] = minStackObj.stack[i];
        minStack.stack[i] = minStackObj.minStack.stack[i];
    } */

    //% Reusing copy assign. operator
    //& Assign base class (main stack)
    Stack::operator=(minStackObj);

    //& Assign the auxiliary minStack
    this->minStack = minStackObj.minStack;

    return *this;
}

//$ Push operation (Override)
StackWithMin& StackWithMin::push(int data)
{

    Stack::push(data);

    if ( minStack.isStackUnderflow() || data < minStack.peek() )
    {
        minStack.push(data);    //& Push the new min value
    }
    else
    {
        minStack.push(minStack.peek()); //& Push the already minimun value again
    }

    return *this;
}

//$ Pop operation (Override)
StackWithMin& StackWithMin::pop()
{
    if ( this->isStackUnderflow() )
        throw StackUnderflowException();
    
    Stack::pop();   //& Pop from main stack
    minStack.pop(); //& Pop from min stack

    return *this;

}

//$ Gets the minimun value in the stack
int StackWithMin::getMin() const
{
    if ( minStack.isStackUnderflow() )
        throw EmptyStackException();

    return minStack.peek();
}

int main()
{
    try
    {
        std::cout << "Starting StackWithMin operations testing...\n";

        //$ Test 1: Create a stack
        std::cout << "\nTest 1: Creating a stack with size 5...\n";
        StackWithMin stack(5);

        //$ Test 2: Push elements and get the minimum
        std::cout << "\nTest 2: Pushing elements and checking minimum...\n";
        stack.push(10);
        std::cout << "Pushed 10. Current min: " << stack.getMin() << "\n";
        stack.push(20);
        std::cout << "Pushed 20. Current min: " << stack.getMin() << "\n";
        stack.push(5);
        std::cout << "Pushed 5. Current min: " << stack.getMin() << "\n";
        stack.push(8);
        std::cout << "Pushed 8. Current min: " << stack.getMin() << "\n";
        stack.push(15);
        std::cout << "Pushed 15. Current min: " << stack.getMin() << "\n";

        if ( stack.isStackOverflow())
            std::cout<<"Stack is full!\n";
        else
            std::cout<<"Stack is not full!\n";

        //$ Test 3: Peek the top element
        std::cout << "\nTest 3: Peeking the top element...\n";
        std::cout << "Top element: " << stack.peek() << "\n";

        //$ Test 4: Pop elements and get the minimum
        std::cout << "\nTest 4: Popping elements and checking minimum...\n";
        stack.pop();
        std::cout << "Popped one element. Current min: " << stack.getMin() << "\n";
        stack.pop();
        std::cout << "Popped one element. Current min: " << stack.getMin() << "\n";
        stack.pop();
        std::cout << "Popped one element. Current min: " << stack.getMin() << "\n";
        stack.pop();
        std::cout << "Popped one element. Current min: " << stack.getMin() << "\n";

        //$ Test 5: Push until stack overflows
        std::cout << "\nTest 5: Pushing until stack overflows...\n";
        stack.push(1);

        //$ Test 6: Pop from an empty stack (should throw exception)
        std::cout << "\nTest 6: Popping until the stack is empty...\n";
        stack.pop();
        std::cout << "Top element: " << stack.peek() << "\n";
        stack.pop();
        // stack.pop(); //& Should throw StackUnderflowException
        
        if ( stack.isStackUnderflow())
            std::cout<<"Stack is empty!\n";
        else
            std::cout<<"Stack is not empty!\n";
    }
    catch (const NegativeSizeException &e)
    {
        std::cerr << "Caught NegativeSizeException: " << e.what() << "\n";
    }
    catch (const StackOverflowException &e)
    {
        std::cerr << "Caught StackOverflowException: " << e.what() << "\n";
    }
    catch (const StackUnderflowException &e)
    {
        std::cerr << "Caught StackUnderflowException: " << e.what() << "\n";
    }
    catch (const EmptyStackException &e)
    {
        std::cerr << "Caught EmptyStackException: " << e.what() << "\n";
    }
    catch (const StackExceptions &e) // Generic exception handling for all stack exceptions
    {
        std::cerr << "Caught StackException: " << e.what() << "\n";
    }
    catch (const std::exception &e) // Catch any other standard exceptions
    {
        std::cerr << "Caught std::exception: " << e.what() << "\n";
    }
    catch (...) // Catch any other unknown exceptions
    {
        std::cerr << "Caught an unknown exception!\n";
    }

    std::cin.get();
    return 0;
}