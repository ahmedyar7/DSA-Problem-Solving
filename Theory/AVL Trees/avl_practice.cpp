#include <iostream>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode* left;
  TreeNode* right;
  int height = 1;
};

class AvlTree {
 private:
  int get_height(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  int balance_factor(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return get_height(node->left) - get_height(node->right);
  }

  TreeNode* rotate_left(TreeNode* node) {
    TreeNode* new_root = node->right;
    TreeNode* subtree = new_root->left;

    new_root->left = node;
    node->right = subtree;

    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    return new_root;
  }

  TreeNode* rotate_right(TreeNode* node) {
    TreeNode* new_root = node->left;
    TreeNode* subtree = new_root->right;

    new_root->right = node;
    node->left = subtree;

    new_root->height =
        1 + max(get_height(new_root->left), get_height(new_root->right));
    node->height = 1 + max(get_height(node->left), get_height(node->right));

    return new_root;
  }

 public:
};