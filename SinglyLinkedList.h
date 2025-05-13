//
// Created by User on 14.05.2025.
//

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>


template <typename T>
class SinglyLinkedList {
private:
    std::shared_ptr<SinglyNode<T>> head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void push_front(const T& value) {
        auto newNode = std::make_shared<SinglyNode<T>>(value);
        newNode->next = head;
        head = newNode;
    }

    void push_back(const T& value) {
        auto newNode = std::make_shared<SinglyNode<T>>(value);
        if (!head) {
            head = newNode;
        } else {
            auto temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void pop_front() {
        if (!head) throw std::runtime_error("List is empty");
        head = head->next;
    }

    void pop_back() {
        if (!head) throw std::runtime_error("List is empty");
        if (!head->next) {
            head.reset();
            return;
        }
        auto temp = head;
        while (temp->next->next) temp = temp->next;
        temp->next.reset();
    }

    T& at(size_t index) {
        size_t i = 0;
        auto temp = head;
        while (temp && i < index) {
            temp = temp->next;
            ++i;
        }
        if (!temp) throw std::out_of_range("Index out of range");
        return temp->data;
    }

    void insert_at(size_t index, const T& value) {
        if (index == 0) {
            push_front(value);
            return;
        }
        auto temp = head;
        for (size_t i = 0; temp && i < index - 1; ++i) temp = temp->next;
        if (!temp) throw std::out_of_range("Index out of range");
        auto newNode = std::make_shared<SinglyNode<T>>(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove_at(size_t index) {
        if (index == 0) {
            pop_front();
            return;
        }
        auto temp = head;
        for (size_t i = 0; temp && i < index - 1; ++i) temp = temp->next;
        if (!temp || !temp->next) throw std::out_of_range("Index out of range");
        temp->next = temp->next->next;
    }

    size_t size() const {
        size_t count = 0;
        auto temp = head;
        while (temp) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    bool empty() const {
        return !head;
    }

    bool find(const T& value) const {
        auto temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void print() const {
        auto temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};


#endif //SINGLYLINKEDLIST_H
