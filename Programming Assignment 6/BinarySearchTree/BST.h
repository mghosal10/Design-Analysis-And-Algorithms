#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
 class BinNode;
    
 public:
  /***** Function Members *****/
  BST();
  bool empty() const;
  bool search(const int & item) const; 
  void insert(const int & item);
  void delete_node(const int & item);
  void preOrder_call();
  void inOrder_call();
  void postOrder_call();
  int countNodes_call();
    
  
 private:
    void preOrder(BinNode * bin);
    void inOrder(BinNode * bin);
    void postOrder(BinNode * bin);
    int countNodes(BinNode * bin);
  /***** Node class *****/
  class BinNode 
  {
   public:
    int data;
    BinNode * left;
    BinNode * right;

    // BinNode constructors
    // Default -- data part is default int value; both links are null.
    BinNode()
    : left(0), right(0)
    {}

    // Explicit Value -- data part contains item; both links are null.
    BinNode(int item)
    : data(item), left(0), right(0)
    {}
 
  };// end of class BinNode declaration
  
  /***** Data Members *****/
  BinNode * myRoot;
    BinNode * child;

}; // end of class declaration

#endif
