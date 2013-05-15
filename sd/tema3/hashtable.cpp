/**
 *  Duma Andrei Dorian
 *  315 CA
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hashtable.h"

/**
 * Constructor
 */
WordEntry::WordEntry(char* w) {
    strcpy(word, w);
    list = new SiteList();
    next = NULL;
}

/**
 * Destructor
 */
WordEntry::~WordEntry() {
    delete list;
}

/**
 * Adaugă un site la lista din cadrul Entry-ului
 */
void WordEntry::addSite(char* s) {
    list->addSite(s);
}

/**
 * Creează o copie a Entry-ului
 */
WordEntry* WordEntry::duplicate() {
    WordEntry* e = new WordEntry(word);
    delete e->list;
    e->list = list->duplicate();

    return e;
}

/**
 * Constructor
 *
 * params: funcția de hash și numărul inițial de "găleți"
 */
HashTable::HashTable(unsigned int(*hash_f)(char*), int b_no) {
    hash = hash_f;
    buckets_no = b_no;
    entries_no = 0;
    buckets = new WordEntry*[buckets_no];

    int i;
    for (i=0; i<b_no; i++) {
        buckets[i] = NULL;
    }
}

/**
 * Destructor - eliberează memoria alocată
 */
HashTable::~HashTable() {
    int i;
    WordEntry* p = NULL;
    WordEntry* prev = NULL;

    for (i=0; i<buckets_no; i++) {
        p = buckets[i];
        prev = NULL;

        while (p != NULL) {
            prev = p;
            p = p->next;
            delete prev;
        }
    }

    buckets_no = 0;
    delete[] buckets;
}

/**
 * Verifică dacă s-a atins factorul de umplere de 0.7
 */
bool HashTable::crowdy() {
    if ((double)entries_no / buckets_no > 0.7) {
        return true;
    }
    return false;
}

/**
 * Dublează dimensiune tabelului, redistribuind elementele
 */
HashTable* extend(HashTable* h) {
    HashTable* _h = new HashTable(h->hash, 2 * h->buckets_no);

    WordEntry* p = NULL;

    int i;
    for (i=0; i < h->buckets_no; i++) {
        p = h->buckets[i];
        while (p != NULL) {
            _h->add(p);
            p = p->next;
        }
    }

    delete h;
    return _h;
}

/**
 * Adaugă un WordEntry (dat printr-un pointer) în tabel
 */
void HashTable::add(WordEntry* e) {
    int b = hash(e->word) % buckets_no;

    WordEntry* _e = e->duplicate();
    _e->next = buckets[b];
    buckets[b] = _e;
    ++entries_no;
}

/**
 * Adaugă un WordEntry (dat prin word & site) în tabel
 */
void HashTable::add(char* word, char* site) {
    int b = hash(word) % buckets_no;
    WordEntry* p = buckets[b];
    WordEntry* prev = NULL;

    while (p != NULL && strcmp(p->word, word) != 0) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        if (prev == NULL) {
            buckets[b] = new WordEntry(word);
            buckets[b]->addSite(site);
        } else {
            prev->next = new WordEntry(word);
            prev->next->addSite(site);
        }
        ++entries_no;
    } else {
        p->addSite(site);
    }
}

/**
 * Întoarce lista de site-uri în care apare 'word'
 */
SiteList* HashTable::get(char* word) {
    int b = hash(word) % buckets_no;
    WordEntry* p = buckets[b];

    while (p != NULL) {
        if (strcmp(p->word, word)==0) {
            return p->list;
        }
        p = p->next;
    }

    return NULL;
}
