// CS 3352, fall 2022
// Homework 6

#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Class definitions with inline member functions.

class BSTNode
{
private:
   int key;
   BSTNode *parent;
   BSTNode *leftChild;
   BSTNode *rightChild;
public:
   BSTNode(int k) {key = k; setParent(NULL); setLeftChild(NULL); setRightChild(NULL);}
   int getKey() {return key;}
   string getKeyString();
   BSTNode *getParent() {return parent;}
   BSTNode *getLeftChild() {return leftChild;}
   BSTNode *getRightChild() {return rightChild;}
   void setParent(BSTNode *n) {parent = n;}
   void setLeftChild(BSTNode *n) {leftChild = n;}
   void setRightChild(BSTNode *n) {rightChild = n;}
};

class BinarySearchTree
{
private:
   BSTNode *root;
   void transplant(BSTNode *u, BSTNode *v);
public:
   BinarySearchTree() {root = NULL;}
   ~BinarySearchTree();
   string inorderTreeWalk(BSTNode *);
   string inorderTreeWalk() {return inorderTreeWalk(root);}
   BSTNode *treeSearch(BSTNode *, int);
   BSTNode *treeSearch(int k) {return treeSearch(root, k);}
   BSTNode *treeMinimum(BSTNode *);
   BSTNode *treeMinimum() {return root != NULL ? treeMinimum(root) : NULL;}
   BSTNode *treeMaximum(BSTNode *);
   BSTNode *treeMaximum() {return root != NULL ? treeMaximum(root) : NULL;}
   BSTNode *treeSuccessor(BSTNode *);
   BSTNode *treePredecessor(BSTNode *);
   void treeInsert(BSTNode *);
   void treeDelete(BSTNode *);
};

#endif // #ifndef BST_H
