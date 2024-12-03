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
    height = 1;
    left = nullptr, right = nullptr;
  }
};

class AVLTrees {
 public:
  TreeNode* root;
  AVLTrees() { root = nullptr; }
  void insert(int value) { root = insert_node(root, value); }
  void remove(int value) { root = delete_node(root, value); }
  void inorder() { inorder_traversal(root); }

 public:
 private:
  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  int balance_factor(TreeNode* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
  }

  TreeNode* rotate_left(TreeNode* node) {
    TreeNode* new_root = node->right;
    TreeNode* subtree = new_root->left;
    new_root->left = node;
    node->right = subtree;
    node->height = 1 + max(height(subtree->left), height(subtree->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));
    return new_root;
  }

  TreeNode* rotate_right(TreeNode* node) {
    TreeNode* new_root = node->left;
    TreeNode* subtree = new_root->right;
    new_root->right = node;
    node->left = subtree;
    node->height = 1 + max(height(subtree->left), height(subtree->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));
    return new_root;
  }

  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data)
      node->right = insert_node(node->right, value);
    else if (value < node->data)
      node->left = insert_node(node->left, value);
    else
      return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balance_factor(node);

    // LL CASE
    if (balance > 1 && value < node->left->data) return rotate_right(node);
    // RR CASE
    if (balance < -1 && value > node->right->data) return rotate_left(node);
    // LR CASE
    if (balance > 1 && value > node->left->data) {
      node->left = rotate_left(node->left);
      rotate_right(node);
    }
    // RL CASE
    if (balance < -1 && value < node->right->data) {
      node->right = rotate_right(node->right);
      rotate_left(node);
    }
    return node;
  }

  TreeNode* min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  TreeNode* delete_node(TreeNode* node, int value) {
    if (node == nullptr) return node;
    if (value > node->data) {
      delete_node(node->right, value);
    } else if (value < node->data) {
      delete_node(node->left, value);
    } else {
      if (node->left == nullptr && node->right == nullptr) {
        TreeNode* temp = node;
        node = nullptr;
        delete temp;
      } else if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        node = temp;
      } else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        node = temp;
      } else {
        TreeNode* temp = min_node(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
      }
    }
    if (node == nullptr) return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balance_factor(node);

    if (balance > 1 && balance_factor(node->left) >= 0)
      return rotate_right(node);
    else if (balance < -1 && balance_factor(node->left) <= 0)
      return rotate_left(node);
    else if (balance > 1 && balance_factor(node->left) <= -1) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    } else if (balance < 1 && balance_factor(node->right) >= 1) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    } else {
      return node;
    }
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }
};