


#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <memory>
#include <stdexcept>

template <typename T>
class QueueList {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    std::shared_ptr<Node> front;
    std::shared_ptr<Node> rear;
    size_t count;

public:
    QueueList() : front(nullptr), rear(nullptr), count(0) {}

    void enqueue(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
    }

    void dequeue() {
        if (!front) throw std::runtime_error("Queue is empty");
        front = front->next;
        if (!front) rear.reset();
        --count;
    }

    T& peek() const {
        if (!front) throw std::runtime_error("Queue is empty");
        return front->data;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return false; // для списку немає ліміту
    }

    size_t size() const {
        return count;
    }
};

#endif
