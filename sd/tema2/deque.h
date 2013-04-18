#ifndef __DEQUE_H
#define __DEQUE_H

#include "node.h"

/**
 * FRONT ============= BACK
 * pushFront           pushBack
 * popFront
 */

class Deque {
    public:

        /**
         * Pointeri către primul, respectiv ultimul nod al deque-ului
         */
        Node *first;
        Node *last;

        /**
         * Ziua curentă
         */
        int day;
        
        /**
         * Dimensiunea maximă a vectorilor din deque
         */
        int maxSize;

        /**
         * Numărul de zile cât sunt păstrate vizitele în history
         */
        int maxDays;

        /**
         * Constructor
         */
        Deque(int maxSize);

        /**
         * Destructor
         */
        ~Deque();

        void setMaxDays(int maxDays);

        void dayPasses();

        void pushFront(Visit v);
        void popFront();

        void pushBack(Visit v);
        void popBack(int time);

        void accessPage(char* url);
        Visit get(int n);
        void erase(int n);

        void show_history();
        void recoverHistory(char* filename);
};

#endif
