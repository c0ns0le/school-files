#include<iostream>
#include "heap.h"


int main(void)
{

    Heap<int> heap(10);

    heap.insert(23);
    heap.insert(12);
    heap.insert(76);
    heap.insert(6);
    heap.insert(72);
    heap.insert(8);
    heap.extractMin();

    std::cout << heap.peek() << std::endl;
    return 0;
}
