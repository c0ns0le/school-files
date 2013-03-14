#include <stdio.h>

template <typename T, int N>
class Queue {
private:
    int head;
    int tail;
    T queueArray[N];

public:
    int size;
    
    // Constructor
    Queue() {
        head = tail = size = 0;
    }

    // Destructor
    ~Queue() {
    }

    // Adauga la coada
    void enqueue(T e) {
        if (size == N) {
            fprintf(stderr, "Error: queue is full\n");
            return;
        }
        size++;
        queueArray[tail] = e;
        tail = (tail + 1) % N;
        //printf("Added %d. Size is now %d.\n", e, size);
    }

    // Extrage din coada
    T dequeue() {
        if (size == 0) {
            fprintf(stderr, "Dequeue Error: queue is empty\n");
            T r;
            return r;
        }
        size--;
        T result = queueArray[head];
        head = (head + 1) % N;
        return result;
    }

    // Afla primul element
    T front() {
        if (size == 0) {
            fprintf(stderr, "Front Error: queue is empty\n");
            T r;
            return r;
        }
        return queueArray[head];
    }

    bool isEmpty() {
        if (size == 0) {
            return true;
        } else {
            return false;
        }
    }
};