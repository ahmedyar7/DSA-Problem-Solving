#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  BinaryTree tree;
  int preorder_arr[] = {10, 5, 3, 7, 15, 12, 18};
  int inorder_arr[] = {3, 5, 7, 10, 12, 15, 18};
  int size = sizeof(preorder_arr) / sizeof(preorder_arr[0]);

  int preorder_index =
      0;  // This variable is passed by reference to maintain state
  TreeNode* root = tree.construct_tree(preorder_arr, inorder_arr,
                                       preorder_index, 0, size - 1);
  cout << endl;
  tree.display();

  cout << tree.count() << endl;
  cout << tree.height() << endl;
  cout << tree.leaf_nodes() << endl;
  cout << tree.node_deg2() << endl;

  return 0;
}
