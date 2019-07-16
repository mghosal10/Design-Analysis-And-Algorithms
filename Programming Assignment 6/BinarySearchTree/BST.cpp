#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
   BinNode * locptr = myRoot;
   bool found = false;
   while (!found && locptr != 0)
   {
      if (item < locptr->data)       // descend left
        locptr = locptr->left;
      else if (locptr->data < item)  // descend right
        locptr = locptr->right;
      else                           // item found
        found = true;
   }
   return found;
}


void BST::insert(const int & item)
{
   BinNode * locptr = myRoot;   // search pointer
   BinNode * parent = 0;        // pointer to parent of current node
   bool found = false;     // indicates if item already in BST
   while (!found && locptr != 0)
   {
      parent = locptr;
      if (item < locptr->data)       // descend left
         locptr = locptr->left;
      else if (locptr->data < item)  // descend right
         locptr = locptr->right;
      else                           // item found
         found = true;
   }
   if (!found)
   {                                 // construct node containing item
      locptr = new BinNode(item);  
      if (parent == 0)               // empty tree
         myRoot = locptr;
      else if (item < parent->data )  // insert to left of parent
         parent->left = locptr;
      else                           // insert to right of parent
         parent->right = locptr;
   }
   else
      cout << "Item already in the tree\n";
}

void BST::delete_node(const int & item)
{
    BinNode * locptr = myRoot;
    BinNode * parent = 0;
   
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (locptr->data < item)  // descend right
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else                           // item found
        {
            found = true;
        }
    }
    
    if(found)
    {
        // for nodes that have no children
        if(locptr->left == 0 && locptr->right == 0)
        {
            if(locptr != myRoot)
            {
                if(parent->left == locptr)
                {
                    parent->left = 0;
                }
                else
                {
                    parent->right = 0;
                }
                free(locptr);
            }
            else
            {
                myRoot = 0;
            }
        }
        // for nodes that have 2 children
        else if(locptr->left && locptr->right)
        {
            parent = locptr;
            child = locptr->left;
            
            while (child->right != 0) {
                parent = child;
                child = child->right;
            }
            
            if(parent == locptr)
            {
                locptr->data = child->data;
                locptr->left = child->left;
            }
            else
            {
                locptr->data = child->data;
                parent->right = child->left;
            }
        }
        // for nodes that have one child
        else
        {
            BinNode * single_child = locptr->left ? locptr->left : locptr->right;
            if(locptr != myRoot)
            {
                if(locptr == parent->left)
                {
                    parent->left = single_child;
                }
                else
                {
                    parent->right = single_child;
                }
            }
            else
            {
                myRoot = single_child;
            }
            free(locptr);
        }
    }
    else
    {
       cout << "Node not found!";
    }
}

void BST::preOrder_call()
{
    preOrder(myRoot);
}

void BST::inOrder_call()
{
    inOrder(myRoot);
}

void BST::postOrder_call()
{
    postOrder(myRoot);
}

int BST::countNodes_call()
{
    int counted = countNodes(myRoot);
    counted = counted - 1;
    return counted;
}

void BST::preOrder(BinNode * bin)
{
    if(bin != 0)
    {
        cout << bin->data << " ";
        preOrder(bin->left);
        preOrder(bin->right);
    }
}

void BST::inOrder(BinNode * bin)
{
    if(bin != 0)
    {
        inOrder(bin->left);
        cout << bin->data << " ";
        inOrder(bin->right);
    }
}

void BST::postOrder(BinNode * bin)
{
    if(bin != 0)
    {
        postOrder(bin->left);
        postOrder(bin->right);
        cout << bin->data << " ";
    }
}

int BST::countNodes(BinNode * bin)
{
    int count = 1;
    if(bin == 0)
    {
        return count;
    }
    else
    {
        count = countNodes(bin->left);
        count = count + countNodes(bin->right);
    }
    return count;
}
