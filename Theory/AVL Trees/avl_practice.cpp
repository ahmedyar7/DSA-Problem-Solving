#include <iostream>
using namespace std;

class TreeNode {
 public:
  int value;
  TreeNode* left;
  TreeNode* right;
  int height;

  TreeNode(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

class AVLTrees {
 public:
  TreeNode* root;
  AVLTrees() { root = nullptr; }

  void insert(int value) { root = insert_node(root, value); }
  void inorder() { inorder_traversal(root); }
  void remove(int value) { delete_node(root, value); }

 private:
  // Height of the nodes
  int height(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return node->height;
  }

  // Balance factor of node
  int balance_factor(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }
    return height(node->left) - height(node->right);
  }

  // Left Rotation
  TreeNode* rotate_left(TreeNode* node) {
    TreeNode* new_node = node->right;
    TreeNode* subtree = new_node->left;

    new_node->left = node;
    node->right = subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_node->height = 1 + max(height(new_node->left), height(new_node->right));

    return new_node;
  }

  // Right Rotation
  TreeNode* rotate_right(TreeNode* node) {
    TreeNode* new_node = node->left;
    TreeNode* subtree = new_node->right;

    new_node->right = node;
    node->left = subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_node->height = 1 + max(height(new_node->left), height(new_node->right));

    return new_node;
  }

  // Minimum node
  TreeNode* find_min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  // Insert Node
  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr) {
      return new TreeNode(value);
    }
    if (value > node->value) {
      node->right = insert_node(node->right, value);
    } else if (value < node->value) {
      node->left = insert_node(node->left, value);
    } else {
      return node;
    }

    // Recalaculate height
    node->height = 1 + max(height(node->left), height(node->right));

    // Balance Factor
    int balance = balance_factor(node);

    // --- Rotation Cases --- //

    // LL Case
    if (balance > 1 && node->left->value < value) {
      return rotate_right(node);
    }
    // RR Case
    else if (balance < -1 && node->right->value > value) {
      return rotate_left(node);
    }
    // LR Case
    else if (balance > 1 && node->left->value > value) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
    // RL Case
    else if (balance < -1 && node->right->value < value) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
    // Other condition
    else {
      return node;
    }
  }

  TreeNode* delete_node(TreeNode* node, int value) {
    if (node == nullptr) {
      return nullptr;
    }
    if (value > node->value) {
      node->right = delete_node(node->right, value);
    } else if (value < node->value) {
      node->left = delete_node(node->left, value);
    }

    else {
      // No children
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
      }
      // No left children
      else if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      }
      // No right child
      else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      }
      // Contain Both children
      // delete the smallest children in right subtree
      else {
        TreeNode* temp = find_min_node(node->right);
        node->value = temp->value;
        node->right = delete_node(node->right, temp->value);
      }
    }

    // Re-calculate the height
    node->height = 1 + max(height(node->left), height(node->right));
    // Balance factor
    int balance = balance_factor(node);

    // --- Balance Condition --- //

    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0) {
      return rotate_right(node);
    }
    // RR Case
    else if (balance < -1 && balance_factor(node->right) <= 0) {
      return rotate_left(node);
    }
    // LR Case
    else if (balance > 1 && balance_factor(node->left) <= 0) {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
    // RL Case
    else if (balance < -1 && balance_factor(node->right) >= 0) {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    } else {
      return node;
    }
  }

  // Helper for inorder traversal
  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) {
      return;
    }
    inorder_traversal(node->left);
    cout << node->value << " ";
    inorder_traversal(node->right);
  }
};