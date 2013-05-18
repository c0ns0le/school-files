#ifndef __TRIE_H
#define __TRIE_H

#include "treap.h"

class TrieNode {
    public:
        Treap* t;
        TrieNode* edges[10];

        TrieNode() {
            t = new Treap();
            int i;
            for (i=0; i<10; i++) {
                edges[i] = NULL;
            }
        }

        ~TrieNode() {
            delete t;
            int i;
            for (i=0; i<10; i++) {
                if (edges[i]) {
                    delete edges[i];
                }
            }
        }

        int digit(std::string word, int level) {
            switch (word[level]) {
                case 'a': case 'b': case 'c':           return 2;
                case 'd': case 'e': case 'f':           return 3;
                case 'g': case 'h': case 'i':           return 4;
                case 'j': case 'k': case 'l':           return 5;
                case 'm': case 'n': case 'o':           return 6;
                case 'p': case 'q': case 'r': case 's': return 7;
                case 't': case 'u': case 'v':           return 8;
                case 'w': case 'x': case 'y': case 'z': return 9;
            }
        }

        void insert(int level, int number, std::string word) {
            if (level < word.length()) {
                int id = digit(word, level);
                
                if (edges[id] == NULL) {
                    edges[id] = new TrieNode();
                }

                edges[id]->insert(level + 1, number, word);
            } else {
                t->insert(number, word);
            }
        }

        std::string visit(int level, std::string code, int k) {
            if (level < code.length()) {
                char id = code[level] - '0';

                return edges[id]->visit(level + 1, code, k);
            } else {
                return t->visit(k);
            }
        }
};

class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        ~Trie() {
            delete root;
        }

        void insert(int number, std::string word) {
            root->insert(0, number, word);
        }

        std::string visit(std::string code, int k) {
            return root->visit(0, code, k);
        }
};

#endif
