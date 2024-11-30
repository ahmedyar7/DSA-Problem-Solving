#include <iostream>
using namespace std;

// Understanding the Tree structure
class TreeNode {
 public:
  int data;
  TreeNode* left;
  TreeNode* right;
  int height;

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

  void insert(int value) { root = insert_node(root, value); }

  void inorder() { inorder_traversal(root); }

  TreeNode* delete_node(TreeNode* node, int value) {
    if (node == nullptr)  // Base case: node not found
      return node;

    if (value < node->data)  // Value lies in the left subtree
      node->left = delete_node(node->left, value);
    else if (value > node->data)  // Value lies in the right subtree
      node->right = delete_node(node->right, value);
    else {  // Found the node to delete
      if ((node->left == nullptr) || (node->right == nullptr)) {
        TreeNode* temp = node->left ? node->left : node->right;

        if (temp == nullptr) {  // No child case
          temp = node;
          node = nullptr;
        } else {  // One child case
          *node = *temp;
        }
        delete temp;
      } else {  // Node with two children
        TreeNode* temp = find_min_node(node->right);
        node->data = temp->data;  // Copy inorder successor's data
        node->right = delete_node(node->right, temp->data);  // Delete successor
      }
    }

    if (node == nullptr)  // If the tree had only one node
      return node;

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = balance_factor(node);

    // Balance the tree
    if (balance > 1 && balance_factor(node->left) >= 0)  // Left Left Case
      return right_rotation(node);

    if (balance > 1 && balance_factor(node->left) < 0) {  // Left Right Case
      node->left = left_rotation(node->left);
      return right_rotation(node);
    }

    if (balance < -1 && balance_factor(node->right) <= 0)  // Right Right Case
      return left_rotation(node);

    if (balance < -1 && balance_factor(node->right) > 0) {  // Right Left Case
      node->right = right_rotation(node->right);
      return left_rotation(node);
    }

    return node;  // Return the (possibly balanced) node pointer
  }

 private:
  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    return node->height;
  }

  int balance_factor(TreeNode* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
  }

  TreeNode* left_rotation(TreeNode* root) {
    TreeNode* new_root = root->right;
    TreeNode* subtree = new_root->left;
    new_root->left = root;
    root->right = subtree;
    root->height = max(height(root->left), height(root->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
  }

  TreeNode* right_rotation(TreeNode* root) {
    TreeNode* new_root = root->left;
    TreeNode* subtree = new_root->right;
    new_root->right = root;
    root->left = subtree;
    root->height = max(height(root->left), height(root->right)) + 1;
    new_root->height = max(height(new_root->left), height(new_root->right)) + 1;
    return new_root;
  }

  TreeNode* insert_node(TreeNode* node, int value) {
    if (node == nullptr)  // The node is empty
      return new TreeNode(value);

    if (value < node->data)  // Left Subtree
      node->left = insert_node(node->left, value);
    else if (value > node->data)  // Right Subtree
      node->right = insert_node(node->right, value);
    else
      return node;  // Duplicate values are not allowed

    // Revaluation of height
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balance_factor(node);  // Balance Factor

    if (balance > 1 && value < node->left->data)  // Left Left Rotation
      return right_rotation(node);

    if (balance < -1 && value > node->right->data)  // Right Right Rotation
      return left_rotation(node);

    if (balance > 1 && value > node->left->data) {  // Left Right Rotation
      node->left = left_rotation(node->left);
      return right_rotation(node);
    }

    if (balance < -1 && value < node->right->data) {  // Right Left Rotation
      node->right = left_rotation(node->right);
      return left_rotation(node);
    }
    return node;
  }

  TreeNode* find_min_node(TreeNode* node) {
    TreeNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
  }

  void inorder_traversal(TreeNode* node) {
    if (node == nullptr) return;
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }
};
