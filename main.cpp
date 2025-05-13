#include <iostream>
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main() {
    try {
        std::cout << "=== Singly Linked List ===" << std::endl;
        SinglyLinkedList<int> sList;
        sList.push_back(10);
        sList.push_back(20);
        sList.push_front(5);
        sList.print();

        sList.insert_at(1, 7);
        sList.print();

        sList.remove_at(2);
        sList.print();

        std::cout << "Element at index 1: " << sList.at(1) << std::endl;

        std::cout << "\n=== Doubly Linked List ===" << std::endl;
        DoublyLinkedList<std::string> dList;
        dList.push_front("world");
        dList.push_front("hello");
        dList.push_back("!");

        dList.print();

        dList.insert_at(1, "beautiful");
        dList.print();

        dList.remove_at(2);
        dList.print();

        std::cout << "Element at index 1: " << dList.at(1) << std::endl;

        std::cout << "\nTry accessing invalid index:" << std::endl;
        std::cout << dList.at(100) << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
