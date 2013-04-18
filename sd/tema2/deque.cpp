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
}

void Deque::setMaxDays(int maxDays) {
//printf("setMaxDays: %d %d %d --", day, this->maxDays, first->vector[0].date);
    this->maxDays = maxDays;

    popFront();
//printf(" %d %d %d\n", day, this->maxDays, first->vector[0].date);
}

void Deque::dayPasses() {
//printf("dayPasses: %d %d %d --", day, this->maxDays, first->vector[0].date);
    day += 1;

    popFront();
//printf(" %d %d %d\n", day, this->maxDays, first->vector[0].date);
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
/*
    int oldestPossible = this->day - this->maxDays + 1;
    Node* p = NULL;

    while (first && first->vector[first->size - 1].date < oldestPossible) {
        if (first->next == NULL) {
            delete first;
            first = last = NULL;
            return;
        }
        p = first->next;
        p->prev = NULL;
        delete first;
        first = p;
    }

    if (first == NULL) {
        return;
    }

    int i;
    for (i = 0; i < first->size; i++) {
        if (first->vector[i].date >= oldestPossible) {
            first->remove(i);
            return;
        }
    }
*/
    /** AGAIN **/
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
//fprintf(stderr, "%d %d %d\n", i, first->size, maxSize);
        ++i;
    }
    first->remove(i);
}

void Deque::popBack(int time) {
/*
    int newestPossible = day - time;
    Node* p = NULL;

    while (last && last->vector[0].date > newestPossible) {
        if (last->prev == NULL) {
            delete last;
            first = last = NULL;
            return;
        }
        p = last->prev;
        p->next = NULL;
        delete last;
        last = p;
    }

    int i;
    for (i = last->size - 1; i >= 0; i--) {
        if (last->vector[i].date <= newestPossible) {
            last->size = i + 1;
            return;
        }
    }
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
/*
    Node* p = last;
    if (p == NULL) {
        fprintf(stderr, "NULL!\n");
    }
printf("size: %d n: %d diff: %d\n", p->size, n, p->size - n - 1);
    while (p->prev && n >= p->size) {
        n -= p->size;
        p = p->prev;
printf("size: %d n: %d diff: %d\n", p->size, n, p->size - n - 1);
    }

printf("size: %d n: %d diff: %d\n", p->size, n, p->size - n - 1);

    return p->vector[p->size - n - 1];
    */
    Node* q = first;
    int total = 0;
    while (q != NULL) {
        total += q->size;
        q = q->next;
    }
//printf("Sunt %d elemente in total!\n", total);

    Node* p = last;

    while (n >= p->size) {
//printf("size: %d n: %d diff: %d\n", p->size, n, p->size - n - 1);
        n -= p->size;
        p = p->prev;
    }

    return p->vector[p->size - n - 1];
}

void Deque::erase(int n) {
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
    //printf("HISTORY:\nCurrent day: %d maxDays: %d oldest: %d\n", day, maxDays, first->vector[0].date);
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
