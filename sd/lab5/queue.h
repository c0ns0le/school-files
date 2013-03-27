#ifndef __QUEUE_H
#define __QUEUE_H

#include "list.h"

template <typename T>
class Queue {
private:
    //De ce nu mai este nevoie sa retinem head, tail si size?
    LinkedList<T> queueList;

public:
    // Constructor
//  Queue();

    // Destructor
//  ~Queue();

    void enqueue(T e) {
        queueList.addFirst(e);
    }

    T dequeue() {
        return queueList.removeLast();
    }

    T front() {
        return queueList.first();
    }

    int isEmpty() {
        return queueList.isEmpty();
    }

    void print() {
        queueList.print();
    }
};

#endif
