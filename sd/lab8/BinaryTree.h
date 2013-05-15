/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * Modificari: Adrian Bogatu
  * Echipa SD, 2013
  *
  * License: LGPL
  */

#ifndef __BINARY_TREE_H
#define __BINARY_TREE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class BinaryTree
{
private:
    BinaryTree<T> *leftNode;
    BinaryTree<T> *rightNode;

    T *pData;

public:
    BinaryTree() {
        leftNode = NULL;
        rightNode = NULL;
        pData = NULL;
    }

    ~BinaryTree() {}

    // Inspect if the current node has data.
    bool hasData() {
        if ( pData ) {
            return true;
        }
        return false;
    }

    // Set data for current node.
    void setData(T data) {
        pData = new T;
        *pData = data;
    }

    // Set left subtree.
    void setLeftSubtree(BinaryTree<T> *node) {
        leftNode = node;
    }

    // Get the left subtree.
    BinaryTree<T> *getLeftSubtree() {
        return leftNode;
    }

    // Set right subtree.
    void setRightSubtree(BinaryTree<T> *node) {
        rightNode = node;
    }

    // Get the right subtree.
    BinaryTree<T> *getRightSubtree() {
        return rightNode;
    }

    // Insert data recursively randomly where it is possible.
    void insert(T data) {
        if (!hasData()) {
            setData(data);
            return;
        }
        int direction = rand() % 2;
        /* DEBUG // cout << "Direction: " << direction << endl; */
        if (direction) {
            insertRight(data);
        } else {
            insertLeft(data);
        }
    }

    // Insert data into left subtree.
    void insertLeft(T data) {
        if ( leftNode == NULL ) {
            leftNode = new BinaryTree<T>();
            leftNode->setData(data);
        } else {
            leftNode->insert(data);
        }
    }

    // Insert data into right subtree.
    void insertRight(T data) {
        if ( rightNode == NULL ) {
            rightNode = new BinaryTree<T>();
            rightNode->setData(data);
        } else {
            rightNode->insert(data);
        }
    }

    // Display the binary tree to output.
    void displayTree(int indentLevel) {
        if (leftNode) leftNode->displayTree(indentLevel);
        cout << *pData;
        if (rightNode) rightNode->displayTree(indentLevel);
    }
};


#endif // __BINARY_TREE_H
