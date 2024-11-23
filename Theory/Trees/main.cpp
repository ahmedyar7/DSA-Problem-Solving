#include <iostream>

#include "practice.cpp"

using namespace std;

int main() {
  // Example inputs
  int preorder[] = {1, 2, 4, 5, 3, 6, 7};
  int inorder[] = {4, 2, 5, 1, 6, 3, 7};
  int n = 7;  // Number of nodes

  int preorderIndex = 0;
  TreeNode* root = construct_tree(preorder, inorder, preorderIndex, 0, n - 1);

  cout << "Preorder traversal of the constructed tree: ";
  preorder_traversal(root);
  cout << endl;

  cout << "Inorder traversal of the constructed tree: ";
  inorder_traversal(root);
  cout << endl;

  cout << "Postorder traversal of the constructed tree: ";
  postorder_traversal(root);
  cout << endl;

  cout << "Level traversal of the constructed tree: ";
  levelorder_traversal(root);
  cout << endl;

  return 0;
}
