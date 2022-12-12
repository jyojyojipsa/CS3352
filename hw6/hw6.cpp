// YOUR NAME: Kangmin Kim
//
// CS 3352, fall 2022
// Homework 6: Binary search trees

#include "bst.h"

// #include <iostream>
// #include <sstream>
// #include <string>

// Finds and returns the node with key k in the subtree rooted at node x.
// Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treeSearch(BSTNode *x, int k)
{
	// I referred this website.
	// https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
	//start from the root.
	// Base Cases: root is null or key is present at root
   if(x == nullptr || k == x->getKey())
	   return x; 

    // Key is greater than root's key
   if( x->getKey() < k)
	   return treeSearch(x->getRightChild(), k);
   // return rightChild from tree

    // Key is smaller than root's key
	return treeSearch(x->getLeftChild(), k);
}

// Finds and returns the node with the largest key in the subtree rooted at
// node x.  Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treeMaximum(BSTNode *x)
{
	// While RightChild is not empty
  while(x->getRightChild() != nullptr)
    {	
	// It points the maximum index of node
	   x = x->getRightChild();
    }
   return x;
}

// Finds and returns the node with the largest key smaller than the key of
// node x.  Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treePredecessor(BSTNode *x)
{
		//              15
		//          10      20
		//        8   12  16   25
        
// predecessor of node 15 is 12.
// predecessor of node 10 is 8.
// predecessor of node 20 is 16.
// predecessor doesn't exist for node 8.
// predecessor of node 12 is 10
// predecessor of node 16 is 15
// predecessor of node 25 is 20


// Find children node that is lower but closest.

// declare alternative Node.
   BSTNode *alt;
   alt = x->getParent(); // allocate Parent nodes to alternative node
   if(x->getLeftChild() != nullptr) // if LeftChild is empty 
	   return treeMaximum(x->getLeftChild()); // it just returns.
   
	while (alt != nullptr && x == alt->getLeftChild())
	{
		x = alt;
		alt = alt->getParent();
	} 

   return alt; 
}

// Replaces subtree rooted at node u with the subtree rooted at node v.
// Should be used by the treeDelete function.
void BinarySearchTree::transplant(BSTNode *u, BSTNode *v)
{
  if (u->getParent() == nullptr) // was u the root?
	  root = v; // if so, now v is the root
  else if (u == u->getParent()->getLeftChild()) // otherwise adjust the child of u's parent
	  u->getParent()->setLeftChild(v);
  else
	  u->getParent()->setRightChild(v);

  if(v != nullptr) // if v wasn't the sentinel
	  v->setParent(u->getParent()); // update its parent
}


// Removes node z from the binary search tree.  (Does not deallocate node
// z.)
void BinarySearchTree::treeDelete(BSTNode *z)
{ 
     /* Pseudocode from textbook 12.3 TREE-DELETE(T,z)
	   
              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
	   https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
	 */
   
   BSTNode *alt; // declare alternative node set
   
  if(z->getLeftChild() == nullptr) 
	  transplant(z, z->getRightChild());
  else if(z->getRightChild() == nullptr)
	  transplant(z, z->getLeftChild()); // search for Child node to pick
  else
  {
	 alt = treeMinimum(z->getRightChild());  // set alt to z's rightchild
	 if(alt->getParent() != z)                      
	 {                                              
		 transplant(alt, alt->getRightChild());//u = alt, v = alt's rightchild
		 alt->setRightChild(z->getRightChild());    
		 alt->getRightChild()->setParent(alt);      
	 }                                              
	  transplant(z, alt);                           
	  alt->setLeftChild(z->getLeftChild());  // set alt's leftchild to z's leftchild
      alt->getLeftChild()->setParent(alt);  // parent = alt   
  }
} 

/*class BSTNode
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
*/