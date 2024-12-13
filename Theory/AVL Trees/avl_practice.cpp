#include <iostream>
using namespace std;

// Class Treenode
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

// Class AVL Tress
class AVLTree {
 private:
  // Helper function to find height
  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }

  int balance_factor(TreeNode* node) {
    return (height(node->left) - height(node->right));
  }

  // left rotations
  TreeNode* left_rotate(TreeNode* node) {
    TreeNode* new_root = node->right;
    TreeNode* subtree = new_root->left;

    new_root->left = node;
    node->right = subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
  }

  // right rotation
  TreeNode* right_rotate(TreeNode* node) {
    TreeNode* new_root = node->left;
    TreeNode* subtree = new_root->right;

    new_root->right = node;
    node->left = subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
  }

  TreeNode* find_min(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) {
      current = current->left;
    }
    return current;
  }

  // Insert Node helper function
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

    // Rotation Case

    // LL Case
    if (balance > 1 && node->left->data > value) {
      return right_rotate(node);
    }
    // RR Case
    else if (balance < -1 && node->right->data < value) {
      return left_rotate(node);
    }
    // LR Case
    else if (balance > 1 && node->left->data < value) {
      node->left = left_rotate(node->left);
      return right_rotate(node);
    }
    // RL case
    else if (balance < -1 && node->right->data > value) {
      node->right = right_rotate(node->right);
      return left_rotate(node);
    } else {
      return node;
    }
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
        delete temp;
        return nullptr;
      } else if (node->left == nullptr) {
        TreeNode* temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        TreeNode* temp = node->left;
        delete node;
        return temp;
      } else {
        TreeNode* temp = find_min(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
      }
    }

    int balance = balance_factor(node);
    node->height = 1 + max(height(node->left), height(node->right));

    // LL Case
    if (balance > 1 && balance_factor(node->left) >= 0) {
      return right_rotate(node);
    }
    // RR Case
    else if (balance < -1 && balance_factor(node->right) <= 0) {
      return left_rotate(node);
    }
    // LR Case
    else if (balance > 1 && balance_factor(node->left) <= 0) {
      node->left = left_rotate(node->left);
      return right_rotate(node);
    }
    // RL case
    else if (balance < -1 && balance_factor(node->right) >= 0) {
      node->right = right_rotate(node->right);
      return left_rotate(node);
    } else {
      return node;
    }
  }

 public:
  TreeNode* root;
  AVLTree() { root = nullptr; }

  void insert(int value) { root = insert_node(root, value); }
  void inorder() { inorder_traversal(root); }
  void remove(int value) { delete_node(root, value); }
};

int main() {
  AVLTree tree;

  // Inserting elements
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  cout << "Inorder traversal after inserts: ";
  tree.inorder();

  // Deleting an element
  tree.remove(30);
  cout << "Inorder traversal after deleting 30: ";
  tree.inorder();

  return 0;
}