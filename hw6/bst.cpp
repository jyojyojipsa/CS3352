// CS 3352, fall 2022
// Homework 6

#include "bst.h"

// Returns a node's key as a string.
string BSTNode::getKeyString()
{
   stringstream strstr;
   strstr << key;
   return strstr.str();
}

// Destructor:  Deallocate all nodes in the tree.
BinarySearchTree::~BinarySearchTree()
{
   BSTNode *oldRoot;
   while (root != NULL)
   {
      oldRoot = root;
      treeDelete(oldRoot);
      delete oldRoot;
   }
}

// Walks the subtree rooted at node x and returns a string that represents
// that subtree.
string BinarySearchTree::inorderTreeWalk(BSTNode *x)
{
   string result;
   result = "";
   if (x != NULL)
   {
      result += "(" + inorderTreeWalk(x->getLeftChild());
      result += x->getKeyString();
      result += inorderTreeWalk(x->getRightChild()) + ")";
   }
   return result;
}

// Finds and returns the node with the smallest key in the subtree rooted at
// node x.  Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treeMinimum(BSTNode *x)
{
   while (x->getLeftChild() != NULL)
   {
      x = x->getLeftChild();
   }
   return x;
}

// Finds and returns the node with the smallest key larger than the key of
// node x.  Returns NULL if no such node is found.
BSTNode *BinarySearchTree::treeSuccessor(BSTNode *x)
{
   BSTNode *y;
   if (x->getRightChild() != NULL)
   {
      return treeMinimum(x->getRightChild());
   }
   y = x->getParent();
   while (y != NULL && x == y->getRightChild())
   {
      x = y;
      y = y->getParent();
   }
   return y;
}

// Inserts node z (already allocated) into the binary search tree.
void BinarySearchTree::treeInsert(BSTNode *z)
{
   BSTNode *x, *y;
   y = NULL;
   x = root;
   while (x != NULL)
   {
      y = x;
      if (z->getKey() < x->getKey())
      {
         x = x->getLeftChild();
      }
      else
      {
         x = x->getRightChild();
      }
   }
   z->setParent(y);
   if (y == NULL)
   {
      root = z;
   }
   else if (z->getKey() < y->getKey())
   {
      y->setLeftChild(z);
   }
   else
   {
      y->setRightChild(z);
   }
}

// Read the input as commands that apply to the binary search tree; report
// results.
int main()
{
   BinarySearchTree bst;
   BSTNode *node;
   int key;
   string command;
   while (cin >> command)
   {
      if (command == "delete")
      {
         cin >> key;
         node = bst.treeSearch(key);
         if (node != NULL)
         {
            bst.treeDelete(node);
            delete node;
            cout << "deleted " << key << "\n";
         }
         else
         {
            cout << key << " not found" << "\n";
         }
      }
      else if (command == "insert")
      {
         cin >> key;
         bst.treeInsert(new BSTNode(key));
         cout << "inserted " << key << "\n";
      }
      else if (command == "lookup")
      {
         cin >> key;
         node = bst.treeSearch(key);
         if (node != NULL)
         {
            if (node->getKey() == key)
            {
               cout << key << " is present\n";
            }
            else
            {
               cout << "ERROR: " << key << " searched for but " << node->getKey() << " found\n";
            }
         }
         else
         {
            cout << key << " is absent\n";
         }
      }
      else if (command == "maximum")
      {
         node = bst.treeMaximum();
         if (node != NULL)
         {
            cout << "maximum " << node->getKey() << "\n";
         }
         else
         {
            cout << "no maximum\n";
         }
      }
      else if (command == "minimum")
      {
         node = bst.treeMinimum();
         if (node != NULL)
         {
            cout << "minimum " << node->getKey() << "\n";
         }
         else
         {
            cout << "no minimum\n";
         }
      }
      else if (command == "pred")
      {
         cin >> key;
         node = bst.treeSearch(key);
         if (node != NULL)
         {
            node = bst.treePredecessor(node);
            if (node != NULL)
            {
               cout << node->getKey() << " precedes " << key << "\n";
            }
            else
            {
               cout << "no key precedes " << key << "\n";
            }
         }
         else
         {
            cout << key << " not found" << "\n";
         }
      }
      else if (command == "succ")
      {
         cin >> key;
         node = bst.treeSearch(key);
         if (node != NULL)
         {
            node = bst.treeSuccessor(node);
            if (node != NULL)
            {
               cout << node->getKey() << " succeeds " << key << "\n";
            }
            else
            {
               cout << "no key succeeds " << key << "\n";
            }
         }
         else
         {
            cout << key << " not found" << "\n";
         }
      }
      else if (command == "walk")
      {
         cout << bst.inorderTreeWalk() << "\n";
      }
      else
      {
         cout << "bad command\n";
      }
   }
   return 0;
}
