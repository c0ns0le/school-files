#include "queue.h"

template <typename T, int N>
class Stack {
private:
    Queue<T, N> A, B;
    
public:
    void push(T e) {
        A.enqueue(e);
        while ( !B.isEmpty() ) {
            A.enqueue(B.dequeue());
        }
        while ( !A.isEmpty() ) {
            B.enqueue(A.dequeue());
        }
    }
    
    T pop() {
        return B.dequeue();
    }
    
    bool isEmpty() {
        return B.isEmpty();
    }
};