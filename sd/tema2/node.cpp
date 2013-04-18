#include "node.h"
#include <stdlib.h>

Node::Node(int maxSize) {
    this->maxSize = maxSize;

    this->vector = new Visit[maxSize];

    this->size = 0;

    this->next = NULL;
    this->prev = NULL;
}

Node::~Node() {
    //delete this->vector;
}

bool Node::isEmpty() {
    return (this->size == 0);
}

bool Node::isFull() {
    return (this->size == this->maxSize);
}

void Node::addVisit(Visit v) {
    /**
     * Presupunem că este loc. Verificarea se face în altă parte.
     */
    this->vector[size++] = v;
}

void Node::addVisitFirst(Visit v) {
    /**
     * Adaugă o vizită la începutul vectorului
     * Presupunem că este loc.
     */
    int i;
    for (i = size; i > 0 ; i--) {
        vector[i] = vector[i-1];
    }
    vector[0] = v;
    ++size;
}

void Node::remove(int n) {
    /**
     * Elimină primele n elemente din vector.
     * Presupunem că sunt cel puțin n elemente
     */
    if (n <= 0) {
        return;
    }
    
    int i;
    for (i = 0; i < this->size - n; i++) {
        this->vector[i] = this->vector[i+n];
    }
    size -= n;

    if (this->isEmpty()) {
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
}

void Node::erase(int n) {
    /**
     * Șterge al n-lea element din vector.
     * Presupunem că există.
     */
    int i;
    for (i = n; i < this->size - 1; i++) {
        this->vector[i] = this->vector[i+1];
    }
    --size;
}
