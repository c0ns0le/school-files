#include "treap.h"
#include <iostream>
#include <cstdlib>

TreapNode::TreapNode() {
    number = size = 0;
    priority = -1;
    nil = true;
    word = std::string();
}

TreapNode::~TreapNode() {
    if (nil) {
        return;
    }

    delete left;
    delete right;
}

void TreapNode::fill(int number, std::string word, int priority) {
    this->number = number;
    this->word = word;
    this->priority = priority;
    this->nil = false;
    this->size = 1;
    this->left = new TreapNode();
    this->right = new TreapNode();
}

void TreapNode::purge() {
    nil = true;
    priority = -1;
    size = 0;
    delete left;
    delete right;
}

void TreapNode::insert(TreapNode *&node, int number, std::string word, int priority) {
    if (nil) {
        fill(number, word, priority);
        return;
    }

    ++size;

    if (number > this->number) {
        left->insert(left, number, word, priority);
    } else if (number < this->number) {
        right->insert(right, number, word, priority);
    } else if (word < this->word) {
        left->insert(left, number, word, priority);
    } else if (word > this->word) {
        right->insert(right, number, word, priority);
    }

    if (left->priority > this->priority) {
        rotateRight(node);
    } else if (right->priority > this->priority) {
        rotateLeft(node);
    }
}

std::string TreapNode::visit(TreapNode *&root, TreapNode *&node, int k) {
    int _number;
    std::string _word;
    int _priority;

    std::string result;

    --size;

    if (k < left->size) {
        result = left->visit(root, left, k);
    } else if (k > left->size) {
        result = right->visit(root, right, k - left->size - 1);
    } else if (left->nil && right->nil) {
        result = word;

        _number = number;
        _word = word;
        _priority = priority;
        purge();
        root->insert(root, _number + 1, _word, _priority);
    } else {
        if (left->priority > right->priority) {
            rotateRight(node);
            result = node->visit(root, node, k);
        } else {
            rotateLeft(node);
            result = node->visit(root, node, k);
        }
    }

    return result;
}

void TreapNode::rotateRight(TreapNode *&node) {
    TreapNode* aux = node->left;
    node->left = aux->right;
    aux->right = node;

    node->size = 1 + node->left->size + node->right->size;

    node = aux;

    node->size = 1 + node->left->size + node->right->size;
}

void TreapNode::rotateLeft(TreapNode *&node) {
    TreapNode* aux = node->right;
    node->right = aux->left;
    aux->left = node;

    node->size = 1 + node->left->size + node->right->size;

    node = aux;

    node->size = 1 + node->left->size + node->right->size;
}

void TreapNode::print(int level) {
    int i;
    for (i=0; i<level; i++) {
        std::cout << "  ";
    }

    if (nil) {
        std::cout << "[]\n";
        return;
    }
    
    std::cout << "[" << number << "," << word << "," << priority << "," << size << "]" << std::endl;
    left->print(level+1);
    right->print(level+1);
}

Treap::Treap() {
    root = new TreapNode();
    srand(time(0));
}

Treap::~Treap() {
    delete root;
}

void Treap::insert(int number, std::string word) {
    root->insert(root, number, word, rand());
}

std::string Treap::visit(int k) {
    return root->visit(root, root, k % root->size);
}

void Treap::print() {
    root->print(0);
}
