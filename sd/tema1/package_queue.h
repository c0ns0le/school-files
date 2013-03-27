#ifndef __QUEUE_H
#define __QUEUE_H

#include "package_list.h"
#include "package.h"


class PackageQueue {
    private:
        PackageList list;

    public:
        void enqueue(Package p) {
            list.addFirst(p);
        }

        Package dequeue() {
            return list.removeLast();
        }

        Package front() {
            return list.rear();
        }

        int isEmpty() {
            return list.isEmpty();
        }
};

#endif
