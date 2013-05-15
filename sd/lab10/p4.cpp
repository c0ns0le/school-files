#include<iostream>
#include <stdio.h>
#include "heap.h"

template<class T>
void heapSort(T* array, int &n)
{
    Heap<T> heap(n);
    int i;

    for (i=0; i<n; i++) {
        heap.insert(array[i]);
    }

    for (i=0; i<n; i++) {
        array[i] = heap.extractMin();
    }
}

int main(void)
{
	int* v;
	int n, i;

    scanf("%d", &n);

    v = new int[n];

    for (i = 0; i<n; i++) {
        scanf("%d", v+i);
    }

	// sortare
	heapSort<int>(v, n);

	// Afisare
	for(int i = 0; i < n; ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
