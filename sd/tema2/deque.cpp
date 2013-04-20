#include <stdio.h>
#include "visit.h"
#include "deque.h"

Deque::Deque(int maxSize) {
    this->maxSize = maxSize;
    this->maxDays = 30;
    this->day = 0;

    this->first = NULL;
    this->last  = NULL;
}

Deque::~Deque() {
    Node* p = first;
    Node* next = NULL;

    while (p != NULL) {
        next = p->next;
        delete p;
        p = next;
    }
}

void Deque::setMaxDays(int maxDays) {
    this->maxDays = maxDays;

    popFront();
}

void Deque::dayPasses() {
    day += 1;

    popFront();
}

void Deque::pushFront(Visit v) {
    Node* p = NULL;
    if (first == NULL) {
        first = new Node(this->maxSize);
        last = first;
    } else if (first->isFull()) {
        p = new Node(this->maxSize);
        p->next = first;
        first->prev = p;
        first = p;
    }
    first->addVisitFirst(v);
}

void Deque::pushBack(Visit v) {
    /**
     * Adaugă la la capătul "recent" al deque-ului
     */
    Node *p = NULL;
    if (last == NULL) {
        last = new Node(this->maxSize);
        first = last;
    } else if (last->isFull()) {
        p = new Node(this->maxSize);
        p->prev = last;
        last->next = p;
        last = p;
    }
    last->addVisit(v);
}

void Deque::popFront() {
    /**
     * Elimină vizitele prea vechi.
     */
    int expired = day - maxDays;
    Node* p = NULL;

    if (first == NULL) {
        return;
    }
    
    while (first && first->vector[first->size - 1].date <= expired) {
        p = first->next;
        delete first;
        first = p;
        if (first) {
            first->prev = NULL;
        } else {
            last = NULL;
            return;
        }
    }

    int i = 0;
    while (first->vector[i].date <= expired) {
        ++i;
    }
    first->remove(i);
}

void Deque::popBack(int time) {
    /**
     * Elimină elementele cu vechimea cel mult @time
     */
    int oldestToRemove = day - time + 1;
    Node* p = NULL;

    if (last == NULL) {
        return;
    }

    while (last && last->vector[0].date >= oldestToRemove) {
        p = last->prev;
        delete last;
        last = p;
        if (last) {
            last->next = NULL;
        } else {
            first = NULL;
            return;
        }
    }

    int i = last->size - 1;
    while (last->vector[i].date >= oldestToRemove) {
        --i;
    }
    last->size = i + 1;
}

void Deque::accessPage(char* url) {
    Visit v(url, day);
    pushBack(v);
}

Visit Deque::get(int n) {
    /**
     * Returnează al n-lea element,
     *   numărând de la capătul "recent" al deque-ului
     */
    Node* q = first;
    int total = 0;
    while (q != NULL) {
        total += q->size;
        q = q->next;
    }

    Node* p = last;

    while (n >= p->size) {
        n -= p->size;
        p = p->prev;
    }

    return p->vector[p->size - n - 1];
}

void Deque::erase(int n) {
    /**
     * Șterge al n-lea element, numărând de la capătul "recent" al deque-ului
     */
    Node* p = last;
    while (p->prev && n >= p->size) {
        n -= p->size;
        p = p->prev;
    }

    p->erase(p->size - n - 1);
    if (p->isEmpty()) {
        if (p == first) {
            first = p->next;
            if (first) {
                first->prev = NULL;
            } else {
                last = NULL;
            }
        } else if (p == last) {
            last = p->prev;
            if (last) {
                last->next = NULL;
            } else {
                first = NULL;
            }
        } else {
            p->next->prev = p->prev;
            p->prev->next = p->next;
        }
    }
}

void Deque::show_history() {
    Node* p = last;
    int i;

    printf("HISTORY:\nCurrent day: %d\n", day);
    while (p != NULL) {
        for (i = p->size - 1; i >= 0; i--) {
            printf("%d %s\n", p->vector[i].date, p->vector[i].url);
        }
        p = p->prev;
    }
    printf("\n");
}

void Deque::recoverHistory(char* filename) {
    FILE* f;
    f = fopen(filename, "r");

    int n, i, date;
    fscanf(f, "%d", &n);

    char url[100];
    for (i=0; i<n; i++) {
        fscanf(f, "%d %s", &date, url);
        pushFront(Visit(url, date));
    }

    popFront();
}
