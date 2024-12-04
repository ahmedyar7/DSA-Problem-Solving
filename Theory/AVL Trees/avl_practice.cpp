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

class AVLTrees {
 public:
  TreeNode* root;
  AVLTrees() { root = nullptr; }
  void insert(int value) { insert_node(root, value); }
  void remove(int value) { delete_node(root, value); }
  void inorder() { inorder_traversal(root); }

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

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
  }

  TreeNode* rotate_right(TreeNode* node) {
    TreeNode* new_root = node->left;
    TreeNode* subtree = new_root->right;

    new_root->right = node;
    node->left = subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
  }

  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) return new TreeNode(value);
    if (value > node->data) {
      node->right = insert_node(node->right, value);
    } else if (value < node->data) {
      node->left = insert_node(node->left, value);
    } else {
      return node;
    }

    int balance = balance_factor(node);
    node->height = 1 + max(height(node->left), height(node->right));

    // LL Case
    if (balance > 1 && value < node->left->data) {
      return rotate_right(node);
    }

    // RR Case
    else if (balance < -1 && value > node->right->data) {
      return rotate_left(node);
    }

    // LR Case
    else if (balance > 1 && value > node->left->data) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }

    // RL Case
    else if (balance < -1 && value < node->right->data) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }

    else {
      return node;
    }
  }

  TreeNode* find_min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  TreeNode* delete_node(TreeNode* node, int value) {
    if (node == nullptr) {
      return nullptr;
    }
    if (value > node->data) {
      node->right = delete_node(node->right, value);
    } else if (value < node->data) {
      node->left = delete_node(node->left, value);
    }

    else {
      // No Child Nodes
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }
      // No Right Children
      else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      }
      // No left children
      else if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      }
      // Two children
      else {
        TreeNode* temp = find_min_node(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
      }
    }

    int balance = balance_factor(node);
    node->height = 1 + max(height(node->left), height(node->right));

    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0) {
      return rotate_right(node);
    }
    // RR Case
    else if (balance < -1 && balance_factor(node->right) <= 0) {
      return rotate_left(node);
    }
    // LR Case
    else if (balance > 1 && balance_factor(node->left) < 0) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
    // RL Case
    else if (balance < -1 && balance_factor(node->right) >= 0) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
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