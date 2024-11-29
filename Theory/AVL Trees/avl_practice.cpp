#include <iostream>
using namespace std;

class TreeNode {
 public:
  int data;
  int height;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

class AVLTree {
 public:
  TreeNode* root;
  AVLTree() { root = nullptr; }

 private:
  // Helper Function for checking the balance factor
  int balance_factor(TreeNode* node) {
    if (node == nullptr) return 0;
    return max(height(node->left), height(node->right));
  }

  // Helper Function for finding Height of node
  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  // Helper Function for insertion in Self Balancing Tree
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value < node->data) node->left = insert_node(node->left, value);
    if (value > node->data) node->right = insert_node(node->right, value);
    return node;
  }
};