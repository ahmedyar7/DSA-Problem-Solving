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
    height = 0;
    left = nullptr;
    right = nullptr;
  }
};

class AVLTrees {
 public:
  TreeNode* root;
  AVLTrees() { root = nullptr; }
  void insert(int value) { root = insert_node(root, value); }
  void inorder() { inorder_traversal(root); }
  void delete_value(int value) { delete_node(root, value); }

 private:
  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  int balance_factor(TreeNode* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
  }

  TreeNode* left_rotatation(TreeNode* node) {
    TreeNode* new_root = node->right;
    TreeNode* sub_tree = new_root->left;
    new_root->left = node;
    node->right = sub_tree;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;
    return new_root;
  }

  TreeNode* right_rotation(TreeNode* node) {
    TreeNode* new_root = node->left;
    TreeNode* subtree = new_root->right;
    new_root->right = node;
    node->left = subtree;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    node->height = max(height(node->left), height(node->right)) + 1;
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
    // LL case
    if (balance > 1 && value < node->left->data) return right_rotation(node);
    // RR Case
    else if (balance < -1 && value > node->right->data)
      return left_rotatation(node);
    // LR Case
    else if (balance > 1 && value > node->left->data) {
      node->left = left_rotatation(node->left);
      return right_rotation(node);
    }
    // RL Case
    else if (balance < -1 && value < node->right->data) {
      node->right = right_rotation(node->right);
      return left_rotatation(node);
    } else {
      return node;
    }
  }

  TreeNode* min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  TreeNode* delete_node(TreeNode* node, int value) {
    if (node == nullptr) return nullptr;
    if (value > node->data) {
      node->right = delete_node(node->right, value);
    } else if (value < node->data) {
      node->left = delete_node(node->left, value);
    } else {
      if (node->left == nullptr && node->right == nullptr) {
        TreeNode* temp = node;
        node = nullptr;
        delete temp;
      }

      else if (node->left == nullptr) {
        TreeNode* temp = node->right;
        node->right = nullptr;
        delete temp;
      }

      else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        node->left = nullptr;
        delete temp;
      }

      else {
        TreeNode* inorder = min_node(node->right);
        node->data = inorder->data;
        node->right = delete_node(node->right, inorder->data);
      }
    }
    if (node == nullptr) return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balance_factor(node);
    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0)
      return right_rotation(node);
    // RR Case
    else if (balance < -1 && balance_factor(node->right) <= 0)
      return left_rotatation(node);
    // LR CASE
    else if (balance > 1 && balance_factor(node->left) <= 0) {
      node->left = left_rotatation(node->left);
      return right_rotation(node);
    }
    // RL CASE
    else if (balance < -1 && balance_factor(node->right) >= 0) {
      node->right = right_rotation(node->right);
      return left_rotatation(node);
    } else {
      return node;
    }
    return node;
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }
};