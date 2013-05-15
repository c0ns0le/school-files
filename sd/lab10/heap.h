#ifndef HEAP_H
#define HEAP_H

#include<iostream>
 
template <typename T>
class Heap
{ 
private:
    T* values;
    int dimVect;
    int capVect;
public:
    Heap(int capVect);
    ~Heap();
 
    int parent(int poz);
 
    int leftSubtree(int poz);
 
    int rightSubtree(int poz);
 
    void pushUp(int poz);
 
    void pushDown(int poz);
 
    void insert(T x);
 
    T peek();
 
    T extractMin();

    void print();
};



template <typename T>
Heap<T>::Heap(int capVect)
{
    dimVect = 0;
    this->capVect = capVect;
    values = new T[capVect];
}

template <typename T>
Heap<T>::~Heap()
{
    delete[] values;
}

/* TODO Exercitiul 2 */

template <typename T>
int Heap<T>::parent(int poz)
{
    if (poz <= 0) return -1;
    return (poz-1)/2;
}

template <typename T>
int Heap<T>::leftSubtree(int poz)
{
    int r = 2*poz + 1;
    if (r >= dimVect) return -1;
    return r;
}

template <typename T>
int Heap<T>::rightSubtree(int poz)
{
    int r =  2*poz + 2;
    if (r >= dimVect) return -1;
    return r;
}

template <typename T>
void Heap<T>::pushUp(int poz)
{
    T aux;
    while ( parent(poz) >= 0 && values[poz] < values[parent(poz)] ) {
        aux = values[poz];
        values[poz] = values[parent(poz)];
        values[parent(poz)] = aux;

        poz = parent(poz);
    }
}

template <typename T>
void Heap<T>::pushDown(int poz)
{
    int l, r, swap = poz;
    T aux;
    while ( ( l = leftSubtree(poz) ) >= 0 ) {
        if ( values[poz] > values[l] ) {
            swap = l;
        }
        if ( ( r = rightSubtree(poz) ) >= 0 && values[r] < values[l] ) {
            swap = r;
        }
        if (swap != poz) {
            aux = values[swap];
            values[swap] = values[poz];
            values[poz] = aux;
        } else {
            break;
        }
        poz = swap;
    }
}

/* TODO Exercitiul 3 */

template <typename T>
void Heap<T>::insert(T x)
{
    values[dimVect++] = x;
    pushUp(dimVect-1);
}

template <typename T>
T Heap<T>::peek()
{
    return values[0];
}

template <typename T>
T Heap<T>::extractMin()
{
    T aux;
    aux = values[0];
    values[0] = values[dimVect-1];
    values[dimVect-1] = aux;
    --dimVect;

    pushDown(0);

    return values[dimVect];
}

template <typename T>
void Heap<T>::print()
{
    int i;
    for (i=0; i<dimVect; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

#endif // HEAP_H
