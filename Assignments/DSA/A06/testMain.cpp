#include "CLL.h"

int main()
{
    try
    {
        CircularLinkedList list1;

        //% Insert elements at the beginning
        std::cout << "Using insertAtBeginning() -\n";
        for (int i = 80; i > 0; i -= 10)
        {
            list1.insertAtBeginning(i);
        }
        list1.display();

        //% Insert elements at the end
        std::cout << "Using insertAtEnd() -\n";
        list1.insertAtEnd(90);
        list1.insertAtEnd(100);
        list1.display();

        //% Test the copy constructor
        std::cout << "Copy constructor -\n";
        CircularLinkedList list2 = list1;
        list2.display();

        //% Test the copy assignment operator
        std::cout << "Copy assignment operator -\n";
        CircularLinkedList list3;
        list3 = list1;
        list3.display();

        //% Test inserting after a specific node
        std::cout << "Using searchNode() and insertAfterNode() -\n";
        Node *thirdNode = const_cast<Node*>(list1.searchNode(30)); //% Find a node with data 30
        list1.insertAfterNode(thirdNode, 35);
        list1.display();

        //% Test deleting the first node
        std::cout << "Using deleteFirstNode() -\n";
        list1.deleteFirstNode();
        list1.display();

        //% Test deleting the last node
        std::cout << "Using deleteLastNode() -\n";
        list1.deleteLastNode();
        list1.display();

        //% Test searching for a node by data
        std::cout << "Using searchNode() -\n";
        const Node *foundNode = list1.searchNode(35);
        if (foundNode)
        {
            std::cout << "Node with data 35 found at address: " << foundNode << std::endl;
        }
        else
        {
            std::cout << "Node with data 35 not found." << std::endl;
        }

        //% Test deleting a specific node by address
        std::cout << "Using deleteSpecifiedNode(Node *nodeAddress) -\n";
        list1.deleteSpecifiedNode(thirdNode);
        list1.display();

        //% Test deleting a specific node by data
        std::cout << "Using deleteSpecifiedNode(int data) -\n";
        list1.deleteSpecifiedNode(35);
        list1.display();
        
        std::cout << "All tests completed successfully.\n";
    }
    catch (const NodeNotFoundException &e)
    {
        std::cout << "Node Not Found Exception: " << e.what() << std::endl;
    }
    catch (const EmptyLinkedListException &e)
    {
        std::cout << "Empty Linked List Exception: " << e.what() << std::endl;
    }
    catch (const NullNodeException &e)
    {
        std::cout << "Null Node Exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Standard Exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "An unknown exception occurred." << std::endl;
    }

    std::cin.get();
    return 0;
}