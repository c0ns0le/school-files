/*\
 *   Duma Andrei Dorian
 *   315 CA
\*/

#ifndef __PACKAGE_STACK_H
#define __PACKAGE_STACK_H

#include "package_list.h"
#include "package.h"


class PackageStack {
    private:
        PackageList list;

    public:
        void push(Package p) {
            list.addFirst(p);
        }

        Package pop() {
            return list.removeFirst();
        }

        Package peek() {
            return list.front();
        }

        int isEmpty() {
            return list.isEmpty();
        }
};

#endif
