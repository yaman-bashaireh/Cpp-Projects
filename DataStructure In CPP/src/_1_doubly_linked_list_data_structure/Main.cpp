#include <iostream>
#include "doubly_linked_list_data_structure//Node.h"
#include "doubly_linked_list_data_structure/DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<short> numbers;

    cout << "■ After Insert First Nodes" << endl;

    auto *firstNode = new Node<short>(
             11
         ),
         *secondNode = new Node<short>(
             22
         ),
         *thirdNode = new Node<short>(
             33
         ),
         *fourthNode = new Node<short>(
             44
         ),
         *fifthNode = new Node<short>(
             55
         );

    numbers.insertFirst(
        firstNode
    );
    numbers.insertFirst(
        secondNode
    );
    numbers.insertFirst(
        thirdNode
    );
    numbers.insertFirst(
        fourthNode
    );
    numbers.insertFirst(
        fifthNode
    );

    numbers.printValues();

    cout << "\n■ Node Found = ";

    auto *nodeFound = numbers.findNode(
        fourthNode
    );

    cout << nodeFound->getValue() << endl;

    cout << "\n■ After Insert First Found Node" << endl;

    auto *copyOfNodeFound = new Node(
        nodeFound->getValue()
    );
    numbers.insertFirst(
        copyOfNodeFound
    );

    numbers.printValues();

    cout << "\n■ After Insert After Node" << endl;

    auto *sixthNode = new Node<short>(
        66
    );
    numbers.insertAfter(
        fourthNode,
        sixthNode
    );

    numbers.printValues();

    cout << "\n■ After Insert Last Node" << endl;

    auto *seventhNode = new Node<short>(
        777
    );
    numbers.insertLast(
        seventhNode
    );

    numbers.printValues();

    cout << "\n■ After Delete Node" << endl;

    numbers.deleteNode(
        secondNode
    );

    numbers.printValues();

    cout << "\n■ After Delete First Node" << endl;

    numbers.deleteFirst();

    numbers.printValues();

    cout << "\n■ After Delete Last Node" << endl;

    numbers.deleteLast();

    numbers.printValues();

    cout << "\n■ Count of Nodes: " << numbers.size() << endl;

    cout << "\n■ Is Empty?\n" << boolalpha << numbers.isEmpty() << endl;

    cout << "\n■ After Clear Nodes:" << endl;

    numbers.clear();

    numbers.printValues();

    cout << "\n■ After Reverse Nodes:" << endl;

    firstNode = new Node<short>(
        11
    );
    secondNode = new Node<short>(
        22
    );
    thirdNode = new Node<short>(
        33
    );
    fourthNode = new Node<short>(
        44
    );
    fifthNode = new Node<short>(
        55
    );

    numbers.insertFirst(
        firstNode
    );
    numbers.insertFirst(
        secondNode
    );
    numbers.insertFirst(
        thirdNode
    );
    numbers.insertFirst(
        fourthNode
    );
    numbers.insertFirst(
        fifthNode
    );

    numbers.reverse();

    numbers.printValues();

    size_t index = 2;
    cout << "\n■ Node of " << index << " is: " << to_string(
        numbers.getItem(
            index
        )
    ) << endl;

    index = 2;
    cout << "\n■ Node Value of " << index << " is: " << to_string(
        numbers.getItem(
            index
        )
    ) << endl;

    index = 2;
    cout << "\n■ Is Updated?\n" << boolalpha << numbers.updateItem(
        index,
        333
    ) << endl;

    numbers.printValues();

    index = 3;
    constexpr short VALUE = 666;
    cout << "\n■ After Insert After by Index:" << endl;

    numbers.insertAfter(
        index,
        VALUE
    );

    numbers.printValues();
}