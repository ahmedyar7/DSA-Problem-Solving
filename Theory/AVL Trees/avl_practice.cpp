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
  TreeNode* right_rotation(TreeNode* root) {
    TreeNode* new_root = root->left;
    TreeNode* move_sub_tree = new_root->right;
    new_root->right = root;
    root->left = move_sub_tree;
    root->height = max(height(root->left), height(root->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
  }

  TreeNode* left_rotation(TreeNode* root) {
    TreeNode* new_root = root->right;
    TreeNode* move_subtree = new_root->left;
    new_root->left = root;
    root->right = move_subtree;
    root->height = max(height(root->left), height(root->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
  }

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
    if (value < node->data)
      node->left = insert_node(node->left, value);
    else if (value > node->data)
      node->right = insert_node(node->right, value);
    else
      return node;

    int balance = balance_factor(node);

    // Check for left imbalance
    if (balance > 1 && value < node->left->data) {
      right_rotation(node);
    }
    // Check for right imbalance
    if (balance < -1 && value > node->left->data) {
      left_rotation(node);
    }

    // Check for left right imbalance
    if (balance > 1 && value > node->left->data) {
      node->left = left_rotation(node->left);
      return right_rotation(node);
    }
    // Check for left right imbalance
    if (balance < -1 && value < node->left->data) {
      node->right = right_rotation(node->right);
      return left_rotation(node);
    }

    return node;
  }

  TreeNode* find_min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  TreeNode* delete_node(TreeNode* node, int value) {
    if (node == nullptr) return node;
    if (value < node->data) {
      node->left = delete_node(node->left, value);
    } else if (value > node->data) {
      node->right = delete_node(node->right, value);
    } else
      // Node without childs
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }

    // Has left child
    if (node->right == nullptr) {
      TreeNode* temp = node->left;
      delete node;
      return temp;
    }

    // has right child
    else if (node->left == nullptr) {
      TreeNode* temp = node->right;
      delete node;
      return temp;
    }

    // Node with 2 childrens
    else {
      TreeNode* inorder_successor = find_min_node(node->right);
      node->data = inorder_successor->data;
      node->right = delete_node(node->right, inorder_successor->data);
    }

    if (node == nullptr) return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = balance_factor(node);

    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0)
      return right_rotation(node);
    // RR Case
    if (balance < -1 && balance_factor(node->left) <= 0)
      return left_rotation(node);
    // LR Case
  }
};