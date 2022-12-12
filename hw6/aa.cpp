#include "bst.h"

// Finds and returns the node with key k in the subtree rooted at node x.
// Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treeSearch(BSTNode *x, int k)
{ // I refer this pseudocode from textbook chapter 12

   
   if(k == x->getKey() || x == nullptr) // if x == NULL or k == x.key
      
      return x; 
   
   if( k < x->getKey()) // if k < x.key
        
      return treeSearch(x->getLeftChild(), k); // it will return TREE-SEARCH(x.left.k)    
   else
       
   return treeSearch(x->getRightChild(), k);   // it will return TREE-SEARCH(x.right.k) 
}

// Finds and returns the node with the largest key in the subtree rooted at
// node x.  Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treeMaximum(BSTNode *x)
{// I refer this pseudocode from textbook chapter 12.
   
   // In case of x.right ≠ NULL  
  while(x->getRightChild() != nullptr)
    {   
      x = x->getRightChild(); // x = x.right
    }
   
   return x;   
}

// Finds and returns the node with the largest key smaller than the key of
// node x.  Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treePredecessor(BSTNode *x)
{ 
   // In here, I got the idea from this site: https://sites.math.rutgers.edu/~ajl213/CLRS/CLRS.html
   BSTNode *y;
   
   // x.left ≠ NULL 
   if(x->getLeftChild() != nullptr) {   
       return treeMaximum(x->getLeftChild()); // it will return TREE-MAXIMUM(x.left)
   }// end if
          // y = x.p
      y = x->getParent();
   
   //while y ≠ NULL and x == y.left 
   while (y != nullptr && x == y->getLeftChild())
   {
      // do x = y
      x = y;
      // y = y.p
      y = y->getParent();
   } //end while
   
   return y; 
}

// Replaces subtree rooted at node u with the subtree rooted at node v.
// Should be used by the treeDelete function.
void BinarySearchTree::transplant(BSTNode *u, BSTNode *v)
{  // according to the pseudocode from textbook 12.3 transplant
   
   //if u.p == nullptr
  if (u->getParent() == nullptr)
     // T.root = v
     this->root = v;
     // elseif u == u.p.left
  else if (u == u->getParent()->getLeftChild())
   // u.p.left = v  
  u->getParent()->setLeftChild(v);
  else //else u.p.right = v;
     u->getParent()->setRightChild(v);
  // v ≠ NIL
  if(v != nullptr)
     // v.p = u.p
     v->setParent(u->getParent());
}

void BinarySearchTree::treeDelete(BSTNode *z)
{ // from textbook 12.3 
   
   BSTNode *y;
   
   //if z.left == nullptr
  if(z->getLeftChild() == nullptr)
   // TRANSPLANT(T,z,z.right)   
  transplant(z, z->getRightChild());
  // elseif z.right == nullptr
  else if(z->getRightChild() == nullptr)
     // TRANSPLANT(T,z,z.right())
     transplant(z, z->getLeftChild());
  else
  {
     // else y = TREE-MINUMUM(z.right)
    y = treeMinimum(z->getRightChild());
    
    // if y.p ≠  z
    if(y->getParent() != z)
    { 
      //TRANSPLANT(T,y,y.right)
       transplant(y, y->getRightChild());
       // y.right = z.right
       y->setRightChild(z->getRightChild());
       // y.right.p = y
       y->getRightChild()->setParent(y);
    }
    
    // TRANSPLANT(T,z,y)
     transplant(z, y);
     // y.setLeftChild = z.setLeftChild
     y->setLeftChild(z->getLeftChild());
     // y.left.p = y
     y->getLeftChild()->setParent(y);
  }
}