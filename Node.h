//
// Created by User on 14.05.2025.
//

#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
struct SinglyNode {
    T data;
    std::shared_ptr<SinglyNode<T>> next;
    SinglyNode(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
struct DoublyNode {
    T data;
    std::shared_ptr<DoublyNode<T>> next;
    std::weak_ptr<DoublyNode<T>> prev;
    DoublyNode(const T& val) : data(val), next(nullptr), prev() {}
};


#endif //NODE_H
