/* list.h */
#ifndef __LIST__H
#define __LIST__H

#include <stdio.h>

template <typename T>struct Node {

public:

    T value;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>class LinkedList{
private:

    Node<T> *pFirst;

public:

    //Constructor
    LinkedList() {
        pFirst = NULL;
    }

//  //Destructor
//  ~LinkedList() {
//      Node<T> *p = pFirst->next,
//              *next;
//      while (p != pFirst ) {
//          next = p->next;
//          delete p;
//          p = next;
//      }

//      delete pFirst;
//  }

    T first() {
        return pFirst->value;
    }
    
    /*Adauga un nod cu valoarea == value la inceputul listei */
    void addFirst(T value) {
        Node<T> *x = new Node<T>;
        x->value = value;

        if (pFirst == NULL) {
            pFirst = x;
            x->next = x;
            x->prev = x;
        } else {
            x->next = pFirst;
            x->prev = pFirst->prev;
            x->next->prev = x;
            x->prev->next = x;
            pFirst = x;
        }
    }

    /*Adauga un nod cu valoarea == value la sfarsitul listei */
    void addLast(T value) {
        addFirst(value);
        pFirst = pFirst->next;
    }

    /*Elimina elementul de la inceputul listei si intoarce valoarea acestuia*/
    T removeFirst() {
        T value = pFirst->value;
        Node<T> *to_delete;
        if (pFirst->next == pFirst) {
            delete pFirst;
            pFirst = NULL;
        } else {
            pFirst->next->prev = pFirst->prev;
            pFirst->prev->next = pFirst->next;
            Node<T> *to_delete = pFirst;
            pFirst = pFirst->next;
            delete to_delete;
        }
        return value;
    }

    /*Elimina elementul de la sfarsitul listei listei si intoarce valoarea acestuia*/
    T removeLast() {
        T value = pFirst->prev->value;
        Node<T> *to_delete;
        if (pFirst->next == pFirst) {
            delete pFirst;
            pFirst = NULL;
        } else {
            Node<T> *to_delete = pFirst->prev;
            to_delete->next->prev = to_delete->prev;
            to_delete->prev->next = to_delete->next;
            delete to_delete;
        }
        return value;
    }


    /*Elimina prima aparitie a elementului care are valoarea == value*/
    T removeFirstOccurrence(T value) {
        Node<T> *p = findFirstOccurrence(value);

        if (pFirst->next == pFirst) {
            delete pFirst;
            pFirst = NULL;
        } else {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            delete p;
        }

        return value;
    }

    /*Elimina ultima aparitie a elementului care are valoarea == value*/
    T removeLastOccurrence(T value) {
        Node<T> *p = findLastOccurrence(value);

        if (pFirst->next == pFirst) {
            delete pFirst;
            pFirst = NULL;
        } else {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            delete p;
        }

        return value;
    }

    /*Intoarce prima aparitie a elementului care are valoarea == value, NULL daca nu exista*/
    Node<T>* findFirstOccurrence(T value) {
        Node<T> *p = pFirst;
        while (p->value != value) {
            p = p->next;
            if (p == pFirst) {
                return NULL;
            }
        }
        return p;
    }

    /*Intoarce ultima aparitie a elementului care are valoarea == value, NULL daca nu exista*/
    Node<T>* findLastOccurrence(T value) {
        Node<T> *p = pFirst;
        while (p->value != value) {
            p = p->prev;
            if (p == pFirst) {
                return NULL;
            }
        }
        return p;
    }

    /*Intoarce 1 daca lista este vida, 0 altfel*/
    int isEmpty() {
        return pFirst == NULL;
    }

    void print() {
        if (pFirst == NULL) {
            return;
        }
        Node<T> *p = pFirst->next;
        printf("%d ", pFirst->value);
        while (p != pFirst) {
            printf("%d ", p->value);
            p = p->next;
        }
        printf("\n");
    }
};

#endif
