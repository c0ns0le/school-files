#ifndef __TREAP_H
#define __TREAP_H

#include <string>

class TreapNode {
    public:
        int number;
        std::string word;
        int priority;
        int size;
        bool nil;

        TreapNode* left;
        TreapNode* right;

        TreapNode();
        ~TreapNode();

        void fill(int number, std::string word, int priority);  // OK
        void purge();  // OK
        void insert(TreapNode *&node, int number, std::string word, int priority);  // OK
        std::string visit(TreapNode *&root, TreapNode *&node, int k);  // OK
        void rotateRight(TreapNode *&node);  // OK
        void rotateLeft(TreapNode *&node);  // OK
        void print(int level);  // OK
};

class Treap {
    private:
        TreapNode* root;

    public:
        Treap();
        ~Treap();

        void insert(int number, std::string word);
        std::string visit(int k);
        void print();
};
#endif
