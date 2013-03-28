#ifndef __HASHTABLE__H
#define __HASHTABLE__H

#include "list.h"
#include <stdio.h>
#include <string.h>

template<typename Tkey, typename Tvalue> struct elem_info_ {
        Tkey key;
        Tvalue value;
};

template<typename Tkey, typename Tvalue> class elem_info {
    public:
        Tkey key;
        Tvalue value;

        int operator!=(elem_info<Tkey, Tvalue> e) {
            if (strcmp(this->key, e.key) != 0) {
                return 1;
            }
            return 0;
        }
};

template<typename Tkey, typename Tvalue> class Hashtable {
        private:
                LinkedList<elem_info<Tkey, Tvalue> > *H;
                int HMAX;
                int (*hash) (Tkey);
        public:
                Hashtable(int hmax, int (*h)(Tkey)) {
                    HMAX = hmax;
                    hash = h;
                    H = new LinkedList<elem_info<Tkey, Tvalue> >[HMAX];
                }

                ~Hashtable() {
                    delete H;
                }
                
                void put(Tkey key, Tvalue value) {
                    elem_info<Tkey, Tvalue> e;
                    e.key = key;
                    e.value = value;
                    if (H[(*hash)(key)].findFirstOccurrence(e) == NULL) {
                        H[(*hash)(key)].addFirst(e);
                    } else {
                        H[(*hash)(key)].findFirstOccurrence(e)->value = e;
                    }
                }

                Tvalue get(Tkey key) {
                    elem_info<Tkey, Tvalue> e;
                    e.key = key;
                    Tvalue value;
                    e.value = value;
                    if (H[(*hash)(key)].findFirstOccurrence(e) == NULL) {
                        fprintf(stderr, "Error: not here!\n");
                        Tvalue ceva;
                        return ceva;
                    }
                    return H[(*hash)(key)].findFirstOccurrence(e)->value.value;
                }

                bool hasKey(Tkey key) {
                    elem_info<Tkey, Tvalue> e;
                    e.key = key;
                    Tvalue value;
                    e.value = value;
                    if (H[(*hash)(key)].findFirstOccurrence(e) == NULL) {
                        return 0;
                    }
                    return 1;
                }
};

#endif // __HASHTABLE__H
