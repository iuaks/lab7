//
// Created by User on 14.05.2025.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

// Двозв'язний список

template <typename T>
class DoublyLinkedList {
private:
    std::shared_ptr<DoublyNode<T>> head;
    std::shared_ptr<DoublyNode<T>> tail;
    size_t count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    void push_front(const T& value) {
        auto newNode = std::make_shared<DoublyNode<T>>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        ++count;
    }

    void push_back(const T& value) {
        auto newNode = std::make_shared<DoublyNode<T>>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++count;
    }

    void pop_front() {
        if (!head) throw std::runtime_error("List is empty");
        head = head->next;
        if (head) head->prev.reset();
        else tail.reset();
        --count;
    }

    void pop_back() {
        if (!tail) throw std::runtime_error("List is empty");
        tail = tail->prev.lock();
        if (tail) tail->next.reset();
        else head.reset();
        --count;
    }

    T& at(size_t index) {
        if (index >= count) throw std::out_of_range("Index out of range");
        auto temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->next;
        return temp->data;
    }

    void insert_at(size_t index, const T& value) {
        if (index == 0) {
            push_front(value);
            return;
        } else if (index == count) {
            push_back(value);
            return;
        }
        auto temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->next;
        auto newNode = std::make_shared<DoublyNode<T>>(value);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev.lock()->next = newNode;
        temp->prev = newNode;
        ++count;
    }

    void remove_at(size_t index) {
        if (index >= count) throw std::out_of_range("Index out of range");
        if (index == 0) {
            pop_front();
            return;
        } else if (index == count - 1) {
            pop_back();
            return;
        }
        auto temp = head;
        for (size_t i = 0; i < index; ++i) temp = temp->next;
        auto prev = temp->prev.lock();
        auto next = temp->next;
        if (prev) prev->next = next;
        if (next) next->prev = prev;
        --count;
    }

    size_t size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
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

#endif //DOUBLYLINKEDLIST_H
