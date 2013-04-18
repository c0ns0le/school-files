#ifndef __VECTOR_H
#define __VECTOR_H

#include "visit.h"

class Node {
    public:

        /**
         * Dimensiunea curentă a vectorului
         */
        int size;

        /**
         * Dimensiunea maximă
         */
        int maxSize;

        /**
         * Vector de structuri Visit
         */
        Visit* vector;

        /**
         * Pointeri către nodul precedent / antecedent
         */
        Node* prev;
        Node* next;

        /**
         * Constructor
         */
        Node(int maxSize);

        /**
         * Destructor
         */
        ~Node();

        bool isEmpty();
        bool isFull();
        void addVisit(Visit v);
        void addVisitFirst(Visit v);
        void remove(int n);
        void erase(int n);
};

#endif
