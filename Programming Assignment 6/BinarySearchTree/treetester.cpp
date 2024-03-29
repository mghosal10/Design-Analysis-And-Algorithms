/*----- treetester.cpp -----------------------------------------------------
                Program for testing BST.
 ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
   // Testing Constructor and empty()
   BST intBST;            // test the class constructor
   cout << "Constructing empty BST\n";
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing insert
   cout << "\nNow insert a bunch of integers into the BST."
           "\nTry items not in the BST and some that are in it:\n";
   int number;
   for (;;)
   {
      cout << "Item to insert (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      intBST.insert(number);
   }
   cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

   // Testing search()
   cout << "\n\nNow testing the search() operation."
           "\nTry both items in the BST and some not in it:\n";
   for (;;)
   {
      cout << "Item to find (-999 to stop): ";
      cin >> number;
      if (number == -999) break;
      cout << (intBST.search(number) ? "Found" : "Not found") << endl;
   }
   
    cout << "\nPreorder traversal is : ";
    intBST.preOrder_call();
    cout << "\nInorder traversal is : ";
    intBST.inOrder_call();
    cout << "\nPostorder traversal is : ";
    intBST.postOrder_call();
    int count = intBST.countNodes_call();
    cout << "\nCount of the nodes is : " << count;
    
    for (;;)
    {
        cout << "\nItem to delete (-999 to stop): ";
        cin >> number;
        if (number == -999) break;
        intBST.delete_node(number);
        cout << "\nValues after deleted nodes are : ";
        intBST.inOrder_call();
    }
    
}
