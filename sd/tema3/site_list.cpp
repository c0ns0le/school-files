/**
 *  Duma Andrei Dorian
 *  315 CA
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "site_list.h"

/**
 * Constructor
 *
 * params: char* s
 */
SiteNode::SiteNode(char* s) {
    next = NULL;
    strcpy(site, s);
}

/**
 * Constructor
 */
SiteList::SiteList() {
    first = NULL;
}

/**
 * Destructor
 */
SiteList::~SiteList() {
    SiteNode* p = NULL;
    while (first != NULL) {
        p = first->next;
        delete first;
        first = p;
    }
}

/**
 * Afișează lista de site-uri
 */
void SiteList::print() {
    SiteNode* p = first;

    if (p == NULL) {
        printf("SITE_NOT_FOUND\n");
        return;
    }

    while (p != NULL) {
        printf("%s ", p->site);
        p = p->next;
    }

    printf("\n");
}

/**
 * Adaugă un site în listă
 */
void SiteList::addSite(char* s) {
    SiteNode* p = first;
    SiteNode* prev = NULL;

    while (p != NULL && strcmp(s, p->site)>0) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        if (prev == NULL) {
            first = new SiteNode(s);
        } else {
            prev->next = new SiteNode(s);
        }
    } else {
        if (strcmp(s, p->site) != 0) {
            if (prev == NULL) {
                prev = new SiteNode(s);
                prev->next = first;
                first = prev;
            } else {
                prev->next = new SiteNode(s);
                prev->next->next = p;
            }
        }
    }
}

/**
 * Intersectează lista cu o altă listă, dată
 * de parametrul list
 */
void SiteList::intersectWith(SiteList* list) {
    SiteNode* p = list->first;
    SiteNode* q = first;
    SiteNode* q_prev = NULL;
    SiteNode* last = NULL;
    first = NULL;

    while (p != NULL && q != NULL) {
        if (strcmp(p->site, q->site)<0) {
            p = p->next;
        } else if (strcmp(p->site, q->site)>0) {
            q_prev = q;
            q = q->next;
            delete q_prev;
        } else {
            if (first) {
                last->next = new SiteNode(p->site);
                last = last->next;
            } else {
                first = last = new SiteNode(p->site);
            }
            p = p->next;
            q_prev = q;
            q = q->next;
            delete q_prev;
        }
    }

    while (q != NULL) {
        q_prev = q;
        q = q->next;
        delete q_prev;
    }
}

/**
 * Creează o copie a listei pentru a fi utilizată în alte locuri
 */
SiteList* SiteList::duplicate() {
    SiteList* list = new SiteList;

    SiteNode* p = first;

    if (p == NULL) {
        return list;
    }

    list->first = new SiteNode(p->site);
    p = p->next;

    SiteNode* q = list->first;

    while (p != NULL) {
        q->next = new SiteNode(p->site);
        q = q->next;
        p = p->next;
    }

    return list;
}
