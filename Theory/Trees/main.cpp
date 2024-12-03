#include <iostream>

#include "practice.cpp"
using namespace std;

#include <iostream>
using namespace std;

int main() {
  BinaryTree tree;

  // Insert nodes
  tree.insert(15);
  tree.insert(10);
  tree.insert(20);
  tree.insert(8);
  tree.insert(12);
  tree.insert(17);
  tree.insert(25);

  // Traversals
  cout << "Preorder Traversal: ";
  tree.preorder();
  cout << endl;

  cout << "Inorder Traversal: ";
  tree.inorder();
  cout << endl;

  cout << "Postorder Traversal: ";
  tree.postorder();
  cout << endl;

  cout << "Level Order Traversal: ";
  tree.levelorder();
  cout << endl;

  // Tree properties
  cout << "Number of Nodes: ";
  tree.count();
  cout << endl;

  cout << "Number of Leaf Nodes: ";
  tree.count_leafs();
  cout << endl;

  cout << "Height of Tree: ";
  tree.height();
  cout << endl;

  cout << "Number of Nodes with Degree 1: ";
  tree.deg1();
  cout << endl;

  cout << "Number of Nodes with Degree 2: ";
  tree.deg2();
  cout << endl;

  // Construct tree from preorder and inorder traversals
  int preorder[] = {15, 10, 8, 12, 20, 17, 25};
  int inorder[] = {8, 10, 12, 15, 17, 20, 25};
  int preorder_index = 0;
  TreeNode* newTreeRoot =
      tree.construct_tree(preorder, inorder, preorder_index, 0, 6);

  cout << "Inorder Traversal of Constructed Tree: ";
  tree.inorder();
  cout << endl;

  return 0;
}
