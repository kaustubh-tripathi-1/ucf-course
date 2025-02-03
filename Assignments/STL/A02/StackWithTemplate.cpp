#include<iostream>
#include<string>

//@ Exception classes

//$ Singly Linked List Exception Base Class
class StackExceptions : public std::exception
{
    protected :

        std::string message;

    public:

        StackExceptions(const std::string &msg)
        :   message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }

};

//@ Specific Stack Exception Child Classes

class EmptyStackException : public StackExceptions
{
    public:
        EmptyStackException() : StackExceptions("Error : The stack is empty. Cannot perform some operations like pop, peek etc.") {}
};

template <typename DT>
class StackLL;

//@ Node class
template <typename DT>
class Node
{
    private:

        DT data;
        Node *next;

        friend class StackLL<DT>;

    public :

        //$ Default Non-Param. Constructor
        Node() : data(0), next(nullptr) {}

        //$ Default Param. Constructor
        Node(DT data) : data(data), next(nullptr) {}

};

//@ Stack through Linked List
template <typename DT>
class StackLL
{
    private :

        Node<DT> *top;

    public:

        //$ Default Constructor
        StackLL() : top(nullptr) {}

        //$ Copy Constructor
        StackLL(const StackLL<DT>&);

        //$ Copy Assignment Op.
        StackLL<DT>& operator=(const StackLL<DT>&);

        //$ Destructor
        ~StackLL();

        //$ Pushes an element onto the stack
        StackLL<DT>& push(DT data);

        //$ Pops an element from the stack
        StackLL<DT>& pop();

        //$ Peek at the top element
        DT peek() const;

        //$ Returns a new Reversed Stack
        template <typename T>
        friend StackLL<T> reverseStack(const StackLL<T> &s);

        //$ Overloaded Equality check operator
        bool operator==( const StackLL<DT> &s ) const;
};

//$ Copy Constructor
template <typename DT>
StackLL<DT>::StackLL(const StackLL<DT> &s)
{
    if ( s.top == nullptr )
    {
        this->top = nullptr;
        return;
    }
    
    Node<DT> *sourceStackTraverse = s.top;
    Node<DT> *thisStackTraverse = nullptr;
    
    while ( sourceStackTraverse != nullptr )
    {
        Node<DT>* newNode = new Node<DT>(sourceStackTraverse->data);

        if ( sourceStackTraverse == s.top )
        {
            this->top = newNode;
        }
        else
        {
            thisStackTraverse->next = newNode;
        }
        
        thisStackTraverse = newNode;
        sourceStackTraverse = sourceStackTraverse->next;
    }
}

//$ Copy Assignment Op.
template <typename DT>
StackLL<DT>& StackLL<DT>::operator=(const StackLL<DT> &s)
{
    //& Self-assignment check
    if ( this == &s)
        return *this;

    //& Empty Stack copy
    if ( s.top == nullptr )
    {
        this->top = nullptr;
        return *this;
    }

    //& Existing stack clean up
    this->~StackLL();

    Node<DT> *sourceStackTraverse = s.top;
    Node<DT> *thisStackTraverse = nullptr;
    
    while ( sourceStackTraverse != nullptr )
    {
        Node<DT>* newNode = new Node<DT>(sourceStackTraverse->data);

        if ( sourceStackTraverse == s.top )
        {
            this->top = newNode;
        }
        else
        {
            thisStackTraverse->next = newNode;
        }
        
        thisStackTraverse = newNode;
        sourceStackTraverse = sourceStackTraverse->next;
    }

    return *this;
}

//$ Destructor
template <typename DT>
StackLL<DT>::~StackLL()
{
    while ( top != nullptr )
    {
        Node<DT> *temp = top;

        top = top->next;

        delete temp;
    }
}

//$ Pushes an element onto the stack
template <typename DT>
StackLL<DT>& StackLL<DT>::push(DT data)
{
    if ( top == nullptr )
    {
        top = new Node<DT>(data);
        return *this;
    }

    Node<DT> *newNode = new Node<DT>(data);
    newNode->next = top;

    top = newNode;

    return *this;
}

//$ Pops an element from the stack
template <typename DT>
StackLL<DT>& StackLL<DT>::pop()
{
    if ( top == nullptr )
        throw EmptyStackException();

    if ( top->next == nullptr )
    {
        delete top;
        top = nullptr;
        return *this;
    }
    
    Node<DT> *nodeToBeDeleted = top;

    top = top->next;

    delete nodeToBeDeleted;

    return *this;
}

//$ Peek at the top element
template <typename DT>
DT StackLL<DT>::peek() const
{
    if ( top == nullptr )
        throw EmptyStackException();

    return top->data;
}

//$ Overloaded Equality check operator
template <typename DT>
bool StackLL<DT>::operator==( const StackLL<DT> &s ) const
{
    if ( this == &s )
        return true;

    Node<DT> *traverse1 = this->top;
    Node<DT> *traverse2 = s.top;

    int size1 = 0;
    int size2 = 0;

    while ( traverse1 != nullptr && traverse2 != nullptr )
    {
        if ( traverse1->data != traverse2->data )
            return false;
        
        traverse1 = traverse1->next;
        traverse2 = traverse2->next;
    }

    //& Stacks are equal
    return traverse1 == nullptr && traverse2 == nullptr;    
}

//$ Non-member, Returns a new Reversed Stack
template <typename DT>
StackLL<DT> reverseStack(const StackLL<DT> &s)
{
    StackLL<DT> tempStack1(s);
    StackLL<DT> tempStack2;

    while ( tempStack1.top != nullptr )
    {
        tempStack2.push(tempStack1.peek());
        tempStack1.pop();
    }

    return tempStack2;
}

int coundDigits(int num)
{
    int noOfDigits = 0;
    while ( num )
    {
        noOfDigits++;
        num /= 10;
    }

    return noOfDigits;
}

//$ Checks for palindrome using stack
bool checkPalindrome(int num)
{
    //& My logic with reverse and equality check
    /* StackLL stack1;
    
    while ( num > 0 )
    {
        stack1.push(num % 10);

        num /= 10;
    }

    StackLL reversedStack = reverseStack(stack1);

    if ( stack1 == reversedStack )
        return true;
    
    return false; */

    //& More efficient and better logic
    StackLL<int> s1;
    int noOfDigits = coundDigits(num);

    //& Store half elements in the stack
    int i = 1;
    while ( i <= noOfDigits/2 )
    {
        s1.push(num % 10);
        num /= 10;
        i++;
    }

    //& Odd no. of digits, remove the middle digit
    if ( noOfDigits % 2 )
    {
        num /= 10;
    }

    //& Compare elements in stack with remaining number
    while ( num )
    {
        if ( num % 10 != s1.peek())
            return false;

        s1.pop();
        num /= 10;

    }

    return true;
}

int main()
{
    try
    {
        std::cout << "Starting StackLL operations testing...\n";

        //$ Test 1: Create a stack
        std::cout << "\nTest 1: Creating a stack...\n";
        StackLL<int> stack;
        std::cout << "Stack created successfully.\n";

        //$ Test 2: Push elements onto the stack
        std::cout << "\nTest 2: Pushing elements onto the stack...\n";
        stack.push(10).push(20).push(30).push(40);
        std::cout << "Pushed 10, 20, 30, and 40 onto the stack.\n";
        std::cout << "Top element after pushes: " << stack.peek() << "\n";

        //$ Test 3: Pop elements from the stack
        std::cout << "\nTest 3: Popping elements from the stack...\n";
        stack.pop();
        std::cout << "Popped one element. New top: " << stack.peek() << "\n";
        stack.pop();
        std::cout << "Popped one element. New top: " << stack.peek() << "\n";

        //$ Test 4: Peek operation
        std::cout << "\nTest 4: Peeking the top element...\n";
        std::cout << "Top element is: " << stack.peek() << "\n";

        //$ Test 5: Reverse a stack
        std::cout << "\nTest 5: Reversing the stack...\n";
        StackLL<int> reversedStack = reverseStack(stack);
        std::cout << "Top element of reversed stack: " << reversedStack.peek() << "\n";
        reversedStack.pop();
        std::cout << "Top element of reversed stack after 1 pop(): " << reversedStack.peek() << "\n";

        //$ Test 6: Check equality of stacks
        std::cout << "\nTest 6: Checking equality of stacks...\n";
        StackLL<int> stack2(stack);
        // stack2.push(30).push(20);
        if (stack == stack2)
        {
            std::cout << "Both stacks are equal.\n";
        }
        else
        {
            std::cout << "Stacks are not equal.\n";
        }

        //$ Test 7: Palindrome check
        std::cout << "\nTest 7: Checking palindrome numbers...\n";
        int num1 = 12321, num2 = 12345;
        std::cout << num1 << " is " << (checkPalindrome(num1) ? "a palindrome.\n" : "not a palindrome.\n");
        std::cout << num2 << " is " << (checkPalindrome(num2) ? "a palindrome.\n" : "not a palindrome.\n");

        //$ Test 8: Empty stack exception
        std::cout << "\nTest 8: Testing pop and peek on an empty stack...\n";
        stack.pop();
        stack.pop(); // Stack should now be empty
        std::cout << "Trying to peek on empty stack:\n";
        std::cout << "Top element: " << stack.peek() << "\n"; // Should throw an exception
    }
    catch (const EmptyStackException &e)
    {
        std::cerr << "Caught EmptyStackException: " << e.what() << "\n";
    }
    catch (const StackExceptions &e)
    {
        std::cerr << "Caught StackException: " << e.what() << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught std::exception: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cerr << "Caught an unknown exception!\n";
    }


    std::cin.get();
    return 0;
}