/**
 *  Duma Andrei Dorian
 *  315 CA
 */

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "site_list.h"

/**
 * Tipul stocat în HashTable
 */
class WordEntry {
    public:
        char word[40];
        SiteList* list;
        WordEntry* next;

        WordEntry(char* w);
        ~WordEntry();

        void addSite(char* s);
        WordEntry* duplicate();
};

/**
 * Un hashtable cu elemente de tip WordEntry
 */
class HashTable {
    public:
        WordEntry** buckets;
        int buckets_no;
        int entries_no;
        unsigned int (*hash)(char*);

        HashTable(unsigned int(*hash_f)(char*), int b_no);
        ~HashTable();

        bool crowdy();
        void add(WordEntry* e);
        void add(char* word, char* site);
        SiteList* get(char* word);
};

/**
 * Extinde un hashtable dat ca parametru printr-un pointer
 */
HashTable* extend(HashTable*);

#endif
