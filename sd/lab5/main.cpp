#include "list.h"
#include "queue.h"
#include <stdio.h>

int main() {
//  LinkedList<int> l;

//  l.addFirst(3);
//  l.addFirst(4);
//  l.addFirst(5);
//  l.addLast(7);
//  l.addLast(8);

//  l.print();

//  l.removeFirst();

//  l.print();

//  l.removeLast();

//  l.print();

    Queue<int> q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    printf("%d ", q.dequeue());
    printf("%d ", q.dequeue());
    printf("%d ", q.dequeue());
    //printf("%d ", q.dequeue());

    return 0;
}
