/*\
 *   Duma Andrei Dorian
 *   315 CA
\*/

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include "package.h"


struct PackageNode {
    Package value;
    PackageNode *next;
    PackageNode *prev;
};

class PackageList {
    private:
        PackageNode *first, *last;

    public:
        PackageList() {
            first = last = NULL;
        }

        // remove all elements to free the memory
        ~PackageList() {
            while (!isEmpty()) {
                removeFirst();
            }
        }

        void addFirst(Package p) {
            PackageNode *node = new PackageNode;
            node->value = p;
            node->prev = NULL;
            node->next = first;
            if (isEmpty()) {
                last = node;
            } else {
                first->prev = node;
            }
            first = node;
        }

        Package removeFirst() {
            Package result;
            PackageNode *second;
            if (isEmpty()) {
                fprintf(stderr, "List is empty!\n");
            } else {
                result = first->value;
                second = first->next;
                if (second == NULL) {
                    last = NULL;
                } else {
                    second->prev = NULL;
                }
                delete first;
                first = second;
            }
            return result;
        }

        Package removeLast() {
            Package result;
            PackageNode *prelast;
            if (isEmpty()) {
                fprintf(stderr, "List is empty!\n");
            } else {
                result = last->value;
                prelast = last->prev;
                if (prelast == NULL) {
                    first = NULL;
                } else {
                    prelast->next = NULL;
                }
                delete last;
                last = prelast;
            }
            return result;
        }

        // return first element in the list
        Package front() {
            Package result;
            if (isEmpty()) {
                fprintf(stderr, "List is empty!\n");
            } else {
                result = first->value;
            }
            return result;
        }

        // return last element in the list
        Package rear() {
            Package result;
            if (isEmpty()) {
                fprintf(stderr, "List is empty!\n");
            } else {
                result = last->value;
            }
            return result;
        }

        // check whether the list is empty or not
        int isEmpty() {
            if (first == NULL) {
                return 1;
            }
            return 0;
        }
};

#endif
