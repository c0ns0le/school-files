/**
  * Autor: Victor Carbune
  * Echipa SD, 2012
  *
  * License: LGPL
  */

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "BinaryTree.h"
#include "ExpressionNode.h"

#define MAX 1000

using namespace std;

/** Helper functions. */
bool isExpression(const char *input)
{
    return strchr(input, '|') != NULL;
}

bool isTerm(const char *input)
{
    return !isExpression(input) && strchr(input, '&') != NULL;
}

bool isLiteral(const char *input)
{
    return !isExpression(input) && !isTerm(input);
}

BinaryTree<ExpressionNode> *parseLiteral(const char *inputLiteral)
{
    BinaryTree<ExpressionNode> *node;
    ExpressionNode nodeData;

    // Debugging.
    // cout << "ParseLiteral: " << inputLiteral << endl;

    // Update node data.
    // TODO 2.2
    //
    // Initialize the node data.
    nodeData.isOperator = false;
    strcpy(nodeData.value, inputLiteral);

    node = new BinaryTree<ExpressionNode>();
    node->setData(nodeData);

    return node;
}

BinaryTree<ExpressionNode> *parseTerm(char *inputTerm)
{
    BinaryTree<ExpressionNode> *node;
    ExpressionNode nodeData;

    // Save the value in a local variable.
    char localString[MAX];
    memset(localString, 0, MAX);
    strcpy(localString, inputTerm);

    if (strlen(localString) == 0)
        return NULL;

    // Debugging.
    // cout << "ParseTerm: " << inputTerm << endl;

    // Initialize the node data.
    // TODO 2.1
    // Initialize the node data.
    nodeData.isOperator = true;
    strcpy(nodeData.value, "&");

    // Tokenize the input.
    char *literal = strtok(localString, "&");

    // Initialize the tree node.
    // TODO 2.1
    node = new BinaryTree<ExpressionNode>();

    // Set the data of the current node.
    // TODO 2.1
    node->setData(nodeData);

    // Parse the left subtree.
    // TODO 2.1
    node->setLeftSubtree(parseLiteral(literal));

    // Parse the right subtree.
    char *newString = localString + strlen(literal) + 1;
    if (isLiteral(newString))
        node->setRightSubtree(parseLiteral(newString));
    else
        node->setRightSubtree(parseTerm(newString));

    return node;
}


BinaryTree<ExpressionNode> *parseExpression(char *inputExpr)
{
    BinaryTree<ExpressionNode> *node;
    ExpressionNode nodeData;

    // Work on a local string.
    char localString[MAX];
    memset(localString, 0, MAX);
    strcpy(localString, inputExpr);

    if (strlen(localString) == 0)
        return NULL;

    // Debugging.
    // cout << "ParseExpression: " << inputExpr << endl;

    // Initialize the node data.
    nodeData.isOperator = true;
    strcpy(nodeData.value, "|");

    // Tokenize the input.
    char *term = strtok(localString, "|");

    // Initialize the tree node.
    node = new BinaryTree<ExpressionNode>();

    // Set the data of the node.
    node->setData(nodeData);

    // Parse the left subtree.
    if (isLiteral(term))
        node->setLeftSubtree(parseLiteral(term));
    else
        node->setLeftSubtree(parseTerm(term));

    cout << endl;

    // Parse the right subtree.
    char *newString = localString + strlen(term) + 1;
    if (isExpression(newString)) {
        node->setRightSubtree(parseExpression(newString));
        return node;
    }

    if (isTerm(newString)) {
        node->setRightSubtree(parseTerm(newString));
        return node;
    }

    node->setRightSubtree(parseLiteral(newString));

    return node;
}

bool evaluateAST(BinaryTree<ExpressionNode> *root)
{
    // TODO 3

    return true;
}

int main()
{
    char inputExpr[MAX];
    BinaryTree<ExpressionNode> *root = NULL;

    // Read one line from the input.
    cin.getline(inputExpr, MAX);

    // Parse the expression and store the root node.
    root = isExpression(inputExpr) ? parseExpression(inputExpr) :
        (isTerm(inputExpr) ? parseTerm(inputExpr) : parseLiteral(inputExpr));

    // Debug the root node. The output should match your initial expression.
    // TODO 2.3
    root->displayTree(0);
    // cout << "The result of the expression is: " << evaluateAST(root);

    delete root;

/*    srand(time(0));

    BinaryTree<int> b;
    int i;
    for (i=0; i<10; i++) {
        b.insert(i);
    }

    b.displayTree(0);
*/
    return 0;
}
